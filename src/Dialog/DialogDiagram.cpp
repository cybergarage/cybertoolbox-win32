// DialogDiagram.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogDiagram.h"
#include "World.h"
#include "CDiagram.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogDiagram ダイアログ


DialogDiagram::DialogDiagram(CWnd* pParent /*=NULL*/)
	: CDialog(DialogDiagram::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogDiagram)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogDiagram::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogDiagram)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogDiagram, CDialog)
	//{{AFX_MSG_MAP(DialogDiagram)
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogDiagram メッセージ ハンドラ

BOOL DialogDiagram::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	CDiagram	diagram(getNode());
	SetDlgItemText(IDC_DIAGRAM_NAME, diagram.getName());
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogDiagram::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	CDiagram	diagram(getNode());
	char		inputName[256];
	GetDlgItemText(IDC_DIAGRAM_NAME, inputName, 255);

	setName(inputName);
	
	CDialog::OnOK();
}

void DialogDiagram::OnOpen() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	EndDialog(IDC_OPEN);	
}

