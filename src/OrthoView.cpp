// OrthoView.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "CyberToolBox.h"
#include "CyberToolBoxDoc.h"
#include "CyberToolBoxView.h"
#include "OrthoFrame.h"
#include "OrthoView.h"
#include "PerspectiveView.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
#include "OpenGLFn.h"
#include "World.h"
#include "DialogOrthviewConfig.h"
#include "CUndoActionFn.h"
#include "PrimitiveFloating.h"
#include "DialogObjectAppearance.h"
#include "MathUtil.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// OrthoView

IMPLEMENT_DYNCREATE(OrthoView, CScrollView)

OrthoView::OrthoView()
{
	oglDC = NULL;
	setOffset(0.0f, 0.0f, 0.0f);
	setScale(1.0f);
	setViewMode(ORTHO_XY_PLANE);
	setObjectMode(0);
	setOperationMode(OPERATION_NONE);
	setSnapOn(true);
	setGridSize(1.0f);
	setGridAngle(45.0f);
	setGridDisplayOn(true);
	mFontInfo = new CFontInfo(FONT_TYPE_ORTHOVIEW);
	setGLFontID(0);
	setGLFontOutLineID(0);
	initializeMutexObject();
	
	float bboxSize[] = {10.0f, 10.0f, 10.0f};
	float bboxCenter[] = {0.0f, 0.0f, 0.0f};
	setSceneBoundingBoxSize(bboxSize);
	setSceneBoundingBoxCenter(bboxCenter);

	setSelectedShapeNode(NULL);
	setSelectedTransformNode(NULL);
}

OrthoView::~OrthoView()
{
	closeMutexObject();
	delete	mFontInfo;
	if (oglDC)
		delete oglDC;
}


BEGIN_MESSAGE_MAP(OrthoView, CScrollView)
	//{{AFX_MSG_MAP(OrthoView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_OBJECT_PICK, OnObjectPick)
	ON_COMMAND(ID_OBJECT_MOVE, OnObjectMove)
	ON_COMMAND(ID_OBJECT_ZOOM, OnObjectZoom)
	ON_COMMAND(ID_XY_VIEW, OnXyView)
	ON_COMMAND(ID_XZ_VIEW, OnXzView)
	ON_COMMAND(ID_YZ_VIEW, OnYzView)
	ON_COMMAND(ID_ZOOMALL, OnZoomall)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_UNDO, OnUndo)
	ON_COMMAND(ID_SNAP, OnSnap)
	ON_COMMAND(ID_GRID, OnGrid)
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_CONFIG, OnConfig)
	ON_COMMAND(ID_OBJECT_ROTATE, OnObjectRotate)
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

////////////////////////////////////////////////////////// 
//  PickShape
////////////////////////////////////////////////////////// 

#define SELECTION_BUF_SIZE	1024

int ProcessHits(GLint hits, GLuint buffer[]);

ShapeNode *OrthoView::pickShapeNode(int mx, int my)
{
	GLuint	selectBuf[SELECTION_BUF_SIZE];
	GLint	viewport[4];

    wglMakeCurrent(oglHdc, oglHrc);

	glGetIntegerv(GL_VIEWPORT, viewport);
	glSelectBuffer(SELECTION_BUF_SIZE, selectBuf);

	glRenderMode(GL_SELECT);
	glInitNames();
	glPushName(0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPickMatrix(mx, viewport[3]-my, 1.0, 1.0, viewport);

	drawSceneGraph(true);

	glPopName();

	GLint hits = glRenderMode(GL_RENDER);
	int nShape = ProcessHits(hits, selectBuf);

	if (nShape < 0)
		return NULL;

	SceneGraph *sg = GetWorld()->getSceneGraph();
	ShapeNode *shape = sg->findShapeNode();
	for (int n=0; n<nShape && shape; n++)
		shape=shape->nextTraversal();

    wglMakeCurrent(NULL, NULL);

	return shape;
}

/////////////////////////////////////////////////////////////////////////////
// OrthoView 描画

void OrthoView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: このビュー全体のサイズを計算してください。
	sizeTotal.cx = sizeTotal.cy = 0;
	SetScrollSizes(MM_TEXT, sizeTotal);

	pressButton(ID_XY_VIEW, TRUE);
	pressButton(ID_OBJECT_PICK, TRUE);
	pressButton(ID_SNAP, TRUE);
	pressButton(ID_GRID, TRUE);
}

void OrthoView::drawText(float x, float y, char *string)
{	
	glRasterPos2f(x, y);
	glListBase(getGLFontID());
 	glCallLists(strlen(string), GL_UNSIGNED_BYTE, (const GLvoid*)string);
}

void OrthoView::drawOutLineTextBaseLine()
{	
	float pos[3];
	TransformNode *transform = getEditPrimitiveTransformNode();
	transform->getTranslation(pos);

	float gridSize = getGridSize();

	glBegin(GL_LINES);

	glVertex3f(pos[0], pos[1], pos[2]);
	glVertex3f(pos[0] + gridSize, pos[1], pos[2]);

	glVertex3f(pos[0], pos[1], pos[2]);
	glVertex3f(pos[0], pos[1] + gridSize, pos[2]);

	glVertex3f(pos[0], pos[1], pos[2]);
	if (getViewMode() == ORTHO_XZ_PLANE)
		glVertex3f(pos[0], pos[1], pos[2] - gridSize);
	else
		glVertex3f(pos[0], pos[1], pos[2] + gridSize);

	glEnd();
}

void OrthoView::drawOutLineText(float x, float y, char *string)
{	
	glRasterPos2f(x, y);
	unsigned int id = getGLFontOutLineID();
	if (id != 0) {
		glListBase(getGLFontOutLineID());
 		glCallLists(strlen(string), GL_UNSIGNED_BYTE, (const GLvoid*)string);
	}
}

void OrthoView::drawGridText(float x2d[], float y2d[])
{
	float width = x2d[1] - x2d[0];
	float height = y2d[1] - y2d[0];

	char *hPlusText, *hMinusText;
	char *vPlusText, *vMinusText;
	switch (getViewMode()) {
	case ORTHO_XY_PLANE:
		hPlusText	= "X+";
		hMinusText	= "X-";
		vPlusText	= "Y+";
		vMinusText	= "Y-";
		break;
	case ORTHO_YZ_PLANE:
		hPlusText	= "Z+";
		hMinusText	= "Z-";
		vPlusText	= "Y+";
		vMinusText	= "Y-";
		break;
	case ORTHO_XZ_PLANE:
		hPlusText	= "X+";
		hMinusText	= "X-";
		vPlusText	= "Z-";
		vMinusText	= "Z+";
		break;
	}

	glColor3f(.7f, .7f, .7f);

	RECT rect;
	GetClientRect(&rect);
	float winWidth = (float)rect.right;
	float winHeight = (float)rect.bottom;

	CSize size;
	float x, y;

	size = getCDC()->GetOutputTextExtent(hMinusText, 2);
	x = x2d[0];
	y = (y2d[0]+y2d[1])/2.0f - ((float)size.cy/4.0f)/winHeight*height;
	drawText(x, y, hMinusText);

	size = getCDC()->GetOutputTextExtent(hPlusText, 2);
	x = x2d[1] - ((float)size.cx)/winWidth*width;
	y = (y2d[0]+y2d[1])/2.0f - ((float)size.cy/4.0f)/winHeight*height;
	drawText(x, y, hPlusText);

	size = getCDC()->GetOutputTextExtent(vMinusText, 2);
	x = (x2d[0]+x2d[1])/2.0f - ((float)size.cx/4.0f)/winWidth*width;
	y = y2d[0];
	drawText(x, y, vMinusText);

	size = getCDC()->GetOutputTextExtent(vPlusText, 2);
	x = (x2d[0]+x2d[1])/2.0f - ((float)size.cx/4.0f)/winWidth*width;
	y = y2d[1] - ((float)size.cy/2.0f)/winHeight*height;
	drawText(x, y, vPlusText);
}

void OrthoView::drawGrid(float x2d[], float y2d[])
{
	glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
	gluOrtho2D(x2d[0], x2d[1], y2d[0], y2d[1]);

	glBegin(GL_LINES);

	if (isGridDisplayOn()) {
		float gridSize = getGridSize();
		glColor3f(.0f, .0f, .0f);
		for (float gx=x2d[0]-(float)fmod(x2d[0], gridSize); gx<x2d[1]; gx+=gridSize) {
			glVertex2f(gx, y2d[0]);
			glVertex2f(gx, y2d[1]);
		}
		for (float gy=y2d[0]-(float)fmod(y2d[0], gridSize); gy<y2d[1]; gy+=gridSize) {
			glVertex2f(x2d[0], gy);
			glVertex2f(x2d[1], gy);
		}
	}

	if (isAxisDisplayOn()) {
		glColor3f(.8f, .8f, .8f);

 		glVertex2f(x2d[0], 0);
		glVertex2f(x2d[1], 0);

		glVertex2f(0, y2d[0]);
		glVertex2f(0, y2d[1]);
	}

	glEnd();

	drawGridText(x2d, y2d);
}


#define CIRCLE_STEP	10
#define CIRCLE_SIZE	10
#define LINE_WIDTH	2

void OrthoView::drawCircle(float cx, float cy, float cz, float radius, float lineWidth, float r, float g, float b)
{
	float x, y, z;
	float pi = 3.1415926535f;

	glColor3f(r, g, b);
	glLineWidth(lineWidth);

	glBegin(GL_LINE_LOOP);

		for (int n=0; n<CIRCLE_STEP; n++) { 
			double angle = (360.0/(double)CIRCLE_STEP)*(double)n/180.0*pi;
			switch (getViewMode()) {
			case ORTHO_XY_PLANE:
				x = cx + (float)cos(angle)*radius;
				y = cy + (float)sin(angle)*radius;
				z = cz;
				break;
			case ORTHO_YZ_PLANE:
				x = cx;
				y = cy + (float)sin(angle)*radius;
				z = cz + (float)cos(angle)*radius;
				break;
			case ORTHO_XZ_PLANE:
				x = cx + (float)cos(angle)*radius;
				y = cy;
				z = cz + (float)sin(angle)*radius;
				break;
			}
			glVertex3f(x, y, z);
		}

	glEnd();
	
	glLineWidth(1);
}

void OrthoView::drawLine(float cx, float cy, float cz, float dirx, float diry, float dirz, float minScale, float maxScale, float lineSize, float lineWidth, float r, float g, float b)
{
	glColor3f(r, g, b);
	glLineWidth(lineWidth);

	float x, y, z;

	glBegin(GL_LINES);

		x = cx + dirx * (lineSize*minScale);
		y = cy + diry * (lineSize*minScale);
		z = cz + dirz * (lineSize*minScale);
		glVertex3f(x, y, z);

		x = cx + dirx * (lineSize*maxScale);
		y = cy + diry * (lineSize*maxScale);
		z = cz + dirz * (lineSize*maxScale);
		glVertex3f(x, y, z);

	glEnd();

	glLineWidth(1);
}

void OrthoView::drawViewpoint2D()
{
	SceneGraph *sg = GetWorld()->getSceneGraph();
	ViewpointNode *view = sg->getViewpointNode();
	if (!view)
		view = sg->getDefaultViewpointNode();

	float size;

	float	pos[3];
	view->getPosition(pos);

	size = windowToWorld(CIRCLE_SIZE);
	drawCircle(pos[X], pos[Y], pos[Z], size, LINE_WIDTH, .8f, .8f, 1.0f);

	float		ori[4];
	view->getOrientation(ori);
	SFRotation	rotation(ori);
	SFVec3f		dir(0.0f, 0.0f, -1.0f);
	dir.rotate(&rotation);

	size = windowToWorld(CIRCLE_SIZE);
	drawLine(pos[X], pos[Y], pos[Z], dir.getX(), dir.getY(), dir.getZ(), .3f, 1.5f, size, LINE_WIDTH, .8f, .8f, 1.0f);
}

