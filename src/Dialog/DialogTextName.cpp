// DialogTextName.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogTextName.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogTextName ダイアログ


DialogTextName::DialogTextName(CWnd* pParent /*=NULL*/)
	: CDialog(DialogTextName::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogTextName)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT

	setNode(NULL);
}


void DialogTextName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogTextName)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogTextName, CDialog)
	//{{AFX_MSG_MAP(DialogTextName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogTextName メッセージ ハンドラ

BOOL DialogTextName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	TextNode	*text;
	char			*selectString = NULL;

	SendDlgItemMessage(IDC_TEXT_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (text = GetWorld()->getSceneGraph()->findTextNode(); text; text=text->nextTraversal()) {
		if (text && StringLength(text->getName()) && StringNCompare(text->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
			SendDlgItemMessage(IDC_TEXT_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)text->getName());
		if (!selectString)
			selectString = text->getName();
	}

	Node	*node	= getNode();
	if (node)
		SendDlgItemMessage(IDC_TEXT_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_TEXT_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogTextName::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	char	nodeName[256];
	
	GetDlgItemText(IDC_TEXT_NAME, nodeName, 256-1);

	Node	*node	= GetWorld()->getSceneGraph()->findTextNode(nodeName);
	setNode(node);
	
	CDialog::OnOK();
}
