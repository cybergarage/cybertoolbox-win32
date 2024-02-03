/******************************************************************
*
*	VRML library for C++
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	OpenGLFn.cpp
*
******************************************************************/
#include <windows.h>   
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
#include "SceneGraph.h"
#include "OpenGLFn.h"

////////////////////////////////////////////////////////// 
//  OpenGLSetup
////////////////////////////////////////////////////////// 

HGLRC OpenGLSetup( HWND hWnd )
{
    static PIXELFORMATDESCRIPTOR pfd = {
        sizeof (PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, 
        PFD_TYPE_RGBA,
        24,
        0, 0, 0,               
        0, 0, 0,               
        0, 0,        
        0, 0, 0, 0, 0, 
        32,	
        0,
        0,
        PFD_MAIN_PLANE, 
        0,	 
        0,	 
        0,	 
        0	 
    };

    int nMyPixelFormatID;
    HDC hDC;
    HGLRC hRC;

    hDC = GetDC( hWnd );
    nMyPixelFormatID = ChoosePixelFormat( hDC, &pfd );

    SetPixelFormat( hDC, nMyPixelFormatID, &pfd );

    hRC = wglCreateContext( hDC );
    ReleaseDC( hWnd, hDC );

    return hRC;
}

////////////////////////////////////////////////////////// 
//  OpenGLSetSize
////////////////////////////////////////////////////////// 

void OpenGLSetSize(SceneGraph *sg, int width, int height) 
{
	GLdouble aspect = (GLdouble)width/(GLdouble)height;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float fov = 45.0f;
	ViewpointNode *view = sg->getViewpointNode();
	if (view == NULL)
		view = sg->getDefaultViewpointNode();

	fov = (view->getFieldOfView() / 3.14f) * 180.0f;

	gluPerspective(fov, aspect, 0.1f, 10000.0f);

	glViewport( 0, 0, width, height );
}

////////////////////////////////////////////////////////// 
//  DrawSceneGraph
////////////////////////////////////////////////////////// 

static int gnLights;

void PushLightNode(SceneGraph *sg, LightNode *lightNode)
{
	if (!lightNode->isOn()) 
		return;

	GLint	nMaxLightMax;
	glGetIntegerv(GL_MAX_LIGHTS, &nMaxLightMax);

	if (nMaxLightMax < gnLights) {
		gnLights++;
		return;
	}

	ViewpointNode *view = sg->getViewpointNode();
	if (view == NULL)
		view = sg->getDefaultViewpointNode();

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	float	m4[4][4];
	lightNode->getTranslationMatrix(m4);
	glMultMatrixf((float *)m4);

//	glLoadIdentity();

	float	color[4];
	float	pos[4];
	float	attenuation[3];
	float	direction[3];
	float	intensity;

	if (lightNode->isPointLightNode()) {
		
		PointLightNode *pLight = (PointLightNode *)lightNode;

		glEnable(GL_LIGHT0+gnLights);
		
		pLight->getAmbientColor(color);
		glLightfv(GL_LIGHT0+gnLights, GL_AMBIENT, color);

		pLight->getColor(color);
		intensity = pLight->getIntensity();
		color[0] *= intensity; 
		color[1] *= intensity; 
		color[2] *= intensity; 
		glLightfv(GL_LIGHT0+gnLights, GL_DIFFUSE, color);
		glLightfv(GL_LIGHT0+gnLights, GL_SPECULAR, color);

		pLight->getLocation(pos); pos[3] = 1.0f;
		glLightfv(GL_LIGHT0+gnLights, GL_POSITION, pos);

		direction[0] = 0.0f; direction[1] = 0.0f; direction[2] = -1.0f;
		glLightfv(GL_LIGHT0+gnLights, GL_SPOT_DIRECTION, direction);
		glLightf(GL_LIGHT0+gnLights, GL_SPOT_EXPONENT, 0.0f);
		glLightf(GL_LIGHT0+gnLights, GL_SPOT_CUTOFF, 180.0f);

		pLight->getAttenuation(attenuation);
		glLightf(GL_LIGHT0+gnLights, GL_CONSTANT_ATTENUATION, attenuation[0]);
		glLightf(GL_LIGHT0+gnLights, GL_LINEAR_ATTENUATION, attenuation[1]);
		glLightf(GL_LIGHT0+gnLights, GL_QUADRATIC_ATTENUATION, attenuation[2]);
		
		gnLights++;
	}
	else if (lightNode->isDirectionalLightNode()) {

		DirectionalLightNode *dLight = (DirectionalLightNode *)lightNode;
		
		glEnable(GL_LIGHT0+gnLights);
		
		dLight->getAmbientColor(color);
		glLightfv(GL_LIGHT0+gnLights, GL_AMBIENT, color);

		dLight->getColor(color);
		intensity = dLight->getIntensity();
		color[0] *= intensity; 
		color[1] *= intensity; 
		color[2] *= intensity; 
		glLightfv(GL_LIGHT0+gnLights, GL_DIFFUSE, color);
		glLightfv(GL_LIGHT0+gnLights, GL_SPECULAR, color);

		dLight->getDirection(pos); pos[3] = 0.0f;
		VectorInverse(pos);
		glLightfv(GL_LIGHT0+gnLights, GL_POSITION, pos);

		direction[0] = 0.0f; direction[1] = 0.0f; direction[2] = -1.0f;
		glLightfv(GL_LIGHT0+gnLights, GL_SPOT_DIRECTION, direction);
		glLightf(GL_LIGHT0+gnLights, GL_SPOT_EXPONENT, 0.0f);
		glLightf(GL_LIGHT0+gnLights, GL_SPOT_CUTOFF, 180.0f);

		glLightf(GL_LIGHT0+gnLights, GL_CONSTANT_ATTENUATION, 1.0);
		glLightf(GL_LIGHT0+gnLights, GL_LINEAR_ATTENUATION, 0.0);
		glLightf(GL_LIGHT0+gnLights, GL_QUADRATIC_ATTENUATION, 0.0);

		gnLights++;
	}
	else if (lightNode->isSpotLightNode()) {

		SpotLightNode *sLight = (SpotLightNode *)lightNode;

		glEnable(GL_LIGHT0+gnLights);
		
		sLight->getAmbientColor(color);
		glLightfv(GL_LIGHT0+gnLights, GL_AMBIENT, color);

		sLight->getColor(color);
		intensity = sLight->getIntensity();
		color[0] *= intensity; 
		color[1] *= intensity; 
		color[2] *= intensity; 
		glLightfv(GL_LIGHT0+gnLights, GL_DIFFUSE, color);
		glLightfv(GL_LIGHT0+gnLights, GL_SPECULAR, color);

		sLight->getLocation(pos); pos[3] = 1.0f;
		glLightfv(GL_LIGHT0+gnLights, GL_POSITION, pos);

		sLight->getDirection(direction);
		glLightfv(GL_LIGHT0+gnLights, GL_SPOT_DIRECTION, direction);

		glLightf(GL_LIGHT0+gnLights, GL_SPOT_CUTOFF, (float)Radian2Degree(sLight->getCutOffAngle()));
		glLightf(GL_LIGHT0+gnLights, GL_SPOT_EXPONENT, 0.0f);

		sLight->getAttenuation(attenuation);
		glLightf(GL_LIGHT0+gnLights, GL_CONSTANT_ATTENUATION, attenuation[0]);
		glLightf(GL_LIGHT0+gnLights, GL_LINEAR_ATTENUATION, attenuation[1]);
		glLightf(GL_LIGHT0+gnLights, GL_QUADRATIC_ATTENUATION, attenuation[2]);

		gnLights++;
	}

	glPopMatrix ();
}

void PopLightNode(LightNode *lightNode)
{
	if (!lightNode->isOn()) 
		return;

	GLint	nMaxLightMax;
	glGetIntegerv(GL_MAX_LIGHTS, &nMaxLightMax);

	gnLights--;
	
	if (gnLights < nMaxLightMax)
		glDisable(GL_LIGHT0+gnLights);
}

void DrawShapeNode(SceneGraph *sg, ShapeNode *shape, int drawMode)
{
	/////////////////////////////////
	//	Appearance(Material)
	/////////////////////////////////

	float	color[4];
	color[3] = 1.0f;

	AppearanceNode			*appearance = shape->getAppearanceNodes();
	MaterialNode			*material = NULL;
	ImageTextureNode		*imgTexture = NULL;
	TextureTransformNode	*texTransform = NULL;

	bool				bEnableTexture = false;

	if (appearance) {

		// Texture Transform
		TextureTransformNode *texTransform = appearance->getTextureTransformNodes();
		if (texTransform) {
			float texCenter[2];
			float texScale[2];
			float texTranslation[2];
			float texRotation;

			glMatrixMode(GL_TEXTURE);
			glLoadIdentity();

			texTransform->getTranslation(texTranslation);
			glTranslatef(texTranslation[0], texTranslation[1], 0.0f);

			texTransform->getCenter(texCenter);
			glTranslatef(texCenter[0], texCenter[1], 0.0f);

			texRotation = texTransform->getRotation();
			glRotatef(0.0f, 0.0f, 1.0f, texRotation);

			texTransform->getScale(texScale);
			glScalef(texScale[0], texScale[1], 1.0f);

			glTranslatef(-texCenter[0], -texCenter[1], 0.0f);
		}
		else {
			glMatrixMode(GL_TEXTURE);
			glLoadIdentity();
			glTranslatef(0.0f, 0.0f, 1.0f);
		}

		// Texture
		imgTexture = appearance->getImageTextureNodes();
		if (imgTexture && drawMode == OGL_RENDERING_TEXTURE) {

			int width = imgTexture->getWidth();
			int height = imgTexture->getHeight();
			RGBAColor32 *color = imgTexture->getImage();

			if (0 < width && 0 < height && color != NULL) 
				bEnableTexture = true;

			if (bEnableTexture == true) {
				if (imgTexture->hasTransparencyColor() == true) {
					glEnable(GL_BLEND);
					glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				}
				else
					glDisable(GL_BLEND);

				glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

/*
				glTexImage2D(GL_TEXTURE_2D, 0, 4, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, color);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
*/
				glBindTexture(GL_TEXTURE_2D, imgTexture->getTextureName());

				glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

				glEnable(GL_TEXTURE_2D);

				glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
				glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
				glEnable(GL_COLOR_MATERIAL);
			}
			else {
				glDisable(GL_TEXTURE_2D);
				glDisable(GL_COLOR_MATERIAL);
			}
		}
		else {
			glDisable(GL_TEXTURE_2D);
			glDisable(GL_COLOR_MATERIAL);
		}

		// Material
		material = appearance->getMaterialNodes();
		if (material) {
			float	ambientIntesity = material->getAmbientIntensity();

			material->getDiffuseColor(color);
			glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);

			material->getSpecularColor(color);
			glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);

			material->getEmissiveColor(color);
			glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, color);

			material->getDiffuseColor(color);
			color[0] *= ambientIntesity; 
			color[1] *= ambientIntesity; 
			color[2] *= ambientIntesity; 
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color);

			glMateriali(GL_FRONT, GL_SHININESS, (int)(material->getShininess()*128.0));
		}

	}
	
	if (!appearance || !material) {
		color[0] = 0.8f; color[1] = 0.8f; color[2] = 0.8f;
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, color);
		color[0] = 0.0f; color[1] = 0.0f; color[2] = 0.0f;
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, color);
		glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, color);
		color[0] = 0.8f*0.2f; color[1] = 0.8f*0.2f; color[2] = 0.8f*0.2f;
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, color);
		glMateriali(GL_FRONT_AND_BACK, GL_SHININESS, (int)(0.2*128.0));
	}

	if (!appearance || !imgTexture || drawMode != OGL_RENDERING_TEXTURE) {
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);
	}

	/////////////////////////////////
	//	Transform 
	/////////////////////////////////

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	
	float	m4[4][4];
	shape->getTransformMatrix(m4);
	glMultMatrixf((float *)m4);

	glColor3f(1.0f, 1.0f, 1.0f);

	/////////////////////////////////
	//	Geometry
	/////////////////////////////////

	GeometryNode *gnode = shape->getGeometry();
	if (gnode) {
		if (0 < gnode->getDisplayList())
			gnode->draw();
	}

	ShapeNode *selectedShapeNode = sg->getSelectedShapeNode();
	if (gnode && selectedShapeNode == shape) {
		float	bboxCenter[3];
		float	bboxSize[3];
		gnode->getBoundingBoxCenter(bboxCenter);
		gnode->getBoundingBoxSize(bboxSize);

		glColor3f(1.0f, 1.0f, 1.0f);
		glDisable(GL_LIGHTING);
//		glDisable(GL_COLOR_MATERIAL);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);

		glBegin(GL_LINES);
		int x, y, z;
		for (x=0; x<2; x++) {
			for (y=0; y<2; y++) {
				float point[3];
				point[0] = (x==0) ? bboxCenter[0] - bboxSize[0] : bboxCenter[0] + bboxSize[0];
				point[1] = (y==0) ? bboxCenter[1] - bboxSize[1] : bboxCenter[1] + bboxSize[1];
				point[2] = bboxCenter[2] - bboxSize[2];
				glVertex3fv(point);
				point[2] = bboxCenter[2] + bboxSize[2];
				glVertex3fv(point);
			}
		}
		for (x=0; x<2; x++) {
			for (z=0; z<2; z++) {
				float point[3];
				point[0] = (x==0) ? bboxCenter[0] - bboxSize[0] : bboxCenter[0] + bboxSize[0];
				point[1] = bboxCenter[1] - bboxSize[1];
				point[2] = (z==0) ? bboxCenter[2] - bboxSize[2] : bboxCenter[2] + bboxSize[2];
				glVertex3fv(point);
				point[1] = bboxCenter[1] + bboxSize[1];
				glVertex3fv(point);
			}
		}
		for (y=0; y<2; y++) {
			for (z=0; z<2; z++) {
				float point[3];
				point[0] = bboxCenter[0] - bboxSize[0];
				point[1] = (y==0) ? bboxCenter[1] - bboxSize[1] : bboxCenter[1] + bboxSize[1];
				point[2] = (z==0) ? bboxCenter[2] - bboxSize[2] : bboxCenter[2] + bboxSize[2];
				glVertex3fv(point);
				point[0] = bboxCenter[0] + bboxSize[0];
				glVertex3fv(point);
			}
		}
		glEnd();

		glEnable(GL_LIGHTING);
//		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_TEXTURE_2D);
		glEnable(GL_BLEND);
	}

	glPopMatrix();
}


