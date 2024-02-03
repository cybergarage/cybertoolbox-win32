// DialogModuleMiscPlaySound.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogModuleMiscPlaySound.h"
#include "World.h"
#include "CModule.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogModuleMiscPlaySound ダイアログ


DialogModuleMiscPlaySound::DialogModuleMiscPlaySound(CWnd* pParent /*=NULL*/)
	: CDialog(DialogModuleMiscPlaySound::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogModuleMiscPlaySound)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogModuleMiscPlaySound::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogModuleMiscPlaySound)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogModuleMiscPlaySound, CDialog)
	//{{AFX_MSG_MAP(DialogModuleMiscPlaySound)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogModuleMiscPlaySound メッセージ ハンドラ

BOOL DialogModuleMiscPlaySound::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	AudioClipNode	*alicp;
	char			*selectString = NULL;

	SendDlgItemMessage(IDC_AUDIOCLIP_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (alicp = GetWorld()->getSceneGraph()->findAudioClipNode(); alicp; alicp=alicp->nextTraversal()) {
		char *nodeName = alicp->getName();
		if (alicp && StringLength(nodeName) && StringNCompare(nodeName, CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
			SendDlgItemMessage(IDC_AUDIOCLIP_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)nodeName);
		if (!selectString)
			selectString = nodeName;
	}

	Node	*node	= getNode();

	if (node)
		SendDlgItemMessage(IDC_AUDIOCLIP_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_AUDIOCLIP_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogModuleMiscPlaySound::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	char	nodeName[256];
	
	GetDlgItemText(IDC_AUDIOCLIP_NAME, nodeName, 256);

	Node	*node	= GetWorld()->getSceneGraph()->findAudioClipNode(nodeName);
	setNode(node);

	
	CDialog::OnOK();
}
