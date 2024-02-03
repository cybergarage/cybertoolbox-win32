// DialogSFStringConfig.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogSFStringConfig.h"
#include "VRMLField.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogSFStringConfig �_�C�A���O


DialogSFStringConfig::DialogSFStringConfig(CWnd* pParent /*=NULL*/)
	: CDialog(DialogSFStringConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogSFStringConfig)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogSFStringConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogSFStringConfig)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogSFStringConfig, CDialog)
	//{{AFX_MSG_MAP(DialogSFStringConfig)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogSFStringConfig ���b�Z�[�W �n���h��

BOOL DialogSFStringConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	setTitle(this);

	SFString *field = (SFString *)getField();
	SetDlgItemText(IDC_VALUE, field->getValue());

	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogSFStringConfig::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	SFString *field = (SFString *)getField();

	char value[256];
	GetDlgItemText(IDC_VALUE, value, 255);
	field->setValue(value);
	
	CDialog::OnOK();
}
