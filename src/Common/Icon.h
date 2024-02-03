/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	Icon.h
*
******************************************************************/
#ifndef _ICON_H_
#define _ICON_H_

#ifdef WIN32

#include <windows.h>

class CGrIcon{
public:
	HICON	mhIcon;
	int		mFileImageSize;
	char	*mFileImage;
public:
	~CGrIcon(void)					{delete mFileImage;}
	HICON	GetHandle(void)			{return mhIcon;}
	char	*GetFileImage(void)		{return mFileImage;}
	int		GetFileImageSize(void)	{return mFileImageSize;}
};

typedef CGrIcon		*GrIcon;

#endif

GrIcon	LoadIconFromFile(char *fname);
void	SaveIconIntoFile(GrIcon icon, char *iconFilename);

#endif