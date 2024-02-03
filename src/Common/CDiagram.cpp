/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CDiagram.cpp
*
******************************************************************/

#include "CDiagram.h"
#include "World.h"
#include "StringFn.h"

//////////////////////////////////////////////////
// CDiagram::CDiagram
//////////////////////////////////////////////////

CDiagram::CDiagram(char *name, CEvent *event) {
	TransformNode *transform = new TransformNode();
	setTransformNode(transform);
	setTransformNodeName(name, event);
//	addBasisModule();
	setPosition(0, 0);
	setWidth(0);
	setHeight(0);
	updateExtents();
}

CDiagram::CDiagram(TransformNode *transform) {
	setTransformNode(transform);
	updateExtents();
}

//////////////////////////////////////////////////
// CDiagram::setTransformNodeName
//////////////////////////////////////////////////

void CDiagram::setTransformNodeName(char *name, CEvent *event)
{
	StringReplaceChar(name, '_', '-');
	StringReplaceChar(name, ' ', '-');
	char	transformName[DIAGRAM_NAME_MAXLEN];
	sprintf(transformName, "%s_%s_%s", CTB_DIAGRAM_NODENAME, event->getName(), name);
	(getTransformNode())->setName(transformName);
}

//////////////////////////////////////////////////
// CDiagram::setName
//////////////////////////////////////////////////

void CDiagram::setName(char *name) 
{
	CEvent	event(getEventNode());
	setTransformNodeName(name, &event);

	char	moduleName[MODULE_NAME_MAXLEN];
	int		nScriptNode = 0;
	for (ScriptNode *script = getTransformNode()->getScriptNodes(); script; script = script->next()) {
		sprintf(moduleName, "%s_MODULE%d", getTransformNode()->getName(), nScriptNode++);
		script->setName(moduleName);
	}
}

//////////////////////////////////////////////////
// CDiagram::getName
//////////////////////////////////////////////////

char *CDiagram::getName()
{
	char *transformName = getTransformNodeName();
	int index = StringLastIndexOf(transformName, '_');
	assert(index != -1);
	return (transformName + (index+1));
}

//////////////////////////////////////////////////
// CDiagram::isModule
//////////////////////////////////////////////////

bool CDiagram::isModule(ScriptNode *script)
{
	TransformNode	*transform = getTransformNode();
	if (!StringNCompare(transform->getName(), script->getName(), StringLength(transform->getName())))
		return true;
	else
		return false;
}

//////////////////////////////////////////////////
// CDiagram::hasModule
//////////////////////////////////////////////////

bool CDiagram::hasModule(Node *node)
{
	if (!node->isScriptNode())
		return false;

	for (ScriptNode *script = getTransformNode()->getScriptNodes(); script; script = script->next()) {
		if (script == (ScriptNode *)node)
			return true;
	}

	return false;
}

//////////////////////////////////////////////////
// CDiagram::addModule
//////////////////////////////////////////////////

void CDiagram::setModuleDefaultRoute(CModule *module)
{
	if (module->hasEventInNode() == false) {
		CEvent		event(getEventNode());
		CEventType	*eventType		= event.getEventType();
		Node		*eventOutNode	= event.getSourceNode();
		Field		*eventOutField	= event.getSourceFiled();
		ScriptNode		*moduleScript	= module->getScriptNode();
		assert(eventOutNode);
		assert(eventOutField);
		Field		*eventInField	= moduleScript->getEventIn(eventType->getModuleFieldName());
		assert(eventInField);
		GetWorld()->getSceneGraph()->addRoute(eventOutNode, eventOutField, moduleScript, eventInField);
	}
}

void CDiagram::addModule(CModule *module)
{
	char	moduleName[MODULE_NAME_MAXLEN];

	TransformNode	*transform = getTransformNode();
	ScriptNode		*moduleScript = module->getScriptNode();

	// Set the module's name
	int moduleNumber = 0;
	for (ScriptNode *script = transform->getScriptNodes(); script; script = script->next()) {
		if (isModule(script)) {
			CModule	module(script);
			int nodeNumber = module.getNumber();
			if (moduleNumber < nodeNumber)
				moduleNumber = nodeNumber;
		}
	}
	sprintf(moduleName, "%s_MODULE%d", transform->getName(), moduleNumber+1);
	moduleScript->setName(moduleName);

	// Add the module into the diagram's list
	transform->addChildNode(moduleScript);

	// Add Default Route
	setModuleDefaultRoute(module);

	// Update Extents
	updateExtents();
}

//////////////////////////////////////////////////
// CDiagram::removeModule
//////////////////////////////////////////////////

void CDiagram::removeModule(CModule *module)
{
	ScriptNode *moduleScript = module->getScriptNode();
	GetWorld()->removeNode(moduleScript);
}

//////////////////////////////////////////////////
// CDiagram::deleteModule
//////////////////////////////////////////////////

void CDiagram::deleteModule(CModule *module)
{
	ScriptNode *moduleScript = module->getScriptNode();
	GetWorld()->deleteNode(moduleScript);
}

//////////////////////////////////////////////////
// CDiagram::getNModules
//////////////////////////////////////////////////

int CDiagram::getNModules()
{
	int nScriptNode = 0;
	TransformNode *transform = getTransformNode();

	for (ScriptNode *script = transform->getScriptNodes(); script; script = script->next()) {
		if (isModule(script))
			nScriptNode++;
	}

	return nScriptNode;
}

int CDiagram::getNModules(int rect[])
{
	int nScriptNode = 0;
	TransformNode *transform = getTransformNode();

	for (ScriptNode *script = transform->getScriptNodes(); script; script = script->next()) {
		if (isModule(script)) {
			CModule		module(script);
			int mx = module.getPositionX();
			int my = module.getPositionY();
			int msize = module.getSize();
			if (isRect(rect, mx, my) == true && isRect(rect, mx+msize, my+msize) == true) 
				nScriptNode++;
		}
	}

	return nScriptNode;
}

//////////////////////////////////////////////////
// CDiagram::getModules
//////////////////////////////////////////////////

ScriptNode *CDiagram::getModules()
{
	return getTransformNode()->getScriptNodes();
}

//////////////////////////////////////////////////
// CDiagram::getModule
//////////////////////////////////////////////////

ScriptNode *CDiagram::getModule(int n)
{
	int nScriptNode = 0;
	TransformNode *transform = getTransformNode();

	for (ScriptNode *script = transform->getScriptNodes(); script; script = script->next()) {
		if (isModule(script)) {
			if (nScriptNode == n)
				return script;
			nScriptNode++;
		}
	}

	return NULL;
}

ScriptNode *CDiagram::getModule(int x, int y, int *part)		
{ 
	for (ScriptNode *script = getTransformNode()->getScriptNodes(); script; script = script->next()) {
		if (isModule(script)) {
			CModule	module(script);
			int selectingPart = module.isInside(x, y);
			if (selectingPart) {
				*part  = selectingPart;
				return script;
			}
		}
	}
	*part = DIAGRAM_MODE_NONE;
	return NULL;
}

//////////////////////////////////////////////////
// CDiagram::addBasisModule
//////////////////////////////////////////////////

void CDiagram::addBasisModule()
{
	CEvent		event(getEventNode());
	CEventType	*eventType = event.getEventType();
	CModuleType	*moduleType = GetWorld()->getModuleType(CTB_EVENT_CLASSNAME_SYSTEM_STRING, eventType->getName());

	if (!moduleType)
		return;
	
	CModule module(moduleType);
	module.setPosition(0, 0);
	addModule(&module);
}

//////////////////////////////////////////////////
// CDiagram::getEventNode
//////////////////////////////////////////////////

Node *CDiagram::getEventNode()
{
	char	*nodeName = getTransformNodeName();

	char eventTypeName		[CTB_EVENTNAME_MAXLEN];
	char eventOptionName	[CTB_EVENTNAME_MAXLEN];

	/* Event type name string */
	int	index1 = StringIndexOf(nodeName, '_', strlen(CTB_DIAGRAM_NODENAME) + 1/*'_'*/);
	int	index2 = StringIndexOf(nodeName, '_', index1 + 1);
	assert(0<= index1 && 0<=index2);
	StringNCopy(eventTypeName, nodeName + index1 +1, (index2-1) - index1);

	/* Event option string */
	int	index3 = StringIndexOf(nodeName, '_', index2 + 1);
	assert(0<= index1 && 0<=index2);
	StringNCopy(eventOptionName, nodeName + index2 +1, (index3-1) - index2);

	Node *eventNode = GetWorld()->getEventNode(eventTypeName, eventOptionName);
	assert(eventNode);
	return eventNode;
}

//////////////////////////////////////////////////
// Extents
//////////////////////////////////////////////////

void CDiagram::updateExtents()
{
	int extents[2][2];

	if (getNModules() == 0) {
		extents[EXTENTS_MIN][X] = 0;
		extents[EXTENTS_MIN][Y] = 0;
		extents[EXTENTS_MAX][X] = 0;
		extents[EXTENTS_MAX][Y] = 0;
	}
	else {
		CModule module(getModule(0));
		int	x, y;
		module.getPosition(&x, &y);
		extents[EXTENTS_MIN][X] = x;
		extents[EXTENTS_MIN][Y] = y;
		extents[EXTENTS_MAX][X] = x;
		extents[EXTENTS_MAX][Y] = y;
		for (int n=1; n<getNModules(); n++) {
			CModule module(getModule(n));
			module.getPosition(&x, &y);
			if (extents[EXTENTS_MIN][X] > x)
				extents[EXTENTS_MIN][X] = x;
			if (extents[EXTENTS_MIN][Y] > y)
				extents[EXTENTS_MIN][Y] = y;
			if (extents[EXTENTS_MAX][X] < x)
				extents[EXTENTS_MAX][X] = x;
			if (extents[EXTENTS_MAX][Y] < y)
				extents[EXTENTS_MAX][Y] = y;
		}
	}

	extents[EXTENTS_MAX][X] += MODULE_SIZE;
	extents[EXTENTS_MAX][Y] += MODULE_SIZE;

	setExtents(extents);
}