void OrthoView::drawViewpoint3D()
{
	SceneGraph *sg = GetWorld()->getSceneGraph();
	ViewpointNode *view = sg->getViewpointNode();
	if (!view)
		view = sg->getDefaultViewpointNode();

	TransformNode *viewTransform = GetWorld()->getViewpointObjectNode();
	if (!viewTransform)
		return;

	ShapeNode *shape = viewTransform->getShapeNodes();
	if (!shape)
		return;

	GeometryNode *geom = (GeometryNode *)shape->getGeometryNode();
	if (!geom)
		return;

	float	pos[3];
	float	ori[4];
	view->getPosition(pos);
	view->getOrientation(ori);

	viewTransform->setTranslation(pos);
	viewTransform->setRotation(ori);

	float	m4[4][4];
	shape->getTransformMatrix(m4);
	
	glColor3f(.6f, .6f, .6f);
	glPushMatrix ();
	glMultMatrixf((float *)m4);
	if (0 < geom->getDisplayList())
		geom->draw();
	glPopMatrix ();
}

void OrthoView::drawSpotLight2D(SpotLightNode *light)
{
	float size;

	float	pos[3];
	light->getLocation(pos);

	size = windowToWorld(CIRCLE_SIZE);
	drawCircle(pos[X], pos[Y], pos[Z], size, LINE_WIDTH, 1.0f, 1.0f, 0.0f);

	float	dir[3];
	light->getDirection(dir);

	size = windowToWorld(CIRCLE_SIZE);
	drawLine(pos[X], pos[Y], pos[Z], dir[X], dir[Y], dir[Z], .3f, 1.5f, size, LINE_WIDTH, 1.0f, 1.0f, .8f);
}

void OrthoView::drawSpotLight3D(SpotLightNode *light)
{
	TransformNode *lightTransform = GetWorld()->getSpotLightObjectNode();
	if (!lightTransform)
		return;

	ShapeNode *shape = lightTransform->getShapeNodes();
	if (!shape)
		return;

	GeometryNode *geom = (GeometryNode *)shape->getGeometryNode();
	if (!geom)
		return;

	float	pos[3];
	float	dir[4];
	light->getLocation(pos);
	light->getDirection(dir);

	SFMatrix mxDirection(dir[0], dir[1], dir[2]);
	
	float	rot[4];
	SFRotation rotDirection;
	mxDirection.getSFRotation(&rotDirection);
	rotDirection.getValue(rot);

	lightTransform->setTranslation(pos);
	lightTransform->setRotation(rot);

	float	m4[4][4];
	shape->getTransformMatrix(m4);
	
	glColor3f(.6f, .6f, .0f);
	glPushMatrix ();
	glMultMatrixf((float *)m4);
	if (0 < geom->getDisplayList())
		geom->draw();
	glPopMatrix ();
}

void OrthoView::drawPointLight2D(PointLightNode *light)
{
	float	pos[3];
	light->getLocation(pos);

	float size = windowToWorld(CIRCLE_SIZE);
	drawCircle(pos[X], pos[Y], pos[Z], size, LINE_WIDTH, 1.0f, 1.0f, 0.0f);
}

void OrthoView::drawPointLight3D(PointLightNode *light)
{
	TransformNode *lightTransform = GetWorld()->getPointLightObjectNode();
	if (!lightTransform)
		return;

	ShapeNode *shape = lightTransform->getShapeNodes();
	if (!shape)
		return;

	GeometryNode *geom = (GeometryNode *)shape->getGeometryNode();
	if (!geom)
		return;

	float	pos[3];
	float	ori[4];
	light->getLocation(pos);
	ori[0] = 0.0f;
	ori[1] = 0.0f;
	ori[2] = 1.0f;
	ori[3] = 0.0f;

	lightTransform->setTranslation(pos);
	lightTransform->setRotation(ori);

	float	m4[4][4];
	shape->getTransformMatrix(m4);
	
	glColor3f(.6f, .6f, .0f);
	glPushMatrix ();
	glMultMatrixf((float *)m4);
	if (0 < geom->getDisplayList())
		geom->draw();
	glPopMatrix ();
}

void OrthoView::drawLights()
{
	SceneGraph *sg = GetWorld()->getSceneGraph();

	for (Node *node=sg->getNodes(); node; node=node->nextTraversal()) {
		if (node->isSpotLightNode() == true) {
			if (isSpotLightDisplayOn() == true)
				drawSpotLight2D((SpotLightNode *)node);
		}
		else if (node->isPointLightNode() == true) {
			if (isPointLightDisplayOn() == true) 
				drawPointLight2D((PointLightNode *)node);
		}
	}
}

static TransformNode *GetShapeTransform(ShapeNode *shapeNode)
{
	assert(shapeNode);

	if (!shapeNode)
		return NULL;

	Node	*node		= shapeNode;
	Node	*parentNode	= node->getParentNode();

	if (node->isInstanceNode() == true || node->isInlineChildNode() == true) {
		while (parentNode != NULL) {
			if (node->isInstanceNode() == true) {
				if (parentNode->isInstanceNode() == false)
					break;
			}
			if (node->isInlineNode() == true)
				break;
			node		= parentNode;
			parentNode	= node->getParentNode();
		}
	}

	TransformNode	*transform;
	
	if (parentNode) {
		if (parentNode->isTransformNode() == false) {
			CtbTreeDeleteNode(node);
			transform = new TransformNode();
			parentNode->addChildNode(transform);
			transform->moveChildNode(node);
			CtbTreeAddNode(transform, parentNode);
		}
		else
			transform = (TransformNode *)parentNode;
	}
	else {
		SceneGraph *sg = GetWorld()->getSceneGraph();
		CtbTreeDeleteNode(node);
		transform = new TransformNode();
		sg->addNode(transform);
		transform->moveChildNode(node);
		CtbTreeAddNode(transform, NULL);
	}
	assert(transform);

	return transform;
}

void OrthoView::drawSceneGraph(bool selectionMode)
{
	SceneGraph *sg = GetWorld()->getSceneGraph();
	
	if (selectionMode == false) {
	    glDisable(GL_DEPTH_TEST);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
	else {
	    glEnable(GL_DEPTH_TEST);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	glShadeModel (GL_FLAT);
	glDisable(GL_CULL_FACE);
	glDisable(GL_LIGHTING);
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	float x[2], y[2], z[2];
	getLocalExtents(x, y, z);

	if (selectionMode == false)
		drawGrid(x, y);

	if (selectionMode == false) {
		glMatrixMode( GL_PROJECTION );
		glLoadIdentity();
	}

	float zlength = (float)fabs(z[1]-z[0])*10.0f;
	glOrtho(x[0], x[1], y[0], y[1], z[0]-zlength, z[1]+zlength);

	switch (getViewMode()) {
	case ORTHO_XY_PLANE:	gluLookAt(0, 0, 0,  0, 0, -1,  0, 1, 0);	break;
	case ORTHO_YZ_PLANE:	gluLookAt(0, 0, 0,  1, 0, 0,  0, 1, 0);		break;
	case ORTHO_XZ_PLANE:	gluLookAt(0, 0, 0,  0, -1, 0,  0, 0, -1);	break;
	}

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

	if (isShapeDisplayOn() == true) {
		ShapeNode			*selectedShape		= getSelectedShapeNode();
		TransformNode		*selectedTransform	= getSelectedTransformNode();
			
		if (selectedShape != NULL && selectedTransform == NULL) {
			selectedTransform = GetShapeTransform(selectedShape);
			setSelectedTransformNode(selectedTransform);
		}

		int nShape = 0;
		for (ShapeNode *shape=sg->findShapeNode(); shape; shape=shape->nextTraversal()) {
		
			if (selectionMode == true)
				glLoadName(nShape++);
	
			glPushMatrix ();

			float	m4[4][4];
			shape->getTransformMatrix(m4);
			glMultMatrixf((float *)m4);

			if (selectedShape == shape)
				glColor3f(.9f, .9f, 0.0f);
			else if (selectedTransform != NULL && selectedTransform->isChildNode(shape) == true)
				glColor3f(.5f, .5f, 0.0f);
			else
				glColor3f(1.0f, 1.0f, 1.0f);

			GeometryNode *gnode = shape->getGeometry();
			if (gnode) {
				if (0 < gnode->getDisplayList())
					gnode->draw();
			}

			glPopMatrix();
		}
	}

	if (selectionMode == false) {
		if (isViewpointDisplayOn() == true)
			drawViewpoint2D();
		if (isSpotLightDisplayOn() == true && isPointLightDisplayOn() == true)
			drawLights();
	}

	if (selectionMode == false) {
		if (getOperationMode() == OPERATION_PRMITIVE_EDIT_TEXT) {
			glColor3f(1.0f, 1.0f, 1.0f);
			drawOutLineTextBaseLine();
		}
	}

	glFinish();

	if (selectionMode == false)
		SwapBuffers(wglGetCurrentDC());
}

typedef struct {
	OrthoView		*orthoView;
	CDC				*dc;
	unsigned int	id;
} GLFontUseOutLinesData;

static void CreateGLFontUseOutlines(GLFontUseOutLinesData *data) 
{
	OrthoView	*orthoView = data->orthoView;
	CDC			*dc = data->dc;
	unsigned int id	= data->id;

	GLYPHMETRICSFLOAT gmf[256];
	wglUseFontOutlines(dc->m_hDC, 0, 256, id, 0.0f, 1.0f, WGL_FONT_POLYGONS, gmf);
	orthoView->setGLFontOutLineID(id);

	free(data);

	orthoView->releaseMutexObject();
}

void OrthoView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: この位置に描画用のコードを追加してください
	
	GLint	viewport[4];
    wglMakeCurrent(oglHdc, oglHrc);
	glGetIntegerv(GL_VIEWPORT, viewport);

//	int size = GetDeviceCaps(pDC->m_hDC, LOGPIXELSY);

	if (viewport[2] <= 1 || viewport[3] <= 1)
		return;

	GLuint id = getGLFontID();
	if (id == 0) {
		LOGFONT lf;
		getFontInfo(&lf);
		setFont(&lf);
		pDC->SelectObject(&mFont);
		id = glGenLists(256);
		wglUseFontBitmaps(pDC->m_hDC, 0, 256, id);
		setGLFontID(id);
	}

	setCDC(pDC);

	drawSceneGraph(false);
    
	wglMakeCurrent(NULL, NULL);
}

/////////////////////////////////////////////////////////////////////////////
//	OpenGL
/////////////////////////////////////////////////////////////////////////////

static unsigned char threeto8[8] = 
{
	0, 0111>>1, 0222>>1, 0333>>1, 0444>>1, 0555>>1, 0666>>1, 0377
};

static unsigned char twoto8[4] = 
{
	0, 0x55, 0xaa, 0xff
};

static unsigned char oneto8[2] = 
{
	0, 255
};

static int defaultOverride[13] = 
{
	0, 3, 24, 27, 64, 67, 88, 173, 181, 236, 247, 164, 91
};

static PALETTEENTRY defaultPalEntry[20] = 
{
	{ 0,   0,   0,    0 },
	{ 0x80,0,   0,    0 },
	{ 0,   0x80,0,    0 },
	{ 0x80,0x80,0,    0 },
	{ 0,   0,   0x80, 0 },
	{ 0x80,0,   0x80, 0 },
	{ 0,   0x80,0x80, 0 },
	{ 0xC0,0xC0,0xC0, 0 },

	{ 192, 220, 192,  0 },
	{ 166, 202, 240,  0 },
	{ 255, 251, 240,  0 },
	{ 160, 160, 164,  0 },

	{ 0x80,0x80,0x80, 0 },
	{ 0xFF,0,   0,    0 },
	{ 0,   0xFF,0,    0 },
	{ 0xFF,0xFF,0,    0 },
	{ 0,   0,   0xFF, 0 },
	{ 0xFF,0,   0xFF, 0 },
	{ 0,   0xFF,0xFF, 0 },
	{ 0xFF,0xFF,0xFF, 0 }
};

void OrthoView::OGLSetup()
{
    PIXELFORMATDESCRIPTOR pfd;
    int         n;
//	GLfloat		fMaxObjSize, fAspect;
//	GLfloat		fNearPlane, fFarPlane;

    oglDC = new CClientDC(this);

    ASSERT(oglDC != NULL);

    if (!OGLSetupPixelFormat())
        return;

    n = ::GetPixelFormat(oglDC->GetSafeHdc());
    ::DescribePixelFormat(oglDC->GetSafeHdc(), n, sizeof(pfd), &pfd);

	OGLCreateRGBPalette();

	oglHdc = oglDC->GetSafeHdc(); 
    oglHrc = wglCreateContext(oglHdc);
    wglMakeCurrent(oglHdc, oglHrc);

	PerspectiveView *pview = CtbGetPerspectiveView();
	wglShareLists(pview->oglHrc, oglHrc);

	//GetWorld()->loadSceneGraphVisualObjects();

    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);

    wglMakeCurrent(NULL, NULL);
}

BOOL OrthoView::OGLSetupPixelFormat()
{
    static PIXELFORMATDESCRIPTOR pfd = 
	{
        sizeof(PIXELFORMATDESCRIPTOR),  // size of this pfd
        1,                              // version number
        PFD_DRAW_TO_WINDOW |            // support window
        PFD_SUPPORT_OPENGL |			// support OpenGL
        PFD_DOUBLEBUFFER,				// double buffered
        PFD_TYPE_RGBA,                  // RGBA type
        24,                             // 24-bit color depth
        0, 0, 0, 0, 0, 0,               // color bits ignored
        0,                              // no alpha buffer
        0,                              // shift bit ignored
        0,                              // no accumulation buffer
        0, 0, 0, 0,                     // accum bits ignored
        32,                             // 32-bit z-buffer
        0,                              // no stencil buffer
        0,                              // no auxiliary buffer
        PFD_MAIN_PLANE,                 // main layer
        0,                              // reserved
        0, 0, 0                         // layer masks ignored
    };
    int pixelformat;

    if ( (pixelformat = ChoosePixelFormat(oglDC->GetSafeHdc(), &pfd)) == 0 )
    {
        MessageBox("ChoosePixelFormat failed");
        return FALSE;
    }

    if (SetPixelFormat(oglDC->GetSafeHdc(), pixelformat, &pfd) == FALSE)
    {
        MessageBox("SetPixelFormat failed");
        return FALSE;
    }

    return TRUE;
}

unsigned char OrthoView::OGLComponentFromIndex(int i, UINT nbits, UINT shift)
{
    unsigned char val;

    val = (unsigned char) (i >> shift);
    switch (nbits) 
	{

    case 1:
        val &= 0x1;
        return oneto8[val];
    case 2:
        val &= 0x3;
        return twoto8[val];
    case 3:
        val &= 0x7;
        return threeto8[val];

    default:
        return 0;
    }
}


void OrthoView::OGLCreateRGBPalette()
{
    PIXELFORMATDESCRIPTOR pfd;
    LOGPALETTE *pPal;
    int n, i;
 
    n = ::GetPixelFormat(oglDC->GetSafeHdc());
    ::DescribePixelFormat(oglDC->GetSafeHdc(), n, sizeof(pfd), &pfd);

    if (pfd.dwFlags & PFD_NEED_PALETTE)
    {
        n = 1 << pfd.cColorBits;
        pPal = (PLOGPALETTE) new char[sizeof(LOGPALETTE) + n * sizeof(PALETTEENTRY)];

        ASSERT(pPal != NULL);

        pPal->palVersion = 0x300;
        pPal->palNumEntries = n;
        for (i=0; i<n; i++)
        {
            pPal->palPalEntry[i].peRed =
                    OGLComponentFromIndex(i, pfd.cRedBits, pfd.cRedShift);
            pPal->palPalEntry[i].peGreen =
                    OGLComponentFromIndex(i, pfd.cGreenBits, pfd.cGreenShift);
            pPal->palPalEntry[i].peBlue =
                    OGLComponentFromIndex(i, pfd.cBlueBits, pfd.cBlueShift);
            pPal->palPalEntry[i].peFlags = 0;
        }

        /* fix up the palette to include the default GDI palette */
        if ((pfd.cColorBits == 8)                           &&
            (pfd.cRedBits   == 3) && (pfd.cRedShift   == 0) &&
            (pfd.cGreenBits == 3) && (pfd.cGreenShift == 3) &&
            (pfd.cBlueBits  == 2) && (pfd.cBlueShift  == 6)
           )
        {
			for (i = 1 ; i <= 12 ; i++)
                pPal->palPalEntry[defaultOverride[i]] = defaultPalEntry[i];
        }

        oglPalette.CreatePalette(pPal);
        delete pPal;

        oglOldPalette = oglDC->SelectPalette(&oglPalette, FALSE);
        oglDC->RealizePalette();
    }
}

/////////////////////////////////////////////////////////////////////////////
// OrthoView 診断

#ifdef _DEBUG
void OrthoView::AssertValid() const
{
	CScrollView::AssertValid();
}

void OrthoView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////
//	ToolBar
/////////////////////////////////////////////////////

void OrthoView::enableButton(int id, BOOL bEnable)
{
	CToolBarCtrl	&tbCtrl = ((OrthoFrame *)GetParentFrame())->m_wndToolBar.GetToolBarCtrl();
//	tbCtrl.EnableButton(id, bEnable);
//	tbCtrl.Indeterminate(id, !bEnable);
}

void OrthoView::pressButton(int id, BOOL bEnable)
{
	CToolBarCtrl	&tbCtrl = ((OrthoFrame *)GetParentFrame())->m_wndToolBar.GetToolBarCtrl();
	tbCtrl.PressButton(id, bEnable);
}

BOOL OrthoView::isButtonEnabled(int id)
{
	CToolBarCtrl	&tbCtrl = ((OrthoFrame *)GetParentFrame())->m_wndToolBar.GetToolBarCtrl();
	return tbCtrl.IsButtonEnabled(id);
}

BOOL OrthoView::isButtonPressed(int id)
{
	CToolBarCtrl	&tbCtrl = ((OrthoFrame *)GetParentFrame())->m_wndToolBar.GetToolBarCtrl();
	return tbCtrl.IsButtonPressed(id);
}

void OrthoView::setToolBarButton(int pushedButton)
{
	switch (pushedButton) {
	case ID_OBJECT_PICK:
		enableButton(ID_OBJECT_PICK, TRUE);
		enableButton(ID_OBJECT_ZOOM, FALSE);
		enableButton(ID_OBJECT_MOVE, FALSE);
		enableButton(ID_OBJECT_ROTATE, FALSE);

		pressButton(ID_OBJECT_PICK, TRUE);
		pressButton(ID_OBJECT_ZOOM, FALSE);
		pressButton(ID_OBJECT_ROTATE, FALSE);
		pressButton(ID_OBJECT_MOVE, FALSE);
		break;
	case ID_OBJECT_ZOOM:
		enableButton(ID_OBJECT_PICK, FALSE);
		enableButton(ID_OBJECT_ZOOM, TRUE);
		enableButton(ID_OBJECT_MOVE, FALSE);
		enableButton(ID_OBJECT_ROTATE, FALSE);

		pressButton(ID_OBJECT_PICK, FALSE);
		pressButton(ID_OBJECT_ZOOM, TRUE);
		pressButton(ID_OBJECT_MOVE, FALSE);
		pressButton(ID_OBJECT_ROTATE, FALSE);
		break;
	case ID_OBJECT_MOVE:
		enableButton(ID_OBJECT_PICK, FALSE);
		enableButton(ID_OBJECT_ZOOM, FALSE);
		enableButton(ID_OBJECT_MOVE, TRUE);
		enableButton(ID_OBJECT_ROTATE, FALSE);

		pressButton(ID_OBJECT_PICK, FALSE);
		pressButton(ID_OBJECT_ZOOM, FALSE);
		pressButton(ID_OBJECT_MOVE, TRUE);
		pressButton(ID_OBJECT_ROTATE, FALSE);
		break;

	case ID_OBJECT_ROTATE:
		enableButton(ID_OBJECT_PICK, FALSE);
		enableButton(ID_OBJECT_ZOOM, FALSE);
		enableButton(ID_OBJECT_MOVE, FALSE);
		enableButton(ID_OBJECT_ROTATE, TRUE);

		pressButton(ID_OBJECT_PICK, FALSE);
		pressButton(ID_OBJECT_ZOOM, FALSE);
		pressButton(ID_OBJECT_MOVE, FALSE);
		pressButton(ID_OBJECT_ROTATE, TRUE);
		break;
	
	case ID_XY_VIEW:
		enableButton(ID_XY_VIEW, TRUE);
		enableButton(ID_XZ_VIEW, FALSE);
		enableButton(ID_YZ_VIEW, FALSE);

		pressButton(ID_XY_VIEW, TRUE);
		pressButton(ID_XZ_VIEW, FALSE);
		pressButton(ID_YZ_VIEW, FALSE);
		break;
	case ID_XZ_VIEW:
		enableButton(ID_XY_VIEW, FALSE);
		enableButton(ID_XZ_VIEW, TRUE);
		enableButton(ID_YZ_VIEW, FALSE);

		pressButton(ID_XY_VIEW, FALSE);
		pressButton(ID_XZ_VIEW, TRUE);
		pressButton(ID_YZ_VIEW, FALSE);
		break;
	case ID_YZ_VIEW:
		enableButton(ID_XY_VIEW, FALSE);
		enableButton(ID_XZ_VIEW, FALSE);
		enableButton(ID_YZ_VIEW, TRUE);

		pressButton(ID_XY_VIEW, FALSE);
		pressButton(ID_XZ_VIEW, FALSE);
		pressButton(ID_YZ_VIEW, TRUE);
		break;
	}
}

/////////////////////////////////////////////////////
//	StatusBar
/////////////////////////////////////////////////////

void OrthoView::setStatusBar(float x, float y, float z)
{
	CStatusBarCtrl	&sbCtrl = ((OrthoFrame *)GetParentFrame())->m_wndStatusBar.GetStatusBarCtrl();

	char string[64];

	sprintf(string, "%.2f", x);	sbCtrl.SetText(string, 0, 0);
	sprintf(string, "%.2f", y);	sbCtrl.SetText(string, 1, 0);
	sprintf(string, "%.2f", z);	sbCtrl.SetText(string, 2, 0);

	sbCtrl.UpdateWindow();
}

/////////////////////////////////////////////////////////////////////////////
// OrthoView メッセージ ハンドラ

int OrthoView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: この位置に固有の作成用コードを追加してください
	OGLSetup();
	
    wglMakeCurrent(oglHdc, oglHrc);

    glDisable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glCullFace(GL_BACK);
	glDisable(GL_CULL_FACE);

	glDisable(GL_LIGHTING);
	glShadeModel(GL_FLAT);

    wglMakeCurrent(NULL, NULL);

	mPrimitiveFloating = new PrimitiveFloating(this);
	mPrimitiveFloating->Create(this);

	return 0;
}

BOOL OrthoView::DestroyWindow() 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	mPrimitiveFloating->DestroyWindow();
	
	return CScrollView::DestroyWindow();
}

void OrthoView::OnSize(UINT nType, int cx, int cy) 
{
	CScrollView::OnSize(nType, cx, cy);
	
	// TODO: この位置にメッセージ ハンドラ用のコードを追加してください
    wglMakeCurrent(oglHdc, oglHrc);
	glViewport( 0, 0, cx, cy );
    wglMakeCurrent(NULL, NULL);
}

BOOL OrthoView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	
	return TRUE;
}

void OrthoView::OnObjectPick() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	setObjectMode(OBJECT_PICK);
	setToolBarButton(ID_OBJECT_PICK);
}

void OrthoView::OnObjectMove() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	setObjectMode(OBJECT_MOVE);
	setToolBarButton(ID_OBJECT_MOVE);
}

void OrthoView::OnObjectRotate() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	setObjectMode(OBJECT_ROTATE);
	setToolBarButton(ID_OBJECT_ROTATE);
}

void OrthoView::OnObjectZoom() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	setObjectMode(OBJECT_ZOOM);
	setToolBarButton(ID_OBJECT_ZOOM);
}

void OrthoView::OnXyView() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	setViewMode(ORTHO_XY_PLANE);
	setToolBarButton(ID_XY_VIEW);
	InvalidateRect(NULL);
	UpdateWindow();
}

void OrthoView::OnXzView() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	setViewMode(ORTHO_XZ_PLANE);
	setToolBarButton(ID_XZ_VIEW);
	InvalidateRect(NULL);
	UpdateWindow();
}

void OrthoView::OnYzView() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	setViewMode(ORTHO_YZ_PLANE);
	setToolBarButton(ID_YZ_VIEW);
	InvalidateRect(NULL);
	UpdateWindow();
}

void OrthoView::OnZoomall() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	float	offset[3];
	float	bboxCenter[3];
	float	bboxSize[3];

	SceneGraph *sg = GetWorld()->getSceneGraph();
	
	sg->getBoundingBoxCenter(bboxCenter);
	sg->getBoundingBoxSize(bboxSize);
	if (bboxSize[0] <= 0.0f && bboxSize[1] <= 0.0f && bboxSize[2] <= 0.0f)
		return;


	getOffset(offset);
	getSceneBoundingBoxCenter(bboxCenter);
	getSceneBoundingBoxSize(bboxSize);
	
	enqueue(UndoOrthoViewChangeScaleOffsetBoundingBoxNew(this, getScale(), offset, bboxCenter, bboxSize), UndoOrthoViewChangeScaleOffsetBoundingBoxFn);
	
	sg->getBoundingBoxCenter(bboxCenter);
	sg->getBoundingBoxSize(bboxSize);
	setSceneBoundingBoxCenter(bboxCenter);
	setSceneBoundingBoxSize(bboxSize);

	setOffset(0.0f, 0.0f, 0.0f);
	setScale(1.0f);
	InvalidateRect(NULL);
	UpdateWindow();
}

void OrthoView::OnRButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	ClientToScreen(&point);

	CMenu menu;
	VERIFY(menu.LoadMenu(IDR_ORTHOVIEW_POPUP));
	CMenu* pPopup = menu.GetSubMenu(0);
	ASSERT(pPopup != NULL);

	switch (getObjectMode()) {
	case OBJECT_PICK:
		pPopup->CheckMenuItem(ID_MENUITEM_PICK, MF_CHECKED);
		break;
	case OBJECT_MOVE:
		pPopup->CheckMenuItem(ID_MENUITEM_MOVE, MF_CHECKED);
		break;
	case OBJECT_ROTATE:
		pPopup->CheckMenuItem(ID_MENUITEM_ROTATE, MF_CHECKED);
		break;
	case OBJECT_ZOOM:
		pPopup->CheckMenuItem(ID_MENUITEM_ZOOM, MF_CHECKED);
		break;
	}

	switch (getViewMode()) {
	case ORTHO_XY_PLANE:
		pPopup->CheckMenuItem(ID_MENUITEM_XYPLANE, MF_CHECKED);
		break;
	case ORTHO_YZ_PLANE:
		pPopup->CheckMenuItem(ID_MENUITEM_YZPLANE, MF_CHECKED);
		break;
	case ORTHO_XZ_PLANE:
		pPopup->CheckMenuItem(ID_MENUITEM_XZPLANE, MF_CHECKED);
		break;
	}

	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);

	ScreenToClient(&point);

	CScrollView::OnRButtonDblClk(nFlags, point);
}

BOOL OrthoView::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください

	switch (wParam) {
	case ID_MENUITEM_PICK:
		setObjectMode(OBJECT_PICK);
		setToolBarButton(ID_OBJECT_PICK);
		break;
	case ID_MENUITEM_MOVE:
		setObjectMode(OBJECT_MOVE);
		setToolBarButton(ID_OBJECT_MOVE);
		break;
	case ID_MENUITEM_ROTATE:
		setObjectMode(OBJECT_ROTATE);
		setToolBarButton(ID_OBJECT_ROTATE);
		break;
	case ID_MENUITEM_ZOOM:
		setObjectMode(OBJECT_ZOOM);
		setToolBarButton(ID_OBJECT_ZOOM);
		break;
	case ID_MENUITEM_XYPLANE:
		setViewMode(ORTHO_XY_PLANE);
		setToolBarButton(ID_XY_VIEW);
		InvalidateRect(NULL);
		UpdateWindow();
		break;
	case ID_MENUITEM_YZPLANE:
		setViewMode(ORTHO_YZ_PLANE);
		setToolBarButton(ID_YZ_VIEW);
		InvalidateRect(NULL);
		UpdateWindow();
		break;
	case ID_MENUITEM_XZPLANE:
		setViewMode(ORTHO_XZ_PLANE);
		setToolBarButton(ID_XZ_VIEW);
		InvalidateRect(NULL);
		UpdateWindow();
		break;
	}

	return CScrollView::OnCommand(wParam, lParam);
}

void OrthoView::getLocalExtents(float x[2], float y[2], float z[2])
{
	SceneGraph *sg = GetWorld()->getSceneGraph();
	
	float	bboxCenter[3];
	float	bboxSize[3];

	getSceneBoundingBoxCenter(bboxCenter);
	getSceneBoundingBoxSize(bboxSize);

	float scale = getScale();

	RECT	rect;
	GetClientRect(&rect);
	float aspect = (float)rect.right / (float)rect.bottom;

	float	offset[3];
	getOffset(offset);

	switch (getViewMode()) {
	case ORTHO_XY_PLANE:
		(bboxSize[0] < bboxSize[1]) ? (bboxSize[0] = bboxSize[1]) : (bboxSize[1] = bboxSize[0]);
		x[0] = bboxCenter[0] - bboxSize[0]*aspect*scale + offset[0];
		x[1] = bboxCenter[0] + bboxSize[0]*aspect*scale + offset[0];
		y[0] = bboxCenter[1] - bboxSize[1]*scale + offset[1]; 
		y[1] = bboxCenter[1] + bboxSize[1]*scale + offset[1];
		z[0] = bboxCenter[2] - bboxSize[2]*scale + offset[2];
		z[1] = bboxCenter[2] + bboxSize[2]*scale + offset[2];
		break;
	case ORTHO_YZ_PLANE:
		(bboxSize[1] < bboxSize[2]) ? (bboxSize[1] = bboxSize[2]) : (bboxSize[2] = bboxSize[1]);
		x[0] = bboxCenter[2] - bboxSize[2]*aspect*scale + offset[2];
		x[1] = bboxCenter[2] + bboxSize[2]*aspect*scale + offset[2];
		y[0] = bboxCenter[1] - bboxSize[1]*scale + offset[1]; 
		y[1] = bboxCenter[1] + bboxSize[1]*scale + offset[1];
		z[0] = bboxCenter[0] - bboxSize[0]*scale + offset[0];
		z[1] = bboxCenter[0] + bboxSize[0]*scale + offset[0];
		break;
//	case ORTHO_XZ_PLANE:
	default:
		(bboxSize[0] < bboxSize[2]) ? (bboxSize[0] = bboxSize[2]) : (bboxSize[2] = bboxSize[0]);
		x[0] = bboxCenter[0] - bboxSize[0]*aspect*scale + offset[0];
		x[1] = bboxCenter[0] + bboxSize[0]*aspect*scale + offset[0];	
		y[0] = bboxCenter[2] - bboxSize[2]*scale + offset[2]; 
		y[1] = bboxCenter[2] + bboxSize[2]*scale + offset[2];
		z[0] = bboxCenter[1] - bboxSize[1]*scale + offset[1];
		z[1] = bboxCenter[1] + bboxSize[1]*scale + offset[1];
		break;
	}
}

void OrthoView::windowToWorld(int x, int y, float &wx, float &wy, float &wz)
{
	RECT	rect;
	GetClientRect(&rect);
	int width = rect.right;
	int height = rect.bottom;

	float localExtents[3][2];
	float localWidth[3];
	getLocalExtents(localExtents[0], localExtents[1], localExtents[2]);
	for (int n=0; n<3; n++)
		localWidth[n] = (float)fabs(localExtents[n][1] - localExtents[n][0]);

	wx = wy = wz = 0.0f;

	switch (getViewMode()) {
	case ORTHO_XY_PLANE:
		wx = localExtents[0][0] + (localWidth[0]*((float)x/(float)width));
		wy = localExtents[1][0] + (localWidth[1]*((float)(height-y)/(float)height));
		break;
	case ORTHO_YZ_PLANE:
		wy = localExtents[1][0] + (localWidth[1]*((float)(height-y)/(float)height));
		wz = localExtents[0][0] + (localWidth[0]*((float)x/(float)width));
		break;
	case ORTHO_XZ_PLANE:
		wx = localExtents[0][0] + (localWidth[0]*((float)x/(float)width));
		wz = localExtents[1][0] + (localWidth[1]*((float)(height-y)/(float)height));
		wz = -wz;
		break;
	}
}

void OrthoView::worldToWindow(float wx, float wy, float wz, long &x, long &y)
{
	float lx, ly;

	switch (getViewMode()) {
	case ORTHO_XY_PLANE:
		lx = wx;
		ly = wy;
		break;
	case ORTHO_YZ_PLANE:
		lx = wz;
		ly = wy;
		break;
	case ORTHO_XZ_PLANE:
		lx = wx;
		ly = wz;
		break;
	}

	float localExtents[3][2];
	float localWidth[3];
	getLocalExtents(localExtents[0], localExtents[1], localExtents[2]);
	for (int n=0; n<3; n++)
		localWidth[n] = (float)fabs(localExtents[n][1] - localExtents[n][0]);

	RECT	rect;
	int		winWidth;
	int		winHeight;
	GetClientRect(&rect);
	winWidth	= rect.right;
	winHeight	= rect.bottom;

	x = (long)((float)winWidth  * ((lx - localExtents[0][0])/localWidth[0]));
	y = (long)((float)winHeight * ((ly - localExtents[1][0])/localWidth[1]));
	y = winHeight - y;
}

void OrthoView::worldToWindow(float wx, float wy, float wz, int &x, int &y)
{
	int longx = x;
	int longy = y;
	worldToWindow(wx, wy, wz, longx, longy);
	x = (int)longx;
	y = (int)longy;
}

float OrthoView::windowToWorld(int size)
{
	RECT	rect;
	GetClientRect(&rect);
	int width = rect.right;
	int height = rect.bottom;

	float localExtents[3][2];
	float localWidth;
	getLocalExtents(localExtents[0], localExtents[1], localExtents[2]);
	localWidth = (float)fabs(localExtents[0][1] - localExtents[0][0]);

	return (localWidth*((float)size/(float)width));
}

int OrthoView::worldToWindow(float size)
{
	RECT	rect;
	GetClientRect(&rect);
	int width = rect.right;
	int height = rect.bottom;

	float localExtents[3][2];
	float localWidth;
	getLocalExtents(localExtents[0], localExtents[1], localExtents[2]);
	localWidth = (float)fabs(localExtents[0][1] - localExtents[0][0]);

	return (int)((float)width*(size/localWidth));
}

bool OrthoView::get2DLineIntersectionPoint(float &dec1, float &offset1, float &dec2, float &offset2, float pos[2])
{
	if (dec1 == dec2)
		return false;

	pos[0] = (offset2 - offset1) / (dec1 - dec2);
	pos[1] = dec1 * pos[0] + offset1;

	return true;
}

bool OrthoView::is2DPointOnLine(float linePos1[3], float linePos2[3], float pos[2])
{
	float lineDec, lineOffset;

	get2DLineParameter(linePos1, linePos2, lineDec, lineOffset);

#ifdef CHECK_YPOS
	float y = lineDec * pos[0] + lineOffset;
	if (pos[1] != y)
		return false;
#endif 

	SFVec3f vector1, vector2;

	vector1.setValue(linePos2);
	vector1.sub(linePos1);

	vector2.setValue(pos);
	vector2.sub(linePos1);

	float cross = (vector1.getX() * vector2.getX()) + (vector1.getY() * vector2.getY());
	if (cross < 0.0f)
		return false;

	float dis1 = vector1.getScalar();
	float dis2 = vector2.getScalar();
	float scale = dis2 / dis1;
	
	if (scale <= 0.0f || 1.0f <= scale)
		return false;

	return true;
}

void OrthoView::get2DPoint(float pos[3], float &x, float &y)
{
	switch (getViewMode()) {
	case ORTHO_XY_PLANE:
		x = pos[X];
		y = pos[Y];
		break;
	case ORTHO_YZ_PLANE:
		x = pos[Z];
		y = pos[Y];
		break;
	case ORTHO_XZ_PLANE:	
		x = pos[X];
		y = pos[Z];
		break;
	}
}

bool OrthoView::is2DLineParallelOnYAxis(float pos1[3], float pos2[3])
{
	float x1, y1;
	float x2, y2;

	get2DPoint(pos1, x1, y1);
	get2DPoint(pos2, x2, y2);
	
	if (x1 == x2)
		return true;

	return false;
}

