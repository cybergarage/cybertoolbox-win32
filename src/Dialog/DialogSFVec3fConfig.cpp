// DialogSFVec3fConfig.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogSFVec3fConfig.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogSFVec3fConfig �_�C�A���O


DialogSFVec3fConfig::DialogSFVec3fConfig(CWnd* pParent /*=NULL*/)
	: CDialog(DialogSFVec3fConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogSFVec3fConfig)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogSFVec3fConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogSFVec3fConfig)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogSFVec3fConfig, CDialog)
	//{{AFX_MSG_MAP(DialogSFVec3fConfig)
	ON_NOTIFY(UDN_DELTAPOS, IDC_XSPIN, OnDeltaposXspin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_YSPIN, OnDeltaposYspin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_ZSPIN, OnDeltaposZspin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogSFVec3fConfig ���b�Z�[�W �n���h��

BOOL DialogSFVec3fConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	setTitle(this);

	char value[256];
	SFVec3f *field = (SFVec3f *)getField();

	sprintf(value, "%g", field->getX());
	SetDlgItemText(IDC_XVALUE, value);

	sprintf(value, "%g", field->getY());
	SetDlgItemText(IDC_YVALUE, value);

	sprintf(value, "%g", field->getZ());
	SetDlgItemText(IDC_ZVALUE, value);

	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogSFVec3fConfig::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	SFVec3f *field = (SFVec3f *)getField();

	char	string[256];
	float	x, y, z;

	GetDlgItemText(IDC_XVALUE, string, 255);
	if (sscanf(string, "%f", &x) == 1) {
		GetDlgItemText(IDC_YVALUE, string, 255);
		if (sscanf(string, "%f", &y) == 1) {
			GetDlgItemText(IDC_ZVALUE, string, 255);
			if (sscanf(string, "%f", &z) == 1)
				field->setValue(x, y, z);
		}
	}
	
	CDialog::OnOK();
}

void DialogSFVec3fConfig::OnDeltaposXspin(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char string[256];
	GetDlgItemText(IDC_XVALUE, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		sprintf(string, "%g", value - (float)pNMUpDown->iDelta);
		SetDlgItemText(IDC_XVALUE, string);
	}
	
	*pResult = 0;
}

void DialogSFVec3fConfig::OnDeltaposYspin(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char string[256];
	GetDlgItemText(IDC_YVALUE, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		sprintf(string, "%g", value - (float)pNMUpDown->iDelta);
		SetDlgItemText(IDC_YVALUE, string);
	}
	
	*pResult = 0;
}

void DialogSFVec3fConfig::OnDeltaposZspin(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char string[256];
	GetDlgItemText(IDC_ZVALUE, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		sprintf(string, "%g", value - (float)pNMUpDown->iDelta);
		SetDlgItemText(IDC_ZVALUE, string);
	}
	
	*pResult = 0;
}
