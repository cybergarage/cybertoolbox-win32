/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CModule.cpp
*
******************************************************************/
#include "CModule.h"
#include "StringFn.h"
#include "World.h"

//////////////////////////////////////////////////
// CModule::CModule
//////////////////////////////////////////////////

CModule::CModule(CModuleType *moduleType) 
{
	setModuleType(moduleType);

	ScriptNode *script = new ScriptNode();
	script->setDirectOutput(true);
	script->setMustEvaluate(true);
	setScript(script);

	// Set script
	script->addUrl(moduleType->getScriptName());

	// Add system eventIn fields
	int	n;
	for (n=0; n<GetWorld()->getNEventTypes(); n++) {
		CEventType	*eventType = GetWorld()->getEventType(n);
		script->addEventIn(eventType->getModuleFieldName(), eventType->getFieldType());
	}

	// Add ExecutionNode
	if (moduleType->hasExecutionNode()) 
		script->addEventIn(MODULE_EXECUTION_EVENTINNAME, new SFString("TRUE"));

	// Add system fields of the module type
	script->addField(MODULE_CLASSNAME_FIELDNAME, new SFString(moduleType->getClassName()));
	script->addField(MODULE_MODULENAME_FIELDNAME, new SFString(moduleType->getName()));
	script->addField(MODULE_XPOS_FIELDNAME, new SFInt32());
	script->addField(MODULE_YPOS_FIELDNAME, new SFInt32());
	script->addField(MODULE_VALUE_FIELDNAME, new SFString("0"));

	// Source Field
	//script->addField(MODULE_SOURCE_NODENAME, new SFNode());

	// Target Field
	//script->addField(MODULE_TARGET_NODENAME, new SFNode());

	// Add user eventType fields of the module type (Need to add the user fields at last)
	for (n=0; n<MODULE_INOUTNODE_MAXNUM; n++) {
		if (moduleType->getEventInFieldType(n))
			script->addEventIn(moduleType->getEventInFieldName(n), moduleType->getEventInFieldType(n));
		if (moduleType->getEventOutFieldType(n))
			script->addEventOut(moduleType->getEventOutFieldName(n), moduleType->getEventOutFieldType(n));
	}

	// Initialize script node (The initialization is hang up !! 06/04/1997)
//	script->initialize();
}

CModule::CModule(ScriptNode *script) 
{
	setScript(script);
	char *className = ((SFString *)script->getField(MODULE_CLASSNAME_FIELDNAME))->getValue();
	char *moduleName = ((SFString *)script->getField(MODULE_MODULENAME_FIELDNAME))->getValue();
	CModuleType *cmType = GetWorld()->getModuleType(className, moduleName);
	assert(cmType);
	setModuleType(cmType);
}

////////////////////////////////////////////////
//	CModule::Number
////////////////////////////////////////////////

int CModule::getNumber()
{
	ScriptNode *script = getScriptNode();
	char	*name = script->getName();
	assert(name);
	int index = StringLastIndexOf(name, 'E'); 
	char	*numberString = name + (index + 1);
	return atoi(numberString);
}

////////////////////////////////////////////////
//	eventType Field Position
////////////////////////////////////////////////

void CModule::getEventInNodePosition(int n, int *x, int *y)
{
	assert(0<=n && n<getNEventInNodes());

	int	mx, my;
	getPosition(&mx, &my);

	*x = mx - getNodeSize();
	*y = my + (getEventInNodeSpacing() * (n+1)) + (getNodeSize() * n);
}

void CModule::getEventOutNodePosition(int n, int *x, int *y)
{
	assert(0<=n && n<getNEventOutNodes());

	int	mx, my;
	getPosition(&mx, &my);

	*x = mx + getSize();
	*y = my + (getEventOutNodeSpacing() * (n+1)) + (getNodeSize() * n);
}

////////////////////////////////////////////////
//	eventType Field Number
////////////////////////////////////////////////

int	CModule::getEventInNodeNumber(Field *field)
{
	int nodeNumber = getScriptNode()->getEventInNumber(field);
	assert(0<=nodeNumber);
	return nodeNumber - getNSystemEventInNodes();
}

int	CModule::getEventOutNodeNumber(Field *field)
{
	int nodeNumber = getScriptNode()->getEventOutNumber(field);
	assert(0<=nodeNumber);
	return nodeNumber;
}

////////////////////////////////////////////////
//	CModule::Inside
////////////////////////////////////////////////

int CModule::isInside(int x, int y)
{
	int		mx, my;

	getPosition(&mx, &my);
	int mSize = getSize();
	if (isRect(mx, my, mx+mSize, my+mSize, x, y))
		return MODULE_INSIDE;

	int		n;
	int		nodeSize = getNodeSize();
	int		expandSize = getNodeSize();
	int		nodex, nodey;

	for (n=0; n<getNEventInNodes(); n++) {
		getEventInNodePosition(n, &nodex, &nodey);
		if (isRect(nodex, nodey, nodex+nodeSize, nodey+nodeSize, x, y))
			return (MODULE_INSIDE_INNODE | n);
	}

	for (n=0; n<getNEventOutNodes(); n++) {
		getEventOutNodePosition(n, &nodex, &nodey);
		if (isRect(nodex, nodey, nodex+nodeSize, nodey+nodeSize, x, y))
			return (MODULE_INSIDE_OUTNODE | n);
	}

	if (hasExecutionNode()) {
		getExecutionNodePosition(&nodex, &nodey);
		if (isRect(nodex, nodey, nodex+nodeSize, nodey+nodeSize, x, y))
			return MODULE_INSIDE_EXECUTIONNODE;
	}

	// Add expand size to only x position
	for (n=0; n<getNEventInNodes(); n++) {
		getEventInNodePosition(n, &nodex, &nodey);
		if (isRect(nodex-expandSize, nodey, nodex+nodeSize, nodey+nodeSize, x, y))
			return (MODULE_INSIDE_INNODE | n);
	}

	for (n=0; n<getNEventOutNodes(); n++) {
		getEventOutNodePosition(n, &nodex, &nodey);
		if (isRect(nodex, nodey, nodex+nodeSize+expandSize, nodey+nodeSize, x, y))
			return (MODULE_INSIDE_OUTNODE | n);
	}

	// Add expand size to x/y position
	for (n=0; n<getNEventInNodes(); n++) {
		getEventInNodePosition(n, &nodex, &nodey);
		if (isRect(nodex-expandSize, nodey-expandSize, nodex+nodeSize, nodey+nodeSize+expandSize, x, y))
			return (MODULE_INSIDE_INNODE | n);
	}

	for (n=0; n<getNEventOutNodes(); n++) {
		getEventOutNodePosition(n, &nodex, &nodey);
		if (isRect(nodex, nodey-expandSize, nodex+nodeSize+expandSize, nodey+nodeSize+expandSize, x, y))
			return (MODULE_INSIDE_OUTNODE | n);
	}

	if (hasExecutionNode()) {
		getExecutionNodePosition(&nodex, &nodey);
		if (isRect(nodex-expandSize, nodey-expandSize, nodex+nodeSize+expandSize, nodey+nodeSize, x, y))
			return MODULE_INSIDE_EXECUTIONNODE;
	}

	return MODULE_OUTSIDE;
}


////////////////////////////////////////////////
//	Route
////////////////////////////////////////////////

int	CModule::getNSystemEventInNodes()
{
	Node *node = getScriptNode();
	int	nSystemEventIn = 0;
	int	nEventIn = node->getNEventIn();
	for (int n=0; n<nEventIn; n++) {
		Field *field = node->getEventIn(n);
		if (strncmp(CTB_MODULE_SYSTEM_EVENTIN_STRING, field->getName(), strlen(CTB_MODULE_SYSTEM_EVENTIN_STRING)) == 0)
			nSystemEventIn++;
	}

	/**** Compatibility for Beta 1.0/1.1 ****/
	if (nSystemEventIn == 0)
		nSystemEventIn = 6;

	return nSystemEventIn;
}

////////////////////////////////////////////////
//	Route
////////////////////////////////////////////////

int CModule::getNInputRoutes()
{
	int nInputRoutes = 0;

	Node	*node = getScriptNode();
	Field	*field;
	int		n;

	for (n=0; n<node->getNEventIn(); n++) {
		field = node->getEventIn(n);
		for (Route *route=GetWorld()->getSceneGraph()->getRoutes(); route; route=route->next()) {
			if (node == route->getEventInNode() && field == route->getEventInField())
				nInputRoutes++;
		}
	}

	for (n=0; n<node->getNExposedFields(); n++) {
		field = node->getExposedField(n);
		for (Route *route=GetWorld()->getSceneGraph()->getRoutes(); route; route=route->next()) {
			if (node == route->getEventInNode() && field == route->getEventInField())
				nInputRoutes++;
		}
	}

	return nInputRoutes;
}

int	CModule::getNOutputRoutes()
{
	int nOutputRoutes = 0;

	Node	*node = getScriptNode();
	Field	*field;
	int		n;

	for (n=0; n<node->getNEventOut(); n++) {
		field = node->getEventOut(n);
		for (Route *route=GetWorld()->getSceneGraph()->getRoutes(); route; route=route->next()) {
			if (node == route->getEventOutNode() && field == route->getEventOutField())
				nOutputRoutes++;
		}
	}

	for (n=0; n<node->getNExposedFields(); n++) {
		field = node->getExposedField(n);
		for (Route *route=GetWorld()->getSceneGraph()->getRoutes(); route; route=route->next()) {
			if (node == route->getEventOutNode() && field == route->getEventOutField())
				nOutputRoutes++;
		}
	}

	return nOutputRoutes;
}

int	CModule::getNRoutes()
{
	int nRoutes = 0;

	Node	*node = getScriptNode();

	for (Route *route=GetWorld()->getSceneGraph()->getRoutes(); route; route=route->next()) {
		if (node == route->getEventOutNode() || node == route->getEventInNode())
			nRoutes++;
	}

	return nRoutes;
}

void CModule::setOutputRoute(Field *thisOutField, ScriptNode *targetNode, Field *targetField)
{
	GetWorld()->getSceneGraph()->deleteRoutes(targetNode, targetField);
	GetWorld()->getSceneGraph()->addRoute(getScriptNode(), thisOutField, targetNode, targetField);
}
