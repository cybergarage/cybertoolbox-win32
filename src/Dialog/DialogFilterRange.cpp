// DialogFilterRange.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogFilterRange.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogFilterRange ダイアログ


DialogFilterRange::DialogFilterRange(CWnd* pParent /*=NULL*/)
	: CDialog(DialogFilterRange::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogFilterRange)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogFilterRange::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogFilterRange)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogFilterRange, CDialog)
	//{{AFX_MSG_MAP(DialogFilterRange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogFilterRange メッセージ ハンドラ

BOOL DialogFilterRange::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	char buffer[256];
	char *value = getModule()->getValue();
	float minValue, maxValue;

	if (sscanf(value, "%f,%f", &minValue, &maxValue) != 2) {
		minValue = 0;
		maxValue = 0;
	}
	sprintf(buffer, "%g", minValue);
	SetDlgItemText(IDC_MIN_VALUE, buffer);
	sprintf(buffer, "%g", maxValue);
	SetDlgItemText(IDC_MAX_VALUE, buffer);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogFilterRange::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	char	dlgString[256];
	char	valueString[256];
	float	minValue, maxValue;
	GetDlgItemText(IDC_MIN_VALUE, dlgString, 256);
	minValue = (float)atof(dlgString);
	GetDlgItemText(IDC_MAX_VALUE, dlgString, 256);
	maxValue = (float)atof(dlgString);
	sprintf(valueString, "%g,%g", minValue, maxValue);
	getModule()->setValue(valueString);
	
	CDialog::OnOK();
}
