// DialogSFInt32Config.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogSFInt32Config.h"
#include "VRMLField.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogSFInt32Config �_�C�A���O

DialogSFInt32Config::DialogSFInt32Config(CWnd* pParent /*=NULL*/)
	: CDialog(DialogSFInt32Config::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogSFInt32Config)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogSFInt32Config::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogSFInt32Config)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogSFInt32Config, CDialog)
	//{{AFX_MSG_MAP(DialogSFInt32Config)
	ON_NOTIFY(UDN_DELTAPOS, IDC_VALUE_SPIN, OnDeltaposValueSpin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogSFInt32Config ���b�Z�[�W �n���h��

BOOL DialogSFInt32Config::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	setTitle(this);

	SFInt32 *field = (SFInt32 *)getField();
	SetDlgItemInt(IDC_VALUE, field->getValue());
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogSFInt32Config::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	
	SFInt32 *field = (SFInt32 *)getField();
	field->setValue(GetDlgItemInt(IDC_VALUE));

	CDialog::OnOK();
}

void DialogSFInt32Config::OnDeltaposValueSpin(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	SetDlgItemInt(IDC_VALUE, GetDlgItemInt(IDC_VALUE) - pNMUpDown->iDelta);
	
	*pResult = 0;
}
