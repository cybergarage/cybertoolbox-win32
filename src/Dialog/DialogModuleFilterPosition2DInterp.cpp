// DialogModuleFilterPosition2DInterp.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogModuleFilterPosition2DInterp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogModuleFilterPosition2DInterp ダイアログ


DialogModuleFilterPosition2DInterp::DialogModuleFilterPosition2DInterp(CWnd* pParent /*=NULL*/)
	: CDialog(DialogModuleFilterPosition2DInterp::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogModuleFilterPosition2DInterp)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogModuleFilterPosition2DInterp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogModuleFilterPosition2DInterp)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogModuleFilterPosition2DInterp, CDialog)
	//{{AFX_MSG_MAP(DialogModuleFilterPosition2DInterp)
	ON_NOTIFY(UDN_DELTAPOS, IDC_XSPIN1, OnDeltaposXspin1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_XSPIN2, OnDeltaposXspin2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_YSPIN1, OnDeltaposYspin1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_YSPIN2, OnDeltaposYspin2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogModuleFilterPosition2DInterp メッセージ ハンドラ

BOOL DialogModuleFilterPosition2DInterp::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	char value[256];

	char *moduleValue = getModule()->getValue();
	if (moduleValue) {
		float	xvalue1, xvalue2, yvalue1, yvalue2;
		if (sscanf(moduleValue, "%f,%f-%f,%f", &xvalue1, &yvalue1, &xvalue2, &yvalue2) == 4) {
			sprintf(value, "%g", xvalue1);
			SetDlgItemText(IDC_XVALUE1, value);

			sprintf(value, "%g", yvalue1);
			SetDlgItemText(IDC_YVALUE1, value);

			sprintf(value, "%g", xvalue2);
			SetDlgItemText(IDC_XVALUE2, value);

			sprintf(value, "%g", yvalue2);
			SetDlgItemText(IDC_YVALUE2, value);
		}
		else {
			SetDlgItemText(IDC_XVALUE1, "0");
			SetDlgItemText(IDC_YVALUE1, "0");
			SetDlgItemText(IDC_XVALUE2, "0");
			SetDlgItemText(IDC_YVALUE2, "0");
		}
	}
	else {
		SetDlgItemText(IDC_XVALUE1, "0");
		SetDlgItemText(IDC_YVALUE1, "0");
		SetDlgItemText(IDC_XVALUE2, "0");
		SetDlgItemText(IDC_YVALUE2, "0");
	}
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogModuleFilterPosition2DInterp::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	char	string[256];
	float	xvalue1, xvalue2, yvalue1, yvalue2;

	GetDlgItemText(IDC_XVALUE1, string, 255);
	if (sscanf(string, "%f", &xvalue1) == 1) {
		GetDlgItemText(IDC_XVALUE2, string, 255);
		if (sscanf(string, "%f", &xvalue2) == 1) {
			GetDlgItemText(IDC_YVALUE1, string, 255);
			if (sscanf(string, "%f", &yvalue1) == 1) {
				GetDlgItemText(IDC_YVALUE2, string, 255);
				if (sscanf(string, "%f", &yvalue2) == 1) {
					sprintf(string, "%g,%g-%g,%g", xvalue1, yvalue1, xvalue2, yvalue2);
					getModule()->setValue(string);
				}
			}
		}
	}
	
	CDialog::OnOK();
}

void DialogModuleFilterPosition2DInterp::OnDeltaposXspin1(NMHDR* pNMHDR, LRESULT* pResult) 
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

void DialogModuleFilterPosition2DInterp::OnDeltaposXspin2(NMHDR* pNMHDR, LRESULT* pResult) 
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

void DialogModuleFilterPosition2DInterp::OnDeltaposYspin1(NMHDR* pNMHDR, LRESULT* pResult) 
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

void DialogModuleFilterPosition2DInterp::OnDeltaposYspin2(NMHDR* pNMHDR, LRESULT* pResult) 
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
