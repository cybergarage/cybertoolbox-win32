// DialogSFStringConfig.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogSFStringConfig.h"
#include "VRMLField.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogSFStringConfig ダイアログ


DialogSFStringConfig::DialogSFStringConfig(CWnd* pParent /*=NULL*/)
	: CDialog(DialogSFStringConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogSFStringConfig)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogSFStringConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogSFStringConfig)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogSFStringConfig, CDialog)
	//{{AFX_MSG_MAP(DialogSFStringConfig)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogSFStringConfig メッセージ ハンドラ

BOOL DialogSFStringConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	setTitle(this);

	SFString *field = (SFString *)getField();
	SetDlgItemText(IDC_VALUE, field->getValue());

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogSFStringConfig::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	SFString *field = (SFString *)getField();

	char value[256];
	GetDlgItemText(IDC_VALUE, value, 255);
	field->setValue(value);
	
	CDialog::OnOK();
}
