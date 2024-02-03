// CyberToolBoxView.cpp : CCyberToolBoxView クラスの動作の定義を行います。
//

#include "stdafx.h"
#include "CyberToolBox.h"

#include "CyberToolBoxDoc.h"
#include "CyberToolBoxView.h"
#include "MainFrm.h"

#include "CModuleType.h"
#include "RegKey.h"
#include "File.h"

#include "DiagramView.h"
#include "DiagramFrame.h"
#include "DiagramDoc.h"
#include "DiagramNew.h"
#include "CDiagram.h"
#include "World.h"
#include "StringFn.h"

#include "DialogNewUserEvent.h"

#include "DialogNodeConfig.h"
#include "DialogNodeConfig.h"
#include "DialogDiagram.h"

#include "DialogProgress.h"

#include "DialogNodeNew.h"

#include "DialogEventArea.h"
#include "DialogEventPickup.h"
#include "DialogEventFrame.h"
#include "DialogEventClock.h"
#include "DialogEventDrag.h"
#include "DialogEventTimer.h"

#include "DialogRouteInfo.h"

#include <GL/gl.h>
#include "PerspectiveView.h"
#include "OrthoView.h"

#include "LicenceCode.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxView

IMPLEMENT_DYNCREATE(CCyberToolBoxView, CTreeView)

BEGIN_MESSAGE_MAP(CCyberToolBoxView, CTreeView)
	//{{AFX_MSG_MAP(CCyberToolBoxView)
	ON_COMMAND(ID_SCENEGRAPH_LOAD, OnScenegraphLoad)
	ON_COMMAND(ID_SCENEGRAPH_SAVE, OnScenegraphSave)
	ON_COMMAND(ID_SCENEGRAPH_SAVE_AS, OnScenegraphSaveAs)
	ON_WM_CREATE()
	ON_COMMAND(ID_DIAGRAM_NEW, OnDiagramNew)
	ON_COMMAND(ID_SIMULATION_GO, OnSimulationGo)
	ON_COMMAND(ID_SIMULATION_STOP, OnSimulationStop)
	ON_WM_TIMER()
	ON_COMMAND(ID_EVENT_NEW, OnEventNew)
	ON_WM_DESTROY()
	ON_COMMAND(ID_SIMULATION_STEP, OnSimulationStep)
	ON_COMMAND(ID_FONT_SETTING, OnFontSetting)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	ON_WM_LBUTTONDBLCLK()
	ON_NOTIFY_REFLECT(TVN_BEGINLABELEDIT, OnBeginlabeledit)
	ON_NOTIFY_REFLECT(TVN_ENDLABELEDIT, OnEndlabeledit)
	ON_COMMAND(ID_SCENEGRAPH_NEW, OnScenegraphNew)
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_NOTIFY_REFLECT(TVN_BEGINDRAG, OnBegindrag)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_NODE_NEW, OnNodeNew)
	ON_COMMAND(ID_2DWINDOW, On2dwindow)
	ON_COMMAND(ID_3DWINDOW, On3dwindow)
	ON_COMMAND(ID_VIEW_CHANGE, OnViewChange)
	ON_COMMAND(ID_ROUTE_NEW, OnRouteNew)
	//}}AFX_MSG_MAP
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CTreeView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CTreeView::OnFilePrintPreview)
END_MESSAGE_MAP()

#include "World.h"

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxView クラスの構築/消滅

CCyberToolBoxView::CCyberToolBoxView()
{
	// TODO: この場所に構築用のコードを追加してください。

	((CCyberToolBoxApp *)AfxGetApp())->mTreeView = this;

	mFontInfo = new CFontInfo(FONT_TYPE_SCENEGRAPH);

	setTreeViewMode(CTB_TREEVIEW_MODE_ALLNODES);
	
	mpImagelist = NULL;
	mbDragging = FALSE;
}

CCyberToolBoxView::~CCyberToolBoxView()
{
	delete	mFontInfo;
}

BOOL CCyberToolBoxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CTreeView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxView クラスの描画

void CCyberToolBoxView::OnDraw(CDC* pDC)
{
	CCyberToolBoxDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
}

void CCyberToolBoxView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO:  GetTreeCtrl() メンバ関数の呼び出しを通して直接そのリスト コントロールに
	//  アクセスすることによって TreeView をアイテムで固定できます。
	pressButton(ID_2DWINDOW, TRUE);
	pressButton(ID_3DWINDOW, TRUE);
}

/////////////////////////////////////////////////////
//	ImageList
/////////////////////////////////////////////////////

int GetImageListNodeNumber(Node *node)
{
	if (node->isAnchorNode())
		return 0;
	if (node->isAppearanceNode())
		return 1;
	if (node->isAudioClipNode())
		return 2;
	if (node->isBackgroundNode())
		return 3;
	if (node->isBillboardNode())
		return 4;
	if (node->isBoxNode())
		return 5;
	if (node->isCollisionNode())
		return 6;
	if (node->isColorNode())
		return 7;
	if (node->isColorInterpolatorNode())
		return 8;
	if (node->isConeNode())
		return 9;
	if (node->isCoordinateNode())
		return 10;
	if (node->isCoordinateInterpolatorNode())
		return 11;
	if (node->isCylinderNode())
		return 12;
	if (node->isCylinderSensorNode())
		return 13;
	if (node->isDirectionalLightNode())
		return 14;
	if (node->isElevationGridNode())
		return 15;
	if (node->isExtrusionNode())
		return 16;
	if (node->isFogNode())
		return 17;
	if (node->isFontStyleNode())
		return 18;
	if (node->isGroupNode())
		return 19;
	if (node->isImageTextureNode())
		return 20;
	if (node->isIndexedFaceSetNode())
		return 21;
	if (node->isIndexedLineSetNode())
		return 22;
	if (node->isInlineNode())
		return 23;
	if (node->isLodNode())
		return 24;
	if (node->isMaterialNode())
		return 25;
	if (node->isMovieTextureNode())
		return 26;
	if (node->isNavigationInfoNode())
		return 27;
	if (node->isNormalNode())
		return 28;
	if (node->isNormalInterpolatorNode())
		return 29;
	if (node->isOrientationInterpolatorNode())
		return 30;
	if (node->isPixelTextureNode())
		return 31;
	if (node->isPlaneSensorNode())
		return 32;
	if (node->isPointLightNode())
		return 33;
	if (node->isPointSetNode())
		return 34;
	if (node->isPositionInterpolatorNode())
		return 35;
	if (node->isProximitySensorNode())
		return 36;
	if (node->isScalarInterpolatorNode())
		return 37;
	if (node->isScriptNode())
		return 38;
	if (node->isShapeNode())
		return 39;
	if (node->isSoundNode())
		return 40;
	if (node->isSphereNode())
		return 41;
	if (node->isSphereSensorNode())
		return 42;
	if (node->isSpotLightNode())
		return 43;
	if (node->isSwitchNode())
		return 44;
	if (node->isTextNode())
		return 45;
	if (node->isTextureCoordinateNode())
		return 46;
	if (node->isTextureTransformNode())
		return 47;
	if (node->isTimeSensorNode())
		return 48;
	if (node->isTouchSensorNode())
		return 49;
	if (node->isTransformNode())
		return 50;
	if (node->isViewpointNode())
		return 51;
	if (node->isVisibilitySensorNode())
		return 52;
	if (node->isWorldInfoNode())
		return 53;

	return -1;
}

