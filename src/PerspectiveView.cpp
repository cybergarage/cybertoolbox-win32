// PerspectiveView.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "CyberToolBox.h"
#include "PerspectiveView.h"
#include "PerspectiveFrame.h"
#include <math.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
#include "RegKey.h"
#include "OpenGLFn.h"
#include "World.h"
#include "DialogPerspectiveViewConfig.h"

 
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PerspectiveView

IMPLEMENT_DYNCREATE(PerspectiveView, CView)

PerspectiveView::PerspectiveView()
{
	oglDC = NULL;
	setMouseMode(PRESPECTIVE_MOUSE_MODE_NONE);
	setOperationMode(PRESPECTIVE_OPERATION_MODE_WALKING);
	headLightOn();
}

PerspectiveView::~PerspectiveView()
{
	if (oglDC)
		delete oglDC;
}

BEGIN_MESSAGE_MAP(PerspectiveView, CView)
	//{{AFX_MSG_MAP(PerspectiveView)
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_COMMAND(ID_WALKING, OnWalking)
	ON_COMMAND(ID_PICKING, OnPicking)
	ON_COMMAND(ID_ZOOMVIEW, OnZoomview)
	ON_COMMAND(ID_RENDERING_WIREFRAME, OnRenderingWireframe)
	ON_COMMAND(ID_RENDERING_SHADE, OnRenderingShade)
	ON_COMMAND(ID_HEADLIGHT, OnHeadlight)
	ON_COMMAND(ID_RENDERING_TEXTURE, OnRenderingTexture)
	ON_COMMAND(ID_PAN, OnPan)
	ON_COMMAND(ID_ROTATE, OnRotate)
	ON_COMMAND(ID_CONFIG, OnConfig)
	ON_WM_RBUTTONDBLCLK()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PerspectiveView 描画

void PerspectiveView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: この位置に描画用のコードを追加してください

	SceneGraph *sg = GetWorld()->getSceneGraph();

	BackgroundNode		*defaultBackground	= sg->getDefaultBackgroundNode();
	FogNode				*defaultFog			= sg->getDefaultFogNode();
	NavigationInfoNode	*defaultNavInfo		= sg->getDefaultNavigationInfoNode();
	ViewpointNode		*defaultView		= sg->getDefaultViewpointNode();

	if (!sg->getBackgroundNode()) {
		sg->addNode(defaultBackground);
		sg->setBackgroundNode(defaultBackground, 1);
	}

	if (!sg->getNavigationInfoNode()) {
		sg->addNode(defaultNavInfo);
		sg->setNavigationInfoNode(defaultNavInfo, 1);
	}

	if (!sg->getViewpointNode()) {
		sg->addNode(defaultView);
		sg->setViewpointNode(defaultView, 1);
	}

	NavigationInfoNode *navInfo = sg->getNavigationInfoNode();
	navInfo->setHeadlight(isHeadLightOn());

	if (isHeadLightOn()) {
		float	location[3];
		ViewpointNode *view = sg->getViewpointNode();
		view->getPosition(location);
		defaultLight.setLocation(location);
		defaultLight.setAmbientIntensity(0.3f);
		defaultLight.setIntensity(0.7f);
		sg->addNode(&defaultLight);
	}

    wglMakeCurrent(oglHdc, oglHrc);

	DrawSceneGraph(sg, GetWorld()->getRenderingMode());

	glFinish();
	SwapBuffers(wglGetCurrentDC());

    wglMakeCurrent(NULL, NULL);

	defaultBackground->remove();
	defaultFog->remove();
	defaultNavInfo->remove();
	defaultView->remove();
	
	defaultLight.remove();
}

/////////////////////////////////////////////////////////////////////////////
// PerspectiveView 診断

#ifdef _DEBUG
void PerspectiveView::AssertValid() const
{
	CView::AssertValid();
}

void PerspectiveView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

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

void PerspectiveView::OGLSetup()
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

    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
}

BOOL PerspectiveView::OGLSetupPixelFormat()
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

unsigned char PerspectiveView::OGLComponentFromIndex(int i, UINT nbits, UINT shift)
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


void PerspectiveView::OGLCreateRGBPalette()
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
// PerspectiveView メッセージ ハンドラ

BOOL PerspectiveView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

BOOL PerspectiveView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	return TRUE;
}

