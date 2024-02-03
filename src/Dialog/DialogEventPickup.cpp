// DialogEventPickup.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogEventPickup.h"
#include "World.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogEventPickup �_�C�A���O


DialogEventPickup::DialogEventPickup(CWnd* pParent /*=NULL*/)
	: CDialog(DialogEventPickup::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogEventPickup)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogEventPickup::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogEventPickup)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogEventPickup, CDialog)
	//{{AFX_MSG_MAP(DialogEventPickup)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogEventPickup ���b�Z�[�W �n���h��

BOOL DialogEventPickup::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	CEvent *event = getEvent();
	TouchSensorNode *tsensor = (TouchSensorNode *)event->getSourceNode();

	char		*selectString = NULL;
	
	SendDlgItemMessage(IDC_NODE_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (Node *node = GetWorld()->getSceneGraph()->getNodes(); node; node=node->nextTraversal()) {
		if (node->isGroupingNode()) {
			if (StringLength(node->getName()) && StringNCompare(node->getName(), CTB_NODE_NAME, strlen(CTB_NODE_NAME))) {
				SendDlgItemMessage(IDC_NODE_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)node->getName());
				if (!selectString)
					selectString = node->getName();
			}
		}
	}

	Node *parentNode = NULL;
	
	if (tsensor)
		parentNode = tsensor->getParentNode();

	char *nodeName = NULL;
	if (parentNode)
		nodeName = parentNode->getName();

	if (nodeName) {
		SendDlgItemMessage(IDC_NODE_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)nodeName);
	}
	else {
		if (selectString)
			SendDlgItemMessage(IDC_NODE_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	}
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogEventPickup::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	CEvent *event = getEvent();

	char nodeName[256];
	GetDlgItemText(IDC_NODE_NAME, nodeName, 256);
	
	if (strlen(nodeName))
		event->setOptionString(nodeName);
	else
		MessageBeep(0);

	CDialog::OnOK();
}
