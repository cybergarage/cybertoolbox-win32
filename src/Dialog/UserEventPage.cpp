/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	UserEventPage.cpp
*
******************************************************************/

#include <assert.h>
#include "UserEventPage.h"

////////////////////////////////////////
//	UserEventPage::UserEventPage
////////////////////////////////////////

UserEventPage::UserEventPage()
{
	LOGFONT	lf;
	strcpy(lf.lfFaceName, "Arial");

	lf.lfHeight = 90;
	lf.lfWidth = 0;
	lf.lfEscapement = 0;
	lf.lfOrientation = 0;
	lf.lfWeight = 400;
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
}

UserEventPage::~UserEventPage()
{
}

////////////////////////////////////////
//	Font
////////////////////////////////////////

void UserEventPage::setFont(CWnd *wnd)
{
	if (!wnd)
		return;

	wnd->SetFont(&mFont);
}