BOOL PerspectiveView::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
//  cs.style = WS_OVERLAPPED | WS_SYSMENU | WS_BORDER | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
//	cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
//  cs.style ^= WS_SYSMENU;

	RegKeyGetValue(REGKEY_SECTION_POSITION, REGKEY_KEY_POSITION_DIAGRAMMODULE, &cs.x, &cs.y, &cs.cx, &cs.cy);
	
	return CView::PreCreateWindow(cs);
}

int PerspectiveView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: この位置に固有の作成用コードを追加してください
	OGLSetup();

	GetParentFrame()->SetWindowText(_T(""));

	return 0;
}

void PerspectiveView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: この位置にメッセージ ハンドラ用のコードを追加してください
    wglMakeCurrent(oglHdc, oglHrc);
	OpenGLSetSize(GetWorld()->getSceneGraph(), cx, cy);	
    wglMakeCurrent(NULL, NULL);
}

void PerspectiveView::MoveViewpoint(int mosx, int mosy)
{
	if (getOperationMode() == PRESPECTIVE_OPERATION_MODE_PICKING || !getMouseMode())
		return;

	if (!GetWorld()->hasUserNode())
		return;

	SceneGraph *sg = GetWorld()->getSceneGraph();

	BackgroundNode		*defaultBackground	= sg->getDefaultBackgroundNode();
	FogNode				*defaultFog			= sg->getDefaultFogNode();
	NavigationInfoNode	*defaultNavInfo		= sg->getDefaultNavigationInfoNode();
	ViewpointNode		*defaultView		= sg->getDefaultViewpointNode();

	if (!sg->getNavigationInfoNode()) {
		sg->addNode(defaultNavInfo);
		sg->setNavigationInfoNode(defaultNavInfo, 1);
	}

	if (!sg->getViewpointNode()) {
		sg->addNode(defaultView);
		sg->setViewpointNode(defaultView, 1);
	}

	ViewpointNode		*vpoint = sg->getViewpointNode();
	NavigationInfoNode	*navInfo = sg->getNavigationInfoNode();

	CRect winRect;
	GetWindowRect(&winRect);
	int width = winRect.Width();
	int height = winRect.Height();

	float	trans[3] = {0.0f, 0.0f, 0.0f};
	float	rot[4] = {0.0f, 0.0f, 1.0f, 0.0f};

	static float transScale = 1.0f /10.0f;
	static float rotScale = (3.1415f/120.0f);

	if (getMouseMode() == PRESPECTIVE_MOUSE_MODE_LBUTTONDOWN) {
		switch (getOperationMode()) {
		case PRESPECTIVE_OPERATION_MODE_WALKING:
			trans[Z] = (float)(mosy - height/2) / (float)(height/2) * navInfo->getSpeed() * transScale;
			rot[X] = 0.0f;
			rot[Y] = 1.0f;
			rot[Z] = 0.0f;
			rot[3] = -(float)(mosx - width/2) / (float)(width/2) * rotScale;
			break;
		case PRESPECTIVE_OPERATION_MODE_PAN:
			trans[X] = (float)(mosx - width/2) / (float)(width/2) * navInfo->getSpeed() * transScale;
			trans[Y] = -(float)(mosy - height/2) / (float)(height/2) * navInfo->getSpeed() * transScale;
			break;
		case PRESPECTIVE_OPERATION_MODE_ROTATE:
			rot[X] = 1.0f;
			rot[Y] = 0.0f;
			rot[Z] = 0.0f;
			rot[3] = -(float)(mosy - height/2) / (float)(height/2) * rotScale;
		}
	}

	vpoint->translate(trans);
	vpoint->rotate(rot);

	if (getMouseMode() == PRESPECTIVE_MOUSE_MODE_LBUTTONDOWN) {
		switch (getOperationMode()) {
		case PRESPECTIVE_OPERATION_MODE_ROTATE:
			rot[X] = 0.0f;
			rot[Y] = 0.0f;
			rot[Z] = 1.0f;
			rot[3] = -(float)(mosx - width/2) / (float)(width/2) * rotScale;
			break;
		}
	}

	vpoint->rotate(rot);

	defaultNavInfo->remove();
	defaultView->remove();
}

