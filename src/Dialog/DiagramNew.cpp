// DiagramNew.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DiagramNew.h"
#include "World.h"
#include "CEvent.h"
#include "StringFn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DiagramNew ダイアログ


DiagramNew::DiagramNew(CWnd* pParent /*=NULL*/)
	: CDialog(DiagramNew::IDD, pParent)
{
	//{{AFX_DATA_INIT(DiagramNew)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT

	mListBoxString = new String[GetWorld()->getNEventNodes()];
}


void DiagramNew::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DiagramNew)
                // メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DiagramNew, CDialog)
	//{{AFX_MSG_MAP(DiagramNew)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

DiagramNew::~DiagramNew()
{
	delete[] mListBoxString;
}

/////////////////////////////////////////////////////////////////////////////
// DiagramNew メッセージ ハンドラ

#define NAME_MAXLEN		128

void DiagramNew::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	char	dgmEventString	[NAME_MAXLEN];
	char	dgmNameString	[NAME_MAXLEN];

	GetDlgItemText(IDC_DIAGRAM_EVENTTYPENAME, dgmEventString, NAME_MAXLEN);

	int eventNumber = -1;
	for (int n=0; n < GetWorld()->getNEventNodes(); n++) {
		if (!StringCompare(dgmEventString, getListBoxString(n))) {
			eventNumber = n;
			break;
		}
	}
	assert(eventNumber != -1);
	setEventNumber(eventNumber);

	GetDlgItemText(IDC_DIAGRAM_NAME, dgmNameString, NAME_MAXLEN);
	setName(dgmNameString);

	CDialog::OnOK();
}

BOOL DiagramNew::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください

	Node *eventNode;
	SendDlgItemMessage(IDC_DIAGRAM_EVENTTYPENAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	int	nEvent = 0;
	for (eventNode = GetWorld()->getEventNodes(); eventNode; eventNode=eventNode->next()) {
		char	listboxName[CTB_EVENTNAME_MAXLEN];
		CEvent	event(eventNode);
		char	*eventName = event.getEventTypeName();
		char	*optionName = event.getEventOptionName();
		if (optionName == NULL)
			strcpy(listboxName, eventName);
		else
			sprintf(listboxName, "%s - %s", eventName, optionName);
		SendDlgItemMessage(IDC_DIAGRAM_EVENTTYPENAME, CB_ADDSTRING, 0, (LONG)(LPSTR)listboxName);

		setListBoxString(nEvent++, listboxName);
	}
	SendDlgItemMessage(IDC_DIAGRAM_EVENTTYPENAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)"Start");

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}
