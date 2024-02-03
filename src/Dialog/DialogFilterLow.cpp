// DialogFilterLow.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogFilterLow.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogFilterLow �_�C�A���O


DialogFilterLow::DialogFilterLow(CWnd* pParent /*=NULL*/)
	: CDialog(DialogFilterLow::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogFilterLow)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogFilterLow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogFilterLow)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogFilterLow, CDialog)
	//{{AFX_MSG_MAP(DialogFilterLow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogFilterLow ���b�Z�[�W �n���h��

BOOL DialogFilterLow::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	char buffer[256];
	char *value = getModule()->getValue();
	sprintf(buffer, "%g", atof(value));
	SetDlgItemText(IDC_VALUE, buffer);
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogFilterLow::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	char	dlgString[256];
	char	valueString[256];
	GetDlgItemText(IDC_VALUE, dlgString, 256);
	sprintf(valueString, "%g", atof(dlgString));
	getModule()->setValue(valueString);
	
	CDialog::OnOK();
}
