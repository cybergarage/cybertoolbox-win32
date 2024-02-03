// DialogFilterRange.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogFilterRange.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogFilterRange �_�C�A���O


DialogFilterRange::DialogFilterRange(CWnd* pParent /*=NULL*/)
	: CDialog(DialogFilterRange::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogFilterRange)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogFilterRange::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogFilterRange)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogFilterRange, CDialog)
	//{{AFX_MSG_MAP(DialogFilterRange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogFilterRange ���b�Z�[�W �n���h��

BOOL DialogFilterRange::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	char buffer[256];
	char *value = getModule()->getValue();
	float minValue, maxValue;

	if (sscanf(value, "%f,%f", &minValue, &maxValue) != 2) {
		minValue = 0;
		maxValue = 0;
	}
	sprintf(buffer, "%g", minValue);
	SetDlgItemText(IDC_MIN_VALUE, buffer);
	sprintf(buffer, "%g", maxValue);
	SetDlgItemText(IDC_MAX_VALUE, buffer);
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogFilterRange::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	char	dlgString[256];
	char	valueString[256];
	float	minValue, maxValue;
	GetDlgItemText(IDC_MIN_VALUE, dlgString, 256);
	minValue = (float)atof(dlgString);
	GetDlgItemText(IDC_MAX_VALUE, dlgString, 256);
	maxValue = (float)atof(dlgString);
	sprintf(valueString, "%g,%g", minValue, maxValue);
	getModule()->setValue(valueString);
	
	CDialog::OnOK();
}
