// UserEventCollisionPage.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "UserEventCollisionPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// UserEventCollisionPage �v���p�e�B �y�[�W

IMPLEMENT_DYNCREATE(UserEventCollisionPage, CPropertyPage)

UserEventCollisionPage::UserEventCollisionPage() : CPropertyPage(UserEventCollisionPage::IDD)
{
	//{{AFX_DATA_INIT(UserEventCollisionPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�̏�����������ǉ����܂��B
	//}}AFX_DATA_INIT
}

UserEventCollisionPage::~UserEventCollisionPage()
{
}

void UserEventCollisionPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(UserEventCollisionPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(UserEventCollisionPage, CPropertyPage)
	//{{AFX_MSG_MAP(UserEventCollisionPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// UserEventCollisionPage ���b�Z�[�W �n���h��

BOOL UserEventCollisionPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	setFont(this);
	setFont(GetDlgItem(IDC_OBJECT1_NAME));
	setFont(GetDlgItem(IDC_OBJECT2_NAME));
	setFont(GetDlgItem(IDC_OBJECT1_RADIUS));
	setFont(GetDlgItem(IDC_OBJECT2_RADIUS));
	setFont(GetDlgItem(IDC_OBJECT1_NAME_STRING));
	setFont(GetDlgItem(IDC_OBJECT2_NAME_STRING));
	setFont(GetDlgItem(IDC_OBJECT1_RADIUS_STRING));
	setFont(GetDlgItem(IDC_OBJECT2_RADIUS_STRING));
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}