void CCyberToolBoxView::createImageList()
{
	COLORREF bitMask = RGB(0, 0, 0);
	mItemImageList.Create(16, 16, ILC_COLOR8, 0, CTB_ITEMIMAGE_MAX);

	mItemBitmap[0].LoadBitmap(IDB_ANCHOR);
	mItemBitmap[1].LoadBitmap(IDB_APPEARANCE);
	mItemBitmap[2].LoadBitmap(IDB_AUDIOCLIP);
	mItemBitmap[3].LoadBitmap(IDB_BACKGROUND);
	mItemBitmap[4].LoadBitmap(IDB_BILLBOARD);
	mItemBitmap[5].LoadBitmap(IDB_BOX);
	mItemBitmap[6].LoadBitmap(IDB_COLLISION);
	mItemBitmap[7].LoadBitmap(IDB_COLOR);
	mItemBitmap[8].LoadBitmap(IDB_COLORINTERP);
	mItemBitmap[9].LoadBitmap(IDB_CONE);
	mItemBitmap[10].LoadBitmap(IDB_COORDINATE);
	mItemBitmap[11].LoadBitmap(IDB_COORDINTERP);
	mItemBitmap[12].LoadBitmap(IDB_CYLINDER);
	mItemBitmap[13].LoadBitmap(IDB_CYLINDERSENSOR);
	mItemBitmap[14].LoadBitmap(IDB_DLIGHT);
	mItemBitmap[15].LoadBitmap(IDB_ELEVATIONGRID);
	mItemBitmap[16].LoadBitmap(IDB_EXTRUSION);
	mItemBitmap[17].LoadBitmap(IDB_FOG);
	mItemBitmap[18].LoadBitmap(IDB_FONTSTYLE);
	mItemBitmap[19].LoadBitmap(IDB_GROUP);
	mItemBitmap[20].LoadBitmap(IDB_IMAGETEXTURE);
	mItemBitmap[21].LoadBitmap(IDB_IDXFACESET);
	mItemBitmap[22].LoadBitmap(IDB_IDXLINESET);
	mItemBitmap[23].LoadBitmap(IDB_INLINE);
	mItemBitmap[24].LoadBitmap(IDB_LOD);
	mItemBitmap[25].LoadBitmap(IDB_MATERIAL);
	mItemBitmap[26].LoadBitmap(IDB_MOVIETEXTURE);
	mItemBitmap[27].LoadBitmap(IDB_NAVIGATIONINFO);
	mItemBitmap[28].LoadBitmap(IDB_NORMAL);
	mItemBitmap[29].LoadBitmap(IDB_NORMALINTERP);
	mItemBitmap[30].LoadBitmap(IDB_ORIENTATIONINTERP);
	mItemBitmap[31].LoadBitmap(IDB_PIXELTEXTURE);
	mItemBitmap[32].LoadBitmap(IDB_PLANESENSOR);
	mItemBitmap[33].LoadBitmap(IDB_PLIGHT);
	mItemBitmap[34].LoadBitmap(IDB_POINTSET);
	mItemBitmap[35].LoadBitmap(IDB_POSITIONINTERP);
	mItemBitmap[36].LoadBitmap(IDB_PROXIMITYSENSOR);
	mItemBitmap[37].LoadBitmap(IDB_SCALARINTERP);
	mItemBitmap[38].LoadBitmap(IDB_SCRIPT);
	mItemBitmap[39].LoadBitmap(IDB_SHAPE);
	mItemBitmap[40].LoadBitmap(IDB_SOUND);
	mItemBitmap[41].LoadBitmap(IDB_SPHERE);
	mItemBitmap[42].LoadBitmap(IDB_SPHERESENSOR);
	mItemBitmap[43].LoadBitmap(IDB_SLIGHT);
	mItemBitmap[44].LoadBitmap(IDB_SWITCH);
	mItemBitmap[45].LoadBitmap(IDB_TEXT);
	mItemBitmap[46].LoadBitmap(IDB_TEXCOORD);
	mItemBitmap[47].LoadBitmap(IDB_TEXTRANSFORM);
	mItemBitmap[48].LoadBitmap(IDB_TIMESENSOR);
	mItemBitmap[49].LoadBitmap(IDB_TOUCHSENSOR);
	mItemBitmap[50].LoadBitmap(IDB_TRANSFORM);
	mItemBitmap[51].LoadBitmap(IDB_VIEWPOINT);
	mItemBitmap[52].LoadBitmap(IDB_VISIVILITYSENSOR);
	mItemBitmap[53].LoadBitmap(IDB_WORLDINFO);

	mItemBitmap[CTB_ITEMIMAGE_ROOT].LoadBitmap(IDB_ROOT);
	mItemBitmap[CTB_ITEMIMAGE_NODE].LoadBitmap(IDB_NODE);
	mItemBitmap[CTB_ITEMIMAGE_DIAGRAM].LoadBitmap(IDB_DIAGRAM);
	mItemBitmap[CTB_ITEMIMAGE_EVENTROOT].LoadBitmap(IDB_EVENTROOT);
	mItemBitmap[CTB_ITEMIMAGE_EVENT].LoadBitmap(IDB_EVENT);
	mItemBitmap[CTB_ITEMIMAGE_SCENEGRAPH].LoadBitmap(IDB_SCENEGRAPH);
	mItemBitmap[CTB_ITEMIMAGE_ROUTE_ROOT].LoadBitmap(IDB_ROUTE_ROOT);
	mItemBitmap[CTB_ITEMIMAGE_ROUTE].LoadBitmap(IDB_ROUTE);
		
	for (int n = 0; n<CTB_ITEMIMAGE_MAX; n++)
	  mItemImageList.Add(&mItemBitmap[n], bitMask);
}

/////////////////////////////////////////////////////////////////////////////
//	TreeView Controle
/////////////////////////////////////////////////////////////////////////////

#define DATE_LICENCE	1

bool CCyberToolBoxView::hasLicence(void)
{
#ifndef USE_LICENCE_CHK
	return true;
#endif

#ifdef DATE_LICENCE
	time_t osBinaryTime; 
	time(&osBinaryTime);
	CTime todayTime(osBinaryTime);
	CTime expireDataoTime(1999, 7, 1, 0, 0 ,0, 0);
	if (todayTime.GetTime() < expireDataoTime.GetTime())
		return true;
	return false;
#else
	char licenceCode[64];
	RegKeyGetValue(REGKEY_SECTION_LICENCE, REGKEY_KEY_LICENCE_CODE, licenceCode);
	return CheckLicenceCode(licenceCode);
#endif
}

void CCyberToolBoxView::updateSaveButton(void)
{
	enableButton(ID_SCENEGRAPH_SAVE, hasLicence());
}

/////////////////////////////////////////////////////////////////////////////
//	TreeView Controle
/////////////////////////////////////////////////////////////////////////////

void CCyberToolBoxView::resetTvInsertStruct(TV_INSERTSTRUCT *tvinsert)
{
    tvinsert->hParent = NULL;
    tvinsert->hInsertAfter = TVI_LAST;
    tvinsert->item.mask = TVIF_STATE | TVIF_TEXT | TVIF_PARAM | TVIF_IMAGE | TVIF_SELECTEDIMAGE ;
    tvinsert->item.hItem = NULL;
    tvinsert->item.state = 0;
    tvinsert->item.stateMask = 0;
    tvinsert->item.cchTextMax = 32;
    tvinsert->item.cChildren = 0;
    tvinsert->item.lParam = 0;
}

void CCyberToolBoxView::setTvInsertStruct(TV_INSERTSTRUCT *tvinsert, char *text, int image, HTREEITEM parent, void *param)
{
	resetTvInsertStruct(tvinsert);
    tvinsert->item.pszText = text;
	tvinsert->item.iImage = tvinsert->item.iSelectedImage = image;
	tvinsert->hParent = parent;
	tvinsert->item.lParam = (LPARAM)param;
}

HTREEITEM CCyberToolBoxView::insertTvInsertStruct(char *text, int image, HTREEITEM parent, void *param)
{
	TV_INSERTSTRUCT	tvinsert;
    CTreeCtrl &pTree = GetTreeCtrl();
	setTvInsertStruct(&tvinsert, text, image, parent, param);
	return pTree.InsertItem(&tvinsert);
}

void CCyberToolBoxView::addSceneGraphNode(Node *node, HTREEITEM parent)
{
	if (GetWorld()->isSystemNode(node))
		return;

	HTREEITEM treeItem = insertTvInsertStruct(getNodeName(node), GetImageListNodeNumber(node), parent, node);
	
	node->setValue(treeItem);

	if (node->isInstanceNode() == false && node->isInlineNode() == false) {
		for (Node *cnode=node->getChildNodes(); cnode; cnode=cnode->next())
			addSceneGraphNode(cnode, treeItem);
	}

	InvalidateRect(NULL); UpdateWindow();
}

void CCyberToolBoxView::addSceneGraphNodeForSimpleTreeMode(Node *node)
{
	if (GetWorld()->isSystemNode(node))
		return;

	if (node->isInstanceNode() == true)
		return;

	HTREEITEM parentItem = NULL;
			
	if (node->isViewpointNode()) 
		parentItem = getSceneGraphViewTreeItem();
	else if (node->isLightNode()) 
		parentItem = getSceneGraphLightTreeItem();
	else if (node->isTransformNode()) 
		parentItem = getSceneGraphObjectTreeItem();
	else if (node->isMaterialNode()) 
		parentItem = getSceneGraphMaterialTreeItem();
	
	if (parentItem == NULL) 
		return;

	HTREEITEM treeItem = insertTvInsertStruct(getNodeNameForSimpleTreeMode(node), GetImageListNodeNumber(node), parentItem, node);
	node->setValue(treeItem);

	InvalidateRect(NULL); UpdateWindow();
}

void CCyberToolBoxView::addSceneGraphNode(Node *node, Node *parentNode)
{
	switch (getTreeViewMode()) {
	case CTB_TREEVIEW_MODE_ALLNODES:
		{
			HTREEITEM parentItem = NULL;

			if (parentNode == NULL)
				parentItem = getSceneGraphTreeItem();
			else
				parentItem = (HTREEITEM)parentNode->getValue();

			//assert(parentItem); // Instance node has no parent item.
	
			if (parentItem) 
				addSceneGraphNode(node, parentItem);
		}
		break;
	case CTB_TREEVIEW_MODE_SIMPLE:
		{
			addSceneGraphNodeForSimpleTreeMode(node);
		}
		break;
	}
}

void CCyberToolBoxView::deleteSceneGraphNode(Node *deleteNode)
{
	HTREEITEM item = (HTREEITEM)deleteNode->getValue();
	if (item) {
		CTreeCtrl	&pTree = GetTreeCtrl();
		pTree.DeleteItem(item);
		deleteNode->setValue(NULL);
	}

	Node *node = GetWorld()->getSceneGraph()->getNodes();
	while (node != NULL) {
		Node *nextNode = node->nextTraversal();
		if (node->isInstanceNode() == true) {
			if (node->getReferenceNode() == deleteNode) {
				HTREEITEM item = (HTREEITEM)node->getValue();
				if (item) {
					CTreeCtrl	&pTree = GetTreeCtrl();
					pTree.DeleteItem(item);
					node->setValue(NULL);
				}
			}
		}
		node = nextNode;
	}
}

