#ifndef _USERMESSAGE_H_
#define _USERMESSAGE_H_

#include <afxwin.h>

void UsrMsgError(char *, ...);
void UsrMsgWarning(char *, ...);
BOOL UsrMsgQuestion(char *fmt, ...);

#ifdef WIN32

void UsrMsgSetParentWindow(HWND);
void UsrMsgSetParentWindow(CWnd *);
HWND UsrMsgGetParentWindow();

#endif

#endif
