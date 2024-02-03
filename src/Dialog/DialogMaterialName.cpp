// DialogMaterialName.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogMaterialName.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogMaterialName ダイアログ


DialogMaterialName::DialogMaterialName(CWnd* pParent /*=NULL*/)
	: CDialog(DialogMaterialName::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogMaterialName)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogMaterialName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogMaterialName)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogMaterialName, CDialog)
	//{{AFX_MSG_MAP(DialogMaterialName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogMaterialName メッセージ ハンドラ

BOOL DialogMaterialName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	MaterialNode	*material;
	char			*selectString = NULL;

	SendDlgItemMessage(IDC_MATERIAL_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (material = GetWorld()->getSceneGraph()->findMaterialNode(); material; material=material->nextTraversal()) {
		if (material && StringLength(material->getName()) && StringNCompare(material->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
			SendDlgItemMessage(IDC_MATERIAL_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)material->getName());
		if (!selectString)
			selectString = material->getName();
	}

	Node	*node	= getNode();

	if (node)
		SendDlgItemMessage(IDC_MATERIAL_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_MATERIAL_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogMaterialName::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	char	nodeName[256];
	
	GetDlgItemText(IDC_MATERIAL_NAME, nodeName, 256);

	Node	*node	= GetWorld()->getSceneGraph()->findMaterialNode(nodeName);
	setNode(node);
	
	CDialog::OnOK();
}
