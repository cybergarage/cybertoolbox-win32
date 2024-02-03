// DialogModuleFilterScalarInterp.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogModuleFilterScalarInterp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogModuleFilterScalarInterp ダイアログ


DialogModuleFilterScalarInterp::DialogModuleFilterScalarInterp(CWnd* pParent /*=NULL*/)
	: CDialog(DialogModuleFilterScalarInterp::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogModuleFilterScalarInterp)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogModuleFilterScalarInterp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogModuleFilterScalarInterp)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogModuleFilterScalarInterp, CDialog)
	//{{AFX_MSG_MAP(DialogModuleFilterScalarInterp)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, OnDeltaposSpin1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN2, OnDeltaposSpin2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogModuleFilterScalarInterp メッセージ ハンドラ

BOOL DialogModuleFilterScalarInterp::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	char value[256];

	char *moduleValue = getModule()->getValue();
	if (moduleValue) {
		float	value1, value2;
		if (sscanf(moduleValue, "%f-%f", &value1, &value2) == 2) {
			sprintf(value, "%g", value1);
			SetDlgItemText(IDC_VALUE1, value);

			sprintf(value, "%g", value2);
			SetDlgItemText(IDC_VALUE2, value);
		}
		else {
			SetDlgItemText(IDC_VALUE1, "0");
			SetDlgItemText(IDC_VALUE2, "1");
		}
	}
	else {
		SetDlgItemText(IDC_VALUE1, "0");
		SetDlgItemText(IDC_VALUE2, "1");
	}
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogModuleFilterScalarInterp::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	char	string[256];
	float	value1, value2;

	GetDlgItemText(IDC_VALUE1, string, 255);
	if (sscanf(string, "%f", &value1) == 1) {
		GetDlgItemText(IDC_VALUE2, string, 255);
		if (sscanf(string, "%f", &value2) == 1) {
			sprintf(string, "%g-%g", value1, value2);
			getModule()->setValue(string);
		}
	}
	
	CDialog::OnOK();
}

void DialogModuleFilterScalarInterp::OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	char string[256];
	GetDlgItemText(IDC_VALUE1, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		sprintf(string, "%g", value - (float)pNMUpDown->iDelta);
		SetDlgItemText(IDC_VALUE1, string);
	}
	
	*pResult = 0;
}

void DialogModuleFilterScalarInterp::OnDeltaposSpin2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	char string[256];
	GetDlgItemText(IDC_VALUE2, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		sprintf(string, "%g", value - (float)pNMUpDown->iDelta);
		SetDlgItemText(IDC_VALUE2, string);
	}
	
	*pResult = 0;
}