void OrthoView::get2DLineParameter(float pos1[3], float pos2[3], float &dec, float &offset)
{
	float x1, y1, x2, y2;

	get2DPoint(pos1, x1, y1);
	get2DPoint(pos2, x2, y2);

	if (x1 != x2) {
		dec = (y2 - y1) / (x2 - x1);
		offset = y1 - (x1 * dec);
	} else {
		dec = 0.0f;
		offset = 0.0f;
	}
}

static void swap(float &value1, float &value2)
{
	float	tmp;
	tmp = value1;
	value1 = value2;
	value2 = tmp;
}

bool OrthoView::check2DLinesCross(float pos1Start[3], float pos1End[3], float pos2Start[3], float pos2End[3])
{
	float	line1Dec, line1Offset;
	float	line2Dec, line2Offset;
	float	yAxisX, x1, y1, x2, y2, tmp;

	if (is2DLineParallelOnYAxis(pos1Start, pos1End) == true) {
		get2DPoint(pos1Start,	yAxisX,	tmp);
		get2DPoint(pos2Start,	x1,		y1);
		get2DPoint(pos2End,		x2,		y2);
		if (x2 < x1)
			swap(x1, x2);
		if (x1 < yAxisX && yAxisX < x2)
			return true;
		return false;
	}

	if (is2DLineParallelOnYAxis(pos2Start, pos2End) == true) {
		get2DPoint(pos2Start,	yAxisX,	tmp);
		get2DPoint(pos1Start,	x1,		y1);
		get2DPoint(pos1End,		x2,		y2);
		if (x2 < x1)
			swap(x1, x2);
		if (x1 < yAxisX && yAxisX < x2)
			return true;
		return false;
	}

	get2DLineParameter(pos1Start, pos1End, line1Dec, line1Offset);
	get2DLineParameter(pos2Start, pos2End, line2Dec, line2Offset);

	float	intersectionPos[2];

	if (get2DLineIntersectionPoint(line1Dec, line1Offset, line2Dec, line2Offset, intersectionPos) == true) {
		if (is2DPointOnLine(pos2Start, pos2End, intersectionPos) == true) {

			SFVec3f vector1, vector2;

			vector1.setValue(pos1End);
			vector1.sub(pos1Start);

			vector2.setValue(intersectionPos);
			vector2.sub(pos1Start);

			float cross = (vector1.getX() * vector2.getX()) + (vector1.getY() * vector2.getY());
			if (cross < 0.0f)
				return false;

			float dis1 = vector1.getScalar();
			float dis2 = vector2.getScalar();
			float scale = dis2 / dis1;
	
			if (1.0f < scale)
				return false;

			return true;
		}
	}

	return false;
}

bool OrthoView::polygonEditCheckCrossLine(IndexedLineSetNode *lineSet, float x, float y, float z)
{
	CoordinateNode	*coord = lineSet->getCoordinateNodes();
	int				nCoordPoints = coord->getNPoints();

	if (nCoordPoints < 2)
		return true;

	// remove drag point
	float 	dragPoint[3];
	coord->getPoint(nCoordPoints -1, dragPoint);
	coord->removeLastPoint();
	nCoordPoints--;

	float	addPos[3];
	addPos[X] = x;
	addPos[Y] = y;
	addPos[Z] = z;

	SFVec3f	addPosVec3f(addPos);;

	float	lastPos[3];
	coord->getPoint(nCoordPoints - 1, lastPos);

	float	pos[2][3];
	
	int		n;
	bool	isIntersected = false;

	for (n=1; n<(nCoordPoints - 1); n++) {
		coord->getPoint(n, pos[0]);
		if (addPosVec3f.equals(pos[0]) == true)
			isIntersected = true;
	}

	for (n=0; n<(nCoordPoints - 1) - 1; n++) {
		coord->getPoint(n,	 pos[0]);
		coord->getPoint(n+1, pos[1]);
		if (check2DLinesCross(lastPos, addPos, pos[0], pos[1]) == true) {
			isIntersected = true;
			break;
		}
	}

	// add drag point
	coord->addPoint(dragPoint);

	return !isIntersected;
}

void OrthoView::undoPolygonEdit()
{
	wglMakeCurrent(oglHdc, oglHrc);

	TransformNode *trans = getEditPrimitiveTransformNode();
	IndexedLineSetNode *lineSet = (IndexedLineSetNode *)getEditPrimitiveGeometryNode();

	CoordinateNode *coord = lineSet->getCoordinateNodes();
	if (coord != NULL) {
		int nPoints = coord->getNPoints();
		if (2 <= nPoints)
			coord->removePoint(nPoints-2);
		else 
			return;
	}

	lineSet->clearCoordIndex();
	for (int n=0; n<coord->getNPoints(); n++) 
		lineSet->addCoordIndex(n);
	lineSet->addCoordIndex(-1);

	wglMakeCurrent(oglHdc, oglHrc);
	lineSet->recomputeDisplayList();
	wglMakeCurrent(NULL, NULL);

	InvalidateRect(NULL);
	UpdateWindow();
}

void OrthoView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	
	if (getOperationMode() == OPERATION_PRMITIVE_EDIT_POLYGON) {
		
		float x, y, z;
		windowToWorld(point.x, point.y, x, y, z);

		if (isSnapOn()) {
			switch (getViewMode()) {
			case ORTHO_XY_PLANE:
				transformToSnapPositoin(x, y);
				break;
			case ORTHO_YZ_PLANE:
				transformToSnapPositoin(z, y);
				break;
			case ORTHO_XZ_PLANE:	
				transformToSnapPositoin(x, z);
				break;
			}
		}

		IndexedLineSetNode *lineSet = (IndexedLineSetNode *)getEditPrimitiveGeometryNode();
		CoordinateNode *coord = lineSet->getCoordinateNodes();

		if (coord != NULL) {
			if (1 < coord->getNPoints()) {
				float firstPoint[3];
				coord->getPoint(0, firstPoint);
				if (firstPoint[X] == x && firstPoint[Y] == y && firstPoint[Z] == z) {
					SendMessage(WM_KEYDOWN, VK_RETURN, 0); 
					return;
				}
			}
		}

		if (coord == NULL) {
			coord = new CoordinateNode();
			lineSet->addChildNode(coord);
			coord->addPoint(x, y, z); // Drag point
		}
		
		if (polygonEditCheckCrossLine(lineSet, x, y, z) == false) {
			MessageBeep(0);
			return;
		}

		coord->removeLastPoint();
		coord->addPoint(x, y, z);
		coord->addPoint(x, y, z); // Drag point

		lineSet->clearCoordIndex();
		for (int n=0; n<coord->getNPoints(); n++) 
			lineSet->addCoordIndex(n);
		lineSet->addCoordIndex(-1);

		wglMakeCurrent(oglHdc, oglHrc);
		lineSet->recomputeDisplayList();
	    wglMakeCurrent(NULL, NULL);

		InvalidateRect(NULL);
		UpdateWindow();
		return;
	}
	
	if (getOperationMode() != OPERATION_NONE)
		return;

	setOperationMode(OPERATION_LEFT_DRAG);
	mouseStart[0] = mouse[0] = point.x;
	mouseStart[1] = mouse[1] = point.y;
	dragStart = true;

	SceneGraph *sg = GetWorld()->getSceneGraph();

	ShapeNode *selectedShape  = sg->getSelectedShapeNode();
	if (sg->hasNode(selectedShape) == false)
		sg->setSelectedShapeNode(NULL);

	switch (getObjectMode()) {
	case OBJECT_PICK:
		{
			ShapeNode *pickedShape = pickShapeNode(point.x, point.y);
			if (pickedShape != NULL) {
				setSelectedShapeNode(pickedShape);
				setSelectedTransformNode(GetShapeTransform(pickedShape));
			}
			else {
				setSelectedShapeNode(NULL);
				setSelectedTransformNode(NULL);
			}
			InvalidateRect(NULL);
			UpdateWindow();
			CtbUpdatePerspectiveView();
		}
		break;
	case OBJECT_MOVE:
		{
			SetCursor(AfxGetApp()->LoadCursor(IDC_OBJECT_TRANSLATE));
		}
		break;
	case OBJECT_ROTATE:
		{
			if (sg->getSelectedShapeNode())
				SetCursor(AfxGetApp()->LoadCursor(IDC_OBJECT_ROTATE));
		}
		break;
	case OBJECT_ZOOM:
		{
			if (sg->getSelectedShapeNode())
				SetCursor(AfxGetApp()->LoadCursor(IDC_OBJECT_SCALE));
		}
		break;
	}
	
	SetCapture();

	CScrollView::OnLButtonDown(nFlags, point);
}

void OrthoView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	
	if (getOperationMode() == OPERATION_PRMITIVE_EDIT_TEXT )
		return;
	if (getOperationMode() == OPERATION_PRMITIVE_EDIT_POLYGON)
		return;

	switch (getOperationMode()) {
	case OPERATION_LEFT_DRAG:
		switch (getObjectMode()) {
		case OBJECT_MOVE:
			{
				ShapeNode *selectedShape = getSelectedShapeNode();
				if (selectedShape == NULL) {
					float offset[3];
					getStartOffset(offset);
					enqueue(UndoOrthoViewChangeOffsetNew(this, offset), UndoOrthoViewChangeOffsetFn);
				}
				else {
					TransformNode *tansform = getSelectedTransformNode();
					float translation[3];
					getStartTransformTranslation(translation);
					enqueue(UndoOrthoViewChangeTransformTranslationNew(tansform, translation), UndoOrthoViewChangeTransformTranslationFn);
				}
			}
			break;
		case OBJECT_ROTATE:
			{
				ShapeNode *selectedShape = getSelectedShapeNode();
				if (selectedShape) {
					TransformNode *tansform = getSelectedTransformNode();
					float rotation[4];
					getStartTransformRotation(rotation);
					enqueue(UndoOrthoViewChangeTransformRotationNew(tansform, rotation), UndoOrthoViewChangeTransformRotationFn);
				}
			}
			break;
		case OBJECT_ZOOM:
			{
				ShapeNode *selectedShape = getSelectedShapeNode();
				if (selectedShape != NULL) { 
					TransformNode *transform = getSelectedTransformNode();
					float scale[3];
					getStartTransformScale(scale);
					enqueue(UndoOrthoViewChangeTransformScaleNew(transform, scale), UndoOrthoViewChangeTransformScaleFn);
					transform->initialize();
					break;
				}

				if (point.x == mouseStart[0] && point.y == mouseStart[1])
					break;

				float	offset[3];
				getOffset(offset);
				enqueue(UndoOrthoViewChangeScaleOffsetNew(this, getScale(), offset), UndoOrthoViewChangeScaleOffsetFn);

				int centerx = mouseStart[0] + (point.x - mouseStart[0])/2;
				int centery = mouseStart[1] + (point.y - mouseStart[1])/2;
				float xpos, ypos, zpos;
				windowToWorld(centerx, centery, xpos, ypos, zpos);

				switch (getViewMode()) {
				case ORTHO_XY_PLANE:
					offset[0] = xpos;
					offset[1] = ypos;
					break;
				case ORTHO_YZ_PLANE:
					offset[2] = zpos;
					offset[1] = ypos;
					break;
				case ORTHO_XZ_PLANE:
					offset[0] = xpos;
					offset[2] = zpos;
					break;
				}
				setOffset(offset);

				float x0, y0, z0, x1, y1, z1;
				windowToWorld(mouseStart[0], mouseStart[1], x0, y0, z0);
				windowToWorld(point.x, point.y, x1, y1, z1);
				float width, height;
				switch (getViewMode()) {
				case ORTHO_XY_PLANE:
					width = (float)fabs(x1 - x0);
					height = (float)fabs(y1 - y0);
					break;
				case ORTHO_YZ_PLANE:
					width = (float)fabs(z1 - z0);
					height = (float)fabs(y1 - y0);
					break;
				case ORTHO_XZ_PLANE:
					width = (float)fabs(x1 - x0);
					height = (float)fabs(z1 - z0);
					break;
				}
				float x[2], y[2], z[2];
				getLocalExtents(x, y, z);
				float scale = width / ((float)fabs(x[1] - x[0]) / getScale());
				setScale(scale);
				InvalidateRect(NULL);
				UpdateWindow();
			}
			break;
		}
		break;
	}

	setOperationMode(OPERATION_NONE);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	ReleaseCapture();


	CScrollView::OnLButtonUp(nFlags, point);
}

