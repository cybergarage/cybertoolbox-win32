// DiagramView.h : ヘッダー ファイル
//

/////////////////////////////////////////////////////////////////////////////
// CDiagramView ビュー

#ifndef _CDIAGRAMVIEW_H_
#define _CDIAGRAMVIEW_H_

#include "CDiagram.h"
#include "CFontInfo.h"
#include "TransformNode.h"
#include "CUndoAction.h"
#include "CDiagramClipboard.h"

enum {
DIAGRAM_LINESTYLE_STRAIGHT,
DIAGRAM_LINESTYLE_ZIGZAG
};

class CDiagramView : public CScrollView, public CUndoAction 
{
protected:
	CDiagramView();           // 動的生成に使用されるプロテクト コンストラクタ。
	DECLARE_DYNCREATE(CDiagramView)

// アトリビュート
public:
	TransformNode	*mDiagramNode;
	BOOL			mbDragRect;
	
	void setDiagramNode(TransformNode *diagramNode) {
		mDiagramNode = diagramNode;
		CDiagram diagram(diagramNode);
		updateWindowText();
		updatePosition();
	}

	TransformNode	*getDiagramNode()					{return mDiagramNode;}

	//////////////////////////////////////////////////
	// Clipboard
	//////////////////////////////////////////////////

	static CDiagramClipboard mClipboard;

	CDiagramClipboard *getClipboard() {
		return &mClipboard;
	}

	//////////////////////////////////////////////////
	// Name
	//////////////////////////////////////////////////
	
	char	*getWindowText();
	void	updateWindowText();

	//////////////////////////////////////////////////
	// Selecting Module
	//////////////////////////////////////////////////

	ScriptNode	*mSelectingModule;

	void		setSelectingModule(ScriptNode *module)		{ mSelectingModule = module;}
	ScriptNode	*getSelectingModule()						{ return mSelectingModule;}

	int		getSelectingEventInNode()						{ return (getModuleOperationMode() & MODULE_NODE_NUMBER_MASK); }
	int		getSelectingEventOutNode()						{ return (getModuleOperationMode() & MODULE_NODE_NUMBER_MASK); }

	//////////////////////////////////////////////////
	// Mode
	//////////////////////////////////////////////////

	int		mModuleOperationMode;

	void	setModuleOperationMode(int mode)	{ mModuleOperationMode= mode; }
	int		getModuleOperationMode()			{ return mModuleOperationMode; }

	//////////////////////////////////////////////////
	// Drag Mode
	//////////////////////////////////////////////////

	int		mbDrag;

	void	setDragOn()			{ mbDrag = 1; }
	void	setDragOff()		{ mbDrag = 0; }
	int		isDragging()		{ return mbDrag; }

	//////////////////////////////////////////////////
	// Line Style
	//////////////////////////////////////////////////

	int		mLineStyle;

	void	setLineStyle(int style) { mLineStyle = style; }
	int		getLineStyle()			{ return mLineStyle; }

	//////////////////////////////////////////////////
	// Grid
	//////////////////////////////////////////////////
	
	bool	mGridSnap;
	bool	mGridDisplay;

	void	setGridSnap(bool on)	{ mGridSnap = on; }
	bool	getGridSnap()			{ return mGridSnap; }

	void	setGridDisplay(bool on)	{ mGridDisplay = on; }
	bool	getGridDisplay()		{ return mGridDisplay; }
	
	void	drawText(CDC* pDC, int x, int y, char *string, COLORREF color);
	void	stripText(char *string, char *stripString);
	void	drawGrid(CDC* pDC, int width, int height);
	void	drawLine(CDC* pDC, int sx, int sy, int ex, int ey, bool isXBold, bool isYBold);
	void	drawStraightLine(CDC* pDC, int sx, int sy, int ex, int ey);
	void	drawZigzagLine(CDC* pDC, int outModuleX, int outModuleY, int outNodeX, int outNodeY, int inModuleX, int inModuleY, int inNodeX, int inNodeY, bool isExecutionNode);
	
