/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CDiagramClipboard.cpp
*
******************************************************************/

#include "CDiagramClipboard.h"
#include "CModule.h"

////////////////////////////////////////////////////////////
//	CDiagramClipboard::CDiagramClipboard
////////////////////////////////////////////////////////////

CDiagramClipboard::CDiagramClipboard()
{
}

////////////////////////////////////////////////////////////
//	CDiagramClipboard::CDiagramClipboard
////////////////////////////////////////////////////////////

CDiagramClipboard::CDiagramClipboard(CDiagramClipboard *clipboard)
{
	for (ScriptNode *node=clipboard->getModuleNodes(); node != NULL; node=node->next()) 
		addModuleNode(node);

	for (Route *route=clipboard->getRoutes(); route != NULL; route=route->next()) 
		addRoute(route);
}

////////////////////////////////////////////////////////////
//	CDiagramClipboard::~CDiagramClipboard
////////////////////////////////////////////////////////////

CDiagramClipboard::~CDiagramClipboard()
{
	clear();
}

////////////////////////////////////////////////////////////
//	CDiagramClipboard::addModuleNode
////////////////////////////////////////////////////////////

void CDiagramClipboard::addModuleNode(ScriptNode *node) 
{
	CModule	orgModule(node);

	CModule copyModule(orgModule.getModuleType());
	copyModule.setName(orgModule.getName());
	copyModule.setPositionX(orgModule.getPositionX());
	copyModule.setPositionY(orgModule.getPositionY());

	mModuleNodeList.addNode(copyModule.getScriptNode());		
}

////////////////////////////////////////////////////////////
//	CDiagramClipboard::addRoute
////////////////////////////////////////////////////////////

void CDiagramClipboard::addRoute(Route *route) 
{
	int nModule = getNModuleNodes();

	ScriptNode	*outModule = (ScriptNode *)route->getEventOutNode();
	Field		*outField = NULL;
	for (int n=0; n<nModule; n++) {
		ScriptNode *moduleNode = getModuleNode(n);
		if (StringCompare(outModule->getName(), moduleNode->getName()) == 0) {
			outModule = moduleNode;
			outField = outModule->getEventOut(route->getEventOutField()->getName());
			break;
		}
	}

	ScriptNode	*inModule = (ScriptNode *)route->getEventInNode();
	Field		*inField = NULL;
	for (n=0; n<nModule; n++) {
		ScriptNode *moduleNode = getModuleNode(n);
		if (StringCompare(inModule->getName(), moduleNode->getName()) == 0) {
			inModule = moduleNode;
			inField = inModule->getEventIn(route->getEventInField()->getName());
			break;
		}
	}

	Route *copyRoute = new Route(outModule, outField, inModule, inField);

	mRouteList.addNode(copyRoute);		
}
