/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CEven.h
*
******************************************************************/

#ifndef _CEVNET_H_
#define _CEVNET_H_

#include "LinkedList.h"
#include "Common.h"
#include "Node.h"
#include "CEventType.h"
#include "String.h"

#define CTB_EVENT_ROOT_NODE_NAME			"WORLD_EVENT_ROOT_NODE"
#define CTB_EVENT_NODE_NAME					"WORLD_EVENT"
#define CTB_SUBEVENT_ROOT_NODE_NAME			"WORLD_SUBEVENT_ROOT_NODE"
#define CTB_SUBEVENT_NODE_NAME				"WORLD_SUBEVENT"

#define CTB_EVENT_NONE_OPTION_NAME			"NONE"

#define CTB_EVENT_DEFAULT_NODE_TYPE			"THIS"
#define CTB_EVENT_SOURCE_NODE_NAME			"SOURCE"

#define	CTB_EVENTNAME_MAXLEN				64

///////////////////////////////////////////////////////////////////////
//
//	NODENAME		:	CTB_EVENT_("USER"|"SYSTEM")_(EventName)_(EventOption)_(NODETYPE)
//					;
//
//	NODETYPE		:	VRML_NODE_TYPE
//					|	"THIS"
//					;
//
///////////////////////////////////////////////////////////////////////

class CEvent : public LinkedListNode<CEvent> {
	Node	*mNode;
	String	mEventTypeName;
	String	mEventOptionName;
	String	mEventNodeTypeName;
	String	mSourceNodeName;
public:

	CEvent(CEventType *eventType, char *optionString = CTB_EVENT_NONE_OPTION_NAME);

	CEvent(Node *node) {
		setNode(node);
	}

	//////////////////////////////////////
	// Event Type
	//////////////////////////////////////

	char		*getEventTypeName();
	char		*getEventOptionName();
	CEventType	*getEventType();

	//////////////////////////////////////
	// Node
	//////////////////////////////////////
	
	BOOL	isEventNode();

	void	setNode(Node *node)		{mNode = node;}
	Node	*getNode()				{return mNode;}
	
	//////////////////////////////////////
	// Name
	//////////////////////////////////////

	void setName(Node *node, CEventType *eventType, char *optionString);
	char *getName();

	void setOptionString(char *optionString);

	//////////////////////////////////////
	// Attribute
	//////////////////////////////////////

	int		getAttributeType();

	//////////////////////////////////////
	// Node
	//////////////////////////////////////

	char	*getSourceNodeTypeName();
	char	*getSourceNodeName();
	Node	*getSourceNode();
	Field	*getSourceFiled();
};

#endif