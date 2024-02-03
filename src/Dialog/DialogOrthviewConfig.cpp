// DialogOrthviewConfig.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogOrthviewConfig.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogOrthviewConfig ダイアログ


DialogOrthviewConfig::DialogOrthviewConfig(CWnd* pParent /*=NULL*/)
	: CDialog(DialogOrthviewConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogOrthviewConfig)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogOrthviewConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogOrthviewConfig)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogOrthviewConfig, CDialog)
	//{{AFX_MSG_MAP(DialogOrthviewConfig)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_POSITION, OnDeltaposSpinPosition)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ANGLE, OnDeltaposSpinAngle)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogOrthviewConfig メッセージ ハンドラ

BOOL DialogOrthviewConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	CheckDlgButton(IDC_DISPLAY_AXIS,		isAxisDisplayOn());
	CheckDlgButton(IDC_DISPLAY_GRID,		isGridDisplayOn());
	CheckDlgButton(IDC_DISPLAY_POINTLIGHT,	isPointLightDisplayOn());
	CheckDlgButton(IDC_DISPLAY_SPOTLIGHT,	isSpotLightDisplayOn());
	CheckDlgButton(IDC_DISPLAY_VIEWPOINT,	isViewpointDisplayOn());
	CheckDlgButton(IDC_DISPLAY_SHAPE,		isShapeDisplayOn());
	CheckDlgButton(IDC_SNAP,				isSnapOn());
	
	char value[128];

	sprintf(value, "%g", getGridSize());
	SetDlgItemText(IDC_STEP_POSITION, value);

	sprintf(value, "%g", getGridAngle());
	SetDlgItemText(IDC_STEP_ANGLE, value);

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogOrthviewConfig::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください

	setAxisDisplayOn(IsDlgButtonChecked(IDC_DISPLAY_AXIS) ? true : false);
	setGridDisplayOn(IsDlgButtonChecked(IDC_DISPLAY_GRID) ? true : false);
	setSnapOn(IsDlgButtonChecked(IDC_SNAP) ? true : false);
	setSpotLightDisplayOn(IsDlgButtonChecked(IDC_DISPLAY_SPOTLIGHT) ? true : false);
	setPointLightDisplayOn(IsDlgButtonChecked(IDC_DISPLAY_POINTLIGHT) ? true : false);
	setShapeDisplayOn(IsDlgButtonChecked(IDC_DISPLAY_SHAPE) ? true : false);
	setViewpointDisplayOn(IsDlgButtonChecked(IDC_DISPLAY_VIEWPOINT) ? true : false);

	char	string[128];
	float	value;

	GetDlgItemText(IDC_STEP_POSITION, string, 128);
	if (sscanf(string, "%f", &value)) {
		if (0 < value)
			setGridSize(value);
		else
			MessageBeep(0);
	}

	GetDlgItemText(IDC_STEP_ANGLE, string, 128);
	if (sscanf(string, "%f", &value)) {
		if (0 < value)
			setGridAngle(value);
		else
			MessageBeep(0);
	}

	CDialog::OnOK();
}

void DialogOrthviewConfig::OnDeltaposSpinPosition(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	char string[256];
	GetDlgItemText(IDC_STEP_POSITION, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		float newvalue = value - (float)pNMUpDown->iDelta;
		if (newvalue <= 0) {
			newvalue = 1;
			MessageBeep(0);
		}
		sprintf(string, "%g", newvalue);
		SetDlgItemText(IDC_STEP_POSITION, string);
	}
	
	*pResult = 0;
}

void DialogOrthviewConfig::OnDeltaposSpinAngle(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	char string[256];
	GetDlgItemText(IDC_STEP_ANGLE, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		float newvalue = value - (float)pNMUpDown->iDelta;
		if (newvalue <= 0) {
			newvalue = 1;
			MessageBeep(0);
		}
		sprintf(string, "%g", newvalue);
		SetDlgItemText(IDC_STEP_ANGLE, string);
	}
	
	*pResult = 0;
}
