/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	DialogEvent.h
*
******************************************************************/

#ifndef _DIALOGEVENT_H_
#define _DIALOGEVENT_H_

class CEvent;

class DialogEvent {
	CEvent*mEvent;
public:
	DialogEvent()						{ mEvent = NULL; }
	void		setEvent(CEvent *event)	{ mEvent = event; }
	CEvent		*getEvent()				{ return mEvent; }
};

#endif