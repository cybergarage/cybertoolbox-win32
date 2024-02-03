#if !defined(AFX_ORTHOVIEW_H__D5746E03_3AC1_11D1_A8D2_02608CA85C38__INCLUDED_)
#define AFX_ORTHOVIEW_H__D5746E03_3AC1_11D1_A8D2_02608CA85C38__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// OrthoView.h : ヘッダー ファイル
//

#include "CUndoAction.h"
#include "CFontInfo.h"
#include "SceneGraph.h"
#include "World.h"

class PrimitiveFloating;

/////////////////////////////////////////////////////////////////////////////
// OrthoView ビュー

enum {
ORTHO_XY_PLANE = 1,
ORTHO_YZ_PLANE,
ORTHO_XZ_PLANE,
};

enum {
OBJECT_PICK,
OBJECT_ZOOM,
OBJECT_MOVE,
OBJECT_ROTATE,
};

enum {
OPERATION_NONE,
OPERATION_LEFT_DRAG,
OPERATION_RIGHT_DRAG,
OPERATION_PRMITIVE_EDIT_TEXT,
OPERATION_PRMITIVE_EDIT_POLYGON,
};

class ShapeNode;
class SpotLight;
class PointLight;

class OrthoConfig : public CUndoAction {

public:
	
	OrthoConfig() {
		setAxisDisplayOn(true);
		setGridDisplayOn(true);
		setSnapOn(true);
		setSpotLightDisplayOn(false);
		setPointLightDisplayOn(false);
		setShapeDisplayOn(true);
		setViewpointDisplayOn(false);
		setGridSize(1.0f);
		setGridAngle(45.0f);
	}

	bool			axisDisplayOn;
	void			setAxisDisplayOn(bool on)		{ axisDisplayOn = on; }
	bool			isAxisDisplayOn()				{ return axisDisplayOn; }

	bool			gridDisplayOn;
	void			setGridDisplayOn(bool on)		{ gridDisplayOn = on; }
	bool			isGridDisplayOn()				{ return gridDisplayOn; }

	float			gridSize;
	void			setGridSize(float size)			{ gridSize = size; }
	float			getGridSize()					{ return gridSize; }

	float			gridAngle;
	void			setGridAngle(float euler)		{ gridAngle = euler; }
	float			getGridAngle()					{ return gridAngle; }

	bool			snapOn;
	void			setSnapOn(bool on)				{ snapOn = on; }
	bool			isSnapOn()						{ return snapOn; }

	bool			shapeDisplayOn;
	void			setShapeDisplayOn(bool on)		{ shapeDisplayOn = on; }
	bool			isShapeDisplayOn()				{ return shapeDisplayOn; }

	bool			spotLightDisplayOn;
	void			setSpotLightDisplayOn(bool on)	{ spotLightDisplayOn = on; }
	bool			isSpotLightDisplayOn()			{ return spotLightDisplayOn; }

	bool			pointLightDisplayOn;
	void			setPointLightDisplayOn(bool on)	{ pointLightDisplayOn = on; }
	bool			isPointLightDisplayOn()			{ return pointLightDisplayOn; }

	bool			viewpointDisplayOn;
	void			setViewpointDisplayOn(bool on)	{ viewpointDisplayOn = on; }
	bool			isViewpointDisplayOn()			{ return viewpointDisplayOn; }
};

class OrthoView : public CScrollView, public OrthoConfig
{
protected:
	OrthoView();           // 動的生成に使用されるプロテクト コンストラクタ。
	DECLARE_DYNCREATE(OrthoView)

// アトリビュート
public:

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

	//////////////////////////////
	// Font
	//////////////////////////////

	CFontInfo		*mFontInfo;
	CFont			mFont;
	unsigned int	mGLFontID;
	unsigned int	mGLFontOutLineID;
	CDC				*mpCDC;

	void	getFontInfo(LOGFONT *lf)	{ mFontInfo->getInfo(lf); }
	void	setFontInfo(LOGFONT *lf)	{ mFontInfo->setInfo(lf); }

	void	setFont(LOGFONT *lf) {
		mFont.DeleteObject();
		if (mFont.CreateFontIndirect(lf))
		{
			SetFont(&mFont);
			setFontInfo(lf);
		}
	}

	void setGLFontID(unsigned int id) {
		mGLFontID = id; 
	}

