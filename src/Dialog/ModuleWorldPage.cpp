// ModuleWorldPage.cpp : インプリメンテーション ファイル
//

#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "ModuleWorldPage.h"
#include "ModuleConfig.h"
#include "World.h"
#include "..\DiagramView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ModuleWorldPage プロパティ ページ

IMPLEMENT_DYNCREATE(ModuleWorldPage, CPropertyPage)

ModuleWorldPage::ModuleWorldPage() : CPropertyPage(ModuleWorldPage::IDD)
{
	//{{AFX_DATA_INIT(ModuleWorldPage)
		// メモ - ClassWizard はこの位置にメンバの初期化処理を追加します。
	//}}AFX_DATA_INIT

	setPage(this);
}

ModuleWorldPage::~ModuleWorldPage()
{
}

void ModuleWorldPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ModuleWorldPage)
		// メモ - ClassWizard はこの位置にマッピング用のマクロを追加または削除します。
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ModuleWorldPage, CPropertyPage)
	//{{AFX_MSG_MAP(ModuleWorldPage)
	ON_BN_CLICKED(IDC_MODULE_ADD, OnModuleAdd)
	ON_NOTIFY(LVN_BEGINDRAG, IDC_MODULE_LIST, OnBegindragModuleList)
	ON_WM_LBUTTONUP()
	ON_WM_PAINT()
	ON_WM_HSCROLL()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ModuleWorldPage メッセージ ハンドラ

void ModuleWorldPage::OnModuleAdd() 
{
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	addModuleType();
}

BOOL ModuleWorldPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	// TODO: この位置に初期化の補足処理を追加してください
//	setFont();
	createImageList();
	createToolTip();	

	return TRUE;  // コントロールにフォーカスを設定しないとき、戻り値は TRUE となります
	              // 例外: OCX プロパティ ページの戻り値は FALSE となります
}

void ModuleWorldPage::OnBegindragModuleList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: この位置にコントロール通知ハンドラ用のコードを追加してください
	DragBegin(pNMListView->iItem);
	
	*pResult = 0;
}

void ModuleWorldPage::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	ClientToScreen(&point);
	DragEnd(point.x, point.y);
	ScreenToClient(&point);

	CPropertyPage::OnLButtonUp(nFlags, point);
}

void ModuleWorldPage::OnPaint() 
{
	CPaintDC dc(this); // 描画用のデバイス コンテキスト
	
	// TODO: この位置にメッセージ ハンドラ用のコードを追加してください
	drawImageList();
	
	// 描画用メッセージとして CPropertyPage::OnPaint() を呼び出してはいけません
}

void ModuleWorldPage::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	setScrollBar(nSBCode, nPos);	
	
	CPropertyPage::OnHScroll(nSBCode, nPos, pScrollBar);
}

void ModuleWorldPage::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	setMouseButton(MOUSE_BUTTON_LEFT);
	mousex = point.x; mousey = point.y;
	
	CPropertyPage::OnLButtonDown(nFlags, point);
}

void ModuleWorldPage::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	if (isDragging() == false && getMouseButton() == MOUSE_BUTTON_LEFT && (point.x != mousex || point.y != mousey)) {
		ClientToScreen(&point);
		int n = isInsideImageList(point.x, point.y);
		if (0 <= n)
			DragBegin(n);
		ScreenToClient(&point);
	}
	
	CPropertyPage::OnMouseMove(nFlags, point);
}
