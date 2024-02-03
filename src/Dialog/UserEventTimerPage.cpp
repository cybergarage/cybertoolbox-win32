// UserEventTimerPage.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "UserEventTimerPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// UserEventTimerPage �v���p�e�B �y�[�W

IMPLEMENT_DYNCREATE(UserEventTimerPage, CPropertyPage)

UserEventTimerPage::UserEventTimerPage() : CPropertyPage(UserEventTimerPage::IDD)
{
	//{{AFX_DATA_INIT(UserEventTimerPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�̏�����������ǉ����܂��B
	//}}AFX_DATA_INIT
}

UserEventTimerPage::~UserEventTimerPage()
{
}

void UserEventTimerPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(UserEventTimerPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(UserEventTimerPage, CPropertyPage)
	//{{AFX_MSG_MAP(UserEventTimerPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// UserEventTimerPage ���b�Z�[�W �n���h��

BOOL UserEventTimerPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	setFont(this);
	setFont(GetDlgItem(IDC_FIELD_NAME));
	setFont(GetDlgItem(IDC_WAKEUP_TIME));
	setFont(GetDlgItem(IDC_FRAMESTRING));
	
	SetDlgItemInt(IDC_WAKEUP_TIME, 1);
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}