void PerspectiveView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
    wglMakeCurrent(oglHdc, oglHrc);

	switch (getOperationMode()) {
	case PRESPECTIVE_OPERATION_MODE_PICKING:
		{
			SceneGraph *sg = GetWorld()->getSceneGraph();

			BackgroundNode		*defaultBackground	= sg->getDefaultBackgroundNode();
			FogNode				*defaultFog			= sg->getDefaultFogNode();
			NavigationInfoNode	*defaultNavInfo		= sg->getDefaultNavigationInfoNode();
			ViewpointNode		*defaultView		= sg->getDefaultViewpointNode();

			if (!sg->getViewpointNode()) {
				sg->addNode(defaultView);
				sg->setViewpointNode(defaultView, 1);
			}

			ShapeNode *shape = PickShapeNode(GetWorld()->getSceneGraph(), point.x, point.y);
			
			setSelectedShapeNode(shape);

			if (GetWorld()->isSimulationActive() == TRUE) {
				if (shape && getMouseMode() == PRESPECTIVE_MOUSE_MODE_NONE) {
					for (Node *node=GetWorld()->getSceneGraph()->getNodes(); node; node=node->nextTraversal()) {
						if (node->isTouchSensorNode()) {
							TouchSensorNode *touchSensor = (TouchSensorNode *)node;
							Node *parentNode = touchSensor->getParentNode();
							if (shape->isAncestorNode(parentNode)) {
								setTouchSensorNode(touchSensor);

								SFBool *isActive = touchSensor->getIsActiveField();
								isActive->setValue(TRUE);
								touchSensor->sendEvent(isActive);
								
								SFTime *touchTime = touchSensor->getTouchTimeField();
								touchTime->setValue(GetCurrentSystemTime());
								touchSensor->sendEvent(touchTime);

								setMouseMode(getMouseMode() | PRESPECTIVE_MOUSE_MODE_SELECTING);
								InvalidateRect(NULL);
							}
						} else 	if (node->isPlaneSensorNode()) {
							PlaneSensorNode *planeSensor = (PlaneSensorNode *)node;
							Node *parentNode = planeSensor->getParentNode();
							if (shape->isAncestorNode(parentNode)) {
								setPlaneSensorNode(planeSensor);
								
								SFBool *isActive = planeSensor->getIsActiveField();
								isActive->setValue(TRUE);
								planeSensor->sendEvent(isActive);
								
								float m4[4][4];
								shape->getTransformMatrix(m4);
								setSelectedShapeMatrix(m4);

								setMouseMode(getMouseMode() | PRESPECTIVE_MOUSE_MODE_DRAG);
								InvalidateRect(NULL);
							}
						}
					}
				}
			}
			else {
				GetWorld()->getSceneGraph()->setSelectedShapeNode(shape);
				GetWorld()->getSceneGraph()->setSelectedNode(NULL);
				CtbUpdatePerspectiveView();
				CtbUpdateOrthoView();
			}

			defaultView->remove();
		}
		break;
	case PRESPECTIVE_OPERATION_MODE_WALKING:
	case PRESPECTIVE_OPERATION_MODE_PAN:
	case PRESPECTIVE_OPERATION_MODE_ROTATE:
		{
			setMouseMode(PRESPECTIVE_MOUSE_MODE_LBUTTONDOWN);
			MoveViewpoint(point.x, point.y);
			SetCapture();
			SetTimer(1, 50, NULL);
		}
		break;
	}

	setStartMousePosition(point.x, point.y);

    wglMakeCurrent(NULL, NULL);

	CView::OnLButtonDown(nFlags, point);
}

void PerspectiveView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	switch (getOperationMode()) {
	case PRESPECTIVE_OPERATION_MODE_PICKING:
		{
			if (getMouseMode() & PRESPECTIVE_MOUSE_MODE_SELECTING) {
				TouchSensorNode *touchSensor = getTouchSensorNode();
				SFBool *isActive = (SFBool *)touchSensor->getIsActiveField();
				isActive->setValue(FALSE);
				touchSensor->sendEvent(isActive);
			}
			
			if (getMouseMode() & PRESPECTIVE_MOUSE_MODE_DRAG) {
				PlaneSensorNode *planeSensor = getPlaneSensorNode();
				SFBool *isActive = (SFBool *)planeSensor->getIsActiveField();
				isActive->setValue(FALSE);
				planeSensor->sendEvent(isActive);
			}

			setMouseMode(PRESPECTIVE_MOUSE_MODE_NONE);
		}
		break;
	case PRESPECTIVE_OPERATION_MODE_WALKING:
	case PRESPECTIVE_OPERATION_MODE_PAN:
	case PRESPECTIVE_OPERATION_MODE_ROTATE:
		{
			setMouseMode(PRESPECTIVE_MOUSE_MODE_NONE);
			setMousePosition(point.x, point.y);
			ReleaseCapture();
			KillTimer(1);
		}
		break;
	}

	CView::OnLButtonUp(nFlags, point);
}

