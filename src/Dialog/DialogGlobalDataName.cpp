// DialogGlobalDataName.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogGlobalDataName.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "World.h"
#include "CGlobalData.h"

/////////////////////////////////////////////////////////////////////////////
// DialogGlobalDataName ダイアログ


DialogGlobalDataName::DialogGlobalDataName(CWnd* pParent /*=NULL*/)
	: CDialog(DialogGlobalDataName::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogGlobalDataName)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogGlobalDataName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogGlobalDataName)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogGlobalDataName, CDialog)
	//{{AFX_MSG_MAP(DialogGlobalDataName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogGlobalDataName メッセージ ハンドラ

BOOL DialogGlobalDataName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	char		*selectString = NULL;

	// TODO: この位置に初期化の補足処理を追加してください
	SendDlgItemMessage(IDC_GLOBALDATA_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (AnchorNode *info = GetWorld()->getGlobalDataNodes(); info; info=info->next()) {
		CGlobalData	gdata(info);
			SendDlgItemMessage(IDC_GLOBALDATA_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)gdata.getName());
		if (!selectString)
			selectString = gdata.getName();
	}

	Node	*node	= getNode();

	if (node && node->isAnchorNode()) {
		if (GetWorld()->isGlobalData((AnchorNode *)node)) {
			CGlobalData	gdata((AnchorNode *)node);
			SendDlgItemMessage(IDC_GLOBALDATA_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)gdata.getName());
		}
		else if (selectString)
			SendDlgItemMessage(IDC_GLOBALDATA_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	}
	else if (selectString)
		SendDlgItemMessage(IDC_GLOBALDATA_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogGlobalDataName::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	GetDlgItemText(IDC_GLOBALDATA_NAME, mGlobalDataName, GLOBALDATA_SIZE);
	
	CDialog::OnOK();
}