void OrthoView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	if (getOperationMode() == OPERATION_PRMITIVE_EDIT_POLYGON) {
		SendMessage(WM_KEYDOWN, VK_ESCAPE, 0); 
	}

	if (getOperationMode() != OPERATION_NONE)
		return;

	SceneGraph *sg = GetWorld()->getSceneGraph();

	ShapeNode *selectedShape  = sg->getSelectedShapeNode();
	if (sg->hasNode(selectedShape) == false)
		sg->setSelectedShapeNode(NULL);

	setOperationMode(OPERATION_RIGHT_DRAG);
	mouseStart[0] = mouse[0] = point.x;
	mouseStart[1] = mouse[1] = point.y;
	dragStart = true;

	switch (getObjectMode()) {
	case OBJECT_ZOOM:
		SetCursor(AfxGetApp()->LoadCursor(IDC_ZOOM));
		break;
	}

	SetCapture();
	
	CScrollView::OnRButtonDown(nFlags, point);
}

void OrthoView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください

	if (getOperationMode() == OPERATION_PRMITIVE_EDIT_TEXT)
		return;
	if (getOperationMode() == OPERATION_PRMITIVE_EDIT_POLYGON)
		return;

	switch (getOperationMode()) {
	case OPERATION_RIGHT_DRAG:
		switch (getObjectMode()) {
		case OBJECT_ZOOM:
			enqueue(UndoOrthoViewChangeScaleNew(this, getStartScale()), UndoOrthoViewChangeScaleFn);
			break;
		}
		break;
	}

	setOperationMode(OPERATION_NONE);
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	ReleaseCapture();

	CScrollView::OnRButtonUp(nFlags, point);
}

void OrthoView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	switch (getObjectMode()) {
	case OBJECT_PICK:
		{
			ShapeNode *shape = pickShapeNode(point.x, point.y);
			SceneGraph *sg = GetWorld()->getSceneGraph();
			sg->setSelectedShapeNode(shape);
			if (shape) {
				CtbModuleFloatingShowWindow(SW_HIDE);
				CtbPrimitiveFloatingShowWindow(SW_HIDE);
				
				if (shape->isInstanceNode() == true)
					shape = (ShapeNode *)shape->getReferenceNode();

				AppearanceNode *appearance = shape->getAppearanceNodes();
				if (appearance == NULL) {
					appearance = new AppearanceNode();
					shape->addChildNode(appearance);
					CtbTreeAddNode(appearance, shape);
				}
				
				MaterialNode *material = appearance->getMaterialNodes();
				if (material == NULL) {
					material = new MaterialNode();
					appearance->addChildNode(material);
					CtbTreeAddNode(material, appearance);
				}

				DialogObjectAppearance dialog(this);
				dialog.setAppearanceNode(appearance);

//				PerspectiveView	*perspectiveView = CtbGetPerspectiveView();
//				perspectiveView->SetTimer(1, 200, NULL);

				if (dialog.DoModal() == IDOK) {
					//sg->initialize();
					//setSelectedShapeNode(NULL);
					//setSelectedTransformNode(NULL);

				}

				InvalidateRect(NULL);
				UpdateWindow();
				CtbUpdatePerspectiveView();

//				perspectiveView->KillTimer(1);

				CtbModuleFloatingShowWindow(SW_SHOW);
				CtbPrimitiveFloatingShowWindow(SW_SHOW);
			}
		}
		break;
	}

	CScrollView::OnLButtonDblClk(nFlags, point);
}

void OrthoView::transformToSnapPositoin(float &localx, float &localy)
{
	float gridSize = getGridSize();
	float halfGridSize = gridSize/2.0f;

	float offsetx = (float)fmod(localx, gridSize);
	if (halfGridSize < (float)fabs(offsetx)) {
		if (0.0f < offsetx)
			offsetx = -(gridSize - offsetx);
		else
			offsetx = -(-gridSize - offsetx);
	}
	localx -= offsetx;

	float offsety = (float)fmod(localy, gridSize);
	if (halfGridSize < (float)fabs(offsety)) {
		if (0.0f < offsety)
			offsety = -(gridSize - offsety);
		else
			offsety = -(-gridSize - offsety);
	}
	localy -= offsety;
}

void OrthoView::transformToSnapdAngle(float &eulerAngle)
{
	float gridAngle = getGridAngle();
	float halfGridAngle = gridAngle/2.0f;
	float offset = (float)fmod(eulerAngle, gridAngle);
	if (halfGridAngle < (float)fabs(offset)) {
		if (0.0f < offset)
			offset = -(gridAngle - offset);
		else
			offset = -(-gridAngle - offset);
	}
	eulerAngle -= offset;
}

void OrthoView::transformToSnapMousePositoin(int &mousex, int &mousey)
{
	float localx, localy, localz;
	windowToWorld(mousex, mousey, localx, localy, localz);

	float newLocalx = localx;
	float newLocaly = localy;
	float newLocalz = localz;

	float localExtents[3][2];
	float localWidth[3];
	getLocalExtents(localExtents[0], localExtents[1], localExtents[2]);
	for (int n=0; n<3; n++)
		localWidth[n] = (float)fabs(localExtents[n][1] - localExtents[n][0]);

	RECT	rect;
	int		winWidth;
	int		winHeight;
	GetClientRect(&rect);
	winWidth	= rect.right;
	winHeight	= rect.bottom;

	float offsetx = newLocalx - localx;
	float offsety = newLocaly - localy;

	int mouseOffsetx = (int)((float)winWidth * (offsetx/localWidth[0]));
	mousex -= mouseOffsetx;

	int mouseOffsety = (int)((float)winHeight * (offsety/localWidth[1]));
	mousey -= mouseOffsety;
}

void OrthoView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	static int mouseOffsetx = 0;
	static int mouseOffsety = 0;

#if MOUSE_CURSOR_SNAP_ON
	point.x += mouseOffsetx;
	point.y += mouseOffsety;
