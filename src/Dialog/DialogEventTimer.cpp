// DialogEventTimer.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogEventTimer.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogEventTimer ダイアログ


DialogEventTimer::DialogEventTimer(CWnd* pParent /*=NULL*/)
	: CDialog(DialogEventTimer::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogEventTimer)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogEventTimer::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogEventTimer)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogEventTimer, CDialog)
	//{{AFX_MSG_MAP(DialogEventTimer)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogEventTimer メッセージ ハンドラ

BOOL DialogEventTimer::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	CEvent *event = getEvent();

	char *sourceNodeName = event->getSourceNodeName();
	Node *subEventNode = GetWorld()->getSceneGraph()->findNode(sourceNodeName);
	assert(subEventNode->isScriptNode() == true);
	if (subEventNode->isScriptNode() == false)
		return FALSE;

	ScriptNode *script = (ScriptNode *)subEventNode;
	SFTime *time = (SFTime *)script->getField(CTB_EVENTTYPE_TIMER_SCRIPT_VALUE_NAME);

	assert(time != NULL);

	char value[256];
	sprintf(value, "%g", time->getValue());
	SetDlgItemText(IDC_WAKEUP_TIME, value);
	
	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogEventTimer::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください
	CEvent *event = getEvent();
	TimeSensorNode *tsensor = (TimeSensorNode *)event->getNode();
	assert(tsensor->isTimeSensorNode() == true);
	if (tsensor->isTimeSensorNode() == false)
		return;
	
	char optionString[256];
	GetDlgItemText(IDC_WAKEUP_TIME, optionString, 255);
	float value;
	if (sscanf(optionString, "%f", &value) == 1) {
		sprintf(optionString, "%g", value);
		event->setOptionString(optionString);
	}
	else 
		MessageBeep(0);
	
	CDialog::OnOK();
}
