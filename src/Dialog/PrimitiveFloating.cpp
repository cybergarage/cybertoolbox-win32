// PrimitiveFloating.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "..\CyberToolBoxDoc.h"
#include "..\CyberToolBoxView.h"
#include "PrimitiveFloating.h"
#include "RegKey.h"
#include "..\OrthoView.h"
#include "..\PerspectiveView.h"
#include "World.h"
#include "CUndoActionFn.h"

#ifndef PI
#define PI 3.1415926535897f
#endif

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PrimitiveFloating ダイアログ


PrimitiveFloating::PrimitiveFloating(CWnd* pParent /*=NULL*/)
	: CDialog(PrimitiveFloating::IDD, pParent)
{
	//{{AFX_DATA_INIT(PrimitiveFloating)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void PrimitiveFloating::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PrimitiveFloating)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PrimitiveFloating, CDialog)
	//{{AFX_MSG_MAP(PrimitiveFloating)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PrimitiveFloating メッセージ ハンドラ

BOOL PrimitiveFloating::Create(CWnd* pParent) 
{
	return CDialog::Create(PrimitiveFloating::IDD, pParent);
}

BOOL PrimitiveFloating::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください

	return CDialog::PreCreateWindow(cs);
}

void PrimitiveFloating::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	int type = point.x / 48;
	setPrimitiveType(type);
	
	switch (getPrimitiveType()) {
	case PRIMITIVE_TYPE_BOX:
		SetCursor(AfxGetApp()->LoadCursor(IDC_PRIMITIVE_BOX));
		break;
	case PRIMITIVE_TYPE_CONE:
		SetCursor(AfxGetApp()->LoadCursor(IDC_PRIMITIVE_CONE));
		break;
	case PRIMITIVE_TYPE_SPHERE:
		SetCursor(AfxGetApp()->LoadCursor(IDC_PRIMITIVE_SPHERE));
		break;
	case PRIMITIVE_TYPE_CYLINDER:
		SetCursor(AfxGetApp()->LoadCursor(IDC_PRIMITIVE_CYLINDER));
		break;
	case PRIMITIVE_TYPE_TEXT:
		SetCursor(AfxGetApp()->LoadCursor(IDC_PRIMITIVE_TEXT));
		break;
	case PRIMITIVE_TYPE_POLYGON:
		SetCursor(AfxGetApp()->LoadCursor(IDC_PRIMITIVE_POLYGON));
		break;
	default:
		return;
	}

	CtbModuleFloatingShowWindow(SW_HIDE);

	SetCapture();
	
	CDialog::OnLButtonDown(nFlags, point);
}

void PrimitiveFloating::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));
	ReleaseCapture();

	ClientToScreen(&point);

	CWnd		*dropWindow	= WindowFromPoint(point);
	OrthoView	*orthoView	= CtbGetOrthoView();
	
	if (dropWindow == orthoView) {
		CWaitCursor cursor;

		POINT	pos;
		pos.x = point.x;
		pos.y = point.y;
		orthoView->ScreenToClient(&pos);
		float x, y, z;
		orthoView->windowToWorld(pos.x, pos.y, x, y, z);
		
		PerspectiveView *pview = CtbGetPerspectiveView();
		wglMakeCurrent(pview->oglHdc, pview->oglHrc);

		if (orthoView->isSnapOn()) {
			switch (orthoView->getViewMode()) {
			case ORTHO_XY_PLANE:
				orthoView->transformToSnapPositoin(x, y);
				break;
			case ORTHO_YZ_PLANE:
				orthoView->transformToSnapPositoin(z, y);
				break;
			case ORTHO_XZ_PLANE:	
				orthoView->transformToSnapPositoin(x, z);
				break;
			}
		}

		TransformNode *transNode = new TransformNode();
		transNode->setTranslation(x, y, z);
		switch (orthoView->getViewMode()) {
		case ORTHO_XY_PLANE:
			//transNode->setRotation(1.0f, 0.0f, 0.0f, PI/2.0f);
			transNode->setRotation(0.0f, 0.0f, 1.0f, 0.0f);
			break;
		case ORTHO_YZ_PLANE:
			//transNode->setRotation(0.0f, 0.0f, 1.0f, PI/2.0f);
			transNode->setRotation(0.0f, 1.0f, 0.0f, -PI/2.0f);
			break;
		case ORTHO_XZ_PLANE:	
			//transNode->setRotation(1.0f, 0.0f, 0.0f, -PI);
			transNode->setRotation(1.0f, 0.0f, 0.0f, -PI/2.0f);
			break;
		}
		
		float gridSize = orthoView->getGridSize();
		transNode->setScale(gridSize, gridSize, gridSize); 

		SceneGraph *sg = GetWorld()->getSceneGraph();
		sg->addNode(transNode);

		ShapeNode *shapeNode = new ShapeNode();
		transNode->addChildNode(shapeNode);

		AppearanceNode *appNode = new AppearanceNode();
		shapeNode->addChildNode(appNode);

		MaterialNode *material = new MaterialNode();
		material->setName(getMaterialName(getPrimitiveType()));
		appNode->addChildNode(material);

		Node *primitiveNode = NULL;
		switch (getPrimitiveType()) {
		case PRIMITIVE_TYPE_BOX:
			primitiveNode = new BoxNode();
			CtbModuleFloatingShowWindow(SW_SHOW);
			break;
		case PRIMITIVE_TYPE_CONE:
			primitiveNode = new ConeNode();
			CtbModuleFloatingShowWindow(SW_SHOW);
			break;
		case PRIMITIVE_TYPE_SPHERE:
			primitiveNode = new SphereNode();
			CtbModuleFloatingShowWindow(SW_SHOW);
			break;
		case PRIMITIVE_TYPE_CYLINDER:
			primitiveNode = new CylinderNode();
			CtbModuleFloatingShowWindow(SW_SHOW);
			break;
		case PRIMITIVE_TYPE_TEXT:
			primitiveNode = new TextNode();
			CtbPrimitiveFloatingShowWindow(SW_HIDE);
			break;
		case PRIMITIVE_TYPE_POLYGON:
			primitiveNode = new IndexedLineSetNode();
			transNode->setTranslation(0.0f, 0.0f, 0.0f);
			transNode->setRotation(0.0f, 0.0f, 1.0f, 0.0f);
			CtbPrimitiveFloatingShowWindow(SW_HIDE);
			break;
		default:
			return;
		}
		
		char *name = getPrimitiveName(getPrimitiveType());
		transNode->setName(name);

		shapeNode->addChildNode(primitiveNode);

		sg->initialize();

		CtbGetTreeView()->addSceneGraphNode(transNode, (Node *)NULL);
		orthoView->enqueue(UndoOrthoViewCreatePrimitiveNew(transNode), UndoOrthoViewCreatePrimitiveFn);

		wglMakeCurrent(NULL, NULL);

		orthoView->setEditPrimitiveTransformNode(transNode);

		CtbUpdatePerspectiveView();
		CtbUpdateOrthoView();
	}
	else {
		CtbModuleFloatingShowWindow(SW_SHOW);
	}

	if (dropWindow == orthoView) {
		switch (getPrimitiveType()) {
		case PRIMITIVE_TYPE_TEXT:
			orthoView->setOperationMode(OPERATION_PRMITIVE_EDIT_TEXT);
			SetCursor(AfxGetApp()->LoadCursor(IDC_PRIMITIVE_TEXT));
			orthoView->SetForegroundWindow();
			orthoView->SetCapture();
			orthoView->SetFocus();
			break;
		case PRIMITIVE_TYPE_POLYGON:
			orthoView->setOperationMode(OPERATION_PRMITIVE_EDIT_POLYGON);
			SetCursor(AfxGetApp()->LoadCursor(IDC_PICK));
			orthoView->SetForegroundWindow();
			orthoView->SetCapture();
			orthoView->SetFocus();
			break;
		}
		orthoView->InvalidateRect(NULL);
		orthoView->UpdateWindow();
	}

	ScreenToClient(&point);

	CDialog::OnLButtonUp(nFlags, point);
}