	//////////////////////////////
	// Mouse
	//////////////////////////////

	int			mxOffset;
	int			myOffset;

	void		setMouseOffset(int x, int y)	{mxOffset = x, myOffset = y;}
	void		getMouseOffset(int *x, int *y)	{*x = mxOffset, *y = myOffset;}

	int			mxStart;
	int			myStart;

	void		setMouseStartPosition(int x, int y)		{mxStart = x, myStart = y;}
	void		getMouseStartPosition(int *x, int *y)	{*x = mxStart, *y = myStart;}

	int			mxEnd;
	int			myEnd;

	void		setMouseEndPosition(int x, int y)	{mxEnd = x, myEnd = y;}
	void		getMouseEndPosition(int *x, int *y)	{*x = mxEnd, *y = myEnd;}

	//////////////////////////////
	// Selecting Box
	//////////////////////////////

	bool		mSelectingBox;
	void		selectingBoxOn()	{mSelectingBox = true;}
	void		selectingBoxOff()	{mSelectingBox = false;}
	bool		isSelectingBoxOn()	{return mSelectingBox;}

	int			mSelectingBoxRect[4];
	void		setSelectingBoxRect(int x0, int y0, int x1, int y1) {
					mSelectingBoxRect[0] = x0;
					mSelectingBoxRect[1] = y0;
					mSelectingBoxRect[2] = x1;
					mSelectingBoxRect[3] = y1;
				}

	void		setSelectingBoxRect(int rect[]) {
					mSelectingBoxRect[0] = rect[0];
					mSelectingBoxRect[1] = rect[1];
					mSelectingBoxRect[2] = rect[2];
					mSelectingBoxRect[3] = rect[3];
				}

	void		getSelectingBoxRect(int *x0, int *y0, int *x1, int *y1) {
					*x0 = mSelectingBoxRect[0];
					*y0 = mSelectingBoxRect[1];
					*x1 = mSelectingBoxRect[2];
					*y1 = mSelectingBoxRect[3];
				}

	void		getSelectingBoxRect(int rect[]) {
					rect[0] = mSelectingBoxRect[0];
					rect[1] = mSelectingBoxRect[1];
					rect[2] = mSelectingBoxRect[2];
					rect[3] = mSelectingBoxRect[3];
				}

	void		copyModulesInSelectingBox(CDiagramClipboard *clipboard);
	void		deleteModulesInSelectingBox();

	//////////////////////////////
	// Size
	//////////////////////////////
	
	void		updateScreenSize();

	//////////////////////////////
	// Position
	//////////////////////////////
	
	void		updatePosition();
	void		savePosition();

	//////////////////////////////
	// Font
	//////////////////////////////

	CFontInfo	*mFontInfo;
	CFont		mFont;
	
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

// オペレーション
public:

// オーバーライド
	// ClassWizard は仮想関数を生成しオーバーライドします。
	//{{AFX_VIRTUAL(CDiagramView)
	public:
	virtual BOOL OnScroll(UINT nScrollCode, UINT nPos, BOOL bDoScroll = TRUE);
	protected:
	virtual void OnDraw(CDC* pDC);      // このビューを描画するためにオーバーライドしました。
	virtual void OnInitialUpdate();     // 構築後、最初の処理。
	//}}AFX_VIRTUAL

// インプリメンテーション
protected:
	virtual ~CDiagramView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// 生成されたメッセージ マップ関数
	//{{AFX_MSG(CDiagramView)
	afx_msg void OnFontSetting();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnUndo();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnDestroy();
	afx_msg void OnDiagramConfig();
	afx_msg void OnEditCopy();
	afx_msg void OnEditCut();
	afx_msg void OnEditPaste();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif

/////////////////////////////////////////////////////////////////////////////