	unsigned int getGLFontID(void) { 
		return mGLFontID; 
	}

	void setGLFontOutLineID(unsigned int id) {
		mGLFontOutLineID = id; 
	}

	unsigned int getGLFontOutLineID(void) { 
		return mGLFontOutLineID; 
	}

	void setCDC(CDC *dc) {
		mpCDC = dc;
	}

	CDC *getCDC(void) {
		return mpCDC;
	}

	//////////////////////////////////
	// PrimitiveFloating
	//////////////////////////////////

	PrimitiveFloating	*mPrimitiveFloating;
	PrimitiveFloating	*getPrimitiveFloating()	{return mPrimitiveFloating;}
	
	//////////////////////////////////
	// Operation
	//////////////////////////////////

	float			mScale;
	void			setScale(float scale)	{ if (0.01f <= scale && scale <= 100.0f) mScale = scale; }
	float			getScale()				{ return mScale; }

	float			mStartScale;
	void			setStartScale(float scale)	{ mStartScale = scale; }
	float			getStartScale()				{ return mStartScale; }

	int				mViewMode;
	void			setViewMode(int mode)	{ mViewMode = mode; }
	int				getViewMode()			{ return mViewMode; }

	int				mObjectMode;
	void			setObjectMode(int mode)	{ mObjectMode = mode; }
	int				getObjectMode()			{ return mObjectMode; }

	float			mOffset[3];
	void			setOffset(float x, float y, float z)	{ mOffset[0] = x; mOffset[1] = y; mOffset[2] = z; }
	void			getOffset(float &x, float &y, float &z)	{ x = mOffset[0]; y = mOffset[1]; z = mOffset[2]; }
	void			setOffset(float offset[3])				{ mOffset[0] = offset[0]; mOffset[1] = offset[1]; mOffset[2] = offset[2]; }
	void			getOffset(float offset[3])				{ offset[0] = mOffset[0]; offset[1] = mOffset[1]; offset[2] = mOffset[2]; }

	float			mStartOffset[3];
	void			setStartOffset(float x, float y, float z)		{ mStartOffset[0] = x; mStartOffset[1] = y; mStartOffset[2] = z; }
	void			getStartOffset(float &x, float &y, float &z)	{ x = mStartOffset[0]; y = mStartOffset[1]; z = mStartOffset[2]; }
	void			setStartOffset(float offset[3])					{ mStartOffset[0] = offset[0]; mStartOffset[1] = offset[1]; mStartOffset[2] = offset[2]; }
	void			getStartOffset(float offset[3])					{ offset[0] = mStartOffset[0]; offset[1] = mStartOffset[1]; offset[2] = mStartOffset[2]; }

	void			setSelectedShapeNode(ShapeNode *shape)			{ GetWorld()->getSceneGraph()->setSelectedShapeNode(shape); }	
	ShapeNode			*getSelectedShapeNode()						{ return GetWorld()->getSceneGraph()->getSelectedShapeNode(); }	

	void			setSelectedTransformNode(TransformNode *trans)	{ GetWorld()->getSceneGraph()->setSelectedNode(trans); }	
	TransformNode	*getSelectedTransformNode()					{ return (TransformNode *)GetWorld()->getSceneGraph()->getSelectedNode(); }	

	float			mStartTransformTranslation[3];
	void			setStartTransformTranslation(float x, float y, float z)		{ mStartTransformTranslation[0] = x; mStartTransformTranslation[1] = y; mStartTransformTranslation[2] = z; }
	void			getStartTransformTranslation(float &x, float &y, float &z)	{ x = mStartTransformTranslation[0]; y = mStartTransformTranslation[1]; z = mStartTransformTranslation[2]; }
	void			setStartTransformTranslation(float translation[3])			{ mStartTransformTranslation[0] = translation[0]; mStartTransformTranslation[1] = translation[1]; mStartTransformTranslation[2] = translation[2]; }
	void			getStartTransformTranslation(float translation[3])			{ translation[0] = mStartTransformTranslation[0]; translation[1] = mStartTransformTranslation[1]; translation[2] = mStartTransformTranslation[2]; }

