// DialogDiagram.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "DialogDiagram.h"
#include "World.h"
#include "CDiagram.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogDiagram �_�C�A���O


DialogDiagram::DialogDiagram(CWnd* pParent /*=NULL*/)
	: CDialog(DialogDiagram::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogDiagram)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogDiagram::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogDiagram)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogDiagram, CDialog)
	//{{AFX_MSG_MAP(DialogDiagram)
	ON_BN_CLICKED(IDC_OPEN, OnOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogDiagram ���b�Z�[�W �n���h��

BOOL DialogDiagram::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	CDiagram	diagram(getNode());
	SetDlgItemText(IDC_DIAGRAM_NAME, diagram.getName());
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogDiagram::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	CDiagram	diagram(getNode());
	char		inputName[256];
	GetDlgItemText(IDC_DIAGRAM_NAME, inputName, 255);

	setName(inputName);
	
	CDialog::OnOK();
}

void DialogDiagram::OnOpen() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	EndDialog(IDC_OPEN);	
}

