// DialogPerspectiveViewConfig.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogPerspectiveViewConfig.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogPerspectiveViewConfig �_�C�A���O


DialogPerspectiveViewConfig::DialogPerspectiveViewConfig(CWnd* pParent /*=NULL*/)
	: CDialog(DialogPerspectiveViewConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogPerspectiveViewConfig)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogPerspectiveViewConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogPerspectiveViewConfig)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogPerspectiveViewConfig, CDialog)
	//{{AFX_MSG_MAP(DialogPerspectiveViewConfig)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_NAVIGATIONINFO_SPEED, OnDeltaposSpinNavigationinfoSpeed)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogPerspectiveViewConfig ���b�Z�[�W �n���h��

BOOL DialogPerspectiveViewConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	switch (getRenderingMode()) {
	case OGL_RENDERING_WIRE:
		CheckRadioButton(IDC_WIREFRAME, IDC_TEXTURE, IDC_WIREFRAME);
		break;
	case OGL_RENDERING_SHADE:
		CheckRadioButton(IDC_WIREFRAME, IDC_TEXTURE, IDC_SHADING);
		break;
	case OGL_RENDERING_TEXTURE:
		CheckRadioButton(IDC_WIREFRAME, IDC_TEXTURE, IDC_TEXTURE);
		break;
	}

	char value[128];
	sprintf(value, "%g", getSpeed());
	SetDlgItemText(IDC_NAVIGATIONINFO_SPEED, value);

	CheckDlgButton(IDC_NAVIGATIONINFO_HEADLIGHT, getHeadLight());
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogPerspectiveViewConfig::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	
	setRenderingMode(GetCheckedRadioButton(IDC_WIREFRAME, IDC_TEXTURE)- IDC_WIREFRAME);
	setHeadLight(IsDlgButtonChecked(IDC_NAVIGATIONINFO_HEADLIGHT) ? true : false);

	char	string[128];
	float	value;

	GetDlgItemText(IDC_NAVIGATIONINFO_SPEED, string, 128);
	if (sscanf(string, "%f", &value)) {
		if (0 < value)
			setSpeed(value);
		else
			MessageBeep(0);
	}


	CDialog::OnOK();
}

void DialogPerspectiveViewConfig::OnDeltaposSpinNavigationinfoSpeed(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char string[256];
	GetDlgItemText(IDC_NAVIGATIONINFO_SPEED, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		float newvalue = value - (float)pNMUpDown->iDelta;
		if (newvalue <= 0) {
			newvalue = 1;
			MessageBeep(0);
		}
		sprintf(string, "%g", newvalue);
		SetDlgItemText(IDC_NAVIGATIONINFO_SPEED, string);
	}
	
	*pResult = 0;
}