void DrawNode(SceneGraph *sg, Node *firstNode, int drawMode) 
{
	if (!firstNode)
		return;

	Node	*node;

	for (node = firstNode; node; node=node->next()) {
		if (node->isLightNode()) 
			PushLightNode(sg, (LightNode *)node);
	}

	for (node = firstNode; node; node=node->next()) {
		if (node->isShapeNode()) 
			DrawShapeNode(sg, (ShapeNode *)node, drawMode);
		else
			DrawNode(sg, node->getChildNodes(), drawMode);
	}

	for (node = firstNode; node; node=node->next()) {
		if (node->isLightNode()) 
			PopLightNode((LightNode *)node);
	}
}

void DrawSceneGraph(SceneGraph *sg, int drawMode)
{
	ViewpointNode *view = sg->getViewpointNode();

	if (view) {
		GLint	viewport[4];
		glGetIntegerv(GL_VIEWPORT, viewport);
		OpenGLSetSize(sg, viewport[2], viewport[3]);
	}

    glEnable(GL_DEPTH_TEST);
	switch (drawMode) {
	case OGL_RENDERING_WIRE:
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		break;
	default:
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glEnable(GL_LIGHTING);
//	glShadeModel (GL_FLAT);
    glShadeModel (GL_SMOOTH);

	float clearColor[] = {0.0f, 0.0f, 0.0f};
	
	BackgroundNode *bg = sg->getBackgroundNode();
	if (bg != NULL) {
		if (0 < bg->getNSkyColors())
			bg->getSkyColor(0, clearColor);
	}

	glClearColor(clearColor[0], clearColor[1], clearColor[2], 1.0f);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	if (!view)
		return;

	/////////////////////////////////
	//	ViewpointNode 
	/////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	float	m4[4][4];
	view->getMatrix(m4);
	glMultMatrixf((float *)m4);

	/////////////////////////////////
	//	Fog
	/////////////////////////////////

	glDisable(GL_FOG);

	FogNode *fog = sg->getFogNode();
	if (fog != NULL) {

		glEnable(GL_FOG);

		float visRange = fog->getVisibilityRange();

		float color[] = {0.0f, 0.0f, 0.0f, 1.0f};
		fog->getColor(color);
		glFogfv(GL_FOG_COLOR, color);

		char *fogType = fog->getFogType();
		if (fogType != NULL) {
			if (strcmp(fogType, "EXPONENTIAL") == 0) {
				glFogf(GL_FOG_DENSITY, visRange);
				glFogi(GL_FOG_MODE, GL_EXP2);
				glHint(GL_FOG_HINT, GL_DONT_CARE);
			}
			else { //if (strcmp(fogType, "LINEAR") == 0) {
				glFogf(GL_FOG_START, visRange/10.0f);
				glFogf(GL_FOG_END, visRange);
				glFogi(GL_FOG_MODE, GL_LINEAR);
				glHint(GL_FOG_HINT, GL_DONT_CARE);
			}
		}
	}

	/////////////////////////////////
	//	Light
	/////////////////////////////////

	GLint	nMaxLightMax;
	glGetIntegerv(GL_MAX_LIGHTS, &nMaxLightMax);
	for (int n = 0; n < nMaxLightMax; n++)
		glDisable(GL_LIGHT0+n);

	/////////////////////////////////
	//	General Node
	/////////////////////////////////

	gnLights = 0;

	DrawNode(sg, sg->getNodes(), drawMode);

    glFlush ();
}

////////////////////////////////////////////////////////// 
//  PickShapeNode
////////////////////////////////////////////////////////// 

#define SELECTION_BUF_SIZE	1024

void DrawSceneGraphForSelection(SceneGraph *sg)
{
	ViewpointNode *view = sg->getViewpointNode();

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	if (!view)
		return;

	/////////////////////////////////
	//	ViewpointNode 
	/////////////////////////////////

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	float	m4[4][4];
	view->getMatrix(m4);
	glMultMatrixf((float *)m4);

	/////////////////////////////////
	//	ShapeNode 
	/////////////////////////////////

	int nShapeNode = 0;
	for (ShapeNode *shape = sg->findShapeNode(); shape; shape=shape->nextTraversal()) {

		// For Selection mode
		glLoadName(nShapeNode);

		glPushMatrix ();

		/////////////////////////////////
		//	Transform 
		/////////////////////////////////

		shape->getTransformMatrix(m4);
		glMultMatrixf((float *)m4);

		/////////////////////////////////
		//	Geometry
		/////////////////////////////////

		GeometryNode *gnode = shape->getGeometry();
		if (gnode) {
			unsigned int nDisplayList = gnode->getDisplayList();
			if (0 < nDisplayList)
				glCallList(nDisplayList);
		}

		nShapeNode++;

		glPopMatrix();
	}

    glFlush ();
}

int ProcessHits(GLint hits, GLuint buffer[])
{
	int nShapeNode = -1;

	if (hits <= 0)
		return -1;

	GLint	names, zmin, zmax, z1, z2, sn;
	GLuint	*ptr = buffer;

	names = *ptr; ptr++;
	zmin = *ptr; ptr++;
	zmax = *ptr; ptr++;
	nShapeNode = *ptr; ptr++;

	for (int i=0; i<hits-1; i++) {
		names = *ptr; ptr++;
		z1 = *ptr; ptr++;
		z2 = *ptr; ptr++;
		sn = *ptr; ptr++;
		if (z1 < zmin) {
			zmin = z1;
			nShapeNode = sn;
		}
	}
	return nShapeNode;
}

ShapeNode *PickShapeNode(SceneGraph *sg, int mx, int my)
{
	ViewpointNode *view = sg->getViewpointNode();
	
	if (!view)
		return NULL;

	GLuint	selectBuf[SELECTION_BUF_SIZE];
	GLint	viewport[4];

	glGetIntegerv(GL_VIEWPORT, viewport);
	glSelectBuffer(SELECTION_BUF_SIZE, selectBuf);

	glRenderMode(GL_SELECT);
	glInitNames();
	glPushName(0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPickMatrix(mx, viewport[3]-my, 1.0, 1.0, viewport);

	float fov = (view->getFieldOfView() / 3.14159f) * 180.0f;
	gluPerspective(fov, (GLdouble)viewport[2]/(GLdouble)viewport[3], 0.1f, 10000.0f);

	DrawSceneGraphForSelection(sg);

	glPopName();

	GLint hits = glRenderMode(GL_RENDER);
	int nShapeNode = ProcessHits(hits, selectBuf);

	if (nShapeNode < 0)
		return NULL;

	ShapeNode *shape = sg->findShapeNode();
	for (int n=0; n<nShapeNode && shape; n++)
		shape=shape->nextTraversal();

	return shape;
}