void CCyberToolBoxView::deleteRoute(Route *deleteRoute)
{
	HTREEITEM item = (HTREEITEM)deleteRoute->getValue();
	if (item) {
		CTreeCtrl	&pTree = GetTreeCtrl();
		pTree.DeleteItem(item);
		deleteRoute->setValue(NULL);
	}
}

void CCyberToolBoxView::moveSceneGraphNode(Node *node, Node *parentNode)
{
	CTreeCtrl	&pTree = GetTreeCtrl();
	HTREEITEM	nodeItem;
	HTREEITEM	parentNodeItem;
	HTREEITEM	newNodeItem;

	nodeItem		= (HTREEITEM)node->getValue();

	if (parentNode != NULL)
		parentNodeItem	= (HTREEITEM)parentNode->getValue();
	else
		parentNodeItem = getSceneGraphTreeItem();

	newNodeItem = moveItem(nodeItem, parentNodeItem);

	node->setValue(newNodeItem);

	for (Node *childNode=node->getChildNodes(); childNode != NULL; childNode=childNode->next())
		moveSceneGraphNode(childNode, node);

	pTree.DeleteItem(nodeItem);
}

char *CCyberToolBoxView::getRouteName(Route *route)
{
	char	*outNodeName = route->getEventOutNode()->getName();
	char	*outFieldName = route->getEventOutField()->getName();
	char	*inNodeName = route->getEventInNode()->getName();
	char	*inFieldName = route->getEventInField()->getName();
	sprintf(mRouteName, "%s.%s TO %s.%s", outNodeName, outFieldName, inNodeName, inFieldName);
	return mRouteName;
}

void CCyberToolBoxView::addRoute(Route *route)
{
	if (GetWorld()->isSystemRoute(route) == true)
		return;
	HTREEITEM routeItem = insertTvInsertStruct(getRouteName(route), CTB_ITEMIMAGE_ROUTE, getRouteTreeItem(), route);
	route->setValue(routeItem);
}

void CCyberToolBoxView::addDiagramNode(CEvent *event, CDiagram *diagram)
{
	char			dgmName[128];

	Node			*eventNode = event->getNode();
	HTREEITEM		eventItem = (HTREEITEM)eventNode->getValue();
	TransformNode	*diagramNode = diagram->getTransformNode();

	strcpy(dgmName, diagram->getName());
	HTREEITEM dgmItem = insertTvInsertStruct(dgmName, CTB_ITEMIMAGE_DIAGRAM, eventItem, diagramNode);
	diagramNode->setValue(dgmItem);

	InvalidateRect(NULL); UpdateWindow();
}

void CCyberToolBoxView::addEventNode(CEvent *event)
{
	char	*eventName = getEventName(event);
	Node	*eventNode = event->getNode();

	HTREEITEM eventItem = insertTvInsertStruct(eventName, CTB_ITEMIMAGE_EVENT, getEventTreeItem(), eventNode);
	eventNode->setValue(eventItem);

	for (TransformNode *transform=GetWorld()->getDiagramNodes(); transform; transform=GetWorld()->nextDiagramNode(transform)) {
		CDiagram	diagram(transform);
		if (eventNode == diagram.getEventNode())
			addDiagramNode(event, &diagram);
	}
}

void CCyberToolBoxView::resetSceneGraphTree()
{
    CTreeCtrl &pTree = GetTreeCtrl();
	pTree.DeleteAllItems();

	// Root
	HTREEITEM rootItem = insertTvInsertStruct("World", CTB_ITEMIMAGE_ROOT, NULL, NULL);
	setRootTreeItem(rootItem);

	// SceneGraph 
	HTREEITEM sgItem = insertTvInsertStruct("SceneGraph", CTB_ITEMIMAGE_SCENEGRAPH, rootItem, NULL);
	setSceneGraphTreeItem(sgItem);

	if (getTreeViewMode() == CTB_TREEVIEW_MODE_SIMPLE) {
		setSceneGraphObjectTreeItem(insertTvInsertStruct("Object", CTB_ITEMIMAGE_SCENEGRAPH, sgItem, NULL));
		setSceneGraphMaterialTreeItem(insertTvInsertStruct("Material", CTB_ITEMIMAGE_SCENEGRAPH, sgItem, NULL));
		setSceneGraphViewTreeItem(insertTvInsertStruct("View", CTB_ITEMIMAGE_SCENEGRAPH, sgItem, NULL));
		setSceneGraphLightTreeItem(insertTvInsertStruct("Light", CTB_ITEMIMAGE_SCENEGRAPH, sgItem, NULL));
	}

	SceneGraph *sceneGraph = GetWorld()->getSceneGraph();
	switch (getTreeViewMode()) {
	case CTB_TREEVIEW_MODE_ALLNODES:
		{
			for (Node *node=sceneGraph->getNodes(); node; node=node->next())
				addSceneGraphNode(node, sgItem);
		}
		break;
	case CTB_TREEVIEW_MODE_SIMPLE:
		{
			for (Node *node=sceneGraph->getNodes(); node; node=node->nextTraversal())
				addSceneGraphNodeForSimpleTreeMode(node);
		}
		break;
	}

	// Route 
	HTREEITEM routeItem = insertTvInsertStruct("Route", CTB_ITEMIMAGE_ROUTE_ROOT, rootItem, NULL);
	setRouteTreeItem(routeItem);

	for (Route *route=sceneGraph->getRoutes(); route; route=route->next())
		addRoute(route);

	// Event
	HTREEITEM eventRootItem = insertTvInsertStruct("Event", CTB_ITEMIMAGE_EVENTROOT, rootItem, NULL);
	setEventTreeItem(eventRootItem);

	for (Node *enode=GetWorld()->getEventNodes(); enode; enode=enode->next()) {
		CEvent	event(enode);
		addEventNode(&event);
	}
}

void CCyberToolBoxView::updatePerspectiveView()
{
	CView *view = CtbGetPerspectiveView();
	if (view->IsWindowVisible()) {
		view->InvalidateRect(NULL);
		view->UpdateWindow();
	}
}

void CCyberToolBoxView::updateOrthoView()
{
	CView *view = CtbGetOrthoView();
	if (view->IsWindowVisible()) {
		view->InvalidateRect(NULL);
		view->UpdateWindow();
	}
}

void CCyberToolBoxView::updateViews()
{
	updatePerspectiveView();
	updateOrthoView();
}

void CCyberToolBoxView::setNodeItem(HTREEITEM item, Node *itemNode)
{
	TV_ITEM	tvItem;
	tvItem.mask = TVIF_TEXT;
	tvItem.hItem = item;
	tvItem.pszText = getNodeName(itemNode);

    CTreeCtrl &pTree = GetTreeCtrl();
	pTree.SetItem(&tvItem);

	itemNode->setValue(item);

	if (itemNode->isInstanceNode() == false) {
		for (Node *node=GetWorld()->getSceneGraph()->getNodes(); node; node=node->nextTraversal()) {
			if (node->isInstanceNode() == true) {
				if (node->getReferenceNode() == itemNode) {
					HTREEITEM item = (HTREEITEM)node->getValue();
					setNodeItem(item, node);
				}
			}
		}
	}
}

LPARAM CCyberToolBoxView::getTreeItemParam(HTREEITEM item)
{
    CTreeCtrl &pTree = GetTreeCtrl();
	TV_ITEM tvItem;
	tvItem.hItem = item;
	tvItem.mask = HDI_LPARAM;
	pTree.GetItem(&tvItem);
	return tvItem.lParam;
}

void CCyberToolBoxView::setTreeItemName(HTREEITEM item, char *name)
{
    CTreeCtrl &pTree = GetTreeCtrl();
	TV_ITEM tvItem;
	tvItem.hItem = item;
	tvItem.mask = TVIF_TEXT;
	tvItem.pszText = name;
	pTree.SetItem(&tvItem);

	InvalidateRect(NULL); UpdateWindow();
}

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxView クラスの印刷

BOOL CCyberToolBoxView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// デフォルトの印刷準備
	return DoPreparePrinting(pInfo);
}

void CCyberToolBoxView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CCyberToolBoxView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxView クラスの診断

#ifdef _DEBUG
void CCyberToolBoxView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CCyberToolBoxView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CCyberToolBoxDoc* CCyberToolBoxView::GetDocument() // 非デバッグ バージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCyberToolBoxDoc)));
	return (CCyberToolBoxDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCyberToolBoxView クラスのメッセージ ハンドラ

BOOL CCyberToolBoxView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle | TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS, rect, pParentWnd, nID, pContext);
	
//	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

/////////////////////////////////////////////////////
//	OnCreate
/////////////////////////////////////////////////////

int CCyberToolBoxView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: この位置に固有の作成用コードを追加してください

	ModuleFloating *modFloating = new ModuleFloating("", this);
	modFloating->CPropertySheet::Create(this, WS_CAPTION | DS_MODALFRAME | WS_VISIBLE, /* WS_EX_TOPMOST | */ WS_EX_TOOLWINDOW);
	CtbGetApp()->setModuleFloating(modFloating);

	CTreeCtrl &pTree = GetTreeCtrl();

	resetSceneGraphTree();

//	setToolBarButton(ID_SIMULATION_STOP);

	SetTimer(1, 10, NULL);

	GetParent()->SetWindowText("CyberToolbox");

	LOGFONT lf;
	getFontInfo(&lf);
	setFont(&lf);

	// Tree Item
	createImageList();
	pTree.SetImageList(getImageList(), TVSIL_NORMAL);

	return 0;
}

