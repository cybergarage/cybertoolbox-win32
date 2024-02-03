// DialogModuleStringPosition.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogModuleStringPosition.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogModuleStringPosition ダイアログ


DialogModuleStringPosition::DialogModuleStringPosition(CWnd* pParent /*=NULL*/)
	: CDialog(DialogModuleStringPosition::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogModuleStringPosition)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogModuleStringPosition::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogModuleStringPosition)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogModuleStringPosition, CDialog)
	//{{AFX_MSG_MAP(DialogModuleStringPosition)
	ON_NOTIFY(UDN_DELTAPOS, IDC_XSPIN, OnDeltaposXspin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_YSPIN, OnDeltaposYspin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_ZSPIN, OnDeltaposZspin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogModuleStringPosition メッセージ ハンドラ

BOOL DialogModuleStringPosition::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	char value[256];

	SetDlgItemText(IDC_XVALUE, "0");
	SetDlgItemText(IDC_YVALUE, "0");
	SetDlgItemText(IDC_ZVALUE, "0");

	char *moduleValue = getModule()->getValue();
	if (moduleValue) {
		float	x, y, z;
		if (sscanf(moduleValue, "%f,%f,%f", &x, &y, &z) == 3) {
			sprintf(value, "%g", x);
			SetDlgItemText(IDC_XVALUE, value);

			sprintf(value, "%g", y);
			SetDlgItemText(IDC_YVALUE, value);

			sprintf(value, "%g", z);
			SetDlgItemText(IDC_ZVALUE, value);
		}
	}
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogModuleStringPosition::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	char	string[256];
	float	x, y, z;

	GetDlgItemText(IDC_XVALUE, string, 255);
	if (sscanf(string, "%f", &x) == 1) {
		GetDlgItemText(IDC_YVALUE, string, 255);
		if (sscanf(string, "%f", &y) == 1) {
			GetDlgItemText(IDC_ZVALUE, string, 255);
			if (sscanf(string, "%f", &z) == 1) {
				sprintf(string, "%g,%g,%g", x, y, z);
				getModule()->setValue(string);
			}
		}
	}
	
	CDialog::OnOK();
}

void DialogModuleStringPosition::OnDeltaposXspin(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	char string[256];
	GetDlgItemText(IDC_XVALUE, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		sprintf(string, "%g", value - (float)pNMUpDown->iDelta);
		SetDlgItemText(IDC_XVALUE, string);
	}
	
	*pResult = 0;
}

void DialogModuleStringPosition::OnDeltaposYspin(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	char string[256];
	GetDlgItemText(IDC_YVALUE, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		sprintf(string, "%g", value - (float)pNMUpDown->iDelta);
		SetDlgItemText(IDC_YVALUE, string);
	}
	
	*pResult = 0;
}

void DialogModuleStringPosition::OnDeltaposZspin(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	char string[256];
	GetDlgItemText(IDC_ZVALUE, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		sprintf(string, "%g", value - (float)pNMUpDown->iDelta);
		SetDlgItemText(IDC_ZVALUE, string);
	}
	
	*pResult = 0;
}