	float			mStartTransformRotation[3];
	void			setStartTransformRotation(float x, float y, float z, float angle)		{ mStartTransformRotation[0] = x; mStartTransformRotation[1] = y; mStartTransformRotation[2] = z; mStartTransformRotation[3] = angle;}
	void			getStartTransformRotation(float &x, float &y, float &z, float &angle)	{ x = mStartTransformRotation[0]; y = mStartTransformRotation[1]; z = mStartTransformRotation[2]; angle = mStartTransformRotation[3]; }
	void			setStartTransformRotation(float rotation[4])							{ mStartTransformRotation[0] = rotation[0]; mStartTransformRotation[1] = rotation[1]; mStartTransformRotation[2] = rotation[2]; mStartTransformRotation[3] = rotation[3];}
	void			getStartTransformRotation(float rotation[4])							{ rotation[0] = mStartTransformRotation[0]; rotation[1] = mStartTransformRotation[1]; rotation[2] = mStartTransformRotation[2]; rotation[3] = mStartTransformRotation[3];}

	float			mStartTransformScale[3];
	void			setStartTransformScale(float x, float y, float z)		{ mStartTransformScale[0] = x; mStartTransformScale[1] = y; mStartTransformScale[2] = z;}
	void			getStartTransformScale(float &x, float &y, float &z)	{ x = mStartTransformScale[0]; y = mStartTransformScale[1]; z = mStartTransformScale[2];}
	void			setStartTransformScale(float Scale[3])					{ mStartTransformScale[0] = Scale[0]; mStartTransformScale[1] = Scale[1]; mStartTransformScale[2] = Scale[2];}
	void			getStartTransformScale(float Scale[3])					{ Scale[0] = mStartTransformScale[0]; Scale[1] = mStartTransformScale[1]; Scale[2] = mStartTransformScale[2];}

	int				mouse[2];

	int				mOperationMode;
	void			setOperationMode(int mode)	{ mOperationMode = mode; }
	int				getOperationMode()			{ return mOperationMode; }

	void			getLocalExtents(float x[2], float y[2], float z[2]);

	void			windowToWorld(int x, int y, float &wx, float &wy, float &wz);
	void			worldToWindow(float wx, float wy, float wz, int &x, int &y);
	void			worldToWindow(float wx, float wy, float wz, long &x, long &y);

	float			windowToWorld(int size);
	int				worldToWindow(float size);

	int				mouseStart[2];
	bool			dragStart;

	void			transformToSnapPositoin(float &localx, float &localy);
	void			transformToSnapdAngle(float &eulerAngle);
	void			transformToSnapMousePositoin(int &mousex, int &mousey);

	//////////////////////////////
	// Scene Extents
	//////////////////////////////

	float			mSceneBoundingBoxSize[3];
	float			mSceneBoundingBoxCenter[3];
	
	void setSceneBoundingBoxSize(float size[3]) {
		mSceneBoundingBoxSize[0] = size[0];
		mSceneBoundingBoxSize[1] = size[1];
		mSceneBoundingBoxSize[2] = size[2];
	}

	void getSceneBoundingBoxSize(float size[3]) {
		size[0] = mSceneBoundingBoxSize[0];
		size[1] = mSceneBoundingBoxSize[1];
		size[2] = mSceneBoundingBoxSize[2];
	}

	void setSceneBoundingBoxCenter(float center[3]) {
		mSceneBoundingBoxCenter[0] = center[0];
		mSceneBoundingBoxCenter[1] = center[1];
		mSceneBoundingBoxCenter[2] = center[2];
	}

	void getSceneBoundingBoxCenter(float center[3]) {
		center[0] = mSceneBoundingBoxCenter[0];
		center[1] = mSceneBoundingBoxCenter[1];
		center[2] = mSceneBoundingBoxCenter[2];
	}

	//////////////////////////////
	// ToolBar
	//////////////////////////////

	void		setToolBarButton(int pushedButton);
	BOOL		isButtonEnabled(int id);
	void		enableButton(int id, BOOL bEnable);
	void		pressButton(int id, BOOL bEnable);
	BOOL		isButtonPressed(int id);

	//////////////////////////////
	//	StatusBar
	//////////////////////////////

	void		setStatusBar(float x, float y, float z);

	//////////////////////////////
	//	OpenGL
	//////////////////////////////

