// DialogObjectCollision.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogObjectCollision.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogObjectCollision ダイアログ


DialogObjectCollision::DialogObjectCollision(CWnd* pParent /*=NULL*/)
	: CDialog(DialogObjectCollision::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogObjectCollision)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT

	setNode1(NULL);
	setNode2(NULL);
}


void DialogObjectCollision::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogObjectCollision)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogObjectCollision, CDialog)
	//{{AFX_MSG_MAP(DialogObjectCollision)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogObjectCollision メッセージ ハンドラ

BOOL DialogObjectCollision::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください

	TransformNode	*trans;
	char			*selectString = NULL;

	SendDlgItemMessage(IDC_OBJECT_NAME1, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	SendDlgItemMessage(IDC_OBJECT_NAME2, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);

	for (trans = GetWorld()->getSceneGraph()->findTransformNode(); trans; trans=trans->nextTraversal()) {
		if (trans && StringLength(trans->getName()) && StringNCompare(trans->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME))) {
			SendDlgItemMessage(IDC_OBJECT_NAME1, CB_ADDSTRING, 0, (LONG)(LPSTR)trans->getName());
			SendDlgItemMessage(IDC_OBJECT_NAME2, CB_ADDSTRING, 0, (LONG)(LPSTR)trans->getName());
		}
		if (!selectString)
			selectString = trans->getName();
	}

	Node *node;
	
	node = getNode1();
	if (node)
		SendDlgItemMessage(IDC_OBJECT_NAME1, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_OBJECT_NAME1, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);

	node = getNode2();
	if (node)
		SendDlgItemMessage(IDC_OBJECT_NAME2, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_OBJECT_NAME2, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);


	char	radiusString[256];

	sprintf(radiusString, "%g", getRadius1());
	SetDlgItemText(IDC_OBJECT_RADIUS1, radiusString);

	sprintf(radiusString, "%g", getRadius2());
	SetDlgItemText(IDC_OBJECT_RADIUS2, radiusString);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogObjectCollision::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	char	nodeName[256];
	
	GetDlgItemText(IDC_OBJECT_NAME1, nodeName, 256);
	setNode1(GetWorld()->getSceneGraph()->findTransformNode(nodeName));

	GetDlgItemText(IDC_OBJECT_NAME2, nodeName, 256);
	setNode2(GetWorld()->getSceneGraph()->findTransformNode(nodeName));

	char	radiusString[256];
	float	radius;

	GetDlgItemText(IDC_OBJECT_RADIUS1, radiusString, 255);
	radius = (float)atof(radiusString);
	if (radius <= 0.0f)
		radius = 1.0f;
	setRadius1(radius);

	GetDlgItemText(IDC_OBJECT_RADIUS2, radiusString, 255);
	radius = (float)atof(radiusString);
	if (radius <= 0.0f)
		radius = 1.0f;
	setRadius2(radius);

	CDialog::OnOK();
}
