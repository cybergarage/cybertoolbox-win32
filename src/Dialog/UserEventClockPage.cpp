// UserEventClockPage.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "UserEventClockPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// UserEventClockPage �v���p�e�B �y�[�W

IMPLEMENT_DYNCREATE(UserEventClockPage, CPropertyPage)

UserEventClockPage::UserEventClockPage() : CPropertyPage(UserEventClockPage::IDD)
{
	//{{AFX_DATA_INIT(UserEventClockPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�̏�����������ǉ����܂��B
	//}}AFX_DATA_INIT
}

UserEventClockPage::~UserEventClockPage()
{
}

void UserEventClockPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(UserEventClockPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(UserEventClockPage, CPropertyPage)
	//{{AFX_MSG_MAP(UserEventClockPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// UserEventClockPage ���b�Z�[�W �n���h��

BOOL UserEventClockPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	setFont(this);
	setFont(GetDlgItem(IDC_FIELD_NAME));
	setFont(GetDlgItem(IDC_INTREVAL_TIME));
	setFont(GetDlgItem(IDC_FRAMESTRING));
	
	SetDlgItemInt(IDC_INTREVAL_TIME, 1);

	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

