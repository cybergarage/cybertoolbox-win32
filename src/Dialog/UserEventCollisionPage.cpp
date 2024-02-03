// UserEventCollisionPage.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "UserEventCollisionPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// UserEventCollisionPage プロパティ ページ

IMPLEMENT_DYNCREATE(UserEventCollisionPage, CPropertyPage)

UserEventCollisionPage::UserEventCollisionPage() : CPropertyPage(UserEventCollisionPage::IDD)
{
	//{{AFX_DATA_INIT(UserEventCollisionPage)
		// メモ - ClassWizard はこの位置にメンバの初期化処理を追加します。
	//}}AFX_DATA_INIT
}

UserEventCollisionPage::~UserEventCollisionPage()
{
}

void UserEventCollisionPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(UserEventCollisionPage)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(UserEventCollisionPage, CPropertyPage)
	//{{AFX_MSG_MAP(UserEventCollisionPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// UserEventCollisionPage メッセージ ハンドラ

BOOL UserEventCollisionPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	setFont(this);
	setFont(GetDlgItem(IDC_OBJECT1_NAME));
	setFont(GetDlgItem(IDC_OBJECT2_NAME));
	setFont(GetDlgItem(IDC_OBJECT1_RADIUS));
	setFont(GetDlgItem(IDC_OBJECT2_RADIUS));
	setFont(GetDlgItem(IDC_OBJECT1_NAME_STRING));
	setFont(GetDlgItem(IDC_OBJECT2_NAME_STRING));
	setFont(GetDlgItem(IDC_OBJECT1_RADIUS_STRING));
	setFont(GetDlgItem(IDC_OBJECT2_RADIUS_STRING));
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}
