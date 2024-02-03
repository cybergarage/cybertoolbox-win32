// DialogObjectName.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogObjectName.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogObjectName ダイアログ


DialogObjectName::DialogObjectName(CWnd* pParent /*=NULL*/)
	: CDialog(DialogObjectName::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogObjectName)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT

	setNode(NULL);
}


void DialogObjectName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogObjectName)
                // メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogObjectName, CDialog)
	//{{AFX_MSG_MAP(DialogObjectName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogObjectName メッセージ ハンドラ

BOOL DialogObjectName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	TransformNode	*trans;
	char			*selectString = NULL;

	SendDlgItemMessage(IDC_OBJECTNAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (trans = GetWorld()->getSceneGraph()->findTransformNode(); trans; trans=trans->nextTraversal()) {
		if (trans && StringLength(trans->getName()) && StringNCompare(trans->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
			SendDlgItemMessage(IDC_OBJECTNAME, CB_ADDSTRING, 0, (LONG)(LPSTR)trans->getName());
		if (!selectString)
			selectString = trans->getName();
	}

	Node	*node	= getNode();
	if (node)
		SendDlgItemMessage(IDC_OBJECTNAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_OBJECTNAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogObjectName::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	char	nodeName[256];
	
	GetDlgItemText(IDC_OBJECTNAME, nodeName, 256-1);

	Node	*node	= GetWorld()->getSceneGraph()->findTransformNode(nodeName);
	setNode(node);

	CDialog::OnOK();
}