void PerspectiveView::getWorldPosition(int mousex, int mousey, ShapeNode *selectedShape, float world[3])
{
	GLdouble	model[16], proj[16];
	GLint		viewport[4];
	float		m4[4][4];
	float		objTrans[3];
	double		winx, winy, winz;

    wglMakeCurrent(oglHdc, oglHrc);

	SceneGraph *sg = GetWorld()->getSceneGraph();

	ViewpointNode *view = sg->getViewpointNode();
	if (!view)
		view = sg->getDefaultViewpointNode();

	glGetIntegerv(GL_VIEWPORT, viewport);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	float fov = (view->getFieldOfView() / 3.14f) * 180.0f;
	GLdouble aspect = (GLdouble)viewport[2]/(GLdouble)viewport[3];
	gluPerspective(fov, aspect, 0.1f, 10000.0f);
	glViewport( 0, 0, viewport[2], viewport[3]);
	glGetDoublev(GL_PROJECTION_MATRIX, proj);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity ();
	view->getMatrix(m4);
	glMultMatrixf((float *)m4);

	getSelectedShapeMatrix(m4);
	glMultMatrixf((float *)m4);

	glGetDoublev(GL_MODELVIEW_MATRIX, model);

	SFMatrix matrix(m4);
	matrix.getTranslation(objTrans);

	double x, y, z;

	gluProject((GLdouble)objTrans[0], (GLdouble)objTrans[1], (GLdouble)objTrans[2], model, proj, viewport, &winx, &winy, &winz);
	gluUnProject(winx + (GLdouble)mousex, winy + (GLdouble)mousey, winz, model, proj, viewport, &x, &y, &z);
	
	world[0] = (float)x;
	world[1] = -(float)y;
	world[2] = -(float)z;
	matrix.multi(world);

    wglMakeCurrent(NULL, NULL);
}

void PerspectiveView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください

	switch (getOperationMode()) {
	case PRESPECTIVE_OPERATION_MODE_PICKING:
		{
			if (getMouseMode() & PRESPECTIVE_MOUSE_MODE_DRAG) {
				float world[3];
				int mx = point.x - getStartMousePositionX();
				int my = point.y - getStartMousePositionY();
				getWorldPosition(mx, my, getSelectedShapeNode(), world);
				PlaneSensorNode *planeSensor = getPlaneSensorNode();
				planeSensor->setTranslationChanged(world[0], world[1], world[2]);
				planeSensor->sendEvent(planeSensor->getTranslationChangedField());
			}
		}
		break;
	case PRESPECTIVE_OPERATION_MODE_WALKING:
	case PRESPECTIVE_OPERATION_MODE_PAN:
	case PRESPECTIVE_OPERATION_MODE_ROTATE:
		{
			MoveViewpoint(point.x, point.y);
			setMousePosition(point.x, point.y);
		}
		break;
	}

	CView::OnMouseMove(nFlags, point);
}

void PerspectiveView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	switch (getOperationMode()) {
	case PRESPECTIVE_OPERATION_MODE_WALKING:
	case PRESPECTIVE_OPERATION_MODE_PAN:
	case PRESPECTIVE_OPERATION_MODE_ROTATE:
		{
			setMouseMode(PRESPECTIVE_MOUSE_MODE_RBUTTONDOWN);
			MoveViewpoint(point.x, point.y);
			setMousePosition(point.x, point.y);
			SetCapture();
			SetTimer(1, 50, NULL);
		}
		break;
	}
	
	CView::OnRButtonDown(nFlags, point);
}

void PerspectiveView::OnRButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	switch (getOperationMode()) {
	case PRESPECTIVE_OPERATION_MODE_WALKING:
	case PRESPECTIVE_OPERATION_MODE_PAN:
	case PRESPECTIVE_OPERATION_MODE_ROTATE:
		{
			setMouseMode(PRESPECTIVE_MOUSE_MODE_NONE);
			ReleaseCapture();
			KillTimer(1);
		}
		break;
	}
	
	CView::OnRButtonUp(nFlags, point);
}


void PerspectiveView::OnTimer(UINT nIDEvent) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	int x, y;
	getMousePosition(x, y);
	MoveViewpoint(x, y);

	if (GetWorld()->isSimulationActive() == false) {
		InvalidateRect(NULL);
		UpdateWindow();
		CtbUpdateOrthoView();
	}
	
	MSG msg;
	while(::PeekMessage(&msg, m_hWnd, WM_TIMER, WM_TIMER, PM_REMOVE));

	CView::OnTimer(nIDEvent);
}

void PerspectiveView::OnWalking() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	setOperationMode(PRESPECTIVE_OPERATION_MODE_WALKING);
	setToolBarButton(ID_WALKING);
//	::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
}

void PerspectiveView::OnPicking() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	setOperationMode(PRESPECTIVE_OPERATION_MODE_PICKING);
	setToolBarButton(ID_PICKING);	
//	::SetCursor(AfxGetApp()->LoadCursor(IDC_PICKING_CURSOR));
}

void PerspectiveView::OnPan() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	setOperationMode(PRESPECTIVE_OPERATION_MODE_PAN);
	setToolBarButton(ID_PAN);
}

void PerspectiveView::OnRotate() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	setOperationMode(PRESPECTIVE_OPERATION_MODE_ROTATE);
	setToolBarButton(ID_ROTATE);
}


/////////////////////////////////////////////////////
//	ToolBar
/////////////////////////////////////////////////////

void PerspectiveView::enableButton(int id, BOOL bEnable)
{
	CToolBarCtrl	&tbCtrl = ((PerspectiveFrame *)GetParentFrame())->m_wndToolBar.GetToolBarCtrl();
//	tbCtrl.EnableButton(id, bEnable);
	tbCtrl.Indeterminate(id, !bEnable);
}

void PerspectiveView::pressButton(int id, BOOL bEnable)
{
	CToolBarCtrl	&tbCtrl = ((PerspectiveFrame *)GetParentFrame())->m_wndToolBar.GetToolBarCtrl();
	tbCtrl.PressButton(id, bEnable);
}

BOOL PerspectiveView::isButtonEnabled(int id)
{
	CToolBarCtrl	&tbCtrl = ((PerspectiveFrame *)GetParentFrame())->m_wndToolBar.GetToolBarCtrl();
	return tbCtrl.IsButtonEnabled(id);
}

BOOL PerspectiveView::isButtonPressed(int id)
{
	CToolBarCtrl	&tbCtrl = ((PerspectiveFrame *)GetParentFrame())->m_wndToolBar.GetToolBarCtrl();
	return tbCtrl.IsButtonPressed(id);
}

void PerspectiveView::setToolBarButton(int pushedButton)
{
	switch (pushedButton) {
	case ID_WALKING:
		pressButton(ID_WALKING,		TRUE);
		pressButton(ID_PICKING,		FALSE);
		pressButton(ID_PAN,			FALSE);
		pressButton(ID_ROTATE,		FALSE);
		break;
	case ID_PICKING:
		pressButton(ID_WALKING,		FALSE);
		pressButton(ID_PICKING,		TRUE);
		pressButton(ID_PAN,			FALSE);
		pressButton(ID_ROTATE,		FALSE);
		break;
	case ID_PAN:
		pressButton(ID_WALKING,		FALSE);
		pressButton(ID_PICKING,		FALSE);
		pressButton(ID_PAN,			TRUE);
		pressButton(ID_ROTATE,		FALSE);
		break;
	case ID_ROTATE:
		pressButton(ID_WALKING,		FALSE);
		pressButton(ID_PICKING,		FALSE);
		pressButton(ID_PAN,			FALSE);
		pressButton(ID_ROTATE,		TRUE);
		break;
	case ID_RENDERING_WIREFRAME:
		pressButton(ID_RENDERING_WIREFRAME, TRUE);
		pressButton(ID_RENDERING_SHADE, FALSE);
		pressButton(ID_RENDERING_TEXTURE, FALSE);
		break;
	case ID_RENDERING_SHADE:
		pressButton(ID_RENDERING_WIREFRAME, FALSE);
		pressButton(ID_RENDERING_SHADE, TRUE);
		pressButton(ID_RENDERING_TEXTURE, FALSE);
		break;
	case ID_RENDERING_TEXTURE:
		pressButton(ID_RENDERING_WIREFRAME, FALSE);
		pressButton(ID_RENDERING_SHADE, FALSE);
		pressButton(ID_RENDERING_TEXTURE, TRUE);
		break;
	}
}

/////////////////////////////////////////////////////
//	Selected Sharp
/////////////////////////////////////////////////////

void PerspectiveView::setSelectedShapeMatrix(float value[4][4])
{
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++)
			mSelectedShapeMatrix[i][j] = value[i][j];
	}
}

void PerspectiveView::getSelectedShapeMatrix(float value[4][4])
{
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++)
			value[i][j] = mSelectedShapeMatrix[i][j];
	}
}

/////////////////////////////////////////////////////
//	HeadLight
/////////////////////////////////////////////////////

void PerspectiveView::headLightOn()
{
	SceneGraph *sg = GetWorld()->getSceneGraph();

	NavigationInfoNode *navInfo = sg->getNavigationInfoNode();
	if (navInfo == NULL) 
		navInfo = sg->getDefaultNavigationInfoNode();

	navInfo->setHeadlight(true);
}

void PerspectiveView::headLightOff()
{
	SceneGraph *sg = GetWorld()->getSceneGraph();

	NavigationInfoNode *navInfo = sg->getNavigationInfoNode();
	if (navInfo == NULL) 
		navInfo = sg->getDefaultNavigationInfoNode();

	navInfo->setHeadlight(false);
}

bool PerspectiveView::isHeadLightOn()
{
	SceneGraph *sg = GetWorld()->getSceneGraph();

	NavigationInfoNode *navInfo = sg->getNavigationInfoNode();
	if (navInfo == NULL) 
		navInfo = sg->getDefaultNavigationInfoNode();

	return navInfo->getHeadlight();
}

/////////////////////////////////////////////////////
//	Toolbar
/////////////////////////////////////////////////////

void PerspectiveView::OnZoomview() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください

	GetWorld()->getSceneGraph()->zoomAllViewpoint();

	InvalidateRect(NULL);
	UpdateWindow();
	CtbUpdateOrthoView();
}

void PerspectiveView::OnRenderingWireframe() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	GetWorld()->setRenderingMode(OGL_RENDERING_WIRE);
	setToolBarButton(ID_RENDERING_WIREFRAME);
	InvalidateRect(NULL);
	UpdateWindow();
}

void PerspectiveView::OnRenderingShade() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	GetWorld()->setRenderingMode(OGL_RENDERING_SHADE);
	setToolBarButton(ID_RENDERING_SHADE);
	InvalidateRect(NULL);
	UpdateWindow();
}

void PerspectiveView::OnRenderingTexture() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	GetWorld()->setRenderingMode(OGL_RENDERING_TEXTURE);
	setToolBarButton(ID_RENDERING_TEXTURE);
	InvalidateRect(NULL);
	UpdateWindow();
}

void PerspectiveView::OnHeadlight() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	if (isHeadLightOn()) {
		pressButton(ID_HEADLIGHT, FALSE);
		headLightOff();
	}
	else {
		pressButton(ID_HEADLIGHT, TRUE);
		headLightOn();
	}
	InvalidateRect(NULL);
}

void PerspectiveView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	pressButton(ID_WALKING, TRUE);
	pressButton(ID_HEADLIGHT, TRUE);
	pressButton(ID_RENDERING_TEXTURE, TRUE);
}

void PerspectiveView::OnConfig() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	
	SceneGraph *sg = GetWorld()->getSceneGraph();

	NavigationInfoNode *navInfo = sg->getNavigationInfoNode();
	if (navInfo == NULL) 
		navInfo = sg->getDefaultNavigationInfoNode();

	DialogPerspectiveViewConfig dialog(this);
	
	dialog.setRenderingMode(GetWorld()->getRenderingMode());
	dialog.setSpeed(navInfo->getSpeed());
	dialog.setHeadLight(navInfo->getHeadlight());

	CtbModuleFloatingShowWindow(SW_HIDE);
	CtbPrimitiveFloatingShowWindow(SW_HIDE);
	if (dialog.DoModal() == IDOK) {
		GetWorld()->setRenderingMode(dialog.getRenderingMode());
		switch (GetWorld()->getRenderingMode()) {
		case OGL_RENDERING_WIRE:
			setToolBarButton(ID_RENDERING_WIREFRAME);
			break;
		case OGL_RENDERING_SHADE:
			setToolBarButton(ID_RENDERING_SHADE);
			break;
		case OGL_RENDERING_TEXTURE:
			setToolBarButton(ID_RENDERING_TEXTURE);
			break;
		}
		
		navInfo->setSpeed(dialog.getSpeed());
		
		navInfo->setHeadlight(dialog.getHeadLight());
		if (navInfo->getHeadlight()) {
			pressButton(ID_HEADLIGHT, TRUE);
			headLightOn();
		}
		else {
			pressButton(ID_HEADLIGHT, FALSE);
			headLightOff();
		}

		InvalidateRect(NULL);
		UpdateWindow();
	}
	CtbModuleFloatingShowWindow(SW_SHOW);
	CtbPrimitiveFloatingShowWindow(SW_SHOW);
	
}

void PerspectiveView::OnRButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	ClientToScreen(&point);

	CMenu menu;
	VERIFY(menu.LoadMenu(IDR_PERSPECTIVEVIEW_POPUP));
	CMenu* pPopup = menu.GetSubMenu(0);
	ASSERT(pPopup != NULL);

	switch (getOperationMode()) {
	case PRESPECTIVE_OPERATION_MODE_PICKING:
		pPopup->CheckMenuItem(ID_MENUITEM_PICK, MF_CHECKED);
		break;
	case PRESPECTIVE_OPERATION_MODE_WALKING:
		pPopup->CheckMenuItem(ID_MENUITEM_WALK, MF_CHECKED);
		break;
	case PRESPECTIVE_OPERATION_MODE_PAN:
		pPopup->CheckMenuItem(ID_MENUITEM_PAN, MF_CHECKED);
		break;
	case PRESPECTIVE_OPERATION_MODE_ROTATE:
		pPopup->CheckMenuItem(ID_MENUITEM_ROT, MF_CHECKED);
		break;
	}

	switch (GetWorld()->getRenderingMode()) {
	case OGL_RENDERING_WIRE:
		pPopup->CheckMenuItem(ID_MENUITEM_WIREFRAME, MF_CHECKED);
		break;
	case OGL_RENDERING_SHADE:
		pPopup->CheckMenuItem(ID_MENUITEM_SHADING, MF_CHECKED);
		break;
	case OGL_RENDERING_TEXTURE:
		pPopup->CheckMenuItem(ID_MENUITEM_TEXTURING, MF_CHECKED);
		break;
	}

	pPopup->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);

	ScreenToClient(&point);

	CView::OnRButtonDblClk(nFlags, point);
}

BOOL PerspectiveView::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	switch (wParam) {
	case ID_MENUITEM_PICK:
		setOperationMode(PRESPECTIVE_OPERATION_MODE_PICKING);
		setToolBarButton(ID_PICKING);
		break;
	case ID_MENUITEM_WALK:
		setOperationMode(PRESPECTIVE_OPERATION_MODE_WALKING);
		setToolBarButton(ID_WALKING);
		break;
	case ID_MENUITEM_PAN:
		setOperationMode(PRESPECTIVE_OPERATION_MODE_PAN);
		setToolBarButton(ID_PAN);
		break;
	case ID_MENUITEM_ROT:
		setOperationMode(PRESPECTIVE_OPERATION_MODE_ROTATE);
		setToolBarButton(ID_ROTATE);
		break;
	case ID_MENUITEM_WIREFRAME:
		GetWorld()->setRenderingMode(OGL_RENDERING_WIRE);
		setToolBarButton(ID_RENDERING_WIREFRAME);
		InvalidateRect(NULL);
		UpdateWindow();
		break;
	case ID_MENUITEM_SHADING:
		GetWorld()->setRenderingMode(OGL_RENDERING_SHADE);
		setToolBarButton(ID_RENDERING_SHADE);
		InvalidateRect(NULL);
		UpdateWindow();
		break;
	case ID_MENUITEM_TEXTURING:
		GetWorld()->setRenderingMode(OGL_RENDERING_TEXTURE);
		setToolBarButton(ID_RENDERING_TEXTURE);
		InvalidateRect(NULL);
		UpdateWindow();
		break;
	}
	
	return CView::OnCommand(wParam, lParam);
}
