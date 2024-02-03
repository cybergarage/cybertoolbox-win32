// CyberToolBoxView.h : CCyberToolBoxView クラスの宣言およびインターフェイスの定義をします。
//
/////////////////////////////////////////////////////////////////////////////

#include "SceneGraph.h"
#include "ModuleFloating.h"

#include "DiagramView.h"
#include "CDiagramWindow.h"

#include "CFontInfo.h"

class Node;

enum {
CTB_ITEMIMAGE_NODE = 54,
CTB_ITEMIMAGE_ROOT,
CTB_ITEMIMAGE_DIAGRAM,
CTB_ITEMIMAGE_EVENTROOT,
CTB_ITEMIMAGE_EVENT,
CTB_ITEMIMAGE_SCENEGRAPH,
CTB_ITEMIMAGE_ROUTE_ROOT,
CTB_ITEMIMAGE_ROUTE,
CTB_ITEMIMAGE_MAX,
};


enum {
CTB_DRAGITEM_NONE,
CTB_DRAGITEM_NODE,
CTB_DRAGITEM_DIAGRAM,
};

enum {
CTB_TREEVIEW_MODE_SIMPLE,
CTB_TREEVIEW_MODE_ALLNODES
};

class PerspectiveView;

class CCyberToolBoxView : public CTreeView
{
protected: // シリアライズ機能のみから作成します。
	CCyberToolBoxView();
	DECLARE_DYNCREATE(CCyberToolBoxView)

// アトリビュート
public:
	CSingleDocTemplate	*mDgmDocTemplate;
	CCyberToolBoxDoc*	GetDocument();

// オペレーション
public:

	//////////////////////////////
	// Licence
	//////////////////////////////

	bool hasLicence(void);
	void updateSaveButton(void);

	//////////////////////////////
	// TreeView Control
	//////////////////////////////

	void		resetTvInsertStruct(TV_INSERTSTRUCT *tvinsert);
	void		setTvInsertStruct(TV_INSERTSTRUCT *tvinsert, char *text, int image, HTREEITEM parent, void *param);
	HTREEITEM	insertTvInsertStruct(char *text, int image, HTREEITEM parent, void *param);

	void	resetSceneGraphTree();
	void	setNodeItem(HTREEITEM item, Node *node);

	char	mNodeName[256];
	char	*getNodeName(Node *node);
	char	*getNodeNameForSimpleTreeMode(Node *node);

	char	mEventName[256];
	char	*getEventName(CEvent *event);

	char	mRouteName[512];
	char	*getRouteName(Route *route);

	Node	*getNode(HTREEITEM treeItem);
	Route	*getRoute(HTREEITEM treeItem);

	CDiagramView	*createDiagramWindow(TransformNode *transform);

	
	HTREEITEM	mRootTreeItem;
	void		setRootTreeItem(HTREEITEM item)			{ mRootTreeItem = item; }
	HTREEITEM	getRootTreeItem()						{ return mRootTreeItem; }

	
	HTREEITEM	mSceneGraphTreeItem;
	void		setSceneGraphTreeItem(HTREEITEM item)	{ mSceneGraphTreeItem = item; }
	HTREEITEM	getSceneGraphTreeItem()					{ return mSceneGraphTreeItem; }

	HTREEITEM	mRouteTreeItem;
	void		setRouteTreeItem(HTREEITEM item)		{ mRouteTreeItem = item; }
	HTREEITEM	getRouteTreeItem()						{ return mRouteTreeItem; }

	HTREEITEM	mSceneGraphObjectTreeItem;
	void		setSceneGraphObjectTreeItem(HTREEITEM item)	{ mSceneGraphObjectTreeItem = item; }
	HTREEITEM	getSceneGraphObjectTreeItem()				{ return mSceneGraphObjectTreeItem; }

	HTREEITEM	mSceneGraphLightTreeItem;
	void		setSceneGraphLightTreeItem(HTREEITEM item)	{ mSceneGraphLightTreeItem = item; }
	HTREEITEM	getSceneGraphLightTreeItem()				{ return mSceneGraphLightTreeItem; }

	HTREEITEM	mSceneGraphViewTreeItem;
	void		setSceneGraphViewTreeItem(HTREEITEM item)	{ mSceneGraphViewTreeItem = item; }
	HTREEITEM	getSceneGraphViewTreeItem()					{ return mSceneGraphViewTreeItem; }