#endif

	float lx, ly, lz;

	windowToWorld(point.x, point.y, lx, ly, lz);

	float localExtents[3][2];
	getLocalExtents(localExtents[0], localExtents[1], localExtents[2]);

	if (isSnapOn() && getOperationMode() != OPERATION_RIGHT_DRAG && getObjectMode() != OBJECT_ZOOM && getObjectMode() != OBJECT_MOVE && getObjectMode() != OBJECT_ROTATE) {
		switch (getViewMode()) {
		case ORTHO_XY_PLANE:
			transformToSnapPositoin(lx, ly);
			break;
		case ORTHO_YZ_PLANE:
			transformToSnapPositoin(lz, ly);
			break;
		case ORTHO_XZ_PLANE:	
			transformToSnapPositoin(lx, lz);
			break;
		}
		worldToWindow(lx, ly, lz, point.x, point.y);
#if MOUSE_CURSOR_SNAP_ON
		ClientToScreen(&point);
		SetCursorPos(point.x, point.y);
		ScreenToClient(&point);
#endif
	}

	setStatusBar(lx, ly, lz);

	if (getOperationMode() == OPERATION_PRMITIVE_EDIT_POLYGON) {
		
		IndexedLineSetNode *lineSet = (IndexedLineSetNode *)getEditPrimitiveGeometryNode();
		CoordinateNode *coord = lineSet->getCoordinateNodes();
		if (coord == NULL) 
			return;

		if (isSnapOn()) {
			switch (getViewMode()) {
			case ORTHO_XY_PLANE:
				transformToSnapPositoin(lx, ly);
				break;
			case ORTHO_YZ_PLANE:
				transformToSnapPositoin(lz, ly);
				break;
			case ORTHO_XZ_PLANE:	
				transformToSnapPositoin(lx, lz);
				break;
			}
		}

		coord->setPoint(coord->getNPoints()-1, lx, ly, lz);

		wglMakeCurrent(oglHdc, oglHrc);
		lineSet->recomputeDisplayList();
	    wglMakeCurrent(NULL, NULL);

		InvalidateRect(NULL);
		UpdateWindow();
		return;
	}


	float localWidth[3];
	for (int n=0; n<3; n++)
		localWidth[n] = (float)fabs(localExtents[n][1] - localExtents[n][0]);

	RECT	rect;
	GetClientRect(&rect);
	int		winWidth = rect.right;
	int		winHeight = rect.bottom;

	switch (getOperationMode()) {
	case OPERATION_LEFT_DRAG:
		switch (getObjectMode()) {
		case OBJECT_MOVE:
			{
				ShapeNode		*selectedShape = getSelectedShapeNode();
				TransformNode	*transform = getSelectedTransformNode();

				if (dragStart == true) {
					if (transform) {
						float startTranslation[3];
						transform->getTranslation(startTranslation);
						setStartTransformTranslation(startTranslation);
					}
	
					float offset[3];
					getOffset(offset);
					setStartOffset(offset);

					dragStart = false;
				}

				float xoffset;
				float yoffset;

				if (selectedShape) {
					xoffset = ((float)(point.x - mouseStart[0])/(float)winWidth)*localWidth[0];
					yoffset = ((float)(point.y - mouseStart[1])/(float)winHeight)*localWidth[1];

					if (isSnapOn())
						transformToSnapPositoin(xoffset, yoffset);

					float	offset[3];
					switch (getViewMode()) {
					case ORTHO_XY_PLANE:
						offset[0] = xoffset;
						offset[1] = -yoffset;
						offset[2] = 0.0f;
						break;
					case ORTHO_YZ_PLANE:
						offset[2] = xoffset;
						offset[1] = -yoffset;
						offset[0] = 0.0f;
						break;
					case ORTHO_XZ_PLANE:	
						offset[0] = xoffset;
						offset[2] = yoffset;
						offset[1] = 0.0f;
						break;
					}

					Node *parentNode = transform->getParentNode();
					if (parentNode) {
						SFMatrix matrix;
						parentNode->getTransformMatrix(&matrix);
						SFRotation rotation(&matrix);
						rotation.invert();
						rotation.multi(offset);
					}

					float translation[3];
					getStartTransformTranslation(translation);

					translation[0] += offset[0];
					translation[1] += offset[1];
					translation[2] += offset[2];

					transform->setTranslation(translation);
					CtbUpdatePerspectiveView();
				}
				else {
					xoffset = ((float)(point.x - mouse[0])/(float)winWidth)*localWidth[0];
					yoffset = ((float)(point.y - mouse[1])/(float)winHeight)*localWidth[1];

					float offset[3];
					getOffset(offset);
					switch (getViewMode()) {
					case ORTHO_XY_PLANE:
						offset[0] -= xoffset;
						offset[1] += yoffset;
						break;
					case ORTHO_YZ_PLANE:
						offset[2] -= xoffset;
						offset[1] += yoffset;
						break;
					case ORTHO_XZ_PLANE:	
						offset[0] -= xoffset;
						offset[2] += yoffset;
						break;
					}
					setOffset(offset);
				}

				mouse[0] = point.x;
				mouse[1] = point.y;
				InvalidateRect(NULL);
				UpdateWindow();
			}
			break;
		case OBJECT_ROTATE:
			{
				ShapeNode		*selectedShape = getSelectedShapeNode();
				TransformNode	*transform = getSelectedTransformNode();

				SFRotation	startRotation;

				if (dragStart == true) {
					if (transform) {
						float rotation[4];
						transform->getRotation(rotation);
						startRotation.setValue(rotation);
						setStartTransformRotation(rotation);
					}
					dragStart = false;
				}
				else {
					float	rotation[4];
					getStartTransformRotation(rotation);
					startRotation.setValue(rotation);
				}

				float xoffset;
				float yoffset;

				if (selectedShape) {
					xoffset = ((float)(point.x - mouseStart[0])/(float)winWidth)*180.0f*2.0f;
					yoffset = ((float)(point.y - mouseStart[1])/(float)winHeight)*180.0f*2.0f;

					if (isSnapOn()) {
						transformToSnapdAngle(xoffset);
						transformToSnapdAngle(yoffset);
					}

					xoffset = xoffset / 180.0f * 3.14159f;
					yoffset = yoffset / 180.0f * 3.14159f;

					float direction[3];
					switch (getViewMode()) {
					case ORTHO_XY_PLANE:
						direction[0] = 0.0f;
						direction[1] = 0.0f;
						direction[2] = -1.0f;
						break;
					case ORTHO_YZ_PLANE:
						direction[0] = 1.0f;
						direction[1] = 0.0f;
						direction[2] = 0.0f;
						break;
					case ORTHO_XZ_PLANE:	
						direction[0] = 0.0f;
						direction[1] = -1.0f;
						direction[2] = 0.0f;
						break;
					}

					Node *parentNode = transform->getParentNode();
					if (parentNode) {
						SFMatrix matrix;
						parentNode->getTransformMatrix(&matrix);
						SFRotation parantNodeRotation(&matrix);
						parantNodeRotation.invert();
						parantNodeRotation.multi(direction);
					}
					
					SFRotation rotation(direction[0], direction[1], direction[2], xoffset);

					switch (getViewMode()) {
					case ORTHO_XY_PLANE:
						direction[0] = 1.0f;
						direction[1] = 0.0f;
						direction[2] = 0.0f;
						break;
					case ORTHO_YZ_PLANE:
						direction[0] = 0.0f;
						direction[1] = 0.0f;
						direction[2] = 1.0f;
						break;
					case ORTHO_XZ_PLANE:	
						direction[0] = 1.0f;
						direction[1] = 0.0f;
						direction[2] = 0.0f;
						break;
					}

					parentNode = transform->getParentNode();
					if (parentNode) {
						SFMatrix matrix;
						parentNode->getTransformMatrix(&matrix);
						SFRotation parantNodeRotation(&matrix);
						parantNodeRotation.invert();
						parantNodeRotation.multi(direction);
					}
					
					SFRotation rotation2(direction[0], direction[1], direction[2], yoffset);

					rotation.add(&rotation2);
					rotation.add(&startRotation);

					float value[4];
					rotation.getValue(value);
					transform->setRotation(value);

					InvalidateRect(NULL);
					UpdateWindow();
					CtbUpdatePerspectiveView();
				}
			}
			break;
		case OBJECT_ZOOM:
			{
				ShapeNode		*selectedShape = getSelectedShapeNode();
				TransformNode	*transform = getSelectedTransformNode();

				float		startScale[3];

				if (dragStart == true) {
					if (transform) {
						transform->getScale(startScale);
						setStartTransformScale(startScale);
					}

					float offset[3];
					getOffset(offset);
					setStartOffset(offset);

					if (selectedShape)
						dragStart = false;
				}
				else 
					getStartTransformScale(startScale);

				if (selectedShape) {
					float xoffset = ((float)(point.x - mouseStart[0])/(float)winWidth)*localWidth[0];
					float yoffset = ((float)(point.y - mouseStart[1])/(float)winHeight)*localWidth[1];
					
					if (isSnapOn())
						transformToSnapPositoin(xoffset, yoffset);
					
					if (xoffset == 0.0f && yoffset == 0.0f)
						break;

					float bboxSize[3];
					transform->getBoundingBoxSize(bboxSize);
					getStartTransformScale(startScale);
					bboxSize[0] *= 2.0f;
					bboxSize[1] *= 2.0f;
					bboxSize[2] *= 2.0f;

					float xscale = 1.0f;
					float yscale = 1.0f;

					switch (getViewMode()) {
					case ORTHO_XY_PLANE:
						xscale = (bboxSize[0] + xoffset)/ bboxSize[0];
						yscale = (bboxSize[1] + yoffset)/ bboxSize[1];
						break;
					case ORTHO_YZ_PLANE:
						xscale = (bboxSize[2] + xoffset)/ bboxSize[2];
						yscale = (bboxSize[1] + yoffset)/ bboxSize[1];
						break;
					case ORTHO_XZ_PLANE:	
						xscale = (bboxSize[0] + xoffset)/ bboxSize[0];
						yscale = (bboxSize[2] + yoffset)/ bboxSize[2];
						break;
					}

					if (xscale <= 0.0f) {
						if (isSnapOn()) {
							switch (getViewMode()) {
							case ORTHO_XY_PLANE:
								xscale = getGridSize() / bboxSize[0];
								break;
							case ORTHO_YZ_PLANE:
								xscale = getGridSize() / bboxSize[2];
								break;
							case ORTHO_XZ_PLANE:	
								xscale = getGridSize() / bboxSize[0];
								break;
							}
						}
						else 
							xscale = 0.01f;
					}

					if (yscale <= 0.0f) {
						if (isSnapOn()) {
							switch (getViewMode()) {
							case ORTHO_XY_PLANE:
								yscale = getGridSize() / bboxSize[1];
								break;
							case ORTHO_YZ_PLANE:
								yscale = getGridSize() / bboxSize[1];
								break;
							case ORTHO_XZ_PLANE:	
								yscale = getGridSize() / bboxSize[2];
								break;
							}
						} else 
							yscale = 0.01f;
					}

					float scale[3];
					switch (getViewMode()) {
					case ORTHO_XY_PLANE:
						scale[0] = xscale;
						scale[1] = yscale;
						scale[2] = 1.0f;
						break;
					case ORTHO_YZ_PLANE:
						scale[2] = xscale;
						scale[1] = yscale;
						scale[0] = 1.0f;
						break;
					case ORTHO_XZ_PLANE:	
						scale[0] = xscale;
						scale[2] = yscale;
						scale[1] = 1.0f;
						break;
					}

					SFMatrix matrix;
					transform->setScale(1.0f, 1.0f, 1.0f);
					transform->getTransformMatrix(&matrix);
					SFRotation rotation(&matrix);
					rotation.invert();
					rotation.multi(scale);

					float transScale[3];
					getStartTransformScale(transScale);
					for (int n=0; n<3; n++) {
						if (scale[n] < 0.0f)
							scale[n] = -scale[n];
						transScale[n] *= scale[n];
					}

					transform->setScale(transScale);

					InvalidateRect(NULL);
					UpdateWindow();
					CtbUpdatePerspectiveView();
				}
				else {
					static	CRect rect;
					SIZE	size;
					size.cx = 1; size.cy = 1;
					CRect	oldRect = rect;
					int xmin = min(mouseStart[0], point.x);
					int xmax = max(mouseStart[0], point.x);
					int ymin = min(mouseStart[1], point.y);
					int ymax = max(mouseStart[1], point.y);
					rect.SetRect(xmin, ymin, xmax, ymax);
					CDC *pDC = GetDC();
					if (dragStart == false) {
						pDC->DrawDragRect(&rect, size, &oldRect, size);
					}
					else {
						pDC->DrawDragRect(&rect, size, NULL, size);
						dragStart = false;
					}
					ReleaseDC(pDC);
				}
			}
			break;
		}
		break;
	case OPERATION_RIGHT_DRAG:
		switch (getObjectMode()) {
		case OBJECT_ZOOM:
			if (dragStart == true) {
				setStartScale(getScale());
				dragStart = false;
			}
			float newScale = getStartScale() * (float)((winHeight/2) - (point.y - mouseStart[1]))/(float)(winHeight/2);
			setScale(newScale);
			InvalidateRect(NULL);
			UpdateWindow();
			break;
		}
		break;
	}
	
	CScrollView::OnMouseMove(nFlags, point);
}


void OrthoView::OnUndo() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	if (0 < getNQueues()) {
		undo();
		InvalidateRect(NULL);
		UpdateWindow();
		CtbUpdatePerspectiveView();
	}
	else
		MessageBeep(0);
}

void OrthoView::OnSnap() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	setSnapOn(isSnapOn() ^ true);		
	pressButton(ID_SNAP, isSnapOn() ? TRUE : FALSE);
	InvalidateRect(NULL);
	UpdateWindow();
}

void OrthoView::OnGrid() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	setGridDisplayOn(isGridDisplayOn() ^ true);		
	pressButton(ID_GRID, isGridDisplayOn() ? TRUE : FALSE);
	InvalidateRect(NULL);
	UpdateWindow();
}


void OrthoView::OnConfig() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	DialogOrthviewConfig dialog(this);
	dialog.setAxisDisplayOn(isAxisDisplayOn());
	dialog.setGridDisplayOn(isGridDisplayOn());
	dialog.setSnapOn(isSnapOn());
	dialog.setSpotLightDisplayOn(isSpotLightDisplayOn());
	dialog.setPointLightDisplayOn(isPointLightDisplayOn());
	dialog.setShapeDisplayOn(isShapeDisplayOn());
	dialog.setViewpointDisplayOn(isViewpointDisplayOn());
	dialog.setGridSize(getGridSize());
	dialog.setGridAngle(getGridAngle());
	CtbModuleFloatingShowWindow(SW_HIDE);
	CtbPrimitiveFloatingShowWindow(SW_HIDE);
	if (dialog.DoModal() == IDOK) {
		setAxisDisplayOn(dialog.isAxisDisplayOn());
		setGridDisplayOn(dialog.isGridDisplayOn());
		setSnapOn(dialog.isSnapOn());
		setSpotLightDisplayOn(dialog.isSpotLightDisplayOn());
		setPointLightDisplayOn(dialog.isPointLightDisplayOn());
		setShapeDisplayOn(dialog.isShapeDisplayOn());
		setViewpointDisplayOn(dialog.isViewpointDisplayOn());
		setGridSize(dialog.getGridSize());
		setGridAngle(dialog.getGridAngle());
		pressButton(ID_SNAP, isSnapOn() ? TRUE : FALSE);
		pressButton(ID_GRID, isGridDisplayOn() ? TRUE : FALSE);
		InvalidateRect(NULL);
		UpdateWindow();
	}
	CtbModuleFloatingShowWindow(SW_SHOW);
	CtbPrimitiveFloatingShowWindow(SW_SHOW);
}

void OrthoView::polygonEditCheckPointSetFrontFace(IndexedLineSetNode *lineSet)
{
	CoordinateNode *lineSetCoord = lineSet->getCoordinateNodes();
	if (lineSetCoord == NULL)
		return;

	int nLineSetPoints = lineSetCoord->getNPoints();
	if (nLineSetPoints < 3)
		return;

	float	lineSetPoint[3][3];
	float	lineSetVector[3];
	int		n;

	for (n=0; n<3; n++)
		lineSetCoord->getPoint(n, lineSetPoint[n]);
	GetNormalFromVertices(lineSetPoint, lineSetVector);

	float frontVector[3];
	switch (getViewMode()) {
	case ORTHO_XY_PLANE:
		frontVector[0] = 0.0f;
		frontVector[1] = 0.0f;
		frontVector[2] = 1.0f;
		break;
	case ORTHO_YZ_PLANE:
		frontVector[0] = 1.0f;
		frontVector[1] = 0.0f;
		frontVector[2] = 0.0f;
		break;
	case ORTHO_XZ_PLANE:	
		frontVector[0] = 0.0f;
		frontVector[1] = 1.0f;
		frontVector[2] = 0.0f;
		break;
	}

	float cross = lineSetVector[0]*frontVector[0] + lineSetVector[1]*frontVector[1] + lineSetVector[2]*frontVector[2];
	
	if (cross < 0.0f) {
		SFVec3f *point = new SFVec3f[nLineSetPoints];
		for (n=0; n<nLineSetPoints; n++) {
			float pos[3];
			lineSetCoord->getPoint(n, pos);
			point[n].setValue(pos);
		}
		lineSetCoord->removeAllPoints();
		for (n=0; n<nLineSetPoints; n++) {
			float pos[3];
			point[nLineSetPoints-n-1].getValue(pos);
			lineSetCoord->addPoint(pos);
		}
		delete []point;
	}
}

bool OrthoView::isPolygonLineConvex(IndexedLineSetNode *lineSet)
{
	CoordinateNode *lineSetCoord = lineSet->getCoordinateNodes();
	int nLineSetPoints = lineSetCoord->getNPoints();

	double innerAngle = 0.0f;
	double innerCosAngle = 0.0f;

	for (int n=0; n<nLineSetPoints; n++) {
		int prevPos = n - 1;
		if (prevPos < 0)
			prevPos = nLineSetPoints -1;
		
		int nextPos = n + 1;
		if ((nLineSetPoints - 1) < nextPos)
			nextPos = 0;

		float point[3], prevPoint[3], nextPoint[3];

		lineSetCoord->getPoint(n,		point);
		lineSetCoord->getPoint(prevPos,	prevPoint);
		lineSetCoord->getPoint(nextPos,	nextPoint);

		SFVec3f	vector1;
		vector1.setValue(prevPoint);
		vector1.sub(point);

		SFVec3f	vector2;
		vector2.setValue(nextPoint);
		vector2.sub(point);

		float scalar1 = vector1.getScalar();
		float scalar2 = vector1.getScalar();
		float cross = (vector1.getX() * vector2.getX()) + (vector1.getY() * vector2.getY()) + (vector1.getZ() * vector2.getZ());
		double cosAngle = cross / (scalar1 * scalar2);		
		cosAngle = fmod(cosAngle, 1.0);
		innerCosAngle += cosAngle;
		double angle = acos(cosAngle);
		innerAngle += angle;
	}

	innerAngle /= (double)((nLineSetPoints - 3) + 1);

	if (3.14 < innerAngle && innerAngle < 3.15)
		return true;

	return false;
}

