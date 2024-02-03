// DialogFilterScale.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogFilterScale.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogFilterScale ダイアログ


DialogFilterScale::DialogFilterScale(CWnd* pParent /*=NULL*/)
	: CDialog(DialogFilterScale::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogFilterScale)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogFilterScale::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogFilterScale)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogFilterScale, CDialog)
	//{{AFX_MSG_MAP(DialogFilterScale)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogFilterScale メッセージ ハンドラ

BOOL DialogFilterScale::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	char buffer[256];
	char *value = getModule()->getValue();
	sprintf(buffer, "%g", atof(value));
	SetDlgItemText(IDC_VALUE, buffer);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogFilterScale::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	char	dlgString[256];
	char	valueString[256];
	GetDlgItemText(IDC_VALUE, dlgString, 256);
	sprintf(valueString, "%g", atof(dlgString));
	getModule()->setValue(valueString);
	
	CDialog::OnOK();
}
