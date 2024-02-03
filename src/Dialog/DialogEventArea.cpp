// DialogEventArea.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogEventArea.h"
#include "CEvent.h"
#include "ProximitySensorNode.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogEventArea �_�C�A���O


DialogEventArea::DialogEventArea(CWnd* pParent /*=NULL*/)
	: CDialog(DialogEventArea::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogEventArea)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogEventArea::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogEventArea)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogEventArea, CDialog)
	//{{AFX_MSG_MAP(DialogEventArea)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogEventArea ���b�Z�[�W �n���h��

BOOL DialogEventArea::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	CEvent *event = getEvent();
	ProximitySensorNode *psensor = (ProximitySensorNode *)event->getNode();
	assert(psensor->isProximitySensorNode() == true);
	if (psensor->isProximitySensorNode() == false)
		return FALSE;
	
	char text[128];
	float center[3];
	psensor->getCenter(center);
	sprintf(text, "%g", center[0]);  SetDlgItemText(IDC_CENTER_X, text);
	sprintf(text, "%g", center[1]);  SetDlgItemText(IDC_CENTER_Y, text);
	sprintf(text, "%g", center[2]);  SetDlgItemText(IDC_CENTER_Z, text);

	float size[3];
	psensor->getSize(size);
	sprintf(text, "%g", size[0]);  SetDlgItemText(IDC_SIZE_X, text);
	sprintf(text, "%g", size[1]);  SetDlgItemText(IDC_SIZE_Y, text);
	sprintf(text, "%g", size[2]);  SetDlgItemText(IDC_SIZE_Z, text);

	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogEventArea::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	CEvent *event = getEvent();
	ProximitySensorNode *psensor = (ProximitySensorNode *)event->getNode();
	assert(psensor->isProximitySensorNode() == true);
	if (psensor->isProximitySensorNode() == false)
		return;

	char	value[512];
	float	cx, cy, cz;
	float	sx, sy, sz;
	int		nValue = 0;
					
	GetDlgItemText(IDC_CENTER_X, value, 512);
	if (sscanf(value, "%f", &cx) == 1)
		nValue++;

	GetDlgItemText(IDC_CENTER_Y, value, 512);
	if (sscanf(value, "%f", &cy) == 1)
		nValue++;

	GetDlgItemText(IDC_CENTER_Z, value, 512);
	if (sscanf(value, "%f", &cz) == 1)
		nValue++;

	GetDlgItemText(IDC_SIZE_X, value, 512);
	if (sscanf(value, "%f", &sx) == 1)
		nValue++;

	GetDlgItemText(IDC_SIZE_Y, value, 512);
	if (sscanf(value, "%f", &sy) == 1)
		nValue++;

	GetDlgItemText(IDC_SIZE_Z, value, 512);
	if (sscanf(value, "%f", &sz) == 1)
		nValue++;

	if (nValue == 6) {
		char optionString[128];
		sprintf(optionString, "%g:%g:%g:%g:%g:%g", cx, cy, cz, sx, sy, sz);
		event->setOptionString(optionString);
	}
	else
		MessageBeep(0);

	CDialog::OnOK();
}
