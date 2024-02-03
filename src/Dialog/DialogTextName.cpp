// DialogTextName.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogTextName.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogTextName �_�C�A���O


DialogTextName::DialogTextName(CWnd* pParent /*=NULL*/)
	: CDialog(DialogTextName::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogTextName)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT

	setNode(NULL);
}


void DialogTextName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogTextName)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogTextName, CDialog)
	//{{AFX_MSG_MAP(DialogTextName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogTextName ���b�Z�[�W �n���h��

BOOL DialogTextName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	TextNode	*text;
	char			*selectString = NULL;

	SendDlgItemMessage(IDC_TEXT_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (text = GetWorld()->getSceneGraph()->findTextNode(); text; text=text->nextTraversal()) {
		if (text && StringLength(text->getName()) && StringNCompare(text->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
			SendDlgItemMessage(IDC_TEXT_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)text->getName());
		if (!selectString)
			selectString = text->getName();
	}

	Node	*node	= getNode();
	if (node)
		SendDlgItemMessage(IDC_TEXT_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_TEXT_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogTextName::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	char	nodeName[256];
	
	GetDlgItemText(IDC_TEXT_NAME, nodeName, 256-1);

	Node	*node	= GetWorld()->getSceneGraph()->findTextNode(nodeName);
	setNode(node);
	
	CDialog::OnOK();
}
