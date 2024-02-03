/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CDiagram.h
*
******************************************************************/

#ifndef _CDIAGRAM_H_
#define _CDIAGRAM_H_

#include <assert.h>
#include "common.h"
#include "SceneGraph.h"
#include "CModule.h"
#include "CEvent.h"

enum {
DIAGRAM_MODE_NONE,
DIAGRAM_MODE_MOVING_MODULE				= 0x01,
DIAGRAM_MODE_SELECTING_MODULE			= MODULE_INSIDE,
DIAGRAM_MODE_SELECTING_MODULE_INNODE	= MODULE_INSIDE_INNODE,
DIAGRAM_MODE_SELECTING_MODULE_OUTNODE	= MODULE_INSIDE_OUTNODE,
};

enum {
EXTENTS_MIN,
EXTENTS_MAX
};

#define CTB_DIAGRAM_NODENAME	"WORLD_DIAGRAM"

#define DIAGRAM_NAME_MAXLEN		256

///////////////////////////////////////////////////////////////////////
//
// NODENAME			: WORLD_DIAGRAM_(EVENTTYPESTRING)_(WINDOWNAME)
//					;
//
// EVENTTYPESTRING	: WORLD_EVENT_BASIS_(EventName)
//					| WORLD_EVENT_USER_(EventName)_(EventOption)
//					;
//
///////////////////////////////////////////////////////////////////////

class CDiagram {

	TransformNode	*mTransform;
	int				mExtents[2][2];

public:

	CDiagram(char *name, CEvent *event);

	CDiagram(TransformNode *transform);

	//////////////////////////////////////////////////
	// Node name		
	//////////////////////////////////////////////////

	void setTransformNode(TransformNode *transform) {
		assert(transform != NULL);
		mTransform = transform;
	}

	TransformNode *getTransformNode() {
		assert(mTransform != NULL);
		return mTransform;
	}

	void setTransformNodeName(char *name, CEvent *event);

	char *getTransformNodeName() {
		return (getTransformNode())->getName();
	}

	//////////////////////////////////////////////////
	// Name
	//////////////////////////////////////////////////

	void setName(char *name);

	char *getName();

	//////////////////////////////////////////////////
	// EventType
	//////////////////////////////////////////////////

	void	setEventType(CEvent *event) {
		setTransformNodeName(getName(), event);
	}

	Node	*getEventNode();

	//////////////////////////////////////////////////
	// Position
	//////////////////////////////////////////////////

	void setPosition(int x, int y) {
		(getTransformNode())->setTranslation((float)x, (float)y, 0.0f);
	}

	void getPosition(int *x, int *y) {
		float	translation[3];
		(getTransformNode())->getTranslation(translation);
		*x = (int)translation[X];
		*y = (int)translation[Y];
	}

	void setXPositionX(int x) {
		(getTransformNode())->setTranslation((float)x, (float)getYPosition(), 0.0f);
	}

	void setYPositionint(int y) {
		(getTransformNode())->setTranslation((float)getXPosition(), (float)y, 0.0f);
	}

	int getXPosition() {
		float	translation[3];
		(getTransformNode())->getTranslation(translation);
		return (int)translation[X];
	}

	int getYPosition() {
		float	translation[3];
		(getTransformNode())->getTranslation(translation);
		return (int)translation[Y];
	}

	//////////////////////////////////////////////////
	// Width/Height
	//////////////////////////////////////////////////

	void setWidth(int width) {
		(getTransformNode())->setScale((float)width, (float)getHeight(), 1.0f);
	}

	void setHeight(int height) {
		(getTransformNode())->setScale((float)getWidth(), (float)height, 1.0f);
	}

	int getWidth() {
		float	scale[3];
		(getTransformNode())->getScale(scale);
		return (int)scale[X];
	}

	int getHeight() {
		float	scale[3];
		(getTransformNode())->getScale(scale);
		return (int)scale[Y];
	}

	//////////////////////////////////////////////////
	// Module
	//////////////////////////////////////////////////

	bool		isModule(ScriptNode *script);
	
	void		addModule(CModule *module);
	void		deleteModule(CModule *module);
	void		removeModule(CModule *module);
	void		setModuleDefaultRoute(CModule *module);

	int			getNModules();
	int			getNModules(int rect[]);
	ScriptNode	*getModules();
	ScriptNode	*getModule(int n);
	ScriptNode	*getModule(int x, int y, int *part);

	bool		hasModule(Node *script);

	void		addBasisModule();

	//////////////////////////////////////////////////
	// Route
	//////////////////////////////////////////////////
	
	bool hasRoute(Route *route) {
		if (hasModule(route->getEventInNode()) && hasModule(route->getEventOutNode())) 
			return true;
		return false;
	}

	//////////////////////////////////////////////////
	// Extents
	//////////////////////////////////////////////////

	void	getExtents(int extents[2][2]) {
		extents[EXTENTS_MIN][X] = mExtents[EXTENTS_MIN][X];
		extents[EXTENTS_MIN][Y] = mExtents[EXTENTS_MIN][Y];
		extents[EXTENTS_MAX][X] = mExtents[EXTENTS_MAX][X];
		extents[EXTENTS_MAX][Y] = mExtents[EXTENTS_MAX][Y];
	}

	void	setExtents(int extents[2][2]) {
		mExtents[EXTENTS_MIN][X] = extents[EXTENTS_MIN][X];
		mExtents[EXTENTS_MIN][Y] = extents[EXTENTS_MIN][Y];
		mExtents[EXTENTS_MAX][X] = extents[EXTENTS_MAX][X];
		mExtents[EXTENTS_MAX][Y] = extents[EXTENTS_MAX][Y];
	}

	void	updateExtents();
};

#endif