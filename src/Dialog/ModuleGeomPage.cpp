// ModuleGeomPage.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "ModuleGeomPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ModuleGeomPage �v���p�e�B �y�[�W

IMPLEMENT_DYNCREATE(ModuleGeomPage, CPropertyPage)

ModuleGeomPage::ModuleGeomPage() : CPropertyPage(ModuleGeomPage::IDD)
{
	//{{AFX_DATA_INIT(ModuleGeomPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�̏�����������ǉ����܂��B
	//}}AFX_DATA_INIT

	setPage(this);
}

ModuleGeomPage::~ModuleGeomPage()
{
}

void ModuleGeomPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ModuleGeomPage)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ModuleGeomPage, CPropertyPage)
	//{{AFX_MSG_MAP(ModuleGeomPage)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ModuleGeomPage ���b�Z�[�W �n���h��

BOOL ModuleGeomPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
//	setFont();
	createImageList();
	createToolTip();	
	
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}

void ModuleGeomPage::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	ClientToScreen(&point);
	DragEnd(point.x, point.y);
	ScreenToClient(&point);
	
	CPropertyPage::OnLButtonUp(nFlags, point);
}

void ModuleGeomPage::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	setMouseButton(MOUSE_BUTTON_LEFT);
	mousex = point.x; mousey = point.y;
	
	CPropertyPage::OnLButtonDown(nFlags, point);
}

void ModuleGeomPage::OnMouseMove(UINT nFlags, CPoint point) 
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

void ModuleGeomPage::OnPaint() 
{
	CPaintDC dc(this); // �`��p�̃f�o�C�X �R���e�L�X�g
	
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����Ă�������
	drawImageList();
	
	// �`��p���b�Z�[�W�Ƃ��� CPropertyPage::OnPaint() ���Ăяo���Ă͂����܂���
}

void ModuleGeomPage::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: ���̈ʒu�Ƀ��b�Z�[�W �n���h���p�̃R�[�h��ǉ����邩�܂��̓f�t�H���g�̏������Ăяo���Ă�������
	setScrollBar(nSBCode, nPos);	
	
	CPropertyPage::OnHScroll(nSBCode, nPos, pScrollBar);
}
