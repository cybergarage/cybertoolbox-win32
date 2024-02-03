// DialogModuleMiscPlaySound.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogModuleMiscPlaySound.h"
#include "World.h"
#include "CModule.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogModuleMiscPlaySound �_�C�A���O


DialogModuleMiscPlaySound::DialogModuleMiscPlaySound(CWnd* pParent /*=NULL*/)
	: CDialog(DialogModuleMiscPlaySound::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogModuleMiscPlaySound)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogModuleMiscPlaySound::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogModuleMiscPlaySound)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogModuleMiscPlaySound, CDialog)
	//{{AFX_MSG_MAP(DialogModuleMiscPlaySound)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogModuleMiscPlaySound ���b�Z�[�W �n���h��

BOOL DialogModuleMiscPlaySound::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	AudioClipNode	*alicp;
	char			*selectString = NULL;

	SendDlgItemMessage(IDC_AUDIOCLIP_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (alicp = GetWorld()->getSceneGraph()->findAudioClipNode(); alicp; alicp=alicp->nextTraversal()) {
		char *nodeName = alicp->getName();
		if (alicp && StringLength(nodeName) && StringNCompare(nodeName, CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
			SendDlgItemMessage(IDC_AUDIOCLIP_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)nodeName);
		if (!selectString)
			selectString = nodeName;
	}

	Node	*node	= getNode();

	if (node)
		SendDlgItemMessage(IDC_AUDIOCLIP_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_AUDIOCLIP_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogModuleMiscPlaySound::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	char	nodeName[256];
	
	GetDlgItemText(IDC_AUDIOCLIP_NAME, nodeName, 256);

	Node	*node	= GetWorld()->getSceneGraph()->findAudioClipNode(nodeName);
	setNode(node);

	
	CDialog::OnOK();
}
