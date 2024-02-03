// UserEventAreaPage.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "UserEventAreaPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// UserEventAreaPage プロパティ ページ

IMPLEMENT_DYNCREATE(UserEventAreaPage, CPropertyPage)

UserEventAreaPage::UserEventAreaPage() : CPropertyPage(UserEventAreaPage::IDD)
{
	//{{AFX_DATA_INIT(UserEventAreaPage)
		// メモ - ClassWizard はこの位置にメンバの初期化処理を追加します。
	//}}AFX_DATA_INIT
}

UserEventAreaPage::~UserEventAreaPage()
{
}

void UserEventAreaPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(UserEventAreaPage)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(UserEventAreaPage, CPropertyPage)
	//{{AFX_MSG_MAP(UserEventAreaPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// UserEventAreaPage メッセージ ハンドラ

BOOL UserEventAreaPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	setFont(this);
	setFont(GetDlgItem(IDC_CENTER_STATIC));
	setFont(GetDlgItem(IDC_SIZE_STATIC));
	setFont(GetDlgItem(IDC_CX_STATIC));
	setFont(GetDlgItem(IDC_CY_STATIC));
	setFont(GetDlgItem(IDC_CZ_STATIC));
	setFont(GetDlgItem(IDC_SX_STATIC));
	setFont(GetDlgItem(IDC_SY_STATIC));
	setFont(GetDlgItem(IDC_SZ_STATIC));
	setFont(GetDlgItem(IDC_CENTER_X));
	setFont(GetDlgItem(IDC_CENTER_Y));
	setFont(GetDlgItem(IDC_CENTER_Z));
	setFont(GetDlgItem(IDC_SIZE_X));
	setFont(GetDlgItem(IDC_SIZE_Y));
	setFont(GetDlgItem(IDC_SIZE_Z));

	SetDlgItemInt(IDC_CENTER_X, 0);
	SetDlgItemInt(IDC_CENTER_Y, 0);
	SetDlgItemInt(IDC_CENTER_Z, 0);
	SetDlgItemInt(IDC_SIZE_X, 1);
	SetDlgItemInt(IDC_SIZE_Y, 1);
	SetDlgItemInt(IDC_SIZE_Z, 1);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}
