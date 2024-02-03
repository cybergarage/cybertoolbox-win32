/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CUndoAction.cpp
*
******************************************************************/
#include <stdlib.h>
#include "Common.h"
#include "CUndoAction.h"

////////////////////////////////////////
//	CUndoActionNode
////////////////////////////////////////

CUndoActionNode::CUndoActionNode(void)
{
	setHeaderFlag(TRUE);
	mInfo = mUndoActionFn = mFreeActionFn = NULL;
}

CUndoActionNode::~CUndoActionNode(void)
{
	if (mInfo)
		free(mInfo);
}

CUndoActionNode::CUndoActionNode(void *info, void (*undoActionFn)(void *info), void (*freeActionFn)(void *info))
{
	setHeaderFlag(FALSE);
	mInfo = info;
	mUndoActionFn = undoActionFn;
	mFreeActionFn = freeActionFn;
}

void CUndoActionNode::doUndoAction(void)
{
	if(isHeaderNode())
		return;
	if (mUndoActionFn)
		mUndoActionFn(mInfo);
}

void CUndoActionNode::doFreeAction(void)
{
	if(isHeaderNode())
		return;
	if (mFreeActionFn)
		mFreeActionFn(mInfo);
}

////////////////////////////////////////
//	CUndoAction
////////////////////////////////////////

CUndoAction::CUndoAction(void)
{
	setUndoQueueLevel(UNDO_ACTION_DEFAULT_QUEUELEVEL_MAX);
}

CUndoAction::~CUndoAction(void)
{
	mUndoActionNodeList.deleteNodes();
}

void CUndoAction::dequeue(void)
{
	CUndoActionNode *undoActionNode = mUndoActionNodeList.getLastNode();
	if (undoActionNode)
		delete undoActionNode;
}

void CUndoAction::enqueue(void *info, void (*undoActionFn)(void *info), void (*freeActionFn)(void *info))
{
	CUndoActionNode *undoActionNode = new CUndoActionNode(info, undoActionFn, freeActionFn);
	mUndoActionNodeList.addNode(undoActionNode);

	int undoQueueLevel = getUndoQueueLevel();
	if (undoQueueLevel < getNQueues()) {
		CUndoActionNode *undoActionNode = mUndoActionNodeList.getNodes();
		undoActionNode->doFreeAction();
		delete undoActionNode;
	}
}

void CUndoAction::undo(void)
{
	CUndoActionNode *undoActionNode = mUndoActionNodeList.getLastNode();
	if (!undoActionNode)
		return;
	undoActionNode->doUndoAction();
	dequeue();
}
