// UserEventClockPage.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "UserEventClockPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// UserEventClockPage プロパティ ページ

IMPLEMENT_DYNCREATE(UserEventClockPage, CPropertyPage)

UserEventClockPage::UserEventClockPage() : CPropertyPage(UserEventClockPage::IDD)
{
	//{{AFX_DATA_INIT(UserEventClockPage)
		// メモ - ClassWizard はこの位置にメンバの初期化処理を追加します。
	//}}AFX_DATA_INIT
}

UserEventClockPage::~UserEventClockPage()
{
}

void UserEventClockPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(UserEventClockPage)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(UserEventClockPage, CPropertyPage)
	//{{AFX_MSG_MAP(UserEventClockPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// UserEventClockPage メッセージ ハンドラ

BOOL UserEventClockPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	setFont(this);
	setFont(GetDlgItem(IDC_FIELD_NAME));
	setFont(GetDlgItem(IDC_INTREVAL_TIME));
	setFont(GetDlgItem(IDC_FRAMESTRING));
	
	SetDlgItemInt(IDC_INTREVAL_TIME, 1);

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

