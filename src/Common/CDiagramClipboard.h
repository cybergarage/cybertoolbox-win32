/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CDiagramClipboard.h
*
******************************************************************/

#ifndef _CDIAGRAMCLIPBOARD_H_
#define _CDIAGRAMCLIPBOARD_H_

#include <assert.h>
#include "SceneGraph.h"

class CDiagramClipboard {
	
	NodeList			mModuleNodeList;
	LinkedList<Route>	mRouteList;

public:

	CDiagramClipboard();
	CDiagramClipboard(CDiagramClipboard *clipboard);

	~CDiagramClipboard();

	///////////////////////////////////////////////
	//	ModuleNode
	///////////////////////////////////////////////

	void addModuleNode(ScriptNode *node);

	ScriptNode *getModuleNodes() {
		return (ScriptNode *)mModuleNodeList.getNodes();		
	}

	ScriptNode *getModuleNode(int n) {
		return (ScriptNode *)mModuleNodeList.getNode(n);		
	}

	int getNModuleNodes() {
		return mModuleNodeList.getNNodes();
	}

	void clearModuleNodeList() {
		mModuleNodeList.deleteNodes();		
	}

	///////////////////////////////////////////////
	//	Route
	///////////////////////////////////////////////

	void addRoute(Route *route);

	Route *getRoutes() {
		return (Route *)mRouteList.getNodes();		
	}

	Route *getRoute(int n) {
		return (Route *)mRouteList.getNode(n);		
	}

	int getNRoutes() {
		return mRouteList.getNNodes();
	}

	void clearRouteList() {
		mRouteList.deleteNodes();		
	}

	///////////////////////////////////////////////
	//	clear
	///////////////////////////////////////////////

	void clear() {
		clearModuleNodeList();
		clearRouteList();
	}
};

#endif

