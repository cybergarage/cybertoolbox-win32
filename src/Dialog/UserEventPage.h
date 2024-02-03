/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	UserEventPage.h
*
******************************************************************/

#ifndef _USEREVENTPAGE_H_
#define _USEREVENTPAGE_H_

#include <afxwin.h>
#include <afxcmn.h>
#include <afxdlgs.h>

class UserEventPage {

	CFont			mFont;

public:

	~UserEventPage();
	UserEventPage();

	void	setFont(CWnd *wnd);
};

#endif