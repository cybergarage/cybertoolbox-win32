/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CModule.h
*
******************************************************************/

#ifndef _CMODULE_H_
#define _CMODULE_H_

#include "SceneGraph.h"
#include "CModuleType.h"
#include "World.h"

#define MODULE_CLASSNAME_FIELDNAME		"SYSTEM_FIELD_MODULE_CLASSNAME"
#define MODULE_MODULENAME_FIELDNAME		"SYSTEM_FIELD_MODULE_NAME"
#define MODULE_XPOS_FIELDNAME			"SYSTEM_FIELD_MODULE_XPOS"
#define MODULE_YPOS_FIELDNAME			"SYSTEM_FIELD_MODULE_YPOS"
#define MODULE_VALUE_FIELDNAME			"SYSTEM_FIELD_MODULE_VALUE"
#define MODULE_EXECUTION_EVENTINNAME	"SYSTEM_EVENTIN_MODULE_EXECUTION"

#define MODULE_NAME_MAXLEN				256

#define MODULE_SIZE						32
#define MODULE_NODE_SIZE				5
#define MODULE_NODE_SPACING				((MODULE_SIZE - MODULE_NODE_SIZE * MODULE_INOUTNODE_MAXNUM) / (MODULE_INOUTNODE_MAXNUM+1))

#define MODULE_SOURCE_NODENAME			"SYSTEM_FIELD_MODULE_SOURCE_NODE"

#define MODULE_TARGET_FIELDNAME			"SYSTEM_FIELD_MODULE_TARGET_FILED"
#define MODULE_TARGET_NODENAME			"SYSTEM_FIELD_MODULE_TARGET_NODE"

enum {
MODULE_OUTSIDE,
MODULE_INSIDE				= 0x100,
MODULE_INSIDE_INNODE		= 0x200,	
MODULE_INSIDE_OUTNODE		= 0x400,
MODULE_INSIDE_EXECUTIONNODE	= 0x800,
};

#define MODULE_NONE_VALUE				"WORLD_NONE"

#define MODULE_NODE_NUMBER_MASK		0xff

class CModule {

	CModuleType	*mModuleType;
	ScriptNode	*mScript;

public:

	CModule(CModuleType *moduleType);
	CModule(ScriptNode *script);

	//////////////////////////////////////////////////
	// ModuleType
	//////////////////////////////////////////////////

	void setModuleType(CModuleType *moduleType) {
		mModuleType = moduleType;
	}

	CModuleType *getModuleType() {
		assert(mModuleType);
		return mModuleType;
	}

	//////////////////////////////////////////////////
	// ScriptNode
	//////////////////////////////////////////////////

	void setScript(ScriptNode *script) {
		mScript = script;
	}

	ScriptNode *getScriptNode() {
		assert(mScript);
		return mScript;
	}

	////////////////////////////////////////////////
	//	Name
	////////////////////////////////////////////////

	void setName(char *name) {
		getScriptNode()->setName(name);
	}

	char *getName() {
		return getScriptNode()->getName();
	}

	////////////////////////////////////////////////
	//	X position
	////////////////////////////////////////////////

	void setPositionX(int value) {
		SFInt32 *xpos = (SFInt32 *)getScriptNode()->getField(MODULE_XPOS_FIELDNAME);
		assert(xpos);
		xpos->setValue(value);
	}
	int getPositionX() {
		SFInt32 *xpos = (SFInt32 *)getScriptNode()->getField(MODULE_XPOS_FIELDNAME);
		assert(xpos);
		return xpos->getValue();
	}

	////////////////////////////////////////////////
	//	Y position
	////////////////////////////////////////////////

	void setPositionY(int value) {
		SFInt32 *ypos = (SFInt32 *)getScriptNode()->getField(MODULE_YPOS_FIELDNAME);
		assert(ypos);
		ypos->setValue(value);
	}
	int getPositionY() {
		SFInt32 *ypos = (SFInt32 *)getScriptNode()->getField(MODULE_YPOS_FIELDNAME);
		assert(ypos);
		return ypos->getValue();
	}

	////////////////////////////////////////////////
	//	Position
	////////////////////////////////////////////////

	void setPosition(int x, int y) {
		setPositionX(x);
		setPositionY(y);
	}

	void getPosition(int *x, int *y) {
		*x = getPositionX();
		*y = getPositionY();
	}

	////////////////////////////////////////////////
	//	Value
	////////////////////////////////////////////////

	void setValue(char *value) {
		SFString *svalue = (SFString *)getScriptNode()->getField(MODULE_VALUE_FIELDNAME);
		assert(svalue);
		svalue->setValue(value);
	}
	char *getValue() {
		SFString *svalue = (SFString *)getScriptNode()->getField(MODULE_VALUE_FIELDNAME);
		assert(svalue);
		return svalue->getValue();
	}

	////////////////////////////////////////////////
	//	Size
	////////////////////////////////////////////////

	int getSize()	{ return MODULE_SIZE; }

	////////////////////////////////////////////////
	//	Number
	////////////////////////////////////////////////
		
	int getNumber();

	////////////////////////////////////////////////
	//	Event Field
	////////////////////////////////////////////////

