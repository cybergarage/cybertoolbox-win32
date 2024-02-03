// DialogWorldConstant.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogWorldConstant.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogWorldConstant ダイアログ


DialogWorldConstant::DialogWorldConstant(CWnd* pParent /*=NULL*/)
	: CDialog(DialogWorldConstant::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogWorldConstant)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogWorldConstant::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogWorldConstant)
                // メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogWorldConstant, CDialog)
	//{{AFX_MSG_MAP(DialogWorldConstant)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogWorldConstant メッセージ ハンドラ

BOOL DialogWorldConstant::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	SetDlgItemText(IDC_VALUE, getModule()->getValue());
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogWorldConstant::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	char	valueString[256];
	GetDlgItemText(IDC_VALUE, valueString, 256);
	getModule()->setValue(valueString);

	CDialog::OnOK();
}

