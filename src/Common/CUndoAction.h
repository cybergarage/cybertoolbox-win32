/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CUndoAction.h
*
******************************************************************/
#ifndef _CUNDOACTION_H_
#define _CUNDOACTION_H_

#include "LinkedList.h"

#define UNDO_ACTION_DEFAULT_QUEUELEVEL_MAX	20

////////////////////////////////////////
//	CUndoActionNode
////////////////////////////////////////

class CUndoActionNode : public LinkedListNode<CUndoActionNode> {
	void	*mInfo;
	void	(*mUndoActionFn)(void *info);
	void	(*mFreeActionFn)(void *info);
public:
	CUndoActionNode(void);
	~CUndoActionNode(void);
	CUndoActionNode(void *info, void (*undoActionFn)(void *info), void (*freeActionFn)(void *info) = NULL);
	void	doFreeAction(void);
	void	doUndoAction(void);
};

////////////////////////////////////////
//	CUndoAction
////////////////////////////////////////

class CUndoAction {
	LinkedList<CUndoActionNode>	mUndoActionNodeList;
	int								mUndoLevel;
public:
	CUndoAction(void);
	~CUndoAction(void);
	void		setUndoQueueLevel(int undoLevel){ mUndoLevel = undoLevel; }
	int			getUndoQueueLevel(void)			{ return mUndoLevel; }
	int			getNQueues(void)				{ return mUndoActionNodeList.getNNodes();}
	void		enqueue(void *info, void (*undoActionFn)(void *info), void (*freeActionFn)(void *info) = NULL);
	void		dequeue(void);
	void		undo(void);
};

#endif