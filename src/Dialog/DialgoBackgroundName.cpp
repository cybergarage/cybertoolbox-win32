// DialgoBackgroundName.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialgoBackgroundName.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialgoBackgroundName ダイアログ


DialgoBackgroundName::DialgoBackgroundName(CWnd* pParent /*=NULL*/)
	: CDialog(DialgoBackgroundName::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialgoBackgroundName)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT

	setNode(NULL);
}


void DialgoBackgroundName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialgoBackgroundName)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialgoBackgroundName, CDialog)
	//{{AFX_MSG_MAP(DialgoBackgroundName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialgoBackgroundName メッセージ ハンドラ

BOOL DialgoBackgroundName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	BackgroundNode	*bg;
	char			*selectString = NULL;

	SendDlgItemMessage(IDC_BACKGROUND_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (bg = GetWorld()->getSceneGraph()->findBackgroundNode(); bg; bg=bg->nextTraversal()) {
		if (bg && StringLength(bg->getName()) && StringNCompare(bg->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
			SendDlgItemMessage(IDC_BACKGROUND_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)bg->getName());
		if (!selectString)
			selectString = bg->getName();
	}

	Node	*node	= getNode();
	if (node)
		SendDlgItemMessage(IDC_BACKGROUND_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_BACKGROUND_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialgoBackgroundName::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	char	nodeName[256];
	
	GetDlgItemText(IDC_BACKGROUND_NAME, nodeName, 256-1);

	Node	*node	= GetWorld()->getSceneGraph()->findBackgroundNode(nodeName);
	setNode(node);
	
	CDialog::OnOK();
}
