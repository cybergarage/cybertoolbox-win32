// DialogSFRotationConfig.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogSFRotationConfig.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifndef PI
#define PI 3.1415926535897
//#define PI 3.141592653589793238462643383279

inline double Degree2Radian(double degree)
{
	return (degree / 180.0 * PI);
}

inline double Radian2Degree(double radian)
{
	return (radian / PI * 180.0);
}

#endif

/////////////////////////////////////////////////////////////////////////////
// DialogSFRotationConfig ダイアログ


DialogSFRotationConfig::DialogSFRotationConfig(CWnd* pParent /*=NULL*/)
	: CDialog(DialogSFRotationConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogSFRotationConfig)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogSFRotationConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogSFRotationConfig)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogSFRotationConfig, CDialog)
	//{{AFX_MSG_MAP(DialogSFRotationConfig)
	ON_NOTIFY(UDN_DELTAPOS, IDC_XSPIN, OnDeltaposXspin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_YSPIN, OnDeltaposYspin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_ZSPIN, OnDeltaposZspin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_RSPIN, OnDeltaposRspin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogSFRotationConfig メッセージ ハンドラ

BOOL DialogSFRotationConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	setTitle(this);

	CheckRadioButton(IDC_UNIT_DEGREE, IDC_UNIT_RADIAN, IDC_UNIT_DEGREE);

	char value[256];
	SFRotation *field = (SFRotation *)getField();

	sprintf(value, "%g", field->getX());
	SetDlgItemText(IDC_XVALUE, value);

	sprintf(value, "%g", field->getY());
	SetDlgItemText(IDC_YVALUE, value);

	sprintf(value, "%g", field->getZ());
	SetDlgItemText(IDC_ZVALUE, value);

	sprintf(value, "%.2f", Radian2Degree(field->getAngle()));
	sprintf(value, "%g", atof(value));
	SetDlgItemText(IDC_RVALUE, value);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogSFRotationConfig::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	SFRotation *field = (SFRotation *)getField();

	char	string[256];
	float	x, y, z, angle;

	GetDlgItemText(IDC_XVALUE, string, 255);
	if (sscanf(string, "%f", &x) == 1) {
		GetDlgItemText(IDC_YVALUE, string, 255);
		if (sscanf(string, "%f", &y) == 1) {
			GetDlgItemText(IDC_ZVALUE, string, 255);
			if (sscanf(string, "%f", &z) == 1) {
				GetDlgItemText(IDC_RVALUE, string, 255);
				if (sscanf(string, "%f", &angle) == 1) {
					if (GetCheckedRadioButton(IDC_UNIT_DEGREE, IDC_UNIT_RADIAN) == IDC_UNIT_DEGREE) 
						angle = (float)Degree2Radian(angle);
					field->setValue(x, y, z, angle);
				}
			}
		}
	}
	
	CDialog::OnOK();
}

void DialogSFRotationConfig::OnDeltaposXspin(NMHDR* pNMHDR, LRESULT* pResult) 
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

void DialogSFRotationConfig::OnDeltaposYspin(NMHDR* pNMHDR, LRESULT* pResult) 
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

void DialogSFRotationConfig::OnDeltaposZspin(NMHDR* pNMHDR, LRESULT* pResult) 
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

void DialogSFRotationConfig::OnDeltaposRspin(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	char string[256];
	GetDlgItemText(IDC_RVALUE, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		sprintf(string, "%g", value - (float)pNMUpDown->iDelta);
		SetDlgItemText(IDC_RVALUE, string);
	}
	
	*pResult = 0;
}