	void		drawSceneGraph(bool selectionMode);
	void		drawText(float x, float y, char *string);
	void		drawOutLineText(float x, float y, char *string);
	void		drawOutLineTextBaseLine();
	void		drawGridText(float x2d[], float y2d[]);
	void		drawGrid(float x2d[], float y2d[]);
	void		drawViewpoint2D();
	void		drawViewpoint3D();
	void		drawLights();
	void		drawSpotLight2D(SpotLightNode *light);
	void		drawPointLight2D(PointLightNode *light);
	void		drawDirectionalLight2D(DirectionalLightNode *light);
	void		drawSpotLight3D(SpotLightNode *light);
	void		drawPointLight3D(PointLightNode *light);
	void		drawDirectionalLight3D(DirectionalLightNode *light);
	void		drawCircle(float cx, float cy, float cz, float radius, float lineWidth, float r, float g, float b);
	void		drawLine(float cx, float cy, float cz, float dirx, float diry, float dirz, float minScale, float maxScale, float lineSize, float lineWidth, float r, float g, float b);
	ShapeNode	*pickShapeNode(int mx, int my);

	//////////////////////////////
	//	Mutex
	//////////////////////////////

	HANDLE		mhMutexObject;

	void		initializeMutexObject()	{ mhMutexObject = CreateMutex(NULL, FALSE, "ORTHVIEW_MUTEXOBJECT"); } 
	void		closeMutexObject()		{ CloseHandle(mhMutexObject); } 
	DWORD		waitForMutexObject()	{ return WaitForSingleObject(mhMutexObject, INFINITE); }
	BOOL		releaseMutexObject()	{ return ReleaseMutex(mhMutexObject); }

	//////////////////////////////
	//	Primitive Editing
	//////////////////////////////

	TransformNode	*mEditPrimitiveTransformNode;

	void setEditPrimitiveTransformNode(TransformNode *trans) {
		mEditPrimitiveTransformNode = trans;
	}

	TransformNode *getEditPrimitiveTransformNode() {
		return mEditPrimitiveTransformNode;
	}

	GeometryNode *getEditPrimitiveGeometryNode() {
		return (GeometryNode *)getEditPrimitiveTransformNode()->getShapeNodes()->getGeometryNode();
	}

	bool				get2DLineIntersectionPoint(float &dec1, float &offset1, float &dec2, float &offset2, float pos[2]);
	bool				is2DPointOnLine(float linePos1[3], float linePos2[3], float pos[2]);
	bool				is2DLineParallelOnYAxis(float pos1[3], float pos[3]);
	bool				is2DPointOverYAxis(float linePos1[3], float linePos2[3], float pos[2]);
	void				get2DLineParameter(float pos1[3], float pos[3], float &dec, float &offset);
	void				get2DPoint(float pos[3], float &x, float &y);
	bool				check2DLinesCross(float pos1Start[3], float pos1End[3], float pos2Start[3], float pos2End[3]);
	void				polygonEditCheckPointSetFrontFace(IndexedLineSetNode *lineSet);
	void				polygonEditAddSideSurface(IndexedFaceSetNode *faceSet, int index[]);
	IndexedFaceSetNode	*polygonEditCreateIndexedFaceSet(IndexedLineSetNode *lineSet);
	bool				isPolygonLineConvex(IndexedLineSetNode *lineSet);
	void				undoPolygonEdit();
	
	bool				polygonEditCheckCrossLine(IndexedLineSetNode *lineSet, float x, float y, float z);
	
// オーバーライド
	// ClassWizard は仮想関数のオーバーライドを生成します。
	//{{AFX_VIRTUAL(OrthoView)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void OnDraw(CDC* pDC);      // このビューを描画するためにオーバーライドしました。
	virtual void OnInitialUpdate();     // 構築後、最初の処理。
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	virtual ~OrthoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(OrthoView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnObjectPick();
	afx_msg void OnObjectMove();
	afx_msg void OnObjectZoom();
	afx_msg void OnXyView();
	afx_msg void OnXzView();
	afx_msg void OnYzView();
	afx_msg void OnZoomall();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnUndo();
	afx_msg void OnSnap();
	afx_msg void OnGrid();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnConfig();
	afx_msg void OnObjectRotate();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio は前行の直前に追加の宣言を挿入します。

#endif // !defined(AFX_ORTHOVIEW_H__D5746E03_3AC1_11D1_A8D2_02608CA85C38__INCLUDED_)
