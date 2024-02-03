/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CGlobalData.cpp
*
******************************************************************/

#include "CGlobalData.h"
#include "World.h"
#include "StringFn.h"

//////////////////////////////////////////////////
// CGlobalData::CGlobalData
//////////////////////////////////////////////////

CGlobalData::CGlobalData(char *name) {
	AnchorNode *info = new AnchorNode();
	setNode(info);
	setName(name);
}

CGlobalData::CGlobalData(AnchorNode *node) {
	setNode(node);
}

//////////////////////////////////////////////////
// CGlobalData::setName
//////////////////////////////////////////////////

void CGlobalData::setName(char *name)
{
	assert(name && strlen(name));
	char	nodeName[CTB_GLOBALDATA_NAME_MAXLEN];
	sprintf(nodeName, "%s_%s", CTB_GLOBALDATA_NODENAME, name);
	getNode()->setName(nodeName);
}

//////////////////////////////////////////////////
// CGlobalData::getName
//////////////////////////////////////////////////

char *CGlobalData::getName()
{
	char *nodeName = getNode()->getName();
	int index = StringLastIndexOf(nodeName, '_');
	assert(index != -1);
	return (nodeName + (index+1));
}
