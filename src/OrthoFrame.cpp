// OrthoFrame.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "CyberToolBox.h"
#include "OrthoFrame.h"
#include "RegKey.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// OrthoFrame

IMPLEMENT_DYNCREATE(OrthoFrame, CFrameWnd)

OrthoFrame::OrthoFrame()
{
}

OrthoFrame::~OrthoFrame()
{
}

void OrthoFrame::OnUpdateFrameTitle(BOOL bAddToTitle)
{
	CFrameWnd::OnUpdateFrameTitle(bAddToTitle);
	SetWindowText(_T(""));
}

BEGIN_MESSAGE_MAP(OrthoFrame, CFrameWnd)
	//{{AFX_MSG_MAP(OrthoFrame)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// OrthoFrame ���b�Z�[�W �n���h��

BOOL OrthoFrame::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: ���̈ʒu�ɌŗL�̏�����ǉ����邩�A�܂��͊�{�N���X���Ăяo���Ă�������
	cs.style = WS_OVERLAPPED | WS_THICKFRAME | WS_BORDER | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
	cs.dwExStyle |= WS_EX_TOOLWINDOW;

	if (RegKeyGetValue(REGKEY_SECTION_POSITION, REGKEY_KEY_POSITION_ORTHOVIEW, &cs.x, &cs.y, &cs.cx, &cs.cy) == FALSE) {
		cs.x = 350;
		cs.y = 100;
		cs.cx = 450;
		cs.cy = 450;
	}

	cs.hMenu = 0;
	
	return CFrameWnd::PreCreateWindow(cs);
}

static UINT indicators[] =
{
//	ID_SEPARATOR,           // �X�e�[�^�X ���C�� �C���W�P�[�^
///	ID_INDICATOR_KANA,
//	ID_INDICATOR_CAPS,
//	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
	ID_INDICATOR_SCRL,
	ID_INDICATOR_SCRL,
};

int OrthoFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: ���̈ʒu�ɌŗL�̍쐬�p�R�[�h��ǉ����Ă�������
	// TODO: ���̈ʒu�ɌŗL�̍쐬�p�R�[�h��ǉ����Ă�������
	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadToolBar(IDR_ORTHOVIEW))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // �쐬�Ɏ��s
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // �쐬�Ɏ��s
	}

	// TODO: �����c�[�� �`�b�v�X���K�v�Ȃ��ꍇ�A�������폜���Ă��������B
	m_wndToolBar.SetBarStyle(CBRS_ALIGN_LEFT | CBRS_TOOLTIPS | CBRS_FLYBY);


	for (int n=0; n<3; n++) {
		UINT	id, style;
		int		width;
		m_wndStatusBar.GetPaneInfo(n, id, style, width); 
		m_wndStatusBar.SetPaneInfo(n, id, style, (int)(width*1.5)); 
	}

	// TODO: �c�[�� �o�[���h�b�L���O�\�ɂ��Ȃ��ꍇ�͈ȉ��̂R�s���폜
	//       ���Ă��������B
//	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
//	EnableDocking(CBRS_ALIGN_ANY);
//	DockControlBar(&m_wndToolBar);
	
	return 0;
}

BOOL OrthoFrame::DestroyWindow() 
{
	// TODO: ���̈ʒu�ɌŗL�̏�����ǉ����邩�A�܂��͊�{�N���X���Ăяo���Ă�������
	RECT	rect;
	GetWindowRect(&rect);
	RegKeyWriteValue(REGKEY_SECTION_POSITION, REGKEY_KEY_POSITION_ORTHOVIEW, rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top);
	
	return CFrameWnd::DestroyWindow();
}