BOOL PrimitiveFloating::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください

	int	x, y, width, height;
	if (RegKeyGetValue(REGKEY_SECTION_POSITION, REGKEY_KEY_POSITION_ORTHOVIEW, &x, &y, &width, &height)) {
		RECT rect;
		GetClientRect(&rect);
		SetWindowPos(NULL, x+width-rect.right, y, 0, 0, SWP_NOSIZE);
	}

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

char *PrimitiveFloating::getPrimitiveName(int primitiveType)
{
	static char primitiveName[256];
	char buffer[256];

	strcpy(primitiveName, "");
	
	int n = 0;
	while(strlen(primitiveName) <= 0) {
		switch (primitiveType) {
		case PRIMITIVE_TYPE_BOX:
			strcpy(primitiveName, "box");
			break;
		case PRIMITIVE_TYPE_CONE:
			strcpy(primitiveName, "cone");
			break;
		case PRIMITIVE_TYPE_SPHERE:
			strcpy(primitiveName, "sphere");
			break;
		case PRIMITIVE_TYPE_CYLINDER:
			strcpy(primitiveName, "cylinder");
			break;
		case PRIMITIVE_TYPE_TEXT:
			strcpy(primitiveName, "text");
			break;
		case PRIMITIVE_TYPE_POLYGON:
			strcpy(primitiveName, "polygon");
			break;
		default:
			return "";
		}

		strcat(primitiveName, itoa(n, buffer, 10));

		SceneGraph *sg = GetWorld()->getSceneGraph();
		
		if (sg->findNode(primitiveName) != NULL)
			strcpy(primitiveName, "");

		n++;
	}

	return primitiveName;
}

char *PrimitiveFloating::getMaterialName(int primitiveType)
{
	static char primitiveName[256];
	char buffer[256];

	strcpy(primitiveName, "");
	
	int n = 0;
	while(strlen(primitiveName) <= 0) {
		switch (primitiveType) {
		case PRIMITIVE_TYPE_BOX:
			strcpy(primitiveName, "boxMaterial");
			break;
		case PRIMITIVE_TYPE_CONE:
			strcpy(primitiveName, "coneMaterial");
			break;
		case PRIMITIVE_TYPE_SPHERE:
			strcpy(primitiveName, "sphereMaterial");
			break;
		case PRIMITIVE_TYPE_CYLINDER:
			strcpy(primitiveName, "cylinderMaterial");
			break;
		case PRIMITIVE_TYPE_TEXT:
			strcpy(primitiveName, "textMaterial");
			break;
		case PRIMITIVE_TYPE_POLYGON:
			strcpy(primitiveName, "polygonMaterial");
			break;
		default:
			return "";
		}

		strcat(primitiveName, itoa(n, buffer, 10));

		SceneGraph *sg = GetWorld()->getSceneGraph();
		
		if (sg->findNode(primitiveName) != NULL)
			strcpy(primitiveName, "");

		n++;
	}

	return primitiveName;
}

