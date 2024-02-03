/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CGlobalData.h
*
******************************************************************/

#ifndef _CGLOBALDATA_H_
#define _CGLOBALDATA_H_

#include <assert.h>
#include "common.h"

class AnchorNode;

#define CTB_GLOBALDATA_NODENAME			"WORLD_GLOBALDATA"
#define CTB_GLOBALDATA_DATAFIELD		"WORLD_GLOBALDATA_VALUE"
#define CTB_GLOBALDATA_SCRIPT_NAME		"SystemGlobalData.class"

#define CTB_GLOBALDATA_NAME_MAXLEN	512

///////////////////////////////////////////////////////////////////////
//
// NODENAME			: CTB_GLOBALDATA_(DATANAME)
//					;
//
///////////////////////////////////////////////////////////////////////

class CGlobalData {

	AnchorNode		*mAnchor;

public:

	CGlobalData(char *name);

	CGlobalData(AnchorNode *info);

	//////////////////////////////////////////////////
	// Node
	//////////////////////////////////////////////////

	void setNode(AnchorNode *info) {
		assert(info != NULL);
		mAnchor = info;
	}

	AnchorNode *getNode() {
		assert(mAnchor != NULL);
		return mAnchor;
	}

	//////////////////////////////////////////////////
	// Name		
	//////////////////////////////////////////////////

	void setName(char *name);
	char *getName();
};

#endif