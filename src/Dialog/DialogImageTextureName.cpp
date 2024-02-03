// DialogImageTextureName.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogImageTextureName.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogImageTextureName ダイアログ


DialogImageTextureName::DialogImageTextureName(CWnd* pParent /*=NULL*/)
	: CDialog(DialogImageTextureName::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogImageTextureName)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogImageTextureName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogImageTextureName)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogImageTextureName, CDialog)
	//{{AFX_MSG_MAP(DialogImageTextureName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogImageTextureName メッセージ ハンドラ

BOOL DialogImageTextureName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	ImageTextureNode	*imgTex;
	char			*selectString = NULL;

	SendDlgItemMessage(IDC_IMAGETEXTURE_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (imgTex = GetWorld()->getSceneGraph()->findImageTextureNode(); imgTex; imgTex=imgTex->nextTraversal()) {
		if (imgTex && StringLength(imgTex->getName()) && StringNCompare(imgTex->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
			SendDlgItemMessage(IDC_IMAGETEXTURE_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)imgTex->getName());
		if (!selectString)
			selectString = imgTex->getName();
	}

	Node	*node	= getNode();
	if (node)
		SendDlgItemMessage(IDC_IMAGETEXTURE_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_IMAGETEXTURE_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogImageTextureName::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	char	nodeName[256];
	
	GetDlgItemText(IDC_IMAGETEXTURE_NAME, nodeName, 256-1);

	Node	*node	= GetWorld()->getSceneGraph()->findImageTextureNode(nodeName);
	setNode(node);
	
	CDialog::OnOK();
}
