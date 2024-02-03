// DialogSFBoolConfig.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogSFBoolConfig.h"
#include "VRMLField.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogSFBoolConfig ダイアログ


DialogSFBoolConfig::DialogSFBoolConfig(CWnd* pParent /*=NULL*/)
	: CDialog(DialogSFBoolConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogSFBoolConfig)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogSFBoolConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogSFBoolConfig)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogSFBoolConfig, CDialog)
	//{{AFX_MSG_MAP(DialogSFBoolConfig)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogSFBoolConfig メッセージ ハンドラ

BOOL DialogSFBoolConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	setTitle(this);

	SFBool *field = (SFBool *)getField();

	if (field->getValue() == true)
		CheckRadioButton(IDC_TRUE_RADIO, IDC_FALSE_RADIO, IDC_TRUE_RADIO);
	else
		CheckRadioButton(IDC_TRUE_RADIO, IDC_FALSE_RADIO, IDC_FALSE_RADIO);

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogSFBoolConfig::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	
	int id = GetCheckedRadioButton(IDC_TRUE_RADIO, IDC_FALSE_RADIO);

	SFBool *field = (SFBool *)getField();

	if (id == IDC_TRUE_RADIO)
		field->setValue(true);
	else
		field->setValue(false);

	CDialog::OnOK();
}
