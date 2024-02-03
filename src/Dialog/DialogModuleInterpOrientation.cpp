// DialogModuleInterpOrientation.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogModuleInterpOrientation.h"

#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogModuleInterpOrientation ダイアログ


DialogModuleInterpOrientation::DialogModuleInterpOrientation(CWnd* pParent /*=NULL*/)
	: CDialog(DialogModuleInterpOrientation::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogModuleInterpOrientation)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogModuleInterpOrientation::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogModuleInterpOrientation)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogModuleInterpOrientation, CDialog)
	//{{AFX_MSG_MAP(DialogModuleInterpOrientation)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogModuleInterpOrientation メッセージ ハンドラ

BOOL DialogModuleInterpOrientation::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	OrientationInterpolatorNode	*interp;
	char					*selectString = NULL;

	SendDlgItemMessage(IDC_NODE_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (interp = GetWorld()->getSceneGraph()->findOrientationInterpolatorNode(); interp; interp=interp->nextTraversal()) {
		if (interp && StringLength(interp->getName()) && StringNCompare(interp->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
			SendDlgItemMessage(IDC_NODE_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)interp->getName());
		if (!selectString)
			selectString = interp->getName();
	}

	Node	*node	= getNode();
	if (node)
		SendDlgItemMessage(IDC_NODE_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_NODE_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogModuleInterpOrientation::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	char	nodeName[256];
	
	GetDlgItemText(IDC_NODE_NAME, nodeName, 256-1);

	Node	*node	= GetWorld()->getSceneGraph()->findOrientationInterpolatorNode(nodeName);
	setNode(node);
	
	CDialog::OnOK();
}
