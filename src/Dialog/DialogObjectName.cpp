// DialogObjectName.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogObjectName.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogObjectName �_�C�A���O


DialogObjectName::DialogObjectName(CWnd* pParent /*=NULL*/)
	: CDialog(DialogObjectName::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogObjectName)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT

	setNode(NULL);
}


void DialogObjectName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogObjectName)
                // ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogObjectName, CDialog)
	//{{AFX_MSG_MAP(DialogObjectName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogObjectName ���b�Z�[�W �n���h��

BOOL DialogObjectName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	TransformNode	*trans;
	char			*selectString = NULL;

	SendDlgItemMessage(IDC_OBJECTNAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (trans = GetWorld()->getSceneGraph()->findTransformNode(); trans; trans=trans->nextTraversal()) {
		if (trans && StringLength(trans->getName()) && StringNCompare(trans->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
			SendDlgItemMessage(IDC_OBJECTNAME, CB_ADDSTRING, 0, (LONG)(LPSTR)trans->getName());
		if (!selectString)
			selectString = trans->getName();
	}

	Node	*node	= getNode();
	if (node)
		SendDlgItemMessage(IDC_OBJECTNAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_OBJECTNAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);

	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogObjectName::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	char	nodeName[256];
	
	GetDlgItemText(IDC_OBJECTNAME, nodeName, 256-1);

	Node	*node	= GetWorld()->getSceneGraph()->findTransformNode(nodeName);
	setNode(node);

	CDialog::OnOK();
}
