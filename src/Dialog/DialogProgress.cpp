// DialogProgress.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogProgress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogProgress ダイアログ


DialogProgress::DialogProgress(char *name, int range, CWnd* pParent /*=NULL*/)
	: CDialog(DialogProgress::IDD, pParent)
{
	mName = name;
	mRange = range;
	//{{AFX_DATA_INIT(DialogProgress)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}

BOOL DialogProgress::Create()
{
	return CDialog::Create(DialogProgress::IDD);
}

void DialogProgress::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogProgress)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogProgress, CDialog)
	//{{AFX_MSG_MAP(DialogProgress)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogProgress メッセージ ハンドラ

BOOL DialogProgress::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	SetWindowText(mName);

	mProgressCtrl = (CProgressCtrl *)GetDlgItem(IDC_PROGRESS);
	mProgressCtrl->SetRange(0, mRange);

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogProgress::setPos(int pos)
{
	mProgressCtrl->SetPos(pos);
}
