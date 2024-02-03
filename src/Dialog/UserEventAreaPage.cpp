// UserEventAreaPage.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "UserEventAreaPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// UserEventAreaPage �v���p�e�B �y�[�W

IMPLEMENT_DYNCREATE(UserEventAreaPage, CPropertyPage)

UserEventAreaPage::UserEventAreaPage() : CPropertyPage(UserEventAreaPage::IDD)
{
	//{{AFX_DATA_INIT(UserEventAreaPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�̏�����������ǉ����܂��B
	//}}AFX_DATA_INIT
}

UserEventAreaPage::~UserEventAreaPage()
{
}

void UserEventAreaPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(UserEventAreaPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(UserEventAreaPage, CPropertyPage)
	//{{AFX_MSG_MAP(UserEventAreaPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// UserEventAreaPage ���b�Z�[�W �n���h��

BOOL UserEventAreaPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	setFont(this);
	setFont(GetDlgItem(IDC_CENTER_STATIC));
	setFont(GetDlgItem(IDC_SIZE_STATIC));
	setFont(GetDlgItem(IDC_CX_STATIC));
	setFont(GetDlgItem(IDC_CY_STATIC));
	setFont(GetDlgItem(IDC_CZ_STATIC));
	setFont(GetDlgItem(IDC_SX_STATIC));
	setFont(GetDlgItem(IDC_SY_STATIC));
	setFont(GetDlgItem(IDC_SZ_STATIC));
	setFont(GetDlgItem(IDC_CENTER_X));
	setFont(GetDlgItem(IDC_CENTER_Y));
	setFont(GetDlgItem(IDC_CENTER_Z));
	setFont(GetDlgItem(IDC_SIZE_X));
	setFont(GetDlgItem(IDC_SIZE_Y));
	setFont(GetDlgItem(IDC_SIZE_Z));

	SetDlgItemInt(IDC_CENTER_X, 0);
	SetDlgItemInt(IDC_CENTER_Y, 0);
	SetDlgItemInt(IDC_CENTER_Z, 0);
	SetDlgItemInt(IDC_SIZE_X, 1);
	SetDlgItemInt(IDC_SIZE_Y, 1);
	SetDlgItemInt(IDC_SIZE_Z, 1);
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}
