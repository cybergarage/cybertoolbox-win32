// ModuleFloating.cpp : インプリメンテーション ファイル
//

#include "stdafx.h"
#include "CyberToolBox.h"
#include "ModuleFloating.h"
#include "RegKey.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ModuleFloating

IMPLEMENT_DYNAMIC(ModuleFloating, CPropertySheet)

ModuleFloating::ModuleFloating(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&mModuleWorldPage);
	AddPage(&mModuleObjectPage);
	AddPage(&mModuleMaterialPage);
	AddPage(&mModuleViewPage);
	AddPage(&mModuleLightPage);
	AddPage(&mModuleInterpPage);
	AddPage(&mModuleNumericPage);
	AddPage(&mModuleMathPage);
	AddPage(&mModuleGeomPage);
	AddPage(&mModuleBooleanPage);
	AddPage(&mModuleFilterPage);
	AddPage(&mModuleMiscPage);

	mbInitialized = false;
}

ModuleFloating::ModuleFloating(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&mModuleWorldPage);
	AddPage(&mModuleObjectPage);
	AddPage(&mModuleMaterialPage);
	AddPage(&mModuleViewPage);
	AddPage(&mModuleLightPage);
	AddPage(&mModuleInterpPage);
	AddPage(&mModuleNumericPage);
	AddPage(&mModuleMathPage);
	AddPage(&mModuleGeomPage);
	AddPage(&mModuleBooleanPage);
	AddPage(&mModuleFilterPage);
	AddPage(&mModuleMiscPage);

	mbInitialized = false;
}

ModuleFloating::~ModuleFloating()
{
}


BEGIN_MESSAGE_MAP(ModuleFloating, CPropertySheet)
	//{{AFX_MSG_MAP(ModuleFloating)
	ON_WM_CREATE()
	ON_WM_MOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ModuleFloating メッセージ ハンドラ

BOOL ModuleFloating::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	return CWnd::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}

int ModuleFloating::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CPropertySheet::OnCreate(lpCreateStruct) == -1)
		return -1;

	return 0;
}

void ModuleFloating::OnMove(int x, int y) 
{
	CPropertySheet::OnMove(x, y);
	
	// TODO: この位置にメッセージ ハンドラ用のコードを追加してください

	if (mbInitialized == false)
		return;

	RECT	rect;
	GetWindowRect(&rect);
	RegKeyWriteValue(REGKEY_SECTION_POSITION, REGKEY_KEY_POSITION_DIAGRAMMODULE, rect.left, rect.top, rect.right-rect.left, rect.bottom-rect.top);
}

BOOL ModuleFloating::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください
	return CPropertySheet::PreCreateWindow(cs);
}

void ModuleFloating::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	
	CPropertySheet::OnLButtonDown(nFlags, point);
}

void ModuleFloating::OnClose() 
{
	// TODO: この位置にメッセージ ハンドラ用のコードを追加するかまたはデフォルトの処理を呼び出してください
	return;

	CPropertySheet::OnClose();
}

BOOL ModuleFloating::OnInitDialog() 
{
	BOOL bResult = CPropertySheet::OnInitDialog();
	
	// TODO: この位置に固有のコードを追加してください

	int	x, y, width, height;
	if (RegKeyGetValue(REGKEY_SECTION_POSITION, REGKEY_KEY_POSITION_DIAGRAMMODULE, &x, &y, &width, &height)) 
		SetWindowPos(NULL, x, y, 0, 0, SWP_NOSIZE);
	else
		SetWindowPos(NULL, 0, 450, 0, 0, SWP_NOSIZE);

	static CFont	mFont;

	LOGFONT	lf;
	lf.lfHeight = 1200;
	strcpy(lf.lfFaceName, "Arial");

	lf.lfHeight = 90;
	lf.lfWidth = 0;
	lf.lfEscapement = 0;
	lf.lfOrientation = 0;
	lf.lfWeight = 700;
	lf.lfItalic = FALSE;
	lf.lfUnderline = FALSE;
	lf.lfStrikeOut = 0;
	lf.lfCharSet = 0;
	lf.lfOutPrecision = OUT_DEFAULT_PRECIS;
	lf.lfClipPrecision = CLIP_DEFAULT_PRECIS;
	lf.lfQuality = DEFAULT_QUALITY;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	
	mFont.DeleteObject();
	mFont.CreatePointFontIndirect(&lf);
	SetFont(&mFont);

	mbInitialized = true;
	
	return bResult;
}

BOOL ModuleFloating::DestroyWindow() 
{
	// TODO: この位置に固有の処理を追加するか、または基本クラスを呼び出してください

	return CPropertySheet::DestroyWindow();
}
