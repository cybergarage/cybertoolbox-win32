// DialogSwitchName.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogSwitchName.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogSwitchName �_�C�A���O


DialogSwitchName::DialogSwitchName(CWnd* pParent /*=NULL*/)
	: CDialog(DialogSwitchName::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogSwitchName)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT

	setNode(NULL);
}


void DialogSwitchName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogSwitchName)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogSwitchName, CDialog)
	//{{AFX_MSG_MAP(DialogSwitchName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogSwitchName ���b�Z�[�W �n���h��

BOOL DialogSwitchName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	SwitchNode	*switchNode;
	char		*selectString = NULL;

	SendDlgItemMessage(IDC_SWITCH_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (switchNode = GetWorld()->getSceneGraph()->findSwitchNode(); switchNode; switchNode=switchNode->nextTraversal()) {
		if (switchNode && StringLength(switchNode->getName()) && StringNCompare(switchNode->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
			SendDlgItemMessage(IDC_SWITCH_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)switchNode->getName());
		if (!selectString)
			selectString = switchNode->getName();
	}

	Node	*node	= getNode();
	if (node)
		SendDlgItemMessage(IDC_SWITCH_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_SWITCH_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogSwitchName::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	char	nodeName[256];
	
	GetDlgItemText(IDC_SWITCH_NAME, nodeName, 256-1);

	Node	*node	= GetWorld()->getSceneGraph()->findSwitchNode(nodeName);
	setNode(node);
	
	CDialog::OnOK();
}
