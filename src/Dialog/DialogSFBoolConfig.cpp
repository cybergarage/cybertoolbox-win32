// DialogSFBoolConfig.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogSFBoolConfig.h"
#include "VRMLField.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogSFBoolConfig �_�C�A���O


DialogSFBoolConfig::DialogSFBoolConfig(CWnd* pParent /*=NULL*/)
	: CDialog(DialogSFBoolConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogSFBoolConfig)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogSFBoolConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogSFBoolConfig)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogSFBoolConfig, CDialog)
	//{{AFX_MSG_MAP(DialogSFBoolConfig)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogSFBoolConfig ���b�Z�[�W �n���h��

BOOL DialogSFBoolConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	setTitle(this);

	SFBool *field = (SFBool *)getField();

	if (field->getValue() == true)
		CheckRadioButton(IDC_TRUE_RADIO, IDC_FALSE_RADIO, IDC_TRUE_RADIO);
	else
		CheckRadioButton(IDC_TRUE_RADIO, IDC_FALSE_RADIO, IDC_FALSE_RADIO);

	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogSFBoolConfig::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	
	int id = GetCheckedRadioButton(IDC_TRUE_RADIO, IDC_FALSE_RADIO);

	SFBool *field = (SFBool *)getField();

	if (id == IDC_TRUE_RADIO)
		field->setValue(true);
	else
		field->setValue(false);

	CDialog::OnOK();
}
