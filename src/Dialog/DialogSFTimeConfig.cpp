// DialogSFTimeConfig.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogSFTimeConfig.h"
#include "VRMLField.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogSFTimeConfig ダイアログ


DialogSFTimeConfig::DialogSFTimeConfig(CWnd* pParent /*=NULL*/)
	: CDialog(DialogSFTimeConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogSFTimeConfig)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogSFTimeConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogSFTimeConfig)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogSFTimeConfig, CDialog)
	//{{AFX_MSG_MAP(DialogSFTimeConfig)
	ON_NOTIFY(UDN_DELTAPOS, IDC_VALUE_SPIN, OnDeltaposValueSpin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogSFTimeConfig メッセージ ハンドラ

BOOL DialogSFTimeConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	setTitle(this);

	char value[256];
	SFTime *field = (SFTime *)getField();
	sprintf(value, "%g", field->getValue());
	SetDlgItemText(IDC_VALUE, value);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogSFTimeConfig::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	SFTime *field = (SFTime *)getField();

	char string[256];
	GetDlgItemText(IDC_VALUE, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1)
		field->setValue(value);
	
	CDialog::OnOK();
}

void DialogSFTimeConfig::OnDeltaposValueSpin(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	char string[256];
	GetDlgItemText(IDC_VALUE, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		sprintf(string, "%g", value - (float)pNMUpDown->iDelta);
		SetDlgItemText(IDC_VALUE, string);
	}
	
	*pResult = 0;
}
