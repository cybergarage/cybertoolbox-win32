// DialogMaterialName.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogMaterialName.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogMaterialName �_�C�A���O


DialogMaterialName::DialogMaterialName(CWnd* pParent /*=NULL*/)
	: CDialog(DialogMaterialName::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogMaterialName)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogMaterialName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogMaterialName)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogMaterialName, CDialog)
	//{{AFX_MSG_MAP(DialogMaterialName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogMaterialName ���b�Z�[�W �n���h��

BOOL DialogMaterialName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	MaterialNode	*material;
	char			*selectString = NULL;

	SendDlgItemMessage(IDC_MATERIAL_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (material = GetWorld()->getSceneGraph()->findMaterialNode(); material; material=material->nextTraversal()) {
		if (material && StringLength(material->getName()) && StringNCompare(material->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
			SendDlgItemMessage(IDC_MATERIAL_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)material->getName());
		if (!selectString)
			selectString = material->getName();
	}

	Node	*node	= getNode();

	if (node)
		SendDlgItemMessage(IDC_MATERIAL_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_MATERIAL_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogMaterialName::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	char	nodeName[256];
	
	GetDlgItemText(IDC_MATERIAL_NAME, nodeName, 256);

	Node	*node	= GetWorld()->getSceneGraph()->findMaterialNode(nodeName);
	setNode(node);
	
	CDialog::OnOK();
}
