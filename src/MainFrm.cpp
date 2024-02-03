// MainFrm.cpp : CMainFrame �N���X�̓���̒�`���s���܂��B
//

#include "stdafx.h"
#include "CyberToolBox.h"
#include "CyberToolBoxDoc.h"
#include "CyberToolBoxView.h"
#include "RegKey.h"

#include "MainFrm.h"

#include "DiagramNew.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_ABOUTBOX, OnAboutbox)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // �X�e�[�^�X ���C�� �C���W�P�[�^
	ID_INDICATOR_KANA,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame �N���X�̍\�z/����

CMainFrame::CMainFrame()
{
	// TODO: ���̈ʒu�Ƀ����o�̏����������R�[�h��ǉ����Ă��������B
	
}

CMainFrame::~CMainFrame()
{
}

void CMainFrame::OnUpdateFrameTitle(BOOL bAddToTitle)
{
	CFrameWnd::OnUpdateFrameTitle(bAddToTitle);
	SetWindowText(_T("CyberToolbox"));
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // �쐬�Ɏ��s
	}
/*
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // �쐬�Ɏ��s
	}
*/
	// TODO: �����c�[�� �`�b�v�X���K�v�Ȃ��ꍇ�A�������폜���Ă��������B
	m_wndToolBar.SetBarStyle(CBRS_ALIGN_LEFT | CBRS_TOOLTIPS | CBRS_FLYBY);

	CtbGetTreeView()->updateSaveButton();	

	// TODO: �c�[�� �o�[���h�b�L���O�\�ɂ��Ȃ��ꍇ�͈ȉ��̂R�s���폜
	//       ���Ă��������B
//	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
//	EnableDocking(CBRS_ALIGN_ANY);
//	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���̈ʒu�� CREATESTRUCT cs ���C�����āAWindow �N���X��X�^�C����
	//       �C�����Ă��������B
	if (RegKeyGetValue(REGKEY_SECTION_POSITION, REGKEY_KEY_POSITION_SCENEGRAPH, &cs.x, &cs.y, &cs.cx, &cs.cy) == FALSE) {
		cs.x = 0;
		cs.y = 0;
		cs.cx = 300;
		cs.cy = 450;
	}

	cs.hMenu = 0;
	
	return CFrameWnd::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame �N���X�̐f�f

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame ���b�Z�[�W �n���h��



BOOL CMainFrame::DestroyWindow() 
{
	// TODO: ���̈ʒu�ɌŗL�̏�����ǉ����邩�A�܂��͊�{�N���X���Ăяo���Ă�������
	RECT	rect;
	GetWindowRect(&rect);
	RegKeyWriteValue(REGKEY_SECTION_POSITION, REGKEY_KEY_POSITION_SCENEGRAPH, rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top);
	
	return CFrameWnd::DestroyWindow();
}


void CMainFrame::OnAboutbox() 
{
	// TODO: ���̈ʒu�ɃR�}���h �n���h���p�̃R�[�h��ǉ����Ă�������
	CtbModuleFloatingShowWindow(SW_HIDE);
	CtbPrimitiveFloatingShowWindow(SW_HIDE);
	CtbGetApp()->OnAppAbout();
	CtbModuleFloatingShowWindow(SW_SHOW);
	CtbPrimitiveFloatingShowWindow(SW_SHOW);
}
