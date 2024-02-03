// DialogProgress.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogProgress.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogProgress �_�C�A���O


DialogProgress::DialogProgress(char *name, int range, CWnd* pParent /*=NULL*/)
	: CDialog(DialogProgress::IDD, pParent)
{
	mName = name;
	mRange = range;
	//{{AFX_DATA_INIT(DialogProgress)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}

BOOL DialogProgress::Create()
{
	return CDialog::Create(DialogProgress::IDD);
}

void DialogProgress::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogProgress)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogProgress, CDialog)
	//{{AFX_MSG_MAP(DialogProgress)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogProgress ���b�Z�[�W �n���h��

BOOL DialogProgress::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	SetWindowText(mName);

	mProgressCtrl = (CProgressCtrl *)GetDlgItem(IDC_PROGRESS);
	mProgressCtrl->SetRange(0, mRange);

	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogProgress::setPos(int pos)
{
	mProgressCtrl->SetPos(pos);
}
