// DialogDiagramConfig.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "..\CyberToolBoxDoc.h"
#include "..\CyberToolBoxView.h"
#include "DialogDiagramConfig.h"
#include "World.h"
#include "CDiagram.h"
#include "..\DiagramView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DialogDiagramConfig �_�C�A���O


DialogDiagramConfig::DialogDiagramConfig(CWnd* pParent /*=NULL*/)
	: CDialog(DialogDiagramConfig::IDD, pParent)
{
	//{{AFX_DATA_INIT(DialogDiagramConfig)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_INIT
}


void DialogDiagramConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DialogDiagramConfig)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DialogDiagramConfig, CDialog)
	//{{AFX_MSG_MAP(DialogDiagramConfig)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DialogDiagramConfig ���b�Z�[�W �n���h��

BOOL DialogDiagramConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	CDiagram	diagram(getTransformNode());
	SetDlgItemText(IDC_DIAGRAM_NAME, diagram.getName());
	
	CheckDlgButton(IDC_GRID_DISPLAY, getGridDisplay());
	CheckDlgButton(IDC_GRID_SNAP, getGridSnap());

	if (getLineStyle() == DIAGRAM_LINESTYLE_STRAIGHT)
		SendDlgItemMessage(IDC_LINE_TYPE, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)"Straight Line");
	else
		SendDlgItemMessage(IDC_LINE_TYPE, CB_SELECTSTRING,(WPARAM)-1, (LPARAM)(LPCSTR)"Zigzag Line");

	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void DialogDiagramConfig::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	CDiagram	diagram(getTransformNode());
	char		dgmName[256];
	dgmName[0] = '\0';
	GetDlgItemText(IDC_DIAGRAM_NAME, dgmName, 255);

	if (0 < StringLength(dgmName) && !GetWorld()->getDiagramNode(dgmName, diagram.getEventNode())){
		TransformNode			*diagramNode = getTransformNode();
		HTREEITEM			treeItem = (HTREEITEM)diagramNode->getValue();
		CCyberToolBoxView	*treeView = CtbGetTreeView();

		diagram.setName(dgmName);
		treeView->setTreeItemName(treeItem, diagram.getName());
	}
	else {
		if (strcmp(dgmName, diagram.getName()) != 0)
			MessageBeep(0);
	}

	setGridDisplay(IsDlgButtonChecked(IDC_GRID_DISPLAY) ? true : false);
	setGridSnap(IsDlgButtonChecked(IDC_GRID_SNAP) ? true : false);
	
	char lineStyleString[32];
	GetDlgItemText(IDC_LINE_TYPE, lineStyleString, 32);
	if (!strcmp(lineStyleString, "Straight"))
		setLineStyle(DIAGRAM_LINESTYLE_STRAIGHT);
	else
		setLineStyle(DIAGRAM_LINESTYLE_ZIGZAG);
	
	CDialog::OnOK();
}
