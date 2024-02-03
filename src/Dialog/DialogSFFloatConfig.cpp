// DialogSFFloatConfig.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogSFFloatConfig.h"
#include "VRMLField.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogSFFloatConfig �_�C�A���O


DialogSFFloatConfig::DialogSFFloatConfig(CWnd* pParent /*=NULL*/)
	: CDialog(DialogSFFloatConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogSFFloatConfig)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogSFFloatConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogSFFloatConfig)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogSFFloatConfig, CDialog)
	//{{AFX_MSG_MAP(DialogSFFloatConfig)
	ON_NOTIFY(UDN_DELTAPOS, IDC_VALUE_SPIN, OnDeltaposValueSpin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogSFFloatConfig ���b�Z�[�W �n���h��

BOOL DialogSFFloatConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	setTitle(this);

	char value[256];
	SFFloat *field = (SFFloat *)getField();
	sprintf(value, "%g", field->getValue());
	SetDlgItemText(IDC_VALUE, value);
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogSFFloatConfig::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	
	SFFloat *field = (SFFloat *)getField();

	char string[256];
	GetDlgItemText(IDC_VALUE, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1)
		field->setValue(value);

	CDialog::OnOK();
}

void DialogSFFloatConfig::OnDeltaposValueSpin(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char string[256];
	GetDlgItemText(IDC_VALUE, string, 255);
	float value;
	if (sscanf(string, "%f", &value) == 1) {
		sprintf(string, "%g", value - (float)pNMUpDown->iDelta);
		SetDlgItemText(IDC_VALUE, string);
	}
	
	*pResult = 0;
}
