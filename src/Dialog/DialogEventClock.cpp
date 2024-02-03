// DialogEventClock.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogEventClock.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogEventClock ダイアログ


DialogEventClock::DialogEventClock(CWnd* pParent /*=NULL*/)
	: CDialog(DialogEventClock::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogEventClock)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogEventClock::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogEventClock)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogEventClock, CDialog)
	//{{AFX_MSG_MAP(DialogEventClock)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogEventClock メッセージ ハンドラ

BOOL DialogEventClock::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	CEvent *event = getEvent();
	TimeSensorNode *tsensor = (TimeSensorNode *)event->getNode();
	assert(tsensor->isTimeSensorNode() == true);
	if (tsensor->isTimeSensorNode() == false)
		return FALSE;

	char value[256];
	sprintf(value, "%g", tsensor->getCycleInterval());
	SetDlgItemText(IDC_INTREVAL_TIME, value);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogEventClock::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	CEvent *event = getEvent();
	TimeSensorNode *tsensor = (TimeSensorNode *)event->getNode();
	assert(tsensor->isTimeSensorNode() == true);
	if (tsensor->isTimeSensorNode() == false)
		return;
	
	char optionString[256];
	GetDlgItemText(IDC_INTREVAL_TIME, optionString, 255);
	float value;
	if (sscanf(optionString, "%f", &value) == 1) {
		sprintf(optionString, "%g", value);
		event->setOptionString(optionString);
	}
	else 
		MessageBeep(0);

	CDialog::OnOK();
}
