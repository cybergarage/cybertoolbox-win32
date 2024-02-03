// DialgoBackgroundName.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialgoBackgroundName.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialgoBackgroundName �_�C�A���O


DialgoBackgroundName::DialgoBackgroundName(CWnd* pParent /*=NULL*/)
	: CDialog(DialgoBackgroundName::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialgoBackgroundName)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT

	setNode(NULL);
}


void DialgoBackgroundName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialgoBackgroundName)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialgoBackgroundName, CDialog)
	//{{AFX_MSG_MAP(DialgoBackgroundName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialgoBackgroundName ���b�Z�[�W �n���h��

BOOL DialgoBackgroundName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	BackgroundNode	*bg;
	char			*selectString = NULL;

	SendDlgItemMessage(IDC_BACKGROUND_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (bg = GetWorld()->getSceneGraph()->findBackgroundNode(); bg; bg=bg->nextTraversal()) {
		if (bg && StringLength(bg->getName()) && StringNCompare(bg->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
			SendDlgItemMessage(IDC_BACKGROUND_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)bg->getName());
		if (!selectString)
			selectString = bg->getName();
	}

	Node	*node	= getNode();
	if (node)
		SendDlgItemMessage(IDC_BACKGROUND_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_BACKGROUND_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialgoBackgroundName::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	char	nodeName[256];
	
	GetDlgItemText(IDC_BACKGROUND_NAME, nodeName, 256-1);

	Node	*node	= GetWorld()->getSceneGraph()->findBackgroundNode(nodeName);
	setNode(node);
	
	CDialog::OnOK();
}