void OrthoView::polygonEditAddSideSurface(IndexedFaceSetNode *faceSet, int index[4])
{
	int			n;

	CoordinateNode *faceSetCoord = faceSet->getCoordinateNodes();
	float			sideFacePoint[4][3];
	float			sideFaceVector[3];

	for (n=0; n<4; n++) 
		faceSetCoord->getPoint(n, sideFacePoint[n]);
	GetNormalFromVertices(sideFacePoint, sideFaceVector);

	float frontVector[3];
	switch (getViewMode()) {
	case ORTHO_XY_PLANE:
		frontVector[0] = -1.0f;
		frontVector[1] = 0.0f;
		frontVector[2] = 0.0f;
		break;
	case ORTHO_YZ_PLANE:
		frontVector[0] = 0.0f;
		frontVector[1] = 0.0f;
		frontVector[2] = 1.0f;
		break;
	case ORTHO_XZ_PLANE:	
		frontVector[0] = -1.0f;
		frontVector[1] = 0.0f;
		frontVector[2] = 0.0f;
		break;
	}

	float cross = sideFaceVector[0]*frontVector[0] + sideFaceVector[1]*frontVector[1] + sideFaceVector[2]*frontVector[2];

	bool ccw = false;
	if (cross == 0.0f) {
		switch (getViewMode()) {
		case ORTHO_XY_PLANE:
			frontVector[0] = 0.0f;
			frontVector[1] = 1.0f;
			frontVector[2] = 0.0f;
			break;
		case ORTHO_YZ_PLANE:
			frontVector[0] = 0.0f;
			frontVector[1] = 1.0f;
			frontVector[2] = 0.0f;
			break;
		case ORTHO_XZ_PLANE:	
			frontVector[0] = 0.0f;
			frontVector[1] = 0.0f;
			frontVector[2] = -1.0f;
			break;
		}
		cross = sideFaceVector[0]*frontVector[0] + sideFaceVector[1]*frontVector[1] + sideFaceVector[2]*frontVector[2];
	}

	if (0.0f < cross)
		ccw = true;
	else
		ccw = false;

	if (ccw = true) {
		faceSet->addCoordIndex(index[0]);
		faceSet->addCoordIndex(index[1]);
		faceSet->addCoordIndex(index[2]);
		faceSet->addCoordIndex(index[3]);
		faceSet->addCoordIndex(-1);
	}
	else {
		faceSet->addCoordIndex(index[0]);
		faceSet->addCoordIndex(index[3]);
		faceSet->addCoordIndex(index[2]);
		faceSet->addCoordIndex(index[1]);
		faceSet->addCoordIndex(-1);
	}
}

IndexedFaceSetNode *OrthoView::polygonEditCreateIndexedFaceSet(IndexedLineSetNode *lineSet)
{
	int n;
	
	CoordinateNode *lineSetCoord = lineSet->getCoordinateNodes();
	if (lineSetCoord == NULL)
		return NULL;

	int nLineSetPoints = lineSetCoord->getNPoints();
	if (nLineSetPoints < 3)
		return NULL;

	IndexedFaceSetNode *faceSet = new IndexedFaceSetNode();
	CoordinateNode *faceSetCoord = new CoordinateNode();
	float gridSize = getGridSize();
	
	bool convex = isPolygonLineConvex(lineSet);
	faceSet->setConvex(convex);

	faceSet->addChildNode(faceSetCoord);

	for (n=0; n<nLineSetPoints; n++) {
		float point[3];
		lineSetCoord->getPoint(n, point);
		switch (getViewMode()) {
		case ORTHO_XY_PLANE:
			point[Z] += gridSize/2.0f;
			break;
		case ORTHO_YZ_PLANE:
			point[X] += gridSize/2.0f;
			break;
		case ORTHO_XZ_PLANE:	
			point[Y] += gridSize/2.0f;
			break;
		}
		faceSetCoord->addPoint(point);
	}
	for (n=0; n<nLineSetPoints; n++)
		faceSet->addCoordIndex(n);
	faceSet->addCoordIndex(-1);

	for (n=0; n<nLineSetPoints; n++) {
		float point[3];
		lineSetCoord->getPoint(n, point);
		switch (getViewMode()) {
		case ORTHO_XY_PLANE:
			point[Z] -= gridSize/2.0f;
			break;
		case ORTHO_YZ_PLANE:
			point[X] -= gridSize/2.0f;
			break;
		case ORTHO_XZ_PLANE:	
			point[Y] -= gridSize/2.0f;
			break;
		}
		faceSetCoord->addPoint(point);
	}
	for (n=0; n<nLineSetPoints; n++)
		faceSet->addCoordIndex(((nLineSetPoints - 1) - n) + nLineSetPoints);
	faceSet->addCoordIndex(-1);

	for (n=0; n<nLineSetPoints; n++) {
		int index[4];
		index[0] = n;
		index[1] = n + nLineSetPoints;
		if (n != (nLineSetPoints -1)) {
			index[2] = n + nLineSetPoints + 1;
			index[3] = n +                + 1;
		}
		else {
			index[2] = 0 + nLineSetPoints;
			index[3] = 0;
		}
		polygonEditAddSideSurface(faceSet, index);
/*
		faceSet->addCoordIndex(n                     );
		faceSet->addCoordIndex(n + nLineSetPoints    );
		faceSet->addCoordIndex(n + nLineSetPoints + 1);
		faceSet->addCoordIndex(n +                + 1);
		faceSet->addCoordIndex(-1);
*/
	}

	return faceSet;
}

void OrthoView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください

	if (getOperationMode() == OPERATION_PRMITIVE_EDIT_TEXT) {
		switch (nChar) {
		case VK_ESCAPE:
			{
				TransformNode *trans = getEditPrimitiveTransformNode();
				CtbGetTreeView()->deleteSceneGraphNode(trans);
				trans->remove();
				delete trans;

				dequeue();

				setEditPrimitiveTransformNode(NULL);
				setOperationMode(OPERATION_NONE);

				SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
				ReleaseCapture();
				
				InvalidateRect(NULL);
				UpdateWindow();
				CtbUpdatePerspectiveView();
				CtbModuleFloatingShowWindow(SW_SHOW);
				CtbPrimitiveFloatingShowWindow(SW_SHOW);
			}
			break;
		case VK_RETURN:
			{
				getEditPrimitiveGeometryNode()->initialize();

				setEditPrimitiveTransformNode(NULL);
				setOperationMode(OPERATION_NONE);

				SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
				ReleaseCapture();

				InvalidateRect(NULL);
				UpdateWindow();
				CtbUpdatePerspectiveView();
				CtbModuleFloatingShowWindow(SW_SHOW);
				CtbPrimitiveFloatingShowWindow(SW_SHOW);
			}
			break;
		case VK_BACK:
			{
				TextNode *textNode = (TextNode *)getEditPrimitiveGeometryNode();
				char *string = NULL;
				if (0 < textNode->getNStrings())
					string = textNode->getString(0);
				int stringLen = 0;
				if (string)
					stringLen = strlen(string);
				
				if (stringLen == 0)
					break;
				
				char *newString = new char[stringLen - 1 + 1];
				strncpy(newString, string, stringLen-1);
				newString[stringLen-1] = '\0';

				textNode->setString(0, newString);
				
				delete []newString;
				
				InvalidateRect(NULL);
				UpdateWindow();
				CtbUpdatePerspectiveView();
			}
			break;
		}
	}
	if (getOperationMode() == OPERATION_PRMITIVE_EDIT_POLYGON) {
		switch (nChar) {
		case VK_ESCAPE:
			{
				TransformNode *trans = getEditPrimitiveTransformNode();
				CtbGetTreeView()->deleteSceneGraphNode(trans);
				trans->remove();
				delete trans;

				setEditPrimitiveTransformNode(NULL);
				setOperationMode(OPERATION_NONE);

				SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
				ReleaseCapture();

				InvalidateRect(NULL);
				UpdateWindow();
				CtbUpdatePerspectiveView();
				CtbModuleFloatingShowWindow(SW_SHOW);
				CtbPrimitiveFloatingShowWindow(SW_SHOW);
			}
			return;
		case VK_RETURN:
			{
				wglMakeCurrent(oglHdc, oglHrc);

				TransformNode *trans = getEditPrimitiveTransformNode();
				IndexedLineSetNode *lineSet = (IndexedLineSetNode *)getEditPrimitiveGeometryNode();

				CoordinateNode *coord = lineSet->getCoordinateNodes();
				if (coord != NULL)
					coord->removeLastPoint();

				lineSet->clearCoordIndex();
				for (int n=0; n<coord->getNPoints(); n++) 
					lineSet->addCoordIndex(n);
				lineSet->addCoordIndex(-1);

				polygonEditCheckPointSetFrontFace(lineSet);
				IndexedFaceSetNode *faceSet = polygonEditCreateIndexedFaceSet(lineSet);

				if (faceSet == NULL) {
					CtbGetTreeView()->deleteSceneGraphNode(trans);
					trans->remove();
					delete trans;
				}
				else {
					CtbGetTreeView()->deleteSceneGraphNode(lineSet);
					lineSet->remove();
					delete lineSet;
					ShapeNode *shape = trans->getShapeNodes();
					shape->addChildNode(faceSet);
					CtbGetTreeView()->addSceneGraphNode(faceSet, shape);

					float center[3];
					trans->initialize();
					trans->getBoundingBoxCenter(center);
					trans->setCenter(center);
				}

				wglMakeCurrent(NULL, NULL);

				setEditPrimitiveTransformNode(NULL);
				setOperationMode(OPERATION_NONE);

				SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
				ReleaseCapture();

				InvalidateRect(NULL);
				UpdateWindow();
				CtbUpdatePerspectiveView();
				CtbModuleFloatingShowWindow(SW_SHOW);
				CtbPrimitiveFloatingShowWindow(SW_SHOW);
			}
			return;
		case VK_BACK:
			{
				undoPolygonEdit();
			}
			break;
		}
	}
	else {
		switch (nChar) {
		case VK_DELETE:
			ShapeNode *shape = GetWorld()->getSceneGraph()->getSelectedShapeNode();
			if (shape) {
				Node *parentNode = shape->getParentNode();
				shape->remove();
				enqueue(UndoOrthoViewDeletePrimitiveNew(parentNode, shape), UndoOrthoViewDeletePrimitiveFn);
				GetWorld()->getSceneGraph()->setSelectedShapeNode(NULL);
				CtbGetTreeView()->deleteSceneGraphNode(shape);
			}
			InvalidateRect(NULL);
			UpdateWindow();
			CtbUpdatePerspectiveView();
			break;
		}
	}

	CScrollView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void OrthoView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	if (getOperationMode() == OPERATION_PRMITIVE_EDIT_TEXT) {
		if (' ' <= nChar) { 
			TextNode *textNode = (TextNode *)getEditPrimitiveGeometryNode();
		
			char *string = NULL;
			if (0 < textNode->getNStrings())
				string = textNode->getString(0);
			int stringLen = 0;
			if (string)
				stringLen = strlen(string);
		
			char *newString = new char[stringLen + 1 + 1];
			if (string) {
				strcpy(newString, string);
				strncat(newString, (char *)&nChar, 1);
			}
			else
				strncpy(newString, (char *)&nChar, 1);
				if (0 < textNode->getNStrings())
				textNode->setString(0, newString);
			else
				textNode->addString(newString);
		
			delete []newString;
		
			InvalidateRect(NULL);
			UpdateWindow();
			CtbUpdatePerspectiveView();
		}
	}
	
	CScrollView::OnChar(nChar, nRepCnt, nFlags);
}

