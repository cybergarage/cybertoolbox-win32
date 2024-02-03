/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CDiagramWindow.cpp
*
******************************************************************/

#include "CDiagramWindow.h" 

////////////////////////////////////////
//	Position
////////////////////////////////////////

void CDiagramWindow::getPosition(int *x, int *y)
{
	CWnd	*wnd = getHandle();
	RECT	rect;
	wnd->GetWindowRect(&rect);
	*x = rect.left;
	*y = rect.top;
}

////////////////////////////////////////
//	Size
////////////////////////////////////////

void CDiagramWindow::getSize(int *x, int *y)
{
	CWnd	*wnd = getHandle();
	RECT	rect;
	wnd->GetWindowRect(&rect);
	*x = rect.right - rect.left;
	*y = rect.bottom - rect.top;
}


////////////////////////////////////////
//	Inside
////////////////////////////////////////

BOOL CDiagramWindow::isInside(int x, int y)
{
	int wx, wy, width, height;
	getPosition(&wx, &wy);
	getSize(&width, &height);
	if (wx <= x && x<= (wx + width) && wy <= y && y <= (wy + height))
		return TRUE;
	else
		return FALSE;
}