	HTREEITEM	mSceneGraphMaterialTreeItem;
	void		setSceneGraphMaterialTreeItem(HTREEITEM item)	{ mSceneGraphMaterialTreeItem = item; }
	HTREEITEM	getSceneGraphMaterialTreeItem()					{ return mSceneGraphMaterialTreeItem; }

	HTREEITEM	mEventTreeItem;
	void		setEventTreeItem(HTREEITEM item)		{ mEventTreeItem = item; }
	HTREEITEM	getEventTreeItem()						{ return mEventTreeItem; }

	
	LPARAM		getTreeItemParam(HTREEITEM item);
	void		setTreeItemName(HTREEITEM item, char *name);

	void		addSceneGraphNode(Node *node, HTREEITEM parent);
	void		addSceneGraphNodeForSimpleTreeMode(Node *node);
	void		addSceneGraphNode(Node *node, Node *parent);
	void		addRoute(Route *route);
	void		addEventNode(CEvent *event);
	void		addDiagramNode(CEvent *event, CDiagram *diagram);

	void		deleteSceneGraphNode(Node *node);
	void		deleteRoute(Route *node);
	void		deleteEventNode(CEvent *event);
	void		deleteDiagramNode(CDiagram *diagram);

	void		moveSceneGraphNode(Node *node, Node *parentNode);

	//////////////////////////////
	// PerspectiveView
	//////////////////////////////

	void		updatePerspectiveView();
	void		updateOrthoView();
	void		updateViews();

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

	//////////////////////////////
	// Operation
	//////////////////////////////

	BOOL		deleteItem(HTREEITEM item);
	HTREEITEM	moveItem(HTREEITEM hitem, HTREEITEM hNewParent);
	BOOL		isChildNodeOf(HTREEITEM hitemChild, HTREEITEM hitemSuspectedParent);

	//////////////////////////////
	// ImageList
	//////////////////////////////

	CImageList	mItemImageList;
	CBitmap		mItemBitmap[CTB_ITEMIMAGE_MAX];

	void		createImageList();
	CImageList	*getImageList()	{ return &mItemImageList; }

	//////////////////////////////
	// Drag
	//////////////////////////////

	int			mTypeDragItem;
	BOOL		mbDragging;
	HTREEITEM	mhItemDrag;
	HTREEITEM	mhItemDrop;
	CImageList	*mpImagelist;

	//////////////////////////////
	// ToolBar
	//////////////////////////////

	void		setToolBarButton(int pushedButton);
	BOOL		isButtonEnabled(int id);
	void		enableButton(int id, BOOL bEnable);
	void		pressButton(int id, BOOL bEnable);
	BOOL		isButtonPressed(int id);

	//////////////////////////////
	// TreeView mode
	//////////////////////////////

	int mTreeViewMode;

	void	setTreeViewMode(int mode);
	int		getTreeViewMode(void);

// オーバーライド
	// ClassWizard は仮想関数を生成しオーバーライドします。
	//{{AFX_VIRTUAL(CCyberToolBoxView)
	public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画する際にオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void OnInitialUpdate(); // 構築後の最初の１度だけ呼び出されます。
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// インプリメンテーション
public:
	virtual ~CCyberToolBoxView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成されたメッセージ マップ関数
protected:
	//{{AFX_MSG(CCyberToolBoxView)
	afx_msg void OnScenegraphLoad();
	afx_msg void OnScenegraphSave();
	afx_msg void OnScenegraphSaveAs();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDiagramNew();
	afx_msg void OnSimulationGo();
	afx_msg void OnSimulationStop();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnEventNew();
	afx_msg void OnDestroy();
	afx_msg void OnSimulationStep();
	afx_msg void OnFontSetting();
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnBeginlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnScenegraphNew();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnNodeNew();
	afx_msg void On2dwindow();
	afx_msg void On3dwindow();
	afx_msg void OnViewChange();
	afx_msg void OnRouteNew();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // CyberToolBoxView.cpp ファイルがデバッグ環境の時使用されます。
inline CCyberToolBoxDoc* CCyberToolBoxView::GetDocument()
   { return (CCyberToolBoxDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

