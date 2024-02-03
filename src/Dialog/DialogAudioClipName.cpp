// DialogAudioClipName.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogAudioClipName.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogAudioClipName ダイアログ


DialogAudioClipName::DialogAudioClipName(CWnd* pParent /*=NULL*/)
	: CDialog(DialogAudioClipName::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogAudioClipName)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogAudioClipName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogAudioClipName)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogAudioClipName, CDialog)
	//{{AFX_MSG_MAP(DialogAudioClipName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogAudioClipName メッセージ ハンドラ

BOOL DialogAudioClipName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	AudioClipNode	*aclip;
	char		*selectString = NULL;

	SendDlgItemMessage(IDC_AUDIOCLIP_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (aclip = GetWorld()->getSceneGraph()->findAudioClipNode(); aclip; aclip=aclip->nextTraversal()) {
		if (aclip && StringLength(aclip->getName()) && StringNCompare(aclip->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
			SendDlgItemMessage(IDC_AUDIOCLIP_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)aclip->getName());
		if (!selectString)
			selectString = aclip->getName();
	}

	Node	*node	= getNode();
	if (node)
		SendDlgItemMessage(IDC_AUDIOCLIP_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_AUDIOCLIP_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogAudioClipName::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	char	nodeName[256];
	
	GetDlgItemText(IDC_AUDIOCLIP_NAME, nodeName, 256-1);

	Node	*node	= GetWorld()->getSceneGraph()->findAudioClipNode(nodeName);
	setNode(node);
	
	CDialog::OnOK();
}
