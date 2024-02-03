// DialogSFFloatConfig.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogSFFloatConfig.h"
#include "VRMLField.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogSFFloatConfig ダイアログ


DialogSFFloatConfig::DialogSFFloatConfig(CWnd* pParent /*=NULL*/)
	: CDialog(DialogSFFloatConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogSFFloatConfig)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogSFFloatConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogSFFloatConfig)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogSFFloatConfig, CDialog)
	//{{AFX_MSG_MAP(DialogSFFloatConfig)
	ON_NOTIFY(UDN_DELTAPOS, IDC_VALUE_SPIN, OnDeltaposValueSpin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogSFFloatConfig メッセージ ハンドラ

BOOL DialogSFFloatConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	setTitle(this);

	char value[256];
	SFFloat *field = (SFFloat *)getField();
	sprintf(value, "%g", field->getValue());
	SetDlgItemText(IDC_VALUE, value);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogSFFloatConfig::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	
	SFFloat *field = (SFFloat *)getField();

	char string[256];
	GetDlgItemText(IDC_VALUE, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1)
		field->setValue(value);

	CDialog::OnOK();
}

void DialogSFFloatConfig::OnDeltaposValueSpin(NMHDR* pNMHDR, LRESULT* pResult) 
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