CDiagramView *CCyberToolBoxView::createDiagramWindow(TransformNode *transform)
{
	CCyberToolBoxApp	*ctbApp = (CCyberToolBoxApp *)AfxGetApp();
/*
	mDgmDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CDiagramDoc),
		RUNTIME_CLASS(CDiagramFrame),       // メイン SDI フレーム ウィンドウ
		RUNTIME_CLASS(CDiagramView));
	//ctbApp->AddDocTemplate(dgmDocTemplate);

	CDocument *ctbDoc = mDgmDocTemplate->OpenDocumentFile(NULL);
*/
	CDocument *ctbDoc = ctbApp->mDgmDocTemplate->OpenDocumentFile(NULL);

	POSITION pos = ctbDoc->GetFirstViewPosition();
	assert(pos != NULL);
	CDiagramView *view = (CDiagramView *)ctbDoc->GetNextView(pos);
	assert(view != NULL);

	view->setDiagramNode(transform);

	return view;
}

/////////////////////////////////////////////////////
//	ToolBar
/////////////////////////////////////////////////////

void CCyberToolBoxView::enableButton(int id, BOOL bEnable)
{
	CToolBarCtrl	&tbCtrl = ((CMainFrame *)GetParentFrame())->m_wndToolBar.GetToolBarCtrl();
//	tbCtrl.PressButton(id, !bEnable);
	tbCtrl.Indeterminate(id, !bEnable);
//	tbCtrl.EnableButton(id, bEnable);
/*
	if (bEnable)
		tbCtrl.SetState(id, TBSTATE_ENABLED);
	else
		tbCtrl.SetState(id, TBSTATE_INDETERMINATE);
*/
}

void CCyberToolBoxView::pressButton(int id, BOOL bEnable)
{
	CToolBarCtrl	&tbCtrl = ((CMainFrame *)GetParentFrame())->m_wndToolBar.GetToolBarCtrl();
	tbCtrl.PressButton(id, bEnable);
}

BOOL CCyberToolBoxView::isButtonEnabled(int id)
{
	CToolBarCtrl	&tbCtrl = ((CMainFrame *)GetParentFrame())->m_wndToolBar.GetToolBarCtrl();
	return tbCtrl.IsButtonEnabled(id);
}

BOOL CCyberToolBoxView::isButtonPressed(int id)
{
	CToolBarCtrl	&tbCtrl = ((CMainFrame *)GetParentFrame())->m_wndToolBar.GetToolBarCtrl();
	return tbCtrl.IsButtonPressed(id);
}

void CCyberToolBoxView::setToolBarButton(int pushedButton)
{
	switch (pushedButton) {
	case ID_SIMULATION_GO:
		enableButton(ID_SCENEGRAPH_NEW, FALSE);
		enableButton(ID_SCENEGRAPH_LOAD, FALSE);
		enableButton(ID_SCENEGRAPH_SAVE, FALSE);
		enableButton(ID_DIAGRAM_NEW, FALSE);
		enableButton(ID_NODE_NEW, FALSE);
		enableButton(ID_ROUTE_NEW, FALSE);
		enableButton(ID_EVENT_NEW, FALSE);

		pressButton(ID_SIMULATION_GO, TRUE);
		break;
	case ID_SIMULATION_STOP:
		enableButton(ID_SCENEGRAPH_NEW, TRUE);
		enableButton(ID_SCENEGRAPH_LOAD, TRUE);
		if (hasLicence() == true)
			enableButton(ID_SCENEGRAPH_SAVE, TRUE);
		else
			enableButton(ID_SCENEGRAPH_SAVE, FALSE);
		enableButton(ID_DIAGRAM_NEW, TRUE);
		enableButton(ID_NODE_NEW, TRUE);
		enableButton(ID_ROUTE_NEW, TRUE);
		enableButton(ID_EVENT_NEW, TRUE);

		pressButton(ID_SIMULATION_GO, FALSE);
		break;
	}
}

/////////////////////////////////////////////////////
//	Simulation
/////////////////////////////////////////////////////

void CCyberToolBoxView::OnSimulationGo() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	if (isButtonPressed(ID_SIMULATION_GO)) {
		MessageBeep(0);
		return;
	}

	PerspectiveView *pview = CtbGetPerspectiveView();
	wglMakeCurrent(pview->oglHdc, pview->oglHrc);

	GetWorld()->initialize();
	GetWorld()->setSimulationActive(TRUE);	
	setToolBarButton(ID_SIMULATION_GO);
	CtbModuleFloatingShowWindow(SW_HIDE);
	CtbPrimitiveFloatingShowWindow(SW_HIDE);

	wglMakeCurrent(NULL, NULL);
}

void CCyberToolBoxView::OnSimulationStop() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	if (!isButtonPressed(ID_SIMULATION_GO)) {
		MessageBeep(0);
		return;
	}

	GetWorld()->setSimulationActive(FALSE);	
	setToolBarButton(ID_SIMULATION_STOP);
	CtbModuleFloatingShowWindow(SW_SHOW);
	CtbPrimitiveFloatingShowWindow(SW_SHOW);
}

void CCyberToolBoxView::OnSimulationStep() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	if (isButtonPressed(ID_SIMULATION_GO)) {
		MessageBeep(0);
		return;
	}
	
}

/////////////////////////////////////////////////////////////////////////////
//	SceneGraph 
/////////////////////////////////////////////////////////////////////////////

static char BASED_CODE gScengraphFileTypes[] = "VRML Files (*.wrl)|*.wrl|All Files (*.*)|*.*||";

void CCyberToolBoxView::OnScenegraphNew() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	if (isButtonPressed(ID_SIMULATION_GO)) {
		MessageBeep(0);
		return;
	}

	CtbModuleFloatingShowWindow(SW_HIDE);
	CtbPrimitiveFloatingShowWindow(SW_HIDE);

	CString msgString;
	msgString.LoadString(IDS_SCENEGRAPH_NEW);
	UsrMsgSetParentWindow(this);
	if (UsrMsgQuestion((char *)(LPCTSTR)msgString))
		GetWorld()->clearSceneGraph();	
	resetSceneGraphTree();
	updateViews();

	CtbModuleFloatingShowWindow(SW_SHOW);
	CtbPrimitiveFloatingShowWindow(SW_SHOW);
}

static void LoadSceneGraphCallback(int nLine, void *info)
{
	DialogProgress	*dialog = (DialogProgress *)info;
	dialog->setPos(nLine);
}

static void PreCompileSceneGraphCallback(int nNode, void *info)
{
	DialogProgress	*dialog = (DialogProgress *)info;
	dialog->setPos(nNode);
}

void CCyberToolBoxView::OnScenegraphLoad() 
{
	PerspectiveView *pview = CtbGetPerspectiveView();

	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	if (isButtonPressed(ID_SIMULATION_GO)) {
		MessageBeep(0);
		return;
	}

	CtbModuleFloatingShowWindow(SW_HIDE);
	CtbPrimitiveFloatingShowWindow(SW_HIDE);

	CFileDialog dlg(TRUE, "wrl", "*.wrl", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, gScengraphFileTypes);
	if (dlg.DoModal() == IDOK) {

		CWaitCursor	cursor;

	    wglMakeCurrent(pview->oglHdc, pview->oglHrc);
		
		SceneGraph *sceneGraph = GetWorld()->getSceneGraph();

		int nLine = sceneGraph->getNLines((char *)(LPCTSTR)dlg.GetPathName());

		DialogProgress loadProgressDialog("LOADING SCENEGRAPH", nLine, this);
		loadProgressDialog.Create();
		loadProgressDialog.ShowWindow(SW_SHOW);
		loadProgressDialog.UpdateWindow();

		UsrMsgSetParentWindow(this);
		GetWorld()->addSceneGraph((char *)(LPCTSTR)dlg.GetPathName(), false, LoadSceneGraphCallback, &loadProgressDialog);
		
		loadProgressDialog.DestroyWindow();

		DialogProgress precompileProgressDialog("PRECOMPILING SCENEGRAPH", sceneGraph->getNNodes(), this);
		precompileProgressDialog.Create();
		precompileProgressDialog.ShowWindow(SW_SHOW);
		precompileProgressDialog.UpdateWindow();

		sceneGraph->initialize(PreCompileSceneGraphCallback, &precompileProgressDialog);

		precompileProgressDialog.DestroyWindow();

		// Add default Viewpoint and NavigationInfo
		if (sceneGraph->getViewpointNode() == false) {
			ViewpointNode *vpoint;
			vpoint = sceneGraph->findViewpointNode();
			if (vpoint != NULL)
				sceneGraph->setViewpointNode(vpoint, true);
			else {
				vpoint = new ViewpointNode();
				sceneGraph->addNode(vpoint);
				sceneGraph->setViewpointNode(vpoint, true);
				sceneGraph->zoomAllViewpoint();
				CtbTreeAddNode(vpoint, NULL);
			}
		}
		if (sceneGraph->getNavigationInfoNode() == false) {
			NavigationInfoNode *navInfo;
			navInfo = sceneGraph->findNavigationInfoNode();
			if (navInfo != NULL)
				sceneGraph->setNavigationInfoNode(navInfo, true);
			else {
				navInfo = new NavigationInfoNode();
				navInfo->setHeadlight(true);
				sceneGraph->addNode(navInfo);
				sceneGraph->setNavigationInfoNode(navInfo, true);
				CtbTreeAddNode(navInfo, NULL);
			}
		}
		if (sceneGraph->getBackgroundNode() == false) {
			BackgroundNode *bg;
			bg = sceneGraph->findBackgroundNode();
			if (bg!= NULL)
				sceneGraph->setBackgroundNode(bg, true);
			else {
				float skyColor[] = {0.0f, 0.0f, 0.0f};
				bg = new BackgroundNode();
				bg->addSkyColor(skyColor);
				sceneGraph->addNode(bg);
				sceneGraph->setBackgroundNode(bg, true);
				CtbTreeAddNode(bg, NULL);
			}
		}
		if (sceneGraph->getFogNode() == false) {
			FogNode *fog;
			fog = sceneGraph->findFogNode();
			if (fog!= NULL)
				sceneGraph->setFogNode(fog, true);
		}
		
		GetWorld()->addFullPathSceneGraphUrlFileNames();

		resetSceneGraphTree();
		updateViews();

	    wglMakeCurrent(NULL, NULL);
	}

	CtbModuleFloatingShowWindow(SW_SHOW);
	CtbPrimitiveFloatingShowWindow(SW_SHOW);
}

