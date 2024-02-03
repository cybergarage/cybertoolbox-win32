// PerspectiveFrame.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "CyberToolBox.h"
#include "PerspectiveFrame.h"
#include "RegKey.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PerspectiveFrame

IMPLEMENT_DYNCREATE(PerspectiveFrame, CFrameWnd)

PerspectiveFrame::PerspectiveFrame()
{
}

PerspectiveFrame::~PerspectiveFrame()
{
}

void PerspectiveFrame::OnUpdateFrameTitle(BOOL bAddToTitle)
{
	CFrameWnd::OnUpdateFrameTitle(bAddToTitle);
	SetWindowText(_T(""));
}

BEGIN_MESSAGE_MAP(PerspectiveFrame, CFrameWnd)
	//{{AFX_MSG_MAP(PerspectiveFrame)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PerspectiveFrame メッセージ ハンドラ

BOOL PerspectiveFrame::DestroyWindow() 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	RECT	rect;
	GetWindowRect(&rect);
	RegKeyWriteValue(REGKEY_SECTION_POSITION, REGKEY_KEY_POSITION_PERSPECTIVEVIEW, rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top);
	
	return CFrameWnd::DestroyWindow();
}

BOOL PerspectiveFrame::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	cs.style = WS_OVERLAPPED | WS_THICKFRAME | WS_BORDER | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
	cs.dwExStyle |= WS_EX_TOOLWINDOW;

	if (RegKeyGetValue(REGKEY_SECTION_POSITION, REGKEY_KEY_POSITION_PERSPECTIVEVIEW, &cs.x, &cs.y, &cs.cx, &cs.cy) == FALSE) {
		cs.x = 300;
		cs.y = 0;
		cs.cx = 450;
		cs.cy = 450;
	}

	cs.hMenu = 0;
	
	return CFrameWnd::PreCreateWindow(cs);
}

int PerspectiveFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: この位置に固有の作成用コードを追加してください
	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadToolBar(IDR_PERSPECTIVE))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // 作成に失敗
	}
/*
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // 作成に失敗
	}
*/
	// TODO: もしツール チップスが必要ない場合、ここを削除してください。
	m_wndToolBar.SetBarStyle(CBRS_ALIGN_LEFT | CBRS_TOOLTIPS | CBRS_FLYBY);

	// TODO: ツール バーをドッキング可能にしない場合は以下の３行を削除
	//       してください。
//	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
//	EnableDocking(CBRS_ALIGN_ANY);
//	DockControlBar(&m_wndToolBar);
	
	return 0;
}
