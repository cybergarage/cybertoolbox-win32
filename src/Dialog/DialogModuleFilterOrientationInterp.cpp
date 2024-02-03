// DialogModuleFilterOrientationInterp.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogModuleFilterOrientationInterp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogModuleFilterOrientationInterp ダイアログ


DialogModuleFilterOrientationInterp::DialogModuleFilterOrientationInterp(CWnd* pParent /*=NULL*/)
	: CDialog(DialogModuleFilterOrientationInterp::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogModuleFilterOrientationInterp)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogModuleFilterOrientationInterp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogModuleFilterOrientationInterp)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogModuleFilterOrientationInterp, CDialog)
	//{{AFX_MSG_MAP(DialogModuleFilterOrientationInterp)
	ON_NOTIFY(UDN_DELTAPOS, IDC_XSPIN1, OnDeltaposXspin1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_XSPIN3, OnDeltaposXspin3)
	ON_NOTIFY(UDN_DELTAPOS, IDC_YSPIN1, OnDeltaposYspin1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_YSPIN2, OnDeltaposYspin2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_ZSPIN1, OnDeltaposZspin1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_ZSPIN2, OnDeltaposZspin2)
	ON_NOTIFY(UDN_DELTAPOS, IDC_RSPIN1, OnDeltaposRspin1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_RSPIN2, OnDeltaposRspin2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogModuleFilterOrientationInterp メッセージ ハンドラ

BOOL DialogModuleFilterOrientationInterp::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	char value[256];

	char *moduleValue = getModule()->getValue();
	if (moduleValue) {
		float	xvalue1, xvalue2, yvalue1, yvalue2, zvalue1, zvalue2, rvalue1, rvalue2;
		if (sscanf(moduleValue, "%f,%f,%f,%f-%f,%f,%f,%f", &xvalue1, &yvalue1, &zvalue1, &rvalue1, &xvalue2, &yvalue2, &zvalue2, &rvalue2) == 8) {
			sprintf(value, "%g", xvalue1);
			SetDlgItemText(IDC_XVALUE1, value);

			sprintf(value, "%g", yvalue1);
			SetDlgItemText(IDC_YVALUE1, value);

			sprintf(value, "%g", zvalue1);
			SetDlgItemText(IDC_ZVALUE1, value);

			sprintf(value, "%g", rvalue1);
			SetDlgItemText(IDC_RVALUE1, value);

			sprintf(value, "%g", xvalue2);
			SetDlgItemText(IDC_XVALUE2, value);

			sprintf(value, "%g", yvalue2);
			SetDlgItemText(IDC_YVALUE2, value);

			sprintf(value, "%g", zvalue2);
			SetDlgItemText(IDC_ZVALUE2, value);

			sprintf(value, "%g", rvalue2);
			SetDlgItemText(IDC_RVALUE2, value);
		}
		else {
			SetDlgItemText(IDC_XVALUE1, "0");
			SetDlgItemText(IDC_YVALUE1, "0");
			SetDlgItemText(IDC_ZVALUE1, "0");
			SetDlgItemText(IDC_RVALUE1, "1");
			SetDlgItemText(IDC_XVALUE2, "0");
			SetDlgItemText(IDC_YVALUE2, "0");
			SetDlgItemText(IDC_ZVALUE2, "0");
			SetDlgItemText(IDC_RVALUE2, "1");
		}
	}
	else {
		SetDlgItemText(IDC_XVALUE1, "0");
		SetDlgItemText(IDC_YVALUE1, "0");
		SetDlgItemText(IDC_ZVALUE1, "0");
		SetDlgItemText(IDC_RVALUE1, "1");
		SetDlgItemText(IDC_XVALUE2, "0");
		SetDlgItemText(IDC_YVALUE2, "0");
		SetDlgItemText(IDC_ZVALUE2, "0");
		SetDlgItemText(IDC_RVALUE2, "1");
	}
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogModuleFilterOrientationInterp::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	char	string[256];
	float	xvalue1, xvalue2, yvalue1, yvalue2, zvalue1, zvalue2, rvalue1, rvalue2;

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
							GetDlgItemText(IDC_RVALUE1, string, 255);
							if (sscanf(string, "%f", &rvalue1) == 1) {
								GetDlgItemText(IDC_RVALUE2, string, 255);
								if (sscanf(string, "%f", &rvalue2) == 1) {
									sprintf(string, "%g,%g,%g,%g-%g,%g,%g,%g", xvalue1, yvalue1, zvalue1, rvalue1, xvalue2, yvalue2, zvalue2, rvalue2);
									getModule()->setValue(string);
								}
							}
						}
					}
				}
			}
		}
	}
	
	CDialog::OnOK();
}

void DialogModuleFilterOrientationInterp::OnDeltaposXspin1(NMHDR* pNMHDR, LRESULT* pResult) 
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

void DialogModuleFilterOrientationInterp::OnDeltaposXspin3(NMHDR* pNMHDR, LRESULT* pResult) 
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

void DialogModuleFilterOrientationInterp::OnDeltaposYspin1(NMHDR* pNMHDR, LRESULT* pResult) 
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

void DialogModuleFilterOrientationInterp::OnDeltaposYspin2(NMHDR* pNMHDR, LRESULT* pResult) 
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

void DialogModuleFilterOrientationInterp::OnDeltaposZspin1(NMHDR* pNMHDR, LRESULT* pResult) 
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

void DialogModuleFilterOrientationInterp::OnDeltaposZspin2(NMHDR* pNMHDR, LRESULT* pResult) 
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

void DialogModuleFilterOrientationInterp::OnDeltaposRspin1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	char string[256];
	GetDlgItemText(IDC_RVALUE1, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		sprintf(string, "%g", value - (float)pNMUpDown->iDelta);
		SetDlgItemText(IDC_RVALUE1, string);
	}
	
	*pResult = 0;
}

void DialogModuleFilterOrientationInterp::OnDeltaposRspin2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	char string[256];
	GetDlgItemText(IDC_RVALUE2, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		sprintf(string, "%g", value - (float)pNMUpDown->iDelta);
		SetDlgItemText(IDC_RVALUE2, string);
	}
	
	*pResult = 0;
}
