// DialogViewName.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogViewName.h"
#include "World.h"
#include "CModule.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogViewName ダイアログ


DialogViewName::DialogViewName(CWnd* pParent /*=NULL*/)
	: CDialog(DialogViewName::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogViewName)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogViewName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogViewName)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogViewName, CDialog)
	//{{AFX_MSG_MAP(DialogViewName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogViewName メッセージ ハンドラ

BOOL DialogViewName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	ViewpointNode	*view;
	char		*selectString = NULL;

	SendDlgItemMessage(IDC_VIEW_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (view = GetWorld()->getSceneGraph()->findViewpointNode(); view; view=view->nextTraversal()) {
		if (view && StringLength(view->getName()) && StringNCompare(view->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
			SendDlgItemMessage(IDC_VIEW_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)view->getName());
		if (!selectString)
			selectString = view->getName();
	}

	Node	*node	= getNode();

	if (node)
		SendDlgItemMessage(IDC_VIEW_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_VIEW_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogViewName::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	char	nodeName[256];
	
	GetDlgItemText(IDC_VIEW_NAME, nodeName, 256);

	Node	*node	= GetWorld()->getSceneGraph()->findViewpointNode(nodeName);
	setNode(node);
	
	CDialog::OnOK();
}
