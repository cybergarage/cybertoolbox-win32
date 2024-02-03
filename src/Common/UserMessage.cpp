#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "common.h"

#ifdef WIN32

HWND	gParentWindow = NULL;

void UsrMsgSetParentWindow(HWND hwnd)
{
	gParentWindow = hwnd;
}

void UsrMsgSetParentWindow(CWnd *wnd)
{
	gParentWindow = wnd->m_hWnd;
}

HWND UsrMsgGetParentWindow()
{
	return gParentWindow;
}

#endif

void UsrMsgWarning(char *fmt, ...)
{
	va_list args;
#ifdef WIN32
	char	errorBuf[256] = {""};
	char	buf[256];
#endif
	
	fprintf(stderr, "Error : ");
	va_start(args, fmt);
#ifdef WIN32
	(void)vsprintf(buf, fmt, args);
	strcat(errorBuf, buf);
#else
	(void)vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
#endif
	va_end(args);
	
#if WIN32
	MessageBox(UsrMsgGetParentWindow(), errorBuf, "", MB_ICONEXCLAMATION);
#endif
}

BOOL UsrMsgQuestion(char *fmt, ...)
{
	va_list args;
#ifdef WIN32
	char	errorBuf[256] = {""};
	char	buf[256];
#endif
	
	fprintf(stderr, "Error : ");
	va_start(args, fmt);
#ifdef WIN32
	(void)vsprintf(buf, fmt, args);
	strcat(errorBuf, buf);
#else
	(void)vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
#endif
	va_end(args);
	
#if WIN32
	int ret = MessageBox(UsrMsgGetParentWindow(), errorBuf, "", MB_OKCANCEL | MB_ICONQUESTION);
	if (ret == IDOK)
		return TRUE;
	else
		return FALSE;
#endif
}

void UsrMsgError(char *fmt, ...)
{
	va_list args;
#ifdef WIN32
	char	errorBuf[256] = {""};
	char	buf[256];
#endif
	
	fprintf(stderr, "Error : ");
	va_start(args, fmt);
#ifdef WIN32
	(void)vsprintf(buf, fmt, args);
	strcat(errorBuf, buf);
#else
	(void)vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
#endif
	va_end(args);
	
#if WIN32
	MessageBox(UsrMsgGetParentWindow(), errorBuf, "", MB_ICONEXCLAMATION);
#endif

	exit(-1);
}

