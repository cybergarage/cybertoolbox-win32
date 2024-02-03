// DialogEventFrame.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogEventFrame.h"
#include "CEvent.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogEventFrame ダイアログ


DialogEventFrame::DialogEventFrame(CWnd* pParent /*=NULL*/)
	: CDialog(DialogEventFrame::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogEventFrame)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_INIT
}


void DialogEventFrame::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogEventFrame)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogEventFrame, CDialog)
	//{{AFX_MSG_MAP(DialogEventFrame)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogEventFrame メッセージ ハンドラ

#define FRAME_TICK_FREQ 20

static void SetSlideCtrlText(int pos, CDialog *dialog)
{
	char	text[8];

	sprintf(text, "%d", pos);
	dialog->SetDlgItemText(IDC_TIMESTRING, text);
	dialog->SetDlgItemText(IDC_UNITSTRING, "frame/sec");
}

static void SetSlideCtrlText(double cycleInterval, CDialog *dialog)
{
	int pos = (int)(cycleInterval/ (1.0 / (double)FRAME_TICK_FREQ));
	SetSlideCtrlText(pos, dialog);
}

static void SetSlideCtrlPos(double cycleInterval, CSliderCtrl *sctrl)
{
	if (0.0 < cycleInterval&& cycleInterval<= 1.0) {
		int pos = (int)(cycleInterval/ (1.0 / (double)FRAME_TICK_FREQ));
		sctrl->SetPos(pos);
	}
}

BOOL DialogEventFrame::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: この位置に初期化の補足処理を追加してください
	CSliderCtrl *sctrl = (CSliderCtrl *)GetDlgItem(IDC_TIMESLIDER);
	sctrl->SetRangeMin(0);
	sctrl->SetRangeMax(FRAME_TICK_FREQ);

	int n;
	for (n=0; n<20; n++)
		sctrl->SetTic(n);

	sctrl->SetTicFreq(1);

	CEvent *event = getEvent();
	TimeSensorNode *tsensor = (TimeSensorNode *)event->getNode();
	assert(tsensor->isTimeSensorNode() == true);
	if (tsensor->isTimeSensorNode() == false)
		return FALSE;

	double cycleInterval= tsensor->getCycleInterval();

	SetSlideCtrlPos(cycleInterval, sctrl);
	SetSlideCtrlText(cycleInterval, this);

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void DialogEventFrame::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	CSliderCtrl *sctrl = (CSliderCtrl *)GetDlgItem(IDC_TIMESLIDER);
	int pos = sctrl->GetPos();
	if (pos == 0) {
		sctrl->SetPos(1);
		pos = 1;
	}
	SetSlideCtrlText(pos, this);
	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void DialogEventFrame::OnOK() 
{
	// TODO: この位置にその他の検証用のコードを追加してください

	CEvent *event = getEvent();
	TimeSensorNode *tsensor = (TimeSensorNode *)event->getNode();
	assert(tsensor->isTimeSensorNode() == true);
	if (tsensor->isTimeSensorNode() == false)
		return;

	CSliderCtrl *sctrl = (CSliderCtrl *)GetDlgItem(IDC_TIMESLIDER);
	double cycleInterval= 	1.0 / (double)sctrl->GetPos();

	tsensor->setCycleInterval(cycleInterval);

	CDialog::OnOK();
}
