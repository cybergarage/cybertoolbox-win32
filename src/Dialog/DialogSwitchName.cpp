// DialogSwitchName.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogSwitchName.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogSwitchName ダイアログ


DialogSwitchName::DialogSwitchName(CWnd* pParent /*=NULL*/)
	: CDialog(DialogSwitchName::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogSwitchName)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT

	setNode(NULL);
}


void DialogSwitchName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogSwitchName)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogSwitchName, CDialog)
	//{{AFX_MSG_MAP(DialogSwitchName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogSwitchName メッセージ ハンドラ

BOOL DialogSwitchName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	SwitchNode	*switchNode;
	char		*selectString = NULL;

	SendDlgItemMessage(IDC_SWITCH_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (switchNode = GetWorld()->getSceneGraph()->findSwitchNode(); switchNode; switchNode=switchNode->nextTraversal()) {
		if (switchNode && StringLength(switchNode->getName()) && StringNCompare(switchNode->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
			SendDlgItemMessage(IDC_SWITCH_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)switchNode->getName());
		if (!selectString)
			selectString = switchNode->getName();
	}

	Node	*node	= getNode();
	if (node)
		SendDlgItemMessage(IDC_SWITCH_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_SWITCH_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogSwitchName::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	char	nodeName[256];
	
	GetDlgItemText(IDC_SWITCH_NAME, nodeName, 256-1);

	Node	*node	= GetWorld()->getSceneGraph()->findSwitchNode(nodeName);
	setNode(node);
	
	CDialog::OnOK();
}
