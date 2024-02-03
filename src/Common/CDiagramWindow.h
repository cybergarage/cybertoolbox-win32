/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CDiagramWindow.h
*
******************************************************************/
#ifndef _CDIAGRAMWINDOW_H_
#define _CDIAGRAMWINDOW_H_

#ifdef WIN32
#include <afxwin.h>
#endif

#include <assert.h>
#include "Common.h"
#include "LinkedList.h"
#include "CUndoAction.h"

class CDiagramWindow : public LinkedListNode<CDiagramWindow>, public CUndoAction {
public:
	CWnd	*mDgmView;

public:

	CDiagramWindow(CWnd *wnd) {
		setHeaderFlag(0);
		setHandle(wnd);
	}

	~CDiagramWindow()	{
	}

	////////////////////////////////////////
	//	View
	////////////////////////////////////////

	void setHandle(CWnd *view) {
		mDgmView = view;
	}

	CWnd *getHandle() {
		return mDgmView;
	}

	////////////////////////////////////////
	//	Position
	////////////////////////////////////////

	void getPosition(int *x, int *y);

	////////////////////////////////////////
	//	Size
	////////////////////////////////////////

	void getSize(int *x, int *y);

	////////////////////////////////////////
	//	Inside
	////////////////////////////////////////

	BOOL isInside(int x, int y);
};

#endif
