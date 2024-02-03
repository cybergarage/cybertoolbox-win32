// UserEventTimerPage.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "UserEventTimerPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// UserEventTimerPage プロパティ ページ

IMPLEMENT_DYNCREATE(UserEventTimerPage, CPropertyPage)

UserEventTimerPage::UserEventTimerPage() : CPropertyPage(UserEventTimerPage::IDD)
{
	//{{AFX_DATA_INIT(UserEventTimerPage)
		// メモ - ClassWizard はこの位置にメンバの初期化処理を追加します。
	//}}AFX_DATA_INIT
}

UserEventTimerPage::~UserEventTimerPage()
{
}

void UserEventTimerPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(UserEventTimerPage)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(UserEventTimerPage, CPropertyPage)
	//{{AFX_MSG_MAP(UserEventTimerPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// UserEventTimerPage メッセージ ハンドラ

BOOL UserEventTimerPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	setFont(this);
	setFont(GetDlgItem(IDC_FIELD_NAME));
	setFont(GetDlgItem(IDC_WAKEUP_TIME));
	setFont(GetDlgItem(IDC_FRAMESTRING));
	
	SetDlgItemInt(IDC_WAKEUP_TIME, 1);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}
