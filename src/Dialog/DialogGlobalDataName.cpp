// DialogGlobalDataName.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogGlobalDataName.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "World.h"
#include "CGlobalData.h"

/////////////////////////////////////////////////////////////////////////////
// DialogGlobalDataName �_�C�A���O


DialogGlobalDataName::DialogGlobalDataName(CWnd* pParent /*=NULL*/)
	: CDialog(DialogGlobalDataName::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogGlobalDataName)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogGlobalDataName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogGlobalDataName)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogGlobalDataName, CDialog)
	//{{AFX_MSG_MAP(DialogGlobalDataName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogGlobalDataName ���b�Z�[�W �n���h��

BOOL DialogGlobalDataName::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	char		*selectString = NULL;

	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	SendDlgItemMessage(IDC_GLOBALDATA_NAME, CB_RESETCONTENT, (WPARAM)0, (LPARAM)0L);
	for (AnchorNode *info = GetWorld()->getGlobalDataNodes(); info; info=info->next()) {
		CGlobalData	gdata(info);
			SendDlgItemMessage(IDC_GLOBALDATA_NAME, CB_ADDSTRING, 0, (LONG)(LPSTR)gdata.getName());
		if (!selectString)
			selectString = gdata.getName();
	}

	Node	*node	= getNode();

	if (node && node->isAnchorNode()) {
		if (GetWorld()->isGlobalData((AnchorNode *)node)) {
			CGlobalData	gdata((AnchorNode *)node);
			SendDlgItemMessage(IDC_GLOBALDATA_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)gdata.getName());
		}
		else if (selectString)
			SendDlgItemMessage(IDC_GLOBALDATA_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);
	}
	else if (selectString)
		SendDlgItemMessage(IDC_GLOBALDATA_NAME, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)selectString);

	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogGlobalDataName::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	GetDlgItemText(IDC_GLOBALDATA_NAME, mGlobalDataName, GLOBALDATA_SIZE);
	
	CDialog::OnOK();
}
