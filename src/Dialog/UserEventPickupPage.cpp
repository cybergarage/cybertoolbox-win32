// UserEventPickupPage.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "UserEventPickupPage.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// UserEventPickupPage プロパティ ページ

IMPLEMENT_DYNCREATE(UserEventPickupPage, CPropertyPage)

UserEventPickupPage::UserEventPickupPage() : CPropertyPage(UserEventPickupPage::IDD)
{
	//{{AFX_DATA_INIT(UserEventPickupPage)
		// メモ - ClassWizard はこの位置にメンバの初期化処理を追加します。
	//}}AFX_DATA_INIT
}

UserEventPickupPage::~UserEventPickupPage()
{
}

void UserEventPickupPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(UserEventPickupPage)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(UserEventPickupPage, CPropertyPage)
	//{{AFX_MSG_MAP(UserEventPickupPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// UserEventPickupPage メッセージ ハンドラ

BOOL UserEventPickupPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	setFont(this);
	setFont(GetDlgItem(IDC_FIELD_NAME));
	setFont(GetDlgItem(IDC_NODE_NAME));

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
	
	if (selectString)
		SendDlgItemMessage(IDC_NODE_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}
