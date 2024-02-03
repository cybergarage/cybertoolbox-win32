// DiagramFrame.cpp : インプリメンテーション ファイル
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
// CDiagramFrame メッセージ ハンドラ

static UINT indicators[] =
{
	ID_SEPARATOR,           // ステータス ライン インジケータ
};

int CDiagramFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadToolBar(IDR_DIAGRAM))
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

BOOL CDiagramFrame::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	cs.dwExStyle |= WS_EX_TOOLWINDOW;
	cs.hMenu = 0;

	cs.cx = 320;
	cs.cy = 240;

	return CFrameWnd::PreCreateWindow(cs);
}