	int		getNEventInFields()			{return getScriptNode()->getNEventIn() - getNSystemEventInNodes();}
	int		getNEventOutFields()		{return getScriptNode()->getNEventOut();}

	Field	*getEventInField(int n)		{return getScriptNode()->getEventIn(n + getNSystemEventInNodes());}
	Field	*getEventOutField(int n)	{return getScriptNode()->getEventOut(n);}

	////////////////////////////////////////////////
	//	Event Field Node
	////////////////////////////////////////////////
		
	int		getNodeSize()				{return MODULE_NODE_SIZE;}
	int		getNodeSpaceing()			{return MODULE_NODE_SPACING;}
	int		getNSystemEventInNodes();
	int		getNEventInNodes()			{return getNEventInFields();}
	int		getNEventOutNodes()			{return getNEventOutFields();}
	int		getEventInNodeSpacing()		{return (MODULE_SIZE - MODULE_NODE_SIZE * getNEventInNodes()) / (getNEventInNodes()+1);}
	int		getEventOutNodeSpacing()	{return (MODULE_SIZE - MODULE_NODE_SIZE * getNEventOutNodes()) / (getNEventOutNodes()+1);}

	bool	hasEventInNode()			{return (0 < getNEventInNodes()) ? true : false;}
	bool	hasEventOutNode()			{return (0 < getNEventOutNodes()) ? true : false;}

	void	getEventInNodePosition(int n, int *x, int *y);
	void	getEventOutNodePosition(int n, int *x, int *y);

	int		getEventInNodeNumber(Field *field);
	int		getEventOutNodeNumber(Field *field);

	////////////////////////////////////////////////
	//	Inside
	////////////////////////////////////////////////

	int		isInside(int x, int y);

	////////////////////////////////////////////////
	//	ExecutionNode
	////////////////////////////////////////////////

	BOOL hasExecutionNode() {
		return getExecutionField() ? TRUE : FALSE;
	}

	Field *getExecutionField() {
		return getScriptNode()->getEventIn(MODULE_EXECUTION_EVENTINNAME);
	}

	void getExecutionNodePosition(int *x, int *y) {
		*x = getPositionX() + getSize()/2 - getNodeSize()/2;
		*y = getPositionY() - getNodeSize();
	}

	////////////////////////////////////////////////
	//	Route node position
	////////////////////////////////////////////////

	void getRouteOutNodePosition(Field *field, int *x, int *y) {
		getEventOutNodePosition(getEventOutNodeNumber(field), x, y);
		*x += getNodeSize() / 2; 
		*y += getNodeSize() / 2; 
	}

	void getRouteInNodePosition(Field *field, int *x, int *y) {
		if (field != getExecutionField()) 
			getEventInNodePosition(getEventInNodeNumber(field), x, y);
		else 
			getExecutionNodePosition(x, y);
		*x += getNodeSize() / 2; 
		*y += getNodeSize() / 2; 
	}

	////////////////////////////////////////////////
	//	SourceNode
	////////////////////////////////////////////////

	SFNode	*createSourceNodeField() {
		SFNode *field = new SFNode();
		getScriptNode()->addField(MODULE_SOURCE_NODENAME, field);
		return field;
	}

	SFNode	*getSourceNodeField() {
		return (SFNode *)getScriptNode()->getField(MODULE_SOURCE_NODENAME);
	}

	void	setSourceNode(Node *node) {
		if (node) {
			SFNode *sfnode = getSourceNodeField();
			if (!sfnode)
				sfnode = createSourceNodeField();
			sfnode->setValue(node);
		}
		else {
			SFNode *sfnode = getSourceNodeField();
			if (sfnode)
				delete sfnode;
		}
		initialize();
	}

	Node	*getSourceNode() {
		SFNode *sfnode = getSourceNodeField();
		if (sfnode)
			return sfnode->getValue();
		return NULL;
	}

	////////////////////////////////////////////////
	//	TargetNode
	////////////////////////////////////////////////

	SFNode	*createTargetNodeField() {
		SFNode *field = new SFNode();
		getScriptNode()->addField(MODULE_TARGET_NODENAME, field);
		return field;
	}

	SFNode	*getTargetNodeField() {
		return (SFNode *)getScriptNode()->getField(MODULE_TARGET_NODENAME);
	}

	void	setTargetNode(Node *node) {
		if (node) {
			SFNode *sfnode = getTargetNodeField();
			if (!sfnode)
				sfnode = createTargetNodeField();
			sfnode->setValue(node);
		}
		else {
			SFNode *sfnode = getTargetNodeField();
			if (sfnode)
				delete sfnode;
		}

		initialize();
	}

	Node	*getTargetNode() {
		SFNode *sfnode = getTargetNodeField();
		if (sfnode)
			return sfnode->getValue();
		return NULL;
	}

	////////////////////////////////////////////////
	//	initialize
	////////////////////////////////////////////////

	void initialize() {
		ScriptNode *snode = getScriptNode();
		if (snode) {
			snode->uninitialize();
			snode->initialize();
		}
	}

	////////////////////////////////////////////////
	//	Route
	////////////////////////////////////////////////

	int		getNInputRoutes();
	int		getNOutputRoutes();
	int		getNRoutes();

	void	setOutputRoute(Field *thisOutField, ScriptNode *targetNode, Field *targetField);
};

#endif