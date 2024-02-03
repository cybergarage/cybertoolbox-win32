// PerspectiveView.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// PerspectiveView ビュー

#include "SceneGraph.h"

enum {
PRESPECTIVE_MOUSE_MODE_NONE			= 0x00,
PRESPECTIVE_MOUSE_MODE_SELECTING	= 0x01,
PRESPECTIVE_MOUSE_MODE_DRAG			= 0x02,
PRESPECTIVE_MOUSE_MODE_LBUTTONDOWN	= 0x04,
PRESPECTIVE_MOUSE_MODE_RBUTTONDOWN	= 0x08,
};

enum {
PRESPECTIVE_OPERATION_MODE_WALKING,
PRESPECTIVE_OPERATION_MODE_PICKING,
PRESPECTIVE_OPERATION_MODE_ROTATE,
PRESPECTIVE_OPERATION_MODE_PAN,
};

class PerspectiveView : public CView
{
protected:
	PerspectiveView();           // 動的生成に使用されるプロテクト コンストラクタ
	DECLARE_DYNCREATE(PerspectiveView)

// アトリビュート
public:

	PointLightNode	defaultLight;

// オペレーション
public:

	//////////////////////////////////
	// OpenGL
	//////////////////////////////////
	
    CPalette		oglPalette;
    CPalette		*oglOldPalette;
	CClientDC		*oglDC;
	HDC				oglHdc;
	HGLRC			oglHrc;

	void			OGLSetup();
	BOOL			OGLSetupPixelFormat();
	void			OGLCreateRGBPalette();
	unsigned char	OGLComponentFromIndex(int i, UINT nbits, UINT shift);

	//////////////////////////////////
	// Mode
	//////////////////////////////////

	int				mMouseMode;
	void			setMouseMode(int mode)	{mMouseMode = mode;}
	int				getMouseMode()			{return mMouseMode;}

	int				mOperationMode;
	void			setOperationMode(int mode)	{mOperationMode = mode;}
	int				getOperationMode()			{return mOperationMode;}

	ShapeNode		*mSelectedShapeNode;
	void			setSelectedShapeNode(ShapeNode *shape)			{mSelectedShapeNode = shape;}
	ShapeNode		*getSelectedShapeNode()							{return mSelectedShapeNode;}

	TouchSensorNode	*mTouchSensorNode;
	void			setTouchSensorNode(TouchSensorNode *tsensor)	{mTouchSensorNode = tsensor;}
	TouchSensorNode	*getTouchSensorNode()							{return mTouchSensorNode;}

	PlaneSensorNode	*mPlaneSensorNode;
	void			setPlaneSensorNode(PlaneSensorNode *tsensor)	{mPlaneSensorNode = tsensor;}
	PlaneSensorNode	*getPlaneSensorNode()							{return mPlaneSensorNode;}

	//////////////////////////////////
	// Walk
	//////////////////////////////////

	int				mStartMousePos[2];
	int				mMousePos[2];
	float			mSelectedShapeMatrix[4][4];

	void			MoveViewpoint(int mosx, int mosy);

	void			setMousePosition(int x, int y)			{mMousePos[0] = x; mMousePos[1] = y;}
	void			getMousePosition(int &x, int &y)		{x = mMousePos[0]; y = mMousePos[1];}
	int				getMousePositionX()						{return mMousePos[0];}
	int				getMousePositionY()						{return mMousePos[1];}

	void			setStartMousePosition(int x, int y)		{mStartMousePos[0] = x; mStartMousePos[1] = y;}
	void			getStartMousePosition(int &x, int &y)	{x = mStartMousePos[0]; y = mStartMousePos[1];}
	int				getStartMousePositionX()				{return mStartMousePos[0];}
	int				getStartMousePositionY()				{return mStartMousePos[1];}

	void			getWorldPosition(int mousex, int mousey, ShapeNode *selectedShape, float world[3]);

	void			setSelectedShapeMatrix(float value[4][4]);
	void			getSelectedShapeMatrix(float value[4][4]);

	//////////////////////////////
	// ToolBar
	//////////////////////////////

	void		setToolBarButton(int pushedButton);
	BOOL		isButtonEnabled(int id);
	void		enableButton(int id, BOOL bEnable);
	void		pressButton(int id, BOOL bEnable);
	BOOL		isButtonPressed(int id);

	//////////////////////////////
	// HeadLight
	//////////////////////////////

	void		headLightOn();
	void		headLightOff();
	bool		isHeadLightOn();

// オーバーライド
	// ClassWizard は仮想関数を生成しオーバーライドします。
	//{{AFX_VIRTUAL(PerspectiveView)
	public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // このビューを描画するためにオーバーライドしました。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	virtual ~PerspectiveView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(PerspectiveView)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnWalking();
	afx_msg void OnPicking();
	afx_msg void OnZoomview();
	afx_msg void OnRenderingWireframe();
	afx_msg void OnRenderingShade();
	afx_msg void OnHeadlight();
	afx_msg void OnRenderingTexture();
	afx_msg void OnPan();
	afx_msg void OnRotate();
	afx_msg void OnConfig();
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
