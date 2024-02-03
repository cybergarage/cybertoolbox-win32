// DialogNodeNew.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogNodeNew.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogNodeNew ダイアログ


DialogNodeNew::DialogNodeNew(CWnd* pParent /*=NULL*/)
	: CDialog(DialogNodeNew::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogNodeNew)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT

	setParentNode(NULL);
}


void DialogNodeNew::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogNodeNew)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogNodeNew, CDialog)
	//{{AFX_MSG_MAP(DialogNodeNew)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_NODE_LIST, OnItemchangedNodeList)
	ON_NOTIFY(NM_DBLCLK, IDC_NODE_LIST, OnDblclkNodeList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogNodeNew メッセージ ハンドラ

bool DialogNodeNew::addNode(Node *node) {
	if (mParentNode->isChildNodeType(node)) {
		mNodeList.addNode(node);	
		return true;
	}
	else {
		delete node;
		return false;
	}
}

void DialogNodeNew::createNodeList()
{
	addNode(new AnchorNode());
	addNode(new AppearanceNode());
	addNode(new AudioClipNode());
	addNode(new BackgroundNode());
	addNode(new BillboardNode());
	addNode(new BoxNode());
	addNode(new CollisionNode());
	addNode(new ColorNode());
	addNode(new ColorInterpolatorNode());
	addNode(new ConeNode());
	addNode(new CoordinateNode());
	addNode(new CoordinateInterpolatorNode());
	addNode(new CylinderNode());
	addNode(new CylinderSensorNode());
	addNode(new DirectionalLightNode());
	addNode(new ElevationGridNode());
	addNode(new ExtrusionNode());
	addNode(new FogNode());
	addNode(new FontStyleNode());
	addNode(new GroupNode());
	addNode(new ImageTextureNode());
	addNode(new IndexedFaceSetNode());
	addNode(new IndexedLineSetNode());
	addNode(new InlineNode());
	addNode(new LodNode());
	addNode(new MaterialNode());
	addNode(new MovieTextureNode());
	addNode(new NavigationInfoNode());
	addNode(new NormalNode());
	addNode(new NormalInterpolatorNode());
	addNode(new OrientationInterpolatorNode());
	addNode(new PixelTextureNode());
	addNode(new PlaneSensorNode());
	addNode(new PointLightNode());
	addNode(new PointSetNode());
	addNode(new PositionInterpolatorNode());
	addNode(new ProximitySensorNode());
	addNode(new ScalarInterpolatorNode());
	addNode(new ScriptNode());
	addNode(new ShapeNode());
	addNode(new SoundNode());
	addNode(new SphereNode());
	addNode(new SphereSensorNode());
	addNode(new SpotLightNode());
	addNode(new SwitchNode());
	addNode(new TextNode());
	addNode(new TextureCoordinateNode());
	addNode(new TextureTransformNode());
	addNode(new TimeSensorNode());
	addNode(new TouchSensorNode());
	addNode(new TransformNode());
	addNode(new ViewpointNode());
	addNode(new VisibilitySensorNode());
	addNode(new WorldInfoNode());
}

int GetImageListNodeNumber(Node *node);

void DialogNodeNew::createImageList()
{
	COLORREF bitMask = RGB(0, 0, 0);
	mItemImageList.Create(16, 16, ILC_COLOR8, 0, 54);

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

	for (int n = 0; n<54; n++)
	  mItemImageList.Add(&mItemBitmap[n], bitMask);
}

BOOL DialogNodeNew::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください

    CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_NODE_LIST);

	createImageList();

	CImageList *imgList = getImageList();
	if (imgList)
		pList->SetImageList(imgList, LVSIL_SMALL);

	pList->InsertColumn(0, "Node", LVCFMT_LEFT, 150, 0);

	int n = 0;
	for (Node *node=getNodes(); node; node=node->next() ) {
		if (imgList)
			pList->InsertItem(n++, node->getType(), GetImageListNodeNumber(node));
		else
			pList->InsertItem(n++, node->getType());
	}

	setSelectedItem(-1);

	setSelectedNode(NULL);

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogNodeNew::OnItemchangedNodeList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください

	setSelectedItem(pNMListView->iItem);

	*pResult = 0;
}

void DialogNodeNew::OnDblclkNodeList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	EndDialog(IDOK);
	
	Node *node = getNode(getSelectedItem());
	if (node)
		node->remove();
	setSelectedNode(node);

	*pResult = 0;
}

void DialogNodeNew::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	if (getSelectedItem() < 0) {
		MessageBeep(0);
		return;
	}
	
	Node *node = getNode(getSelectedItem());
	node->remove();
	setSelectedNode(node);

	CDialog::OnOK();
}
