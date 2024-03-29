// MainFrm.cpp : CMainFrame クラスの動作の定義を行います。
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
	ID_SEPARATOR,           // ステータス ライン インジケータ
	ID_INDICATOR_KANA,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame クラスの構築/消滅

CMainFrame::CMainFrame()
{
	// TODO: この位置にメンバの初期化処理コードを追加してください。
	
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

	CtbGetTreeView()->updateSaveButton();	

	// TODO: ツール バーをドッキング可能にしない場合は以下の３行を削除
	//       してください。
//	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
//	EnableDocking(CBRS_ALIGN_ANY);
//	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して、Window クラスやスタイルを
	//       修正してください。
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
// CMainFrame クラスの診断

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
// CMainFrame メッセージ ハンドラ



BOOL CMainFrame::DestroyWindow() 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	RECT	rect;
	GetWindowRect(&rect);
	RegKeyWriteValue(REGKEY_SECTION_POSITION, REGKEY_KEY_POSITION_SCENEGRAPH, rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top);
	
	return CFrameWnd::DestroyWindow();
}


void CMainFrame::OnAboutbox() 
{
	// TODO: この位置にコマンド ハンドラ用のコードを追加してください
	CtbModuleFloatingShowWindow(SW_HIDE);
	CtbPrimitiveFloatingShowWindow(SW_HIDE);
	CtbGetApp()->OnAppAbout();
	CtbModuleFloatingShowWindow(SW_SHOW);
	CtbPrimitiveFloatingShowWindow(SW_SHOW);
}
