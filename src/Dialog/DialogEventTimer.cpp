// DialogEventTimer.cpp : �C���v�������e�[�V���� �t�@�C��
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
// DialogEventTimer �_�C�A���O


DialogEventTimer::DialogEventTimer(CWnd* pParent /*=NULL*/)
	: CDialog(DialogEventTimer::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogEventTimer)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogEventTimer::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogEventTimer)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogEventTimer, CDialog)
	//{{AFX_MSG_MAP(DialogEventTimer)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogEventTimer ���b�Z�[�W �n���h��

BOOL DialogEventTimer::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
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
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogEventTimer::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
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
