/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	Common.h
*
******************************************************************/
#ifndef _COMMON_H_
#define _COMMON_H_

#ifndef BOOL
#ifdef WIN32
#include <afxwin.h>
#else
typedef char	BOOL;
#endif
#endif

#if (!TRUE && !FALSE)
#define TRUE	1
#define FALSE	0
#endif

#if (!X && !Y && !Z)
#define X	0
#define Y	1
#define Z	2
#endif

#include "UserMessage.h"

inline bool isRect(int x0, int y0, int x1, int y1, int x, int y)
{
	if (x0 <= x && x <= x1 && y0 <= y && y <= y1)
		return true;
	else
		return false;
}

inline bool isRect(int rect[], int x, int y)
{	if (rect[0] <= x && x <= rect[2] && rect[1] <= y && y <= rect[3])
		return true;
	else
		return false;
}

#endif