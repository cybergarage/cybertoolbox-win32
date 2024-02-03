/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	ModulePage.cpp
*
******************************************************************/

#include "ModulePage.h"
#include "World.h"
#include "CModuleType.h"
#include "..\resource.h"
#include "CDiagram.h"
#include "..\DiagramView.h"
#include "..\CyberToolBox.h"
#include "ModuleConfig.h"
#include "CUndoActionFn.h"

////////////////////////////////////////
//	ModulePage::ModulePage
////////////////////////////////////////

ModulePage::ModulePage()
{
	setPage(NULL);
	setDragItem(-1);
	setNImages(0);
	setMouseButton(MOUSE_BUTTON_NONE);
	mToolTipString = NULL;
	setDragging(false);
}

ModulePage::~ModulePage()
{
	mImageList.DeleteImageList();
	delete[] mToolTipString;
}

////////////////////////////////////////
//	Font
////////////////////////////////////////

void ModulePage::setFont()
{
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
	getPage()->SetFont(&mFont);

    CListCtrl* pList = (CListCtrl*)getPage()->GetDlgItem(IDC_MODULE_LIST);
	pList->SetFont(&mFont);
}

////////////////////////////////////////
//	ModulePage::createToolTip
////////////////////////////////////////

void ModulePage::updateToolTip()
{
	HWND parentWnd = getPage()->m_hWnd;//->GetDlgItem(IDC_MODULE_IMAGELIST)->m_hWnd;

	CWnd *pageWnd = getPage();
	CWnd *imgListWnd = getPage()->GetDlgItem(IDC_MODULE_IMAGELIST);

	RECT pageRect, imgListRect;
	pageWnd->GetWindowRect(&pageRect);
	imgListWnd->GetWindowRect(&imgListRect);

	int xoffset = imgListRect.left - pageRect.left;
	int yoffset = imgListRect.top - pageRect.top;

	mToolInfo.cbSize = sizeof(TOOLINFO);
	mToolInfo.hwnd = parentWnd;
	mToolInfo.hinst = NULL;

	CScrollBar	*sb = (CScrollBar *)getPage()->GetDlgItem(IDC_IMAGELIST_SCROLLBAR);
	int sbPos = sb->GetScrollPos();

	for (int n=0; n<getNScrollbarElements() && n<nToolTipString; n++) {
		mToolInfo.uId = n;
		mToolInfo.uFlags = TTF_SUBCLASS;
		mToolInfo.lpszText = mToolTipString[n + sbPos].getValue();
		mToolInfo.rect.top = 0 + 2 + yoffset;
		mToolInfo.rect.bottom = 32 + 2 + yoffset;
		mToolInfo.rect.left = 32*n + 2 + xoffset;
		mToolInfo.rect.right = 32*(n+1) + 2 + xoffset;
		SendMessage(mhToolTip, TTM_ADDTOOL, 0, (LPARAM)&mToolInfo);
	}
}

HWND ModulePage::createToolTip()
{
	HWND parentWnd = getPage()->m_hWnd;
	mhToolTip = CreateWindowEx(0, TOOLTIPS_CLASS, NULL, TTS_ALWAYSTIP, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, parentWnd, NULL, AfxGetInstanceHandle(), NULL);

	SendMessage(mhToolTip, TTM_ACTIVATE, TRUE, 0);
	SendMessage(mhToolTip, TTM_SETMAXTIPWIDTH, 0, SHRT_MAX);
	SendMessage(mhToolTip, TTM_SETDELAYTIME, TTDT_AUTOPOP, SHRT_MAX);
	SendMessage(mhToolTip, TTM_SETDELAYTIME, TTDT_INITIAL, 100);
	SendMessage(mhToolTip, TTM_SETDELAYTIME, TTDT_RESHOW, 100);

	char	*className = getClassName();

	nToolTipString = GetWorld()->getNModuleTypes(className);
	mToolTipString = new String[nToolTipString];
	
	int n = 0;
    for (CModuleType *cmType = GetWorld()->getModuleTypes(className); cmType; cmType = cmType->next(className)) {
		mToolTipString[n].setValue(cmType->getName());
		n++;
	}

	updateToolTip();

	return mhToolTip;
}

////////////////////////////////////////
//	ModulePage::updateImageList
////////////////////////////////////////

int ModulePage::getNScrollbarElements()
{
	CWnd *wnd = getPage()->GetDlgItem(IDC_MODULE_IMAGELIST);

	if (!wnd)
		return 0;

	RECT rect;
	wnd->GetClientRect(&rect);
	
	return (rect.right - rect.left)/32;
}

int ModulePage::getScrollBarPos()
{
    CScrollBar	*sb = (CScrollBar *)getPage()->GetDlgItem(IDC_IMAGELIST_SCROLLBAR);

	if (!sb)
		return -1;

	return sb->GetScrollPos();
}


void ModulePage::setScrollBar(UINT nSBCode, UINT nPos)
{
    CScrollBar	*sb = (CScrollBar *)getPage()->GetDlgItem(IDC_IMAGELIST_SCROLLBAR);
	CWnd		*wnd = getPage()->GetDlgItem(IDC_MODULE_IMAGELIST);

	if (!wnd || !sb)
		return;

	int nPage = getNScrollbarElements();
	int	nImage = getNImages();
	int pos = getScrollBarPos();

	switch (nSBCode) {
	case SB_LINELEFT: 
		pos -= 1;
		break;
	case SB_LINERIGHT: 
		pos += 1;
		break;
	case SB_LEFT: 
		pos = 0;
		break;
	case SB_RIGHT: 
		pos = nImage;
		break;
	case SB_PAGELEFT: 
		pos -= nPage;
		break;
	case SB_PAGERIGHT: 
		pos += nPage;
		break;
	case SB_THUMBTRACK:
	case SB_THUMBPOSITION:
		pos = nPos;
		break;
	}

	if (pos < 0)
		pos = 0;

	if ((nImage-nPage) < pos)
		pos = nImage - nPage;

	sb->SetScrollPos(pos);
/*
	wnd->InvalidateRect(NULL);
	wnd->UpdateWindow();
*/
	drawImageList();

	updateToolTip();
}

void ModulePage::initializeScrollBar()
{
	CScrollBar	*sb = (CScrollBar *)getPage()->GetDlgItem(IDC_IMAGELIST_SCROLLBAR);

	if (!sb)
		return;

	int nMaxImage = getNScrollbarElements();

	int nImage = getNImages();
	if (nMaxImage < nImage) {
		sb->SetScrollRange(0, nImage-1);
		sb->SetScrollPos(0);
		SCROLLINFO info;
		info.cbSize = sizeof(SCROLLINFO);
		info.fMask = SIF_PAGE;
		info.nPage = nMaxImage;
		sb->SetScrollInfo(&info);
		sb->EnableScrollBar(ESB_ENABLE_BOTH);
	}
	else {
		sb->SetScrollRange(0, nImage-1);
		sb->SetScrollPos(0);
		SCROLLINFO info;
		info.cbSize = sizeof(SCROLLINFO);
		info.fMask = SIF_PAGE;
		info.nPage = nImage;
		sb->SetScrollInfo(&info);
//		sb->EnableScrollBar(ESB_DISABLE_BOTH);
	}
}

void ModulePage::drawImageList()
{
	CScrollBar	*sb = (CScrollBar *)getPage()->GetDlgItem(IDC_IMAGELIST_SCROLLBAR);
	CWnd		*wnd = getPage()->GetDlgItem(IDC_MODULE_IMAGELIST);

	if (!wnd || !sb)
		return;

	CDC *pdc = wnd->GetDC();

	POINT pt;
	int nModules = getNImages();
	for (int n=0; n<getNScrollbarElements() && n<nToolTipString; n++) {
		int nImage = n + sb->GetScrollPos();
		pt.x = n*32 + 2;
		pt.y = 2;
		mImageList.Draw(pdc, nImage, pt, ILD_NORMAL);
	}

	wnd->ReleaseDC(pdc);
}

int ModulePage::isInsideImageList(int screenx, int screeny)
{
	CWnd *wnd = getPage()->GetDlgItem(IDC_MODULE_IMAGELIST);

	CPoint point;
	point.x = screenx;
	point.y = screeny;
	wnd->ScreenToClient(&point);

	for (int n=0; n<getNScrollbarElements(); n++) {
		int x = n*32 + 2;
		int y = 2;
		if (x < point.x && point.x <= (x+32) && y <= point.y && point.y <= (y+32)) {
			CScrollBar	*sb = (CScrollBar *)getPage()->GetDlgItem(IDC_IMAGELIST_SCROLLBAR);
			return (n + sb->GetScrollPos());
		}
	}

	return -1;
}

void ModulePage::createImageList()
{
	CModuleType *cmType;
	char		*className = getClassName();

	mImageList.DeleteImageList();
    mImageList.Create(32, 32, 0, 0, 8);
//    mImageList.SetBkColor(RGB(255, 255, 255)); 
    mImageList.SetBkColor(GetSysColor(COLOR_3DFACE)); 

	int nImages = 0;
    for (cmType = GetWorld()->getModuleTypes(getClassName()); cmType; cmType = cmType->next(getClassName())) {
		GrIcon icon = cmType->getIcon();
		assert(icon != NULL);
		mImageList.Add(icon->GetHandle());
		nImages++;
    }

	setNImages(nImages);
	initializeScrollBar();
}

////////////////////////////////////////
//	ModulePage::Drag
////////////////////////////////////////

void ModulePage::DragBegin(int item)
{
	if (item < getNImages()) {
//		CtbPrimitiveFloatingShowWindow(SW_HIDE);
		getPage()->SetCapture();
		::SetCursor(AfxGetApp()->LoadCursor(IDC_MODULE_CURSOR));
//		CPoint point(0,0);
//		mImageList.SetDragCursorImage(item, point);
		setDragItem(item);
		setDragging(true);
	}
	else
		MessageBeep(0);
}

void ModulePage::DragEnd(int x, int y)
{
	CPoint	point(x, y);
	CWnd	*dropWindow = getPage()->WindowFromPoint(point);

	if (0 <= getDragItem()) {
		if (GetWorld()->isDiagramWindow(dropWindow)) {
			CDiagramView		*dgmView = (CDiagramView *)dropWindow;
			CDiagram			dgm(dgmView->getDiagramNode());
			dgmView->ScreenToClient(&point);
			CPoint offset = dgmView->GetScrollPosition();
			CModuleType			*cmType = GetWorld()->getModuleType(getClassName(), getDragItem());
			CModule				module(cmType);

			int x = point.x + offset.x;
			int y = point.y + offset.y;
			if (dgmView->getGridSnap()) {
				x -= x % (32/4);
				y -= y % (32/4);
			}

			module.setPosition(x, y);
			dgm.addModule(&module);

			// Undo Action
			dgmView->enqueue(UndoDiagramModuleAddNew(dgmView->getDiagramNode(), module.getScriptNode()), UndoDiagramModuleAddFn);

			// Update Screen Size
			dgmView->updateScreenSize();

			dgmView->InvalidateRect(NULL);
			
			//CCyberToolBoxApp	*ctbApp = (CCyberToolBoxApp *)AfxGetApp();
			//ctbApp->resetSceneGraphTree();
		}
	}

//	CtbPrimitiveFloatingShowWindow(SW_SHOW);

	ReleaseCapture();
	::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_ARROW));

	setDragging(false);

	setMouseButton(MOUSE_BUTTON_NONE);
}

////////////////////////////////////////
//	Module
////////////////////////////////////////

void ModulePage::addModuleType()
{
	ModuleConfig moduleConfig(getPage());
	CModuleType	*cmType = new CModuleType();
	cmType->setClassName(getClassName());
	moduleConfig.setModuleType(cmType);
	if (moduleConfig.DoModal() == IDOK) {
		cmType->check();
		if (cmType->save()) {
			GetWorld()->addModuleType(cmType);
			createImageList();
		}
	}
	else
		delete cmType;
}

void ModulePage::configModuleType(CModuleType *cmType)
{
}

void ModulePage::deleteModuleType(CModuleType *cmType)
{
}

