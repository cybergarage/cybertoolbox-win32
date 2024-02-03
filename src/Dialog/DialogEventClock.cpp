// DialogEventClock.cpp : �C���v�������e�[�V���� �t�@�C��
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
// DialogEventClock �_�C�A���O


DialogEventClock::DialogEventClock(CWnd* pParent /*=NULL*/)
	: CDialog(DialogEventClock::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogEventClock)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogEventClock::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogEventClock)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogEventClock, CDialog)
	//{{AFX_MSG_MAP(DialogEventClock)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogEventClock ���b�Z�[�W �n���h��

BOOL DialogEventClock::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	CEvent *event = getEvent();
	TimeSensorNode *tsensor = (TimeSensorNode *)event->getNode();
	assert(tsensor->isTimeSensorNode() == true);
	if (tsensor->isTimeSensorNode() == false)
		return FALSE;

	char value[256];
	sprintf(value, "%g", tsensor->getCycleInterval());
	SetDlgItemText(IDC_INTREVAL_TIME, value);
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogEventClock::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
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
