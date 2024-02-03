// DialogModuleStringBool.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogModuleStringBool.h"
#include "StringFn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogModuleStringBool �_�C�A���O


DialogModuleStringBool::DialogModuleStringBool(CWnd* pParent /*=NULL*/)
	: CDialog(DialogModuleStringBool::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogModuleStringBool)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogModuleStringBool::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogModuleStringBool)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogModuleStringBool, CDialog)
	//{{AFX_MSG_MAP(DialogModuleStringBool)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogModuleStringBool ���b�Z�[�W �n���h��

BOOL DialogModuleStringBool::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	char *moduleValue = getModule()->getValue();
	if (StringCompareIgnoreCase(moduleValue, "TRUE") == 0 || StringCompareIgnoreCase(moduleValue, "0") == 0) 
		CheckRadioButton(IDC_TRUE_RADIO, IDC_FALSE_RADIO, IDC_TRUE_RADIO);
	else
		CheckRadioButton(IDC_TRUE_RADIO, IDC_FALSE_RADIO, IDC_FALSE_RADIO);
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogModuleStringBool::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	int id = GetCheckedRadioButton(IDC_TRUE_RADIO, IDC_FALSE_RADIO);

	if (id == IDC_TRUE_RADIO)
		getModule()->setValue("true");
	else
		getModule()->setValue("false");
	
	CDialog::OnOK();
}