static void SaveSceneGraphCallback(int nNode, void *info)
{
	DialogProgress	*dialog = (DialogProgress *)info;
	dialog->setPos(nNode);
}

void CCyberToolBoxView::OnScenegraphSave() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	if (hasLicence() == false) {
		MessageBeep(0);
		return;
	}

	if (isButtonPressed(ID_SIMULATION_GO)) {
		MessageBeep(0);
		return;
	}

	CtbModuleFloatingShowWindow(SW_HIDE);
	CtbPrimitiveFloatingShowWindow(SW_HIDE);

	CFileDialog dlg(FALSE, "wrl", "*.wrl", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, gScengraphFileTypes);
	if (dlg.DoModal() == IDOK) {

		PerspectiveView *pview = CtbGetPerspectiveView();
	    wglMakeCurrent(pview->oglHdc, pview->oglHrc);

		CWaitCursor wait;

		SceneGraph *sceneGraph = GetWorld()->getSceneGraph();

		DialogProgress saveProgressDialog("SAVING SCENEGRAPH", sceneGraph->getNNodes(), this);
		saveProgressDialog.Create();
		saveProgressDialog.ShowWindow(SW_SHOW);
		saveProgressDialog.UpdateWindow();

		char selectedFileDirectory[1024];
		strcpy(selectedFileDirectory, (char *)(LPCTSTR)dlg.GetPathName());
		FileStripFileName(selectedFileDirectory);
		
		GetWorld()->copySceneGraphUrlFiles(selectedFileDirectory);
		GetWorld()->saveSceneGraph((char *)(LPCTSTR)dlg.GetPathName(), SaveSceneGraphCallback, &saveProgressDialog);

		saveProgressDialog.DestroyWindow();

	    wglMakeCurrent(NULL, NULL);
	}

	CtbModuleFloatingShowWindow(SW_SHOW);
	CtbPrimitiveFloatingShowWindow(SW_SHOW);
}

void CCyberToolBoxView::OnScenegraphSaveAs() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	if (hasLicence() == false) {
		MessageBeep(0);
		return;
	}

	if (isButtonPressed(ID_SIMULATION_GO)) {
		MessageBeep(0);
		return;
	}

	CModuleType mtype;
	mtype.load("MTYPE.DEF");
	mtype.save("MTYPEOUT.DEF");
}

/////////////////////////////////////////////////////////////////////////////
//	Diagram
/////////////////////////////////////////////////////////////////////////////

void CCyberToolBoxView::OnDiagramNew() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	if (isButtonPressed(ID_SIMULATION_GO)) {
		MessageBeep(0);
		return;
	}

	CtbModuleFloatingShowWindow(SW_HIDE);
	CtbPrimitiveFloatingShowWindow(SW_HIDE);

	DiagramNew diagramDialog(this);
	int ret = diagramDialog.DoModal();

	CtbModuleFloatingShowWindow(SW_SHOW);
	CtbPrimitiveFloatingShowWindow(SW_SHOW);

	if (ret == IDOK) {
		char	diagramName[512];
		if (!diagramDialog.getName() || strlen(diagramDialog.getName()) == 0) {
			for (int n=0; n<1024; n++) {
				sprintf(diagramName, "diagram%d", n);
				if (!GetWorld()->getDiagramNode(diagramName))
					break;
			}
		}
		else
			strcpy(diagramName, diagramDialog.getName());

		Node		*eventNode = GetWorld()->getEventNode(diagramDialog.getEventNumber());
		TransformNode	*transform = GetWorld()->addDiagram(diagramName, eventNode);
		if (transform) {
			CEvent		event(eventNode);
			CDiagram	diagram(transform);
			addDiagramNode(&event, &diagram);
			createDiagramWindow(transform);
		}
		else 
			MessageBeep(0);
	}
}

/////////////////////////////////////////////////////////////////////////////
//	TreeView mode	
/////////////////////////////////////////////////////////////////////////////

void CCyberToolBoxView::setTreeViewMode(int mode)
{
	mTreeViewMode = mode;
}

int CCyberToolBoxView::getTreeViewMode(void)
{
	return mTreeViewMode;
}

/////////////////////////////////////////////////////////////////////////////
//	Event
/////////////////////////////////////////////////////////////////////////////

void CCyberToolBoxView::OnEventNew() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	if (isButtonPressed(ID_SIMULATION_GO)) {
		MessageBeep(0);
		return;
	}

	CtbModuleFloatingShowWindow(SW_HIDE);
	CtbPrimitiveFloatingShowWindow(SW_HIDE);
	DialogNewUserEvent userEventDialog("New Event", this);
	if (userEventDialog.DoModal() == IDOK) {
		CEventType	*eventType = NULL;
		char optionString[256];
		strcpy(optionString, "");
		switch (userEventDialog.getPage()) {
		case USER_EVENT_CLOCK_PAGE: // CLOCK
			{
				int time = (int)userEventDialog.getIntervalTime();
				if (0 < time) {
					eventType = GetWorld()->getEventType(CTB_EVENTTYPE_CLOCK);
					sprintf(optionString, "%d", time);
				}
			}
			break;
		case USER_EVENT_TIMER_PAGE: // TIMER
			{
				int time = (int)userEventDialog.getWakeUpTime();
				if (0 < time) {
					eventType = GetWorld()->getEventType(CTB_EVENTTYPE_TIMER);
					sprintf(optionString, "%d", time);
				}
			}
			break;
		case USER_EVENT_PICKUP_PAGE: // PICKUP
			{
				strcpy(optionString, userEventDialog.getPickupNodeName());
				eventType = GetWorld()->getEventType(CTB_EVENTTYPE_PICKUP);
			}
			break;
		case USER_EVENT_DRAG_PAGE: // Drag
			{
				strcpy(optionString, userEventDialog.getDragNodeName());
				eventType = GetWorld()->getEventType(CTB_EVENTTYPE_DRAG);
			}
			break;
		case USER_EVENT_AREA_PAGE: // Area
			{
				float center[3];
				float size[3];
				userEventDialog.getCenter(center);
				userEventDialog.getSize(size);
				if (size[0] != 0.0f || size[1] != 0.0f || size[2] != 0.0f) {
					eventType = GetWorld()->getEventType(CTB_EVENTTYPE_AREA);
					sprintf(optionString, "%d:%d:%d:%d:%d:%d", (int)center[0], (int)center[1], (int)center[2], (int)size[0], (int)size[1], (int)size[2]);
				}
			}
		}

		if (eventType == NULL || !strlen(optionString)) {
			MessageBeep(0);
			return;
		}

		CEvent	event(eventType, optionString);
		if (GetWorld()->addEventNode(event.getNode()))
			addEventNode(&event);
		else
			MessageBeep(0);
	}	
	CtbModuleFloatingShowWindow(SW_SHOW);
	CtbPrimitiveFloatingShowWindow(SW_SHOW);
}

/////////////////////////////////////////////////////////////////////////////
//	
/////////////////////////////////////////////////////////////////////////////

void CCyberToolBoxView::OnTimer(UINT nIDEvent) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	if (GetWorld()->isSimulationActive()) {

		PerspectiveView *pview = CtbGetPerspectiveView();
		wglMakeCurrent(pview->oglHdc, pview->oglHrc);

		GetWorld()->getSceneGraph()->update();

		wglMakeCurrent(NULL, NULL);

		for (CDiagramWindow *dgm=GetWorld()->getDiagramWindows(); dgm; dgm=dgm->next()) {
			if (dgm->getHandle()) {
				dgm->getHandle()->InvalidateRect(NULL);
				dgm->getHandle()->UpdateWindow();
			}
		}

		updateViews();
	}

	MSG msg;
	while(::PeekMessage(&msg, m_hWnd, WM_TIMER, WM_TIMER, PM_REMOVE));

	CTreeView::OnTimer(nIDEvent);
}

void CCyberToolBoxView::OnDestroy() 
{
	CTreeView::OnDestroy();
	
	// TODO: この位置にメッセージ ハンドラ用のコードを追加してください
	if (GetWorld()->isSimulationActive())
		OnSimulationStop();
	KillTimer(1);

	ModuleFloating *modFloating = CtbGetApp()->getModuleFloating();
	modFloating->DestroyWindow();
	delete modFloating;
}

