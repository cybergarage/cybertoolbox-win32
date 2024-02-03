// ModuleViewPage.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "ModuleViewPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ModuleViewPage �v���p�e�B �y�[�W

IMPLEMENT_DYNCREATE(ModuleViewPage, CPropertyPage)

ModuleViewPage::ModuleViewPage() : CPropertyPage(ModuleViewPage::IDD)
{
	//{{AFX_DATA_INIT(ModuleViewPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�̏�����������ǉ����܂��B
	//}}AFX_DATA_INIT

	setPage(this);
}

ModuleViewPage::~ModuleViewPage()
{
}

void ModuleViewPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ModuleViewPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ModuleViewPage, CPropertyPage)
	//{{AFX_MSG_MAP(ModuleViewPage)
	ON_NOTIFY(LVN_BEGINDRAG, IDC_MODULE_LIST, OnBegindragModuleList)
	ON_WM_LBUTTONUP()
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ModuleViewPage ���b�Z�[�W �n���h��

BOOL ModuleViewPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
//	setFont();
	createImageList();
	createToolTip();	
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void ModuleViewPage::OnBegindragModuleList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	DragBegin(pNMListView->iItem);
	
	*pResult = 0;
}

void ModuleViewPage::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	ClientToScreen(&point);
	DragEnd(point.x, point.y);
	ScreenToClient(&point);
	
	CPropertyPage::OnLButtonUp(nFlags, point);
}

void ModuleViewPage::OnPaint() 
{
	CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g
	
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����Ă�������
	drawImageList();
	
	// �`��p���b�Z�[�W�Ƃ��� CPropertyPage::OnPaint() ���Ăяo���Ă͂����܂���
}

void ModuleViewPage::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	setScrollBar(nSBCode, nPos);	
	
	CPropertyPage::OnHScroll(nSBCode, nPos, pScrollBar);
}

void ModuleViewPage::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	setMouseButton(MOUSE_BUTTON_LEFT);
	mousex = point.x; mousey = point.y;
	
	CPropertyPage::OnLButtonDown(nFlags, point);
}

void ModuleViewPage::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	if (isDragging() == false && getMouseButton() == MOUSE_BUTTON_LEFT && (point.x != mousex || point.y != mousey)) {
		ClientToScreen(&point);
		int n = isInsideImageList(point.x, point.y);
		if (0 <= n)
			DragBegin(n);
		ScreenToClient(&point);
	}
	
	CPropertyPage::OnMouseMove(nFlags, point);
}
