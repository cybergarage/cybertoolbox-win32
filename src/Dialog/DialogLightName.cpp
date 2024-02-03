// DialogLightName.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogLightName.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogLightName �_�C�A���O


DialogLightName::DialogLightName(CWnd* pParent /*=NULL*/)
	: CDialog(DialogLightName::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogLightName)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogLightName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogLightName)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogLightName, CDialog)
	//{{AFX_MSG_MAP(DialogLightName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogLightName ���b�Z�[�W �n���h��

BOOL DialogLightName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������

	char		*selectString = NULL;

	SendDlgItemMessage(IDC_LIGHT_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);

	if (getType() & LIGHTTYPE_DIRECTIONAL) {
		for (DirectionalLightNode *dlight = GetWorld()->getSceneGraph()->findDirectionalLightNode(); dlight; dlight=dlight->nextTraversal()) {
			if (dlight && StringLength(dlight->getName()) && StringNCompare(dlight->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
				SendDlgItemMessage(IDC_LIGHT_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)dlight->getName());
			if (!selectString)
				selectString = dlight->getName();
		}
	}

	if (getType() & LIGHTTYPE_POINT) {
		for (PointLightNode *plight = GetWorld()->getSceneGraph()->findPointLightNode(); plight; plight=plight->nextTraversal()) {
			if (plight && StringLength(plight->getName()) && StringNCompare(plight->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
				SendDlgItemMessage(IDC_LIGHT_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)plight->getName());
			if (!selectString)
				selectString = plight->getName();
		}
	}

	if (getType() & LIGHTTYPE_SPOT) {
		for (SpotLightNode *slight = GetWorld()->getSceneGraph()->findSpotLightNode(); slight; slight=slight->nextTraversal()) {
			if (slight && StringLength(slight->getName()) && StringNCompare(slight->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME)))
				SendDlgItemMessage(IDC_LIGHT_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)slight->getName());
			if (!selectString)
				selectString = slight->getName();
		}
	}

	Node	*node	= getNode();

	if (node)
		SendDlgItemMessage(IDC_LIGHT_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)node->getName());
	else if (selectString)
		SendDlgItemMessage(IDC_LIGHT_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogLightName::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	char	nodeName[256];
	GetDlgItemText(IDC_LIGHT_NAME, nodeName, 256);
	Node	*node = NULL;

	if (getType() & LIGHTTYPE_DIRECTIONAL)
		node = GetWorld()->getSceneGraph()->findDirectionalLightNode(nodeName);

	if (getType() & LIGHTTYPE_POINT && !node) 
		node = GetWorld()->getSceneGraph()->findPointLightNode(nodeName);

	if (getType() & LIGHTTYPE_SPOT && !node) 
		node = GetWorld()->getSceneGraph()->findSpotLightNode(nodeName);

	setNode(node);
	
	CDialog::OnOK();
}