void CCyberToolBoxView::OnFontSetting() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	LOGFONT lf;
	getFontInfo(&lf);

	CtbModuleFloatingShowWindow(SW_HIDE);
	CtbPrimitiveFloatingShowWindow(SW_HIDE);

	CFontDialog dlg(&lf, CF_SCREENFONTS|CF_INITTOLOGFONTSTRUCT);
	if (dlg.DoModal() == IDOK)
		setFont(&lf);

	CtbModuleFloatingShowWindow(SW_SHOW);
	CtbPrimitiveFloatingShowWindow(SW_SHOW);
}

char *CCyberToolBoxView::getNodeName(Node *node) 
{
	if (node->isInstanceNode() == false) {
		if (node->isTransformNode() == true) 
			strcpy(mNodeName, "TransformNode (Object)");
		else
			strcpy(mNodeName, node->getType());
		if (node->getName() && strlen(node->getName()) > 0) {
			strcat(mNodeName, " - ");
			strcat(mNodeName, node->getName());
		}
	}
	else {
		sprintf(mNodeName, "USE - %s", node->getReferenceNode()->getName());
	}
	return mNodeName;
}

char *CCyberToolBoxView::getNodeNameForSimpleTreeMode(Node *node) 
{
	char *nodeName = NULL;

	if (node->getName() && strlen(node->getName()) > 0) {
		strcpy(mNodeName, node->getName());
		nodeName = mNodeName;
	}
	else {
		int cnt = 0;
		while (nodeName == NULL || GetWorld()->getSceneGraph()->findNode(nodeName) != NULL) { 
			if (node->isViewpointNode()) 
				sprintf(mNodeName, "Viewpoint%d", cnt);
			else if (node->isDirectionalLightNode()) 
				sprintf(mNodeName, "DirectionalLight%d", cnt);
			else if (node->isSpotLightNode()) 
				sprintf(mNodeName, "SpotLight%d", cnt);
			else if (node->isPointLightNode()) 
				sprintf(mNodeName, "PointLight%d", cnt);
			else if (node->isMaterialNode()) 
				sprintf(mNodeName, "Material%d", cnt);
			else if (node->isTransformNode()) 
				sprintf(mNodeName, "Object%d", cnt);
			
			nodeName = mNodeName;
			cnt++;
		}
		node->setName(nodeName);
	}

	return nodeName;
}

char *CCyberToolBoxView::getEventName(CEvent *event) 
{
	strcpy(mEventName, event->getEventTypeName());
	if (event->getEventOptionName()) {
		strcat(mEventName, " - ");
		strcat(mEventName, event->getEventOptionName());
	}

	return mEventName;
}

Node *CCyberToolBoxView::getNode(HTREEITEM treeItem)
{
	Node *selectedNode = (Node *)getTreeItemParam(treeItem);

	for (Node *node = GetWorld()->getSceneGraph()->getRootNode(); node; node = node->nextTraversal()) {
		if (node == selectedNode)
			return node;
	}
	return NULL;
}

Route *CCyberToolBoxView::getRoute(HTREEITEM treeItem)
{
	Route *selectedRoute = (Route *)getTreeItemParam(treeItem);

	for (Route *route = GetWorld()->getSceneGraph()->getRoutes(); route; route = route->next()) {
		if (route == selectedRoute)
			return route;
	}
	return NULL;
}

void CCyberToolBoxView::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	
    CTreeCtrl &pTree = GetTreeCtrl();

	TV_ITEM	item = pNMTreeView->itemNew;
	Node *selectedNode = getNode(item.hItem);

	*pResult = 0;
}

void CCyberToolBoxView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
    CTreeCtrl &pTree = GetTreeCtrl();

	UINT	hitInfo;
	HTREEITEM hitItem = pTree.HitTest(point, &hitInfo);
	if (!hitItem)
		return;

	LPARAM param = getTreeItemParam(hitItem);

	// Route
	Route *selectedRoute = getRoute(hitItem);
	if (selectedRoute) {
		DialogRouteInfo dialog;
		dialog.setOutputNode(selectedRoute->getEventOutNode());
		dialog.setOutputField(selectedRoute->getEventOutField());
		dialog.setInputNode(selectedRoute->getEventInNode());
		dialog.setInputField(selectedRoute->getEventInField());
		if (dialog.DoModal() == IDOK) {
			Node	*outNode	= dialog.getOutputNode();
			Field	*outField	= dialog.getOutputField();
			Node	*inNode		= dialog.getInputNode();
			Field	*inField	= dialog.getInputField();
			if (outNode != NULL && outField != NULL && inNode != NULL && inField != NULL) {
				selectedRoute->setEventOutNode(outNode);
				selectedRoute->setEventOutField(outField);
				selectedRoute->setEventInNode(inNode);
				selectedRoute->setEventInField(inField);
				setTreeItemName(hitItem, getRouteName(selectedRoute));
			}
		}
	}

	// Node
	Node *selectedNode = getNode(hitItem);
	if (selectedNode == NULL) {
		MessageBeep(0);
		return;
	}

	// Diagram
	if (GetWorld()->isDiagram(selectedNode)) {

		BOOL bOpened = FALSE;
		TransformNode *diagramNode = (TransformNode *)selectedNode;

		for (CDiagramWindow *dgmWindow=GetWorld()->getDiagramWindows(); dgmWindow; dgmWindow=dgmWindow->next()) {
			CDiagramView *dgmView = (CDiagramView *)dgmWindow->getHandle();
			if (dgmView->getDiagramNode() == diagramNode) {
				dgmView->ShowWindow(SW_SHOW);
				bOpened = TRUE;
				break;
			}
		}
		if (!bOpened)
			createDiagramWindow(diagramNode);

#ifdef OLD
		TransformNode *diagramNode = (TransformNode *)selectedNode;
		DialogDiagram	dialog(this);
		dialog.setNode(diagramNode);
		CtbModuleFloatingShowWindow(SW_HIDE);
		CtbPrimitiveFloatingShowWindow(SW_HIDE);
		switch(dialog.DoModal()) {
		case IDC_OPEN:
			{
				for (CDiagramWindow *dgmWindow=GetWorld()->getDiagramWindows(); dgmWindow; dgmWindow=dgmWindow->next()) {
					CDiagramView *dgmView = (CDiagramView *)dgmWindow->getHandle();
					if (dgmView->getDiagramNode() == diagramNode) {
						bOpened = TRUE;
						break;
					}
				}
				if (!bOpened)
					createDiagramWindow(diagramNode);
			}
			break;
		case IDOK:
			{
				CDiagram diagram(diagramNode);
				char *name = dialog.getName();
				if (StringLength(name) && !GetWorld()->getDiagramNode(name, diagram.getEventNode())){
					diagram.setName(name);
					setTreeItemName(hitItem, diagram.getName());
					CDiagramView *openedDgmView = NULL;
					if (GetWorld()->isDiagram(diagramNode)) {
						for (CDiagramWindow *dgmWindow=GetWorld()->getDiagramWindows(); dgmWindow; dgmWindow=dgmWindow->next()) {
							CDiagramView *dgmView = (CDiagramView *)dgmWindow->getHandle();
							if (dgmView->getDiagramNode() == diagramNode) {
								openedDgmView = dgmView;
								break;
							}
						}
						if (openedDgmView)
							openedDgmView->GetParent()->SetWindowText(diagram.getName());
					}
				}
				else
					MessageBeep(0);
			}
			break;
		}

		CtbModuleFloatingShowWindow(SW_SHOW);
		CtbPrimitiveFloatingShowWindow(SW_SHOW);
#endif
		return;
	}

	if (GetWorld()->isEventNode(selectedNode)) {
		CEvent		event(selectedNode);
		CEventType	*eventType = event.getEventType();

		switch (GetWorld()->getEventTypeNumber(eventType)) {
		case CTB_EVENTTYPE_FRAME: // FRAME (SYSTEM EVENT)
			{
				/*
				CtbModuleFloatingShowWindow(SW_HIDE);
				DialogEventFrame dialog(this);
				dialog.setEvent(&event);
				dialog.DoModal();
				CtbModuleFloatingShowWindow(SW_SHOW);
				*/
			}
			break;

		case CTB_EVENTTYPE_AREA:
			{
				CtbModuleFloatingShowWindow(SW_HIDE);
				CtbPrimitiveFloatingShowWindow(SW_HIDE);
				DialogEventArea dialog(this);
				dialog.setEvent(&event);
				if (dialog.DoModal() == IDOK) {
					char *eventName = getEventName(&event);
					setTreeItemName(hitItem, eventName);
				}
				CtbModuleFloatingShowWindow(SW_SHOW);
				CtbPrimitiveFloatingShowWindow(SW_SHOW);
			}
			break;

		case CTB_EVENTTYPE_PICKUP:
			{
				CtbModuleFloatingShowWindow(SW_HIDE);
				CtbPrimitiveFloatingShowWindow(SW_HIDE);
				DialogEventPickup dialog(this);
				dialog.setEvent(&event);
				if (dialog.DoModal() == IDOK) {
					char *eventName = getEventName(&event);
					setTreeItemName(hitItem, eventName);
				}
				CtbModuleFloatingShowWindow(SW_SHOW);
				CtbPrimitiveFloatingShowWindow(SW_SHOW);
			}
			break;

		case CTB_EVENTTYPE_DRAG:
			{
				CtbModuleFloatingShowWindow(SW_HIDE);
				CtbPrimitiveFloatingShowWindow(SW_HIDE);
				DialogEventDrag dialog(this);
				dialog.setEvent(&event);
				if (dialog.DoModal() == IDOK) {
					char *eventName = getEventName(&event);
					setTreeItemName(hitItem, eventName);
				}
				CtbModuleFloatingShowWindow(SW_SHOW);
				CtbPrimitiveFloatingShowWindow(SW_SHOW);
			}
			break;

		case CTB_EVENTTYPE_CLOCK:
			{
				CtbModuleFloatingShowWindow(SW_HIDE);
				CtbPrimitiveFloatingShowWindow(SW_HIDE);
				DialogEventClock dialog(this);
				dialog.setEvent(&event);
				if (dialog.DoModal() == IDOK) {
					char *eventName = getEventName(&event);
					setTreeItemName(hitItem, eventName);
				}
				CtbModuleFloatingShowWindow(SW_SHOW);
				CtbPrimitiveFloatingShowWindow(SW_SHOW);
			}
			break;

		case CTB_EVENTTYPE_TIMER:
			{
				CtbModuleFloatingShowWindow(SW_HIDE);
				CtbPrimitiveFloatingShowWindow(SW_HIDE);
				DialogEventTimer dialog(this);
				dialog.setEvent(&event);
				if (dialog.DoModal() == IDOK) {
					char *eventName = getEventName(&event);
					setTreeItemName(hitItem, eventName);
				}
				CtbModuleFloatingShowWindow(SW_SHOW);
				CtbPrimitiveFloatingShowWindow(SW_SHOW);
			}
			break;
		}
	}
	
	// General Node
	if (!GetWorld()->isSystemNode(selectedNode)) {
		DialogNodeConfig	nodeConfig;
		nodeConfig.setNode(selectedNode);
		CtbModuleFloatingShowWindow(SW_HIDE);
		CtbPrimitiveFloatingShowWindow(SW_HIDE);
		if (nodeConfig.DoModal() == IDOK) {
			CWaitCursor	cursor;
			PerspectiveView *pview = CtbGetPerspectiveView();
			wglMakeCurrent(pview->oglHdc, pview->oglHrc);
			setNodeItem(hitItem, selectedNode);
			GetWorld()->getSceneGraph()->initialize();
			updateViews();
			wglMakeCurrent(NULL, NULL);
		}
		CtbModuleFloatingShowWindow(SW_SHOW);
		CtbPrimitiveFloatingShowWindow(SW_SHOW);
		return;
	}

	CTreeView::OnLButtonDblClk(nFlags, point);
}

void CCyberToolBoxView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
    CTreeCtrl &pTree = GetTreeCtrl();

	UINT	hitInfo;
	HTREEITEM hitItem = pTree.HitTest(point, &hitInfo);
	if (!hitItem)
		return;

	LPARAM param = getTreeItemParam(hitItem);

	Node *selectedNode = (Node *)param;
	if (selectedNode) {
		if (selectedNode->isShapeNode()) {
			GetWorld()->getSceneGraph()->setSelectedShapeNode((ShapeNode *)selectedNode);
			GetWorld()->getSceneGraph()->setSelectedNode(NULL);
			CtbUpdatePerspectiveView();
			CtbUpdateOrthoView();
		}
	}
	
/*
	// Diagram
	TransformNode *diagramNode = (TransformNode *)param;
	if (GetWorld()->isDiagram(diagramNode)) {
		pTree.SelectItem(hitItem);
		pTree.EditLabel(hitItem);
	}
*/
	CTreeView::OnLButtonDown(nFlags, point);
}

void CCyberToolBoxView::OnBeginlabeledit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	*pResult = 0;

	UINT mask = pTVDispInfo->item.mask;
	if(mask != TVIF_TEXT)
		return;

    CTreeCtrl	&pTree = GetTreeCtrl();
	HTREEITEM	editItem = pTVDispInfo->item.hItem;
	LPARAM		param = getTreeItemParam(editItem);

	TransformNode *diagramNode = (TransformNode *)param;
	if (GetWorld()->isDiagram(diagramNode)) {
		pTree.EditLabel(editItem);
		return;
	}
}

void CCyberToolBoxView::OnEndlabeledit(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TV_DISPINFO* pTVDispInfo = (TV_DISPINFO*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	
	*pResult = 0;

	UINT mask = pTVDispInfo->item.mask;
	if(mask != TVIF_TEXT)
		return;

    CTreeCtrl	&pTree = GetTreeCtrl();
	HTREEITEM	editItem = pTVDispInfo->item.hItem;
	LPARAM		param = getTreeItemParam(editItem);
	char		*labelString = pTVDispInfo->item.pszText;

	CDiagramView *openedDgmView = NULL;
	TransformNode *diagramNode = (TransformNode *)param;
	if (GetWorld()->isDiagram(diagramNode)) {
		CDiagram diagram(diagramNode);
		if (!GetWorld()->getDiagramNode(labelString, diagram.getEventNode())) {
			diagram.setName(labelString);
			setTreeItemName(editItem, labelString);
			for (CDiagramWindow *dgmWindow=GetWorld()->getDiagramWindows(); dgmWindow; dgmWindow=dgmWindow->next()) {
				CDiagramView *dgmView = (CDiagramView *)dgmWindow->getHandle();
				if (dgmView->getDiagramNode() == diagramNode) {
					openedDgmView = dgmView;
					break;
				}
			}
			if (openedDgmView)
				openedDgmView->GetParent()->SetWindowText(labelString);
		}
		else
			MessageBeep(0);
		return;
	}
}

static void CloseDiagramWindow(TransformNode *diagramNode)
{
	CDiagramView *openedDgmView = NULL;
	if (GetWorld()->isDiagram(diagramNode)) {
		CDiagram diagram(diagramNode);
		for (CDiagramWindow *dgmWindow=GetWorld()->getDiagramWindows(); dgmWindow; dgmWindow=dgmWindow->next()) {
			CDiagramView *dgmView = (CDiagramView *)dgmWindow->getHandle();
			if (dgmView->getDiagramNode() == diagramNode) {
				openedDgmView = dgmView;
				break;
			}
		}
		if (openedDgmView)
			openedDgmView->GetParentFrame()->DestroyWindow();
	}
}

BOOL CCyberToolBoxView::deleteItem(HTREEITEM item)
{
	LPARAM	param = getTreeItemParam(item);

	CTreeCtrl	&pTree = GetTreeCtrl();

	// Diagram
	TransformNode *diagramNode = (TransformNode *)param;
	if (GetWorld()->isDiagram(diagramNode)) {
		CloseDiagramWindow(diagramNode);
		delete diagramNode;
		pTree.DeleteItem(item);
		return TRUE;
	}

	// Event
	Node *eventNode = (Node *)param;
	if (GetWorld()->isEventNode(eventNode)) {
		CEvent event(eventNode);
		CEventType *eventType = event.getEventType();
		if (eventType->getAttributeType() == CTB_EVENATTRIBUTE_SYSTEM)
			return FALSE;
		TransformNode *diagramNode=GetWorld()->getDiagramNodes();
		while (diagramNode) {
			TransformNode *nextDiagramNode = GetWorld()->nextDiagramNode(diagramNode);
			CDiagram diagram(diagramNode);
			if (eventNode == diagram.getEventNode()) {
				CloseDiagramWindow(diagramNode);
				delete diagramNode;
			}
			diagramNode = nextDiagramNode;
		}
		delete eventNode;
		pTree.DeleteItem(item);
		return TRUE;
	}

	// General Node
	Node *node = getNode(item);
	if (node) {
		if (!GetWorld()->isSystemNode(node)) {
			deleteSceneGraphNode(node);
			GetWorld()->deleteNode(node);
			return TRUE;
		}
		else
			return FALSE;
	}

	// Route
	Route *route = getRoute(item);
	if (route) {
		deleteRoute(route);
		GetWorld()->getSceneGraph()->deleteRoute(route);
	}

	return FALSE;
}

void CCyberToolBoxView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください

    CTreeCtrl	&pTree = GetTreeCtrl();
	HTREEITEM	selectedItem = pTree.GetSelectedItem();

	if (!selectedItem)
		return;

	switch (nChar) {
	case VK_DELETE:
		{
			Node *node = getNode(selectedItem);
			if (node && GetWorld()->isSystemNode(node)) 
				MessageBeep(0);

			CString msgString;
			msgString.LoadString(IDS_SCENEGRAPH_DELETE_TREENODE);

			UsrMsgSetParentWindow(this);
			if (!UsrMsgQuestion((char *)(LPCTSTR)msgString))
				return;

			if (deleteItem(selectedItem))
				updateViews();
			else
				MessageBeep(0);
		}
		break;
	}
	
	CTreeView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CCyberToolBoxView::OnBegindrag(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	CTreeCtrl	&pTree = GetTreeCtrl();
	CPoint		ptAction;
	UINT		nFlags;

	GetCursorPos(&ptAction);
	ScreenToClient(&ptAction);

	mbDragging = TRUE;
	mhItemDrag = pTree.HitTest(ptAction, &nFlags);
	mhItemDrop = NULL;

	mTypeDragItem = CTB_DRAGITEM_NONE;

	Node *node = getNode(mhItemDrag);
	if (node && !GetWorld()->isSystemNode(node)) 
		mTypeDragItem = CTB_DRAGITEM_NODE;
		
	if (mTypeDragItem) {
		ASSERT(mpImagelist == NULL);
		mpImagelist = pTree.CreateDragImage(mhItemDrag);  // get the image list for dragging
		mpImagelist->DragShowNolock(TRUE);
		mpImagelist->SetDragCursorImage(0, CPoint(0, 0));
		mpImagelist->BeginDrag(0, CPoint(0,0));
		mpImagelist->DragMove(ptAction);
		mpImagelist->DragEnter(this, ptAction);
		SetCapture();
	}
	else {
		mbDragging = FALSE;
		MessageBeep(0);
	}

	*pResult = 0;
}

void CCyberToolBoxView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	CTreeCtrl			&pTree = GetTreeCtrl();
	HTREEITEM			hitem;
	UINT				flags;

	if (mbDragging)
	{
		ASSERT(mpImagelist != NULL);
		mpImagelist->DragMove(point);
		if ((hitem = pTree.HitTest(point, &flags)) != NULL)
		{
			if (mTypeDragItem ==  CTB_DRAGITEM_NODE && (getSceneGraphTreeItem() == hitem || getNode(hitem))) {
				mpImagelist->DragLeave(this);
				pTree.SelectDropTarget(hitem);
				mhItemDrop = hitem;
				mpImagelist->DragEnter(this, point);
			}
			else {
				mpImagelist->DragLeave(this);
				pTree.SelectDropTarget(NULL);
				mhItemDrop = NULL;
				mpImagelist->DragEnter(this, point);
			}
		}
	}

	
	CTreeView::OnMouseMove(nFlags, point);
}

void CCyberToolBoxView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	if (mbDragging)
	{
		CTreeCtrl	&pTree = GetTreeCtrl();

		ASSERT(mpImagelist != NULL);
		mpImagelist->DragLeave(this);
		mpImagelist->EndDrag();
		delete mpImagelist;
		mpImagelist = NULL;

		SceneGraph *sg = GetWorld()->getSceneGraph();

		if (mhItemDrop && mhItemDrag != mhItemDrop && !isChildNodeOf(mhItemDrop, mhItemDrag) && pTree.GetParentItem(mhItemDrag) != mhItemDrop) {

			Node *dragNode = getNode(mhItemDrag);
			Node *dropNode = getNode(mhItemDrop);

			if (mTypeDragItem ==  CTB_DRAGITEM_NODE && dropNode && !GetWorld()->isSystemNode(dropNode) && dropNode->isChildNodeType(dragNode) ) {
				moveSceneGraphNode(dragNode, dropNode);
				dropNode->moveChildNode(dragNode);
			}
			else if (mTypeDragItem ==  CTB_DRAGITEM_NODE && getSceneGraphTreeItem() == mhItemDrop && GetWorld()->getSceneGraph()->getRootNode()->isChildNodeType(dragNode) ) {
				moveSceneGraphNode(dragNode, dropNode);
				GetWorld()->getSceneGraph()->moveNode(dragNode);
			}
			else
				MessageBeep(0);
			
			if (sg->getSelectedShapeNode() == dragNode) {
				sg->setSelectedShapeNode(NULL);
				sg->setSelectedNode(NULL);
			}
		}
		else
			MessageBeep(0);

		ReleaseCapture();
		mbDragging = FALSE;
		pTree.SelectDropTarget(NULL);

		PerspectiveView *pview = CtbGetPerspectiveView();
		wglMakeCurrent(pview->oglHdc, pview->oglHrc);

		sg->initialize();

		wglMakeCurrent(NULL, NULL);

		CtbUpdatePerspectiveView();
		CtbUpdateOrthoView();
	}
	
	CTreeView::OnLButtonUp(nFlags, point);
}

BOOL CCyberToolBoxView::isChildNodeOf(HTREEITEM hitemChild, HTREEITEM hitemSuspectedParent)
{
	CTreeCtrl	&pTree = GetTreeCtrl();

	do
	{
		if (hitemChild == hitemSuspectedParent)
			break;
	}
	while ((hitemChild = pTree.GetParentItem(hitemChild)) != NULL);

	return (hitemChild != NULL);
}

HTREEITEM CCyberToolBoxView::moveItem(HTREEITEM hitemDrag, HTREEITEM hitemDrop)
{
	TV_INSERTSTRUCT		tvstruct;
	TCHAR				sztBuffer[256];
	HTREEITEM			hNewItem;

	CTreeCtrl	&pTree = GetTreeCtrl();

	// avoid an infinite recursion situation
	tvstruct.item.hItem = hitemDrag;
	tvstruct.item.cchTextMax = 255;
	tvstruct.item.pszText = sztBuffer;
	tvstruct.item.mask = TVIF_CHILDREN | TVIF_HANDLE | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_TEXT | TVIF_PARAM;
	pTree.GetItem(&tvstruct.item);  // get information of the dragged element
	tvstruct.hParent = hitemDrop;
	tvstruct.hInsertAfter = TVI_SORT;
	tvstruct.item.mask = TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_TEXT | TVIF_PARAM;
	hNewItem = pTree.InsertItem(&tvstruct);

#ifdef OLD_CODE
	HTREEITEM hFirstChild;
	while ((hFirstChild = pTree.GetChildItem(hitemDrag)) != NULL)
	{
		transferItem(hFirstChild, hNewItem);  // recursively transfer all the items
		pTree.DeleteItem(hFirstChild);		// delete the first child and all its children
	}
#endif

	return hNewItem;
}

void CCyberToolBoxView::OnNodeNew() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
    CTreeCtrl	&pTree = GetTreeCtrl();
	HTREEITEM	selectedItem = pTree.GetSelectedItem();

	if (!selectedItem) {
		MessageBeep(0);
		return;
	}

	LPARAM	param = getTreeItemParam(selectedItem);

	// Diagram
	TransformNode *diagramNode = (TransformNode *)param;
	if (GetWorld()->isDiagram(diagramNode)) {
		MessageBeep(0);
		return;
	}

	// Event
	Node *eventNode = (Node *)param;
	if (GetWorld()->isEventNode(eventNode)) {
		MessageBeep(0);
		return;
	}

	// General Node
	Node *parentNode = getNode(selectedItem);
	if (parentNode && GetWorld()->isSystemNode(parentNode)) {
		MessageBeep(0);
		return;
	}

	Node *rootNode = GetWorld()->getSceneGraph()->getRootNode();
	if (getSceneGraphTreeItem() == selectedItem)
		parentNode = rootNode;

	if (!parentNode) {
		MessageBeep(0);
		return;
	}

	CtbModuleFloatingShowWindow(SW_HIDE);
	CtbPrimitiveFloatingShowWindow(SW_HIDE);

	DialogNodeNew dialog(this);
	dialog.setParentNode(parentNode);
	if (0 < dialog.getNNodes()) {
		SceneGraph *sg = GetWorld()->getSceneGraph();
		if (dialog.DoModal() == IDOK) {
			Node *node = dialog.getSelectedNode();
			if (node) {
				PerspectiveView *pview = CtbGetPerspectiveView();
				wglMakeCurrent(pview->oglHdc, pview->oglHrc);

				if (parentNode == rootNode)
					sg->addNode(node);
				else
					parentNode->addChildNode(node);
				addSceneGraphNode(node, selectedItem);
				sg->initialize();

				wglMakeCurrent(NULL, NULL);

				CtbUpdatePerspectiveView();
				CtbUpdateOrthoView();
			}
		}
	}
	else
		MessageBeep(0);

	CtbModuleFloatingShowWindow(SW_SHOW);
	CtbPrimitiveFloatingShowWindow(SW_SHOW);
}

void CCyberToolBoxView::On2dwindow() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	CFrameWnd *oframe = CtbGetOrthoView()->GetParentFrame();
	if (oframe->ShowWindow(SW_SHOWNA)) {
		oframe->ShowWindow(SW_HIDE);
		pressButton(ID_2DWINDOW, FALSE);
	}
	else {
		oframe->ShowWindow(SW_SHOW);
		pressButton(ID_2DWINDOW, TRUE);
	}
}

void CCyberToolBoxView::On3dwindow() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	CFrameWnd *pframe =CtbGetPerspectiveView()->GetParentFrame();
	if (pframe->ShowWindow(SW_SHOWNA)) {
		pframe->ShowWindow(SW_HIDE);
		pressButton(ID_3DWINDOW, FALSE);
	}
	else {
		pframe->ShowWindow(SW_SHOW);
		pressButton(ID_3DWINDOW, TRUE);
	}
}

void CCyberToolBoxView::OnViewChange() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	if (getTreeViewMode() == CTB_TREEVIEW_MODE_SIMPLE) {
		setTreeViewMode(CTB_TREEVIEW_MODE_ALLNODES);
		pressButton(ID_VIEW_CHANGE, TRUE);
	}
	else {
		setTreeViewMode(CTB_TREEVIEW_MODE_SIMPLE);
		pressButton(ID_VIEW_CHANGE, FALSE);
	}

	resetSceneGraphTree();
}


void CCyberToolBoxView::OnRouteNew() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	if (isButtonPressed(ID_SIMULATION_GO)) {
		MessageBeep(0);
		return;
	}

	DialogRouteInfo dialog;
	
	if (dialog.DoModal() == IDOK) {
		Node	*outNode	= dialog.getOutputNode();
		Field	*outField	= dialog.getOutputField();
		Node	*inNode		= dialog.getInputNode();
		Field	*inField	= dialog.getInputField();
		if (outNode != NULL && outField != NULL && inNode != NULL && inField != NULL) {
			Route * route = GetWorld()->getSceneGraph()->addRoute(outNode, outField, inNode, inField);
			addRoute(route);
		}
	}
}
