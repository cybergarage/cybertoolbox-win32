// DialogModuleFilterScalarInterp.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogModuleFilterScalarInterp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogModuleFilterScalarInterp �_�C�A���O


DialogModuleFilterScalarInterp::DialogModuleFilterScalarInterp(CWnd* pParent /*=NULL*/)
	: CDialog(DialogModuleFilterScalarInterp::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogModuleFilterScalarInterp)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogModuleFilterScalarInterp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogModuleFilterScalarInterp)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogModuleFilterScalarInterp, CDialog)
	//{{AFX_MSG_MAP(DialogModuleFilterScalarInterp)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, OnDeltaposSpin1)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN2, OnDeltaposSpin2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogModuleFilterScalarInterp ���b�Z�[�W �n���h��

BOOL DialogModuleFilterScalarInterp::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	char value[256];

	char *moduleValue = getModule()->getValue();
	if (moduleValue) {
		float	value1, value2;
		if (sscanf(moduleValue, "%f-%f", &value1, &value2) == 2) {
			sprintf(value, "%g", value1);
			SetDlgItemText(IDC_VALUE1, value);

			sprintf(value, "%g", value2);
			SetDlgItemText(IDC_VALUE2, value);
		}
		else {
			SetDlgItemText(IDC_VALUE1, "0");
			SetDlgItemText(IDC_VALUE2, "1");
		}
	}
	else {
		SetDlgItemText(IDC_VALUE1, "0");
		SetDlgItemText(IDC_VALUE2, "1");
	}
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogModuleFilterScalarInterp::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	char	string[256];
	float	value1, value2;

	GetDlgItemText(IDC_VALUE1, string, 255);
	if (sscanf(string, "%f", &value1) == 1) {
		GetDlgItemText(IDC_VALUE2, string, 255);
		if (sscanf(string, "%f", &value2) == 1) {
			sprintf(string, "%g-%g", value1, value2);
			getModule()->setValue(string);
		}
	}
	
	CDialog::OnOK();
}

void DialogModuleFilterScalarInterp::OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char string[256];
	GetDlgItemText(IDC_VALUE1, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		sprintf(string, "%g", value - (float)pNMUpDown->iDelta);
		SetDlgItemText(IDC_VALUE1, string);
	}
	
	*pResult = 0;
}

void DialogModuleFilterScalarInterp::OnDeltaposSpin2(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char string[256];
	GetDlgItemText(IDC_VALUE2, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		sprintf(string, "%g", value - (float)pNMUpDown->iDelta);
		SetDlgItemText(IDC_VALUE2, string);
	}
	
	*pResult = 0;
}
