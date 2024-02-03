// DialogViewName.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogViewName.h"
#include "World.h"
#include "CModule.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogViewName �_�C�A���O


DialogViewName::DialogViewName(CWnd* pParent /*=NULL*/)
	: CDialog(DialogViewName::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogViewName)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogViewName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogViewName)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogViewName, CDialog)
	//{{AFX_MSG_MAP(DialogViewName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogViewName ���b�Z�[�W �n���h��

BOOL DialogViewName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	ViewpointNode	*view;
	char		*selectString = NULL;

	SendDlgItemMessage(IDC_VIEW_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (view = GetWorld()->getSceneGraph()->findViewpointNode(); view; view=view->nextTraversal()) {
		if (view && StringLength(view->getName()) && StringNCompare(view->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
			SendDlgItemMessage(IDC_VIEW_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)view->getName());
		if (!selectString)
			selectString = view->getName();
	}

	Node	*node	= getNode();

	if (node)
		SendDlgItemMessage(IDC_VIEW_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_VIEW_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogViewName::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	char	nodeName[256];
	
	GetDlgItemText(IDC_VIEW_NAME, nodeName, 256);

	Node	*node	= GetWorld()->getSceneGraph()->findViewpointNode(nodeName);
	setNode(node);
	
	CDialog::OnOK();
}
