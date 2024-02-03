// DialogImageTextureName.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogImageTextureName.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogImageTextureName �_�C�A���O


DialogImageTextureName::DialogImageTextureName(CWnd* pParent /*=NULL*/)
	: CDialog(DialogImageTextureName::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogImageTextureName)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogImageTextureName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogImageTextureName)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogImageTextureName, CDialog)
	//{{AFX_MSG_MAP(DialogImageTextureName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogImageTextureName ���b�Z�[�W �n���h��

BOOL DialogImageTextureName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	ImageTextureNode	*imgTex;
	char			*selectString = NULL;

	SendDlgItemMessage(IDC_IMAGETEXTURE_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (imgTex = GetWorld()->getSceneGraph()->findImageTextureNode(); imgTex; imgTex=imgTex->nextTraversal()) {
		if (imgTex && StringLength(imgTex->getName()) && StringNCompare(imgTex->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
			SendDlgItemMessage(IDC_IMAGETEXTURE_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)imgTex->getName());
		if (!selectString)
			selectString = imgTex->getName();
	}

	Node	*node	= getNode();
	if (node)
		SendDlgItemMessage(IDC_IMAGETEXTURE_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_IMAGETEXTURE_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogImageTextureName::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	char	nodeName[256];
	
	GetDlgItemText(IDC_IMAGETEXTURE_NAME, nodeName, 256-1);

	Node	*node	= GetWorld()->getSceneGraph()->findImageTextureNode(nodeName);
	setNode(node);
	
	CDialog::OnOK();
}
