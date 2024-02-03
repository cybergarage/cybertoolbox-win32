// DialogAudioClipName.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogAudioClipName.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogAudioClipName �_�C�A���O


DialogAudioClipName::DialogAudioClipName(CWnd* pParent /*=NULL*/)
	: CDialog(DialogAudioClipName::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogAudioClipName)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogAudioClipName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogAudioClipName)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogAudioClipName, CDialog)
	//{{AFX_MSG_MAP(DialogAudioClipName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogAudioClipName ���b�Z�[�W �n���h��

BOOL DialogAudioClipName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	AudioClipNode	*aclip;
	char		*selectString = NULL;

	SendDlgItemMessage(IDC_AUDIOCLIP_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (aclip = GetWorld()->getSceneGraph()->findAudioClipNode(); aclip; aclip=aclip->nextTraversal()) {
		if (aclip && StringLength(aclip->getName()) && StringNCompare(aclip->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
			SendDlgItemMessage(IDC_AUDIOCLIP_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)aclip->getName());
		if (!selectString)
			selectString = aclip->getName();
	}

	Node	*node	= getNode();
	if (node)
		SendDlgItemMessage(IDC_AUDIOCLIP_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_AUDIOCLIP_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogAudioClipName::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	char	nodeName[256];
	
	GetDlgItemText(IDC_AUDIOCLIP_NAME, nodeName, 256-1);

	Node	*node	= GetWorld()->getSceneGraph()->findAudioClipNode(nodeName);
	setNode(node);
	
	CDialog::OnOK();
}
