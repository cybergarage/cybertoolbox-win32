// DialogPerspectiveViewConfig.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogPerspectiveViewConfig.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogPerspectiveViewConfig ダイアログ


DialogPerspectiveViewConfig::DialogPerspectiveViewConfig(CWnd* pParent /*=NULL*/)
	: CDialog(DialogPerspectiveViewConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogPerspectiveViewConfig)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogPerspectiveViewConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogPerspectiveViewConfig)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogPerspectiveViewConfig, CDialog)
	//{{AFX_MSG_MAP(DialogPerspectiveViewConfig)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_NAVIGATIONINFO_SPEED, OnDeltaposSpinNavigationinfoSpeed)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogPerspectiveViewConfig メッセージ ハンドラ

BOOL DialogPerspectiveViewConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	switch (getRenderingMode()) {
	case OGL_RENDERING_WIRE:
		CheckRadioButton(IDC_WIREFRAME, IDC_TEXTURE, IDC_WIREFRAME);
		break;
	case OGL_RENDERING_SHADE:
		CheckRadioButton(IDC_WIREFRAME, IDC_TEXTURE, IDC_SHADING);
		break;
	case OGL_RENDERING_TEXTURE:
		CheckRadioButton(IDC_WIREFRAME, IDC_TEXTURE, IDC_TEXTURE);
		break;
	}

	char value[128];
	sprintf(value, "%g", getSpeed());
	SetDlgItemText(IDC_NAVIGATIONINFO_SPEED, value);

	CheckDlgButton(IDC_NAVIGATIONINFO_HEADLIGHT, getHeadLight());
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogPerspectiveViewConfig::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	
	setRenderingMode(GetCheckedRadioButton(IDC_WIREFRAME, IDC_TEXTURE)- IDC_WIREFRAME);
	setHeadLight(IsDlgButtonChecked(IDC_NAVIGATIONINFO_HEADLIGHT) ? true : false);

	char	string[128];
	float	value;

	GetDlgItemText(IDC_NAVIGATIONINFO_SPEED, string, 128);
	if (sscanf(string, "%f", &value)) {
		if (0 < value)
			setSpeed(value);
		else
			MessageBeep(0);
	}


	CDialog::OnOK();
}

void DialogPerspectiveViewConfig::OnDeltaposSpinNavigationinfoSpeed(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	char string[256];
	GetDlgItemText(IDC_NAVIGATIONINFO_SPEED, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		float newvalue = value - (float)pNMUpDown->iDelta;
		if (newvalue <= 0) {
			newvalue = 1;
			MessageBeep(0);
		}
		sprintf(string, "%g", newvalue);
		SetDlgItemText(IDC_NAVIGATIONINFO_SPEED, string);
	}
	
	*pResult = 0;
}
