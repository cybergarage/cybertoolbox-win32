// DialogModuleFilterPosition3DInterp.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogModuleFilterPosition3DInterp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogModuleFilterPosition3DInterp ダイアログ


DialogModuleFilterPosition3DInterp::DialogModuleFilterPosition3DInterp(CWnd* pParent /*=NULL*/)
	: CDialog(DialogModuleFilterPosition3DInterp::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogModuleFilterPosition3DInterp)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogModuleFilterPosition3DInterp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogModuleFilterPosition3DInterp)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogModuleFilterPosition3DInterp, CDialog)
	//{{AFX_MSG_MAP(DialogModuleFilterPosition3DInterp)
	ON_NOTIFY(UDN_DELTAPOS, IDC_XSPIN1, OnDeltaposXspin1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_XSPIN2, OnDeltaposXspin2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_YSPIN1, OnDeltaposYspin1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_YSPIN2, OnDeltaposYspin2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_ZSPIN1, OnDeltaposZspin1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_ZSPIN2, OnDeltaposZspin2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogModuleFilterPosition3DInterp メッセージ ハンドラ

BOOL DialogModuleFilterPosition3DInterp::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	char value[256];

	char *moduleValue = getModule()->getValue();
	if (moduleValue) {
		float	xvalue1, xvalue2, yvalue1, yvalue2, zvalue1, zvalue2;
		if (sscanf(moduleValue, "%f,%f,%f-%f,%f,%f", &xvalue1, &yvalue1, &zvalue1, &xvalue2, &yvalue2, &zvalue2) == 6) {
			sprintf(value, "%g", xvalue1);
			SetDlgItemText(IDC_XVALUE1, value);

			sprintf(value, "%g", yvalue1);
			SetDlgItemText(IDC_YVALUE1, value);

			sprintf(value, "%g", zvalue1);
			SetDlgItemText(IDC_ZVALUE1, value);

			sprintf(value, "%g", xvalue2);
			SetDlgItemText(IDC_XVALUE2, value);

			sprintf(value, "%g", yvalue2);
			SetDlgItemText(IDC_YVALUE2, value);

			sprintf(value, "%g", zvalue2);
			SetDlgItemText(IDC_ZVALUE2, value);
		}
		else {
			SetDlgItemText(IDC_XVALUE1, "0");
			SetDlgItemText(IDC_YVALUE1, "0");
			SetDlgItemText(IDC_ZVALUE1, "0");
			SetDlgItemText(IDC_XVALUE2, "0");
			SetDlgItemText(IDC_YVALUE2, "0");
			SetDlgItemText(IDC_ZVALUE2, "0");
		}
	}
	else {
		SetDlgItemText(IDC_XVALUE1, "0");
		SetDlgItemText(IDC_YVALUE1, "0");
		SetDlgItemText(IDC_ZVALUE1, "0");
		SetDlgItemText(IDC_XVALUE2, "0");
		SetDlgItemText(IDC_YVALUE2, "0");
		SetDlgItemText(IDC_ZVALUE2, "0");
	}
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogModuleFilterPosition3DInterp::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	char	string[256];
	float	xvalue1, xvalue2, yvalue1, yvalue2, zvalue1, zvalue2;

	GetDlgItemText(IDC_XVALUE1, string, 255);
	if (sscanf(string, "%f", &xvalue1) == 1) {
		GetDlgItemText(IDC_XVALUE2, string, 255);
		if (sscanf(string, "%f", &xvalue2) == 1) {
			GetDlgItemText(IDC_YVALUE1, string, 255);
			if (sscanf(string, "%f", &yvalue1) == 1) {
				GetDlgItemText(IDC_YVALUE2, string, 255);
				if (sscanf(string, "%f", &yvalue2) == 1) {
					GetDlgItemText(IDC_ZVALUE1, string, 255);
					if (sscanf(string, "%f", &zvalue1) == 1) {
						GetDlgItemText(IDC_ZVALUE2, string, 255);
						if (sscanf(string, "%f", &zvalue2) == 1) {
							sprintf(string, "%g,%g,%g-%g,%g,%g", xvalue1, yvalue1, zvalue1, xvalue2, yvalue2, zvalue2);
							getModule()->setValue(string);
						}
					}
				}
			}
		}
	}
	
	CDialog::OnOK();
}

void DialogModuleFilterPosition3DInterp::OnDeltaposXspin1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	char string[256];
	GetDlgItemText(IDC_XVALUE1, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		sprintf(string, "%g", value - (float)pNMUpDown->iDelta);
		SetDlgItemText(IDC_XVALUE1, string);
	}
	
	*pResult = 0;
}

void DialogModuleFilterPosition3DInterp::OnDeltaposXspin2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	char string[256];
	GetDlgItemText(IDC_XVALUE2, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		sprintf(string, "%g", value - (float)pNMUpDown->iDelta);
		SetDlgItemText(IDC_XVALUE2, string);
	}
	
	*pResult = 0;
}

void DialogModuleFilterPosition3DInterp::OnDeltaposYspin1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	char string[256];
	GetDlgItemText(IDC_YVALUE1, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		sprintf(string, "%g", value - (float)pNMUpDown->iDelta);
		SetDlgItemText(IDC_YVALUE1, string);
	}
	
	*pResult = 0;
}

void DialogModuleFilterPosition3DInterp::OnDeltaposYspin2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	char string[256];
	GetDlgItemText(IDC_YVALUE2, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		sprintf(string, "%g", value - (float)pNMUpDown->iDelta);
		SetDlgItemText(IDC_YVALUE2, string);
	}
	
	*pResult = 0;
}

void DialogModuleFilterPosition3DInterp::OnDeltaposZspin1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	char string[256];
	GetDlgItemText(IDC_ZVALUE1, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		sprintf(string, "%g", value - (float)pNMUpDown->iDelta);
		SetDlgItemText(IDC_ZVALUE1, string);
	}
	
	*pResult = 0;
}

void DialogModuleFilterPosition3DInterp::OnDeltaposZspin2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	char string[256];
	GetDlgItemText(IDC_ZVALUE2, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		sprintf(string, "%g", value - (float)pNMUpDown->iDelta);
		SetDlgItemText(IDC_ZVALUE2, string);
	}
	
	*pResult = 0;
}
