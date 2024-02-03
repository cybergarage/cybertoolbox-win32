// DialogEventPickup.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogEventPickup.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogEventPickup ダイアログ


DialogEventPickup::DialogEventPickup(CWnd* pParent /*=NULL*/)
	: CDialog(DialogEventPickup::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogEventPickup)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogEventPickup::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogEventPickup)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogEventPickup, CDialog)
	//{{AFX_MSG_MAP(DialogEventPickup)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogEventPickup メッセージ ハンドラ

BOOL DialogEventPickup::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	CEvent *event = getEvent();
	TouchSensorNode *tsensor = (TouchSensorNode *)event->getSourceNode();

	char		*selectString = NULL;
	
	SendDlgItemMessage(IDC_NODE_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (Node *node = GetWorld()->getSceneGraph()->getNodes(); node; node=node->nextTraversal()) {
		if (node->isGroupingNode()) {
			if (StringLength(node->getName()) && StringNCompare(node->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME))) {
				SendDlgItemMessage(IDC_NODE_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)node->getName());
				if (!selectString)
					selectString = node->getName();
			}
		}
	}

	Node *parentNode = NULL;
	
	if (tsensor)
		parentNode = tsensor->getParentNode();

	char *nodeName = NULL;
	if (parentNode)
		nodeName = parentNode->getName();

	if (nodeName) {
		SendDlgItemMessage(IDC_NODE_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)nodeName);
	}
	else {
		if (selectString)
			SendDlgItemMessage(IDC_NODE_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	}
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogEventPickup::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	CEvent *event = getEvent();

	char nodeName[256];
	GetDlgItemText(IDC_NODE_NAME, nodeName, 256);
	
	if (strlen(nodeName))
		event->setOptionString(nodeName);
	else
		MessageBeep(0);

	CDialog::OnOK();
}
