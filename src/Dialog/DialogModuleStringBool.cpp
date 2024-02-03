// DialogModuleStringBool.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogModuleStringBool.h"
#include "StringFn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogModuleStringBool ダイアログ


DialogModuleStringBool::DialogModuleStringBool(CWnd* pParent /*=NULL*/)
	: CDialog(DialogModuleStringBool::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogModuleStringBool)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogModuleStringBool::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogModuleStringBool)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogModuleStringBool, CDialog)
	//{{AFX_MSG_MAP(DialogModuleStringBool)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogModuleStringBool メッセージ ハンドラ

BOOL DialogModuleStringBool::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	char *moduleValue = getModule()->getValue();
	if (StringCompareIgnoreCase(moduleValue, "TRUE") == 0 || StringCompareIgnoreCase(moduleValue, "0") == 0) 
		CheckRadioButton(IDC_TRUE_RADIO, IDC_FALSE_RADIO, IDC_TRUE_RADIO);
	else
		CheckRadioButton(IDC_TRUE_RADIO, IDC_FALSE_RADIO, IDC_FALSE_RADIO);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogModuleStringBool::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	int id = GetCheckedRadioButton(IDC_TRUE_RADIO, IDC_FALSE_RADIO);

	if (id == IDC_TRUE_RADIO)
		getModule()->setValue("true");
	else
		getModule()->setValue("false");
	
	CDialog::OnOK();
}

