// DiagramFrame.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "CyberToolBox.h"
#include "DiagramFrame.h"
#include "DiagramView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDiagramFrame

IMPLEMENT_DYNCREATE(CDiagramFrame, CFrameWnd)

CDiagramFrame::CDiagramFrame()
{
}

CDiagramFrame::~CDiagramFrame()
{
}


BEGIN_MESSAGE_MAP(CDiagramFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CDiagramFrame)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDiagramFrame ���b�Z�[�W �n���h��

static UINT indicators[] =
{
	ID_SEPARATOR,           // �X�e�[�^�X ���C�� �C���W�P�[�^
};

int CDiagramFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadToolBar(IDR_DIAGRAM))
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

	// TODO: �c�[�� �o�[���h�b�L���O�\�ɂ��Ȃ��ꍇ�͈ȉ��̂R�s���폜
	//       ���Ă��������B
//	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
//	EnableDocking(CBRS_ALIGN_ANY);
//	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CDiagramFrame::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: ���̈ʒu�ɌŗL�̏�����ǉ����邩�A�܂��͊�{�N���X���Ăяo���Ă�������
	cs.dwExStyle |= WS_EX_TOOLWINDOW;
	cs.hMenu = 0;

	cs.cx = 320;
	cs.cy = 240;

	return CFrameWnd::PreCreateWindow(cs);
}

