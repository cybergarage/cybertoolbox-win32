// DialogSFInt32Config.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogSFInt32Config.h"
#include "VRMLField.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogSFInt32Config ダイアログ

DialogSFInt32Config::DialogSFInt32Config(CWnd* pParent /*=NULL*/)
	: CDialog(DialogSFInt32Config::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogSFInt32Config)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogSFInt32Config::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogSFInt32Config)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogSFInt32Config, CDialog)
	//{{AFX_MSG_MAP(DialogSFInt32Config)
	ON_NOTIFY(UDN_DELTAPOS, IDC_VALUE_SPIN, OnDeltaposValueSpin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogSFInt32Config メッセージ ハンドラ

BOOL DialogSFInt32Config::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	setTitle(this);

	SFInt32 *field = (SFInt32 *)getField();
	SetDlgItemInt(IDC_VALUE, field->getValue());
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogSFInt32Config::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	
	SFInt32 *field = (SFInt32 *)getField();
	field->setValue(GetDlgItemInt(IDC_VALUE));

	CDialog::OnOK();
}

void DialogSFInt32Config::OnDeltaposValueSpin(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	SetDlgItemInt(IDC_VALUE, GetDlgItemInt(IDC_VALUE) - pNMUpDown->iDelta);
	
	*pResult = 0;
}
