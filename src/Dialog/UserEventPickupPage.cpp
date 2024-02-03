// UserEventPickupPage.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "UserEventPickupPage.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// UserEventPickupPage �v���p�e�B �y�[�W

IMPLEMENT_DYNCREATE(UserEventPickupPage, CPropertyPage)

UserEventPickupPage::UserEventPickupPage() : CPropertyPage(UserEventPickupPage::IDD)
{
	//{{AFX_DATA_INIT(UserEventPickupPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�̏�����������ǉ����܂��B
	//}}AFX_DATA_INIT
}

UserEventPickupPage::~UserEventPickupPage()
{
}

void UserEventPickupPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(UserEventPickupPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(UserEventPickupPage, CPropertyPage)
	//{{AFX_MSG_MAP(UserEventPickupPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// UserEventPickupPage ���b�Z�[�W �n���h��

BOOL UserEventPickupPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	setFont(this);
	setFont(GetDlgItem(IDC_FIELD_NAME));
	setFont(GetDlgItem(IDC_NODE_NAME));

	char		*selectString = NULL;
	
	SendDlgItemMessage(IDC_NODE_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (Node *node = GetWorld()->getSceneGraph()->getNodes(); node; node=node->nextTraversal()) {
		if (node->isGroupingNode()) {
			if (StringLength(node->getName()) && StringNCompare(node->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME))) {
				SendDlgItemMessage(IDC_NODE_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)node->getName());
				if (!selectString)
					selectString = node->getName();
			}
		}
	}
	
	if (selectString)
		SendDlgItemMessage(IDC_NODE_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);

	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}
