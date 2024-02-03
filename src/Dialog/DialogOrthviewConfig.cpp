// DialogOrthviewConfig.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogOrthviewConfig.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogOrthviewConfig �_�C�A���O


DialogOrthviewConfig::DialogOrthviewConfig(CWnd* pParent /*=NULL*/)
	: CDialog(DialogOrthviewConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogOrthviewConfig)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogOrthviewConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogOrthviewConfig)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogOrthviewConfig, CDialog)
	//{{AFX_MSG_MAP(DialogOrthviewConfig)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_POSITION, OnDeltaposSpinPosition)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ANGLE, OnDeltaposSpinAngle)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogOrthviewConfig ���b�Z�[�W �n���h��

BOOL DialogOrthviewConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	CheckDlgButton(IDC_DISPLAY_AXIS,		isAxisDisplayOn());
	CheckDlgButton(IDC_DISPLAY_GRID,		isGridDisplayOn());
	CheckDlgButton(IDC_DISPLAY_POINTLIGHT,	isPointLightDisplayOn());
	CheckDlgButton(IDC_DISPLAY_SPOTLIGHT,	isSpotLightDisplayOn());
	CheckDlgButton(IDC_DISPLAY_VIEWPOINT,	isViewpointDisplayOn());
	CheckDlgButton(IDC_DISPLAY_SHAPE,		isShapeDisplayOn());
	CheckDlgButton(IDC_SNAP,				isSnapOn());
	
	char value[128];

	sprintf(value, "%g", getGridSize());
	SetDlgItemText(IDC_STEP_POSITION, value);

	sprintf(value, "%g", getGridAngle());
	SetDlgItemText(IDC_STEP_ANGLE, value);

	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogOrthviewConfig::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������

	setAxisDisplayOn(IsDlgButtonChecked(IDC_DISPLAY_AXIS) ? true : false);
	setGridDisplayOn(IsDlgButtonChecked(IDC_DISPLAY_GRID) ? true : false);
	setSnapOn(IsDlgButtonChecked(IDC_SNAP) ? true : false);
	setSpotLightDisplayOn(IsDlgButtonChecked(IDC_DISPLAY_SPOTLIGHT) ? true : false);
	setPointLightDisplayOn(IsDlgButtonChecked(IDC_DISPLAY_POINTLIGHT) ? true : false);
	setShapeDisplayOn(IsDlgButtonChecked(IDC_DISPLAY_SHAPE) ? true : false);
	setViewpointDisplayOn(IsDlgButtonChecked(IDC_DISPLAY_VIEWPOINT) ? true : false);

	char	string[128];
	float	value;

	GetDlgItemText(IDC_STEP_POSITION, string, 128);
	if (sscanf(string, "%f", &value)) {
		if (0 < value)
			setGridSize(value);
		else
			MessageBeep(0);
	}

	GetDlgItemText(IDC_STEP_ANGLE, string, 128);
	if (sscanf(string, "%f", &value)) {
		if (0 < value)
			setGridAngle(value);
		else
			MessageBeep(0);
	}

	CDialog::OnOK();
}

void DialogOrthviewConfig::OnDeltaposSpinPosition(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char string[256];
	GetDlgItemText(IDC_STEP_POSITION, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		float newvalue = value - (float)pNMUpDown->iDelta;
		if (newvalue <= 0) {
			newvalue = 1;
			MessageBeep(0);
		}
		sprintf(string, "%g", newvalue);
		SetDlgItemText(IDC_STEP_POSITION, string);
	}
	
	*pResult = 0;
}

void DialogOrthviewConfig::OnDeltaposSpinAngle(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char string[256];
	GetDlgItemText(IDC_STEP_ANGLE, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		float newvalue = value - (float)pNMUpDown->iDelta;
		if (newvalue <= 0) {
			newvalue = 1;
			MessageBeep(0);
		}
		sprintf(string, "%g", newvalue);
		SetDlgItemText(IDC_STEP_ANGLE, string);
	}
	
	*pResult = 0;
}
