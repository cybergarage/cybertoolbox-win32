/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CEvent.cpp
*
******************************************************************/
#include "CEvent.h"
#include "StringFn.h"
#include "World.h"
#include "CDiagram.h"

////////////////////////////////////////////////////////////
//	CEvent::CEvent
////////////////////////////////////////////////////////////

CEvent::CEvent(CEventType *eventType, char *optionString)
{
	setNode(NULL); 
	
	// Create event node
	Node	*eventNode = NULL;

	//////////////////////////////////// //
	//	Create Main Event Node
	//////////////////////////////////////

	switch (GetWorld()->getEventTypeNumber(eventType)) {
	case CTB_EVENTTYPE_START: // START (SYSTEM EVENT)
		{
			eventNode = new TimeSensorNode();
			((TimeSensorNode *)eventNode)->setStopTime(-1.0);
			((TimeSensorNode *)eventNode)->setLoop(TRUE);
			((TimeSensorNode *)eventNode)->setCycleInterval(.1);
		}
		break;
	case CTB_EVENTTYPE_FRAME: // FRAME (SYSTEM EVENT)
		{
			eventNode = new TimeSensorNode();
			((TimeSensorNode *)eventNode)->setStopTime(-1.0);
			((TimeSensorNode *)eventNode)->setLoop(TRUE);
			((TimeSensorNode *)eventNode)->setCycleInterval(.1);
		}
		break;
	case CTB_EVENTTYPE_CLOCK:
		{
			eventNode = new TimeSensorNode();
			((TimeSensorNode *)eventNode)->setStopTime(-1.0);
			((TimeSensorNode *)eventNode)->setLoop(TRUE);
		}
		break;
	case CTB_EVENTTYPE_PICKUP:
		{
			eventNode = new GroupNode();
		}
		break;
	case CTB_EVENTTYPE_AREA:
		{
			eventNode = new ProximitySensorNode();
		}
		break;
	case CTB_EVENTTYPE_DRAG:
		{
			eventNode = new GroupNode();
		}
		break;
	case CTB_EVENTTYPE_TIMER:
		{
			eventNode = new TimeSensorNode();
			((TimeSensorNode *)eventNode)->setStopTime(-1.0);
			((TimeSensorNode *)eventNode)->setLoop(FALSE);
		}
		break;
	}

	assert(eventNode);
	setNode(eventNode);
	setName(eventNode, eventType, optionString);

	//////////////////////////////////////
	//	Create Sub Event Node
	//////////////////////////////////////
	
	switch (GetWorld()->getEventTypeNumber(eventType)) {
	case CTB_EVENTTYPE_START: // START (SYSTEM EVENT)
		{
			// Create sub event node
			ScriptNode *eventStartNode = new ScriptNode();
			eventStartNode->setDirectOutput(true);
			eventStartNode->setMustEvaluate(true);
			eventStartNode->addUrl(CTB_EVENTTYPE_START_SCRIPT_NAME);
			eventStartNode->addEventIn(CTB_EVENTTYPE_START_SCRIPT_EVENTIN_NAME, new SFTime());
			eventStartNode->addEventOut(CTB_EVENTTYPE_START_SCRIPT_EVENTOUT_NAME, new SFBool());
			char *nodeName = getSourceNodeName();
			eventStartNode->setName(nodeName);
			GetWorld()->addSubSystemEvent(eventStartNode);

			// Connect the event route
			Node	*sourceNode,	*eventInNode;
			Field	*sourceField,	*eventInField;
			
			sourceNode		= eventNode;
			sourceField		= eventNode->getEventOut("time");
			eventInNode		= eventStartNode;
			eventInField	= eventStartNode->getEventIn(CTB_EVENTTYPE_START_SCRIPT_EVENTIN_NAME);
			GetWorld()->getSceneGraph()->addRoute(sourceNode, sourceField, eventInNode, eventInField);
			
			sourceNode		= eventStartNode;
			sourceField		= eventStartNode->getEventOut(CTB_EVENTTYPE_START_SCRIPT_EVENTOUT_NAME);
			eventInNode		= eventNode;
			eventInField	= eventNode->getExposedField("enabled");
			GetWorld()->getSceneGraph()->addRoute(sourceNode, sourceField, eventInNode, eventInField);
		}
		break;
	}

}

////////////////////////////////////////////////////////////
//	CEvent::isEventNode
////////////////////////////////////////////////////////////

BOOL CEvent::isEventNode()
{
	if (!StringNCompare(getNode()->getName(), CTB_EVENT_NODE_NAME, strlen(CTB_EVENT_NODE_NAME)))
		return TRUE;
	else
		return FALSE;
}

////////////////////////////////////////////////////////////
//	CEvent::getEventTypeName
////////////////////////////////////////////////////////////

char *CEvent::getEventTypeName()
{
	char *eventName = getName();

	if (eventName == NULL)
		return NULL;

	int	index1 = StringIndexOf(eventName, '_');
	int	index2 = StringIndexOf(eventName, '_', index1 + 1);

	assert(0<= index1 && index1 < index2);

	char	eventTypeName[CTB_EVENTNAME_MAXLEN];
	int		length = (index2-1) - index1;
	StringNCopy(eventTypeName, eventName + index1 +1, length);
	mEventTypeName.setValue(eventTypeName);

	return mEventTypeName.getValue();
}

////////////////////////////////////////////////////////////
//	CEvent::getEventType
////////////////////////////////////////////////////////////

CEventType *CEvent::getEventType()
{
	char *eventName = getEventTypeName();
	
	if (eventName == NULL)
		return NULL;

	CEventType *eventType = GetWorld()->getEventType(eventName);
	assert(eventType);
	return eventType;
}	

////////////////////////////////////////////////////////////
//	CEvent::getEventOptionName
////////////////////////////////////////////////////////////

char *CEvent::getEventOptionName()
{
	char *eventName = getName();
	
	if (eventName == NULL)
		return NULL;

	int	index1 = StringIndexOf(eventName, '_');
	int	index2 = StringIndexOf(eventName, '_', index1 + 1);
	int	index3 = StringIndexOf(eventName, '_', index2 + 1);

	assert(0<=index2 && index2<=index3);

	char	eventOptionName[CTB_EVENTNAME_MAXLEN];
	int		length = (index3-1) - index2;
	StringNCopy(eventOptionName, eventName + index2 +1, length);

	if (!StringCompare(eventOptionName, CTB_EVENT_NONE_OPTION_NAME))
		mEventOptionName.setValue(NULL);
	else
		mEventOptionName.setValue(eventOptionName);

	return mEventOptionName.getValue();
}

////////////////////////////////////////////////////////////
//	CEvent::getSourceNodeTypeName
////////////////////////////////////////////////////////////

char *CEvent::getSourceNodeTypeName()
{
	char *eventName = getName();

	if (eventName == NULL)
		return NULL;

	int	index = StringLastIndexOf(eventName, '_');

	assert(0<= index);

	char eventNodeTypeName[CTB_EVENTNAME_MAXLEN];
	strcpy(eventNodeTypeName, eventName + index +1);
	mEventNodeTypeName.setValue(eventNodeTypeName);

	return mEventNodeTypeName.getValue();
}

////////////////////////////////////////////////////////////
//	CEvent::getSourceNodeName
////////////////////////////////////////////////////////////

char *CEvent::getSourceNodeName()
{
	Node *node = getNode();
	if (node == NULL)
		return NULL;

	char	sourceNodeName[CTB_EVENTNAME_MAXLEN];
	sprintf(sourceNodeName, "%s_%s", node->getName(), CTB_EVENT_SOURCE_NODE_NAME);
	mSourceNodeName.setValue(sourceNodeName);	

	return mSourceNodeName.getValue();
}

////////////////////////////////////////////////////////////
//	CEvent::getEventNode
////////////////////////////////////////////////////////////

Node *CEvent::getSourceNode()
{
	char *eventNodeTypeName = getSourceNodeTypeName();

	if (!StringCompare(CTB_EVENT_DEFAULT_NODE_TYPE, eventNodeTypeName))
		return getNode();

	char *nodeName = getSourceNodeName();

	if (nodeName == NULL)
		return NULL;

	Node *sourceNode = NULL;
	for (Node *node = GetWorld()->getSceneGraph()->getNodes(); node; node=node->nextTraversal()) {
		if (!StringCompare(node->getType(), eventNodeTypeName)) {
			if (!StringCompare(nodeName, node->getName())) {
				sourceNode = node;
				break;
			}
		}
	}

	return sourceNode;
}

////////////////////////////////////////////////////////////
//	CEvent::getSourceFiled
////////////////////////////////////////////////////////////

Field *CEvent::getSourceFiled()
{
	Node		*eventNode = getSourceNode();
	CEventType	*eventType = getEventType();

	Field *field = eventNode->getEventOut(eventType->getFieldName());
	assert(field);

	return field;
}

////////////////////////////////////////////////////////////
//	CEvent::setName
////////////////////////////////////////////////////////////

void CEvent::setName(Node *node, CEventType *eventType, char *optionString)
{
	assert(eventType != NULL);
	if (eventType == NULL)
		return;

	/**** GET CURRENT DIAGRAM NODES ****/

	Node			*eventNode = getNode();
	TransformNode	**diagramNodes = NULL;
	int				nDiagramNodes = 0;
	for (TransformNode *transform=GetWorld()->getDiagramNodes(); transform; transform=GetWorld()->nextDiagramNode(transform)) {
		CDiagram diagram(transform);
		if (eventNode == diagram.getEventNode()) {
			diagramNodes = (TransformNode **)realloc(diagramNodes, sizeof(TransformNode *)*(nDiagramNodes+1));
			diagramNodes[nDiagramNodes] = transform;
			nDiagramNodes++;
		}
	}

	/**** SET OPTION PARAMETER ****/

	switch (GetWorld()->getEventTypeNumber(eventType)) {
	case CTB_EVENTTYPE_CLOCK:
		{
			TimeSensorNode *timeSensor = (TimeSensorNode *)getNode();
			timeSensor->setCycleInterval(atof(optionString));
			timeSensor->setLoop(TRUE);
		}
		break;
	case CTB_EVENTTYPE_AREA:
		{
			float center[3];
			float size[3];
			int ret = sscanf(optionString, "%f:%f:%f:%f:%f:%f", &center[0], &center[1], &center[2], &size[0], &size[1], &size[2]);
			assert(ret == 6);
			if (ret == 6) {
				ProximitySensorNode *eventNode = (ProximitySensorNode *)getNode();
				eventNode->setCenter(center);
				eventNode->setSize(size);
			}
		}
		break;
	}

	/**** DELETE CURRENT SUB EVENT NODE ****/
	Node *sourceNode = getSourceNode();
	if (sourceNode != getNode()) 
		delete sourceNode;

	/**** DELETE CURRENT SUB EVENT NODE (FOR TIMER EVENT)****/
	char *sourceNodeName = getSourceNodeName();
	Node *subEventNode = GetWorld()->getSceneGraph()->findNode(sourceNodeName);
	if (subEventNode != NULL)
		delete subEventNode;

	/**** TARGET EVENT NODE TYPE ****/

	char	*eventNodeTypeName = CTB_EVENT_DEFAULT_NODE_TYPE;

	switch (GetWorld()->getEventTypeNumber(eventType)) {
	case CTB_EVENTTYPE_PICKUP:
		eventNodeTypeName = "TouchSensor";
		break;
	case CTB_EVENTTYPE_DRAG:
		eventNodeTypeName = "PlaneSensor";
		break;
	}


	/**** SET NODE NAME ****/

	char	nodeName[CTB_EVENTNAME_MAXLEN];
	sprintf(nodeName, "%s_%s_%s_%s_%s", CTB_EVENT_NODE_NAME, eventType->getAttributeTypeString(), eventType->getName(), optionString, eventNodeTypeName);
	node->setName(nodeName);


	/**** CREATE NEW SUB EVENT NODE ****/

	switch (GetWorld()->getEventTypeNumber(eventType)) {
	case CTB_EVENTTYPE_PICKUP:
		{
			char *sourceNodeName = getSourceNodeName();

			TouchSensorNode *touchSensor = new TouchSensorNode();
			touchSensor->setName(sourceNodeName);
			Node *parentNode = GetWorld()->getSceneGraph()->findNode(optionString);
			assert(parentNode);
			if (parentNode)
				parentNode->addChildNode(touchSensor);
		}
		break;

	case CTB_EVENTTYPE_DRAG:
		{
			char *sourceNodeName = getSourceNodeName();

			PlaneSensorNode *planeSensor = new PlaneSensorNode();
			planeSensor->setName(sourceNodeName);
			planeSensor->setMinPosition(-1.0, -1.0);
			planeSensor->setMaxPosition(1.0, 1.0);
			Node *parentNode = GetWorld()->getSceneGraph()->findNode(optionString);
			assert(parentNode);
			if (parentNode)
				parentNode->addChildNode(planeSensor);
		}
		break;
	case CTB_EVENTTYPE_TIMER: // TIMER (USER EVENT)
		{
			// Create sub event node
			ScriptNode *eventSetTimerNode = new ScriptNode();
			eventSetTimerNode->setDirectOutput(true);
			eventSetTimerNode->setMustEvaluate(true);
			eventSetTimerNode->addUrl(CTB_EVENTTYPE_TIMER_SCRIPT_NAME);
			eventSetTimerNode->addField(CTB_EVENTTYPE_TIMER_SCRIPT_VALUE_NAME, new SFTime(atof(optionString)));
			eventSetTimerNode->addEventIn(CTB_EVENTTYPE_TIMER_SCRIPT_EVENTIN_NAME, new SFTime());
			eventSetTimerNode->addEventOut(CTB_EVENTTYPE_TIMER_SCRIPT_STARTTIME_NAME, new SFTime());
			eventSetTimerNode->addEventOut(CTB_EVENTTYPE_TIMER_SCRIPT_STOPTIME_NAME, new SFTime());
			
			char *nodeName = getSourceNodeName();
			eventSetTimerNode->setName(nodeName);
			GetWorld()->addSubSystemEvent(eventSetTimerNode);

			// Connect the event route
			Node	*sourceNode,	*eventInNode;
			Field	*sourceField,	*eventInField;

			sourceNode		= GetWorld()->getEventNode(GetWorld()->getEventType(CTB_EVENTTYPE_START));
			sourceField		= sourceNode->getEventOut("time");
			eventInNode		= eventSetTimerNode;
			eventInField	= eventSetTimerNode->getEventIn(CTB_EVENTTYPE_TIMER_SCRIPT_EVENTIN_NAME);
			GetWorld()->getSceneGraph()->addRoute(sourceNode, sourceField, eventInNode, eventInField);
		
			sourceNode		= eventSetTimerNode;
			sourceField		= eventSetTimerNode->getEventOut(CTB_EVENTTYPE_TIMER_SCRIPT_STARTTIME_NAME);
			eventInNode		= eventNode;
			eventInField	= eventNode->getExposedField("startTime");
			GetWorld()->getSceneGraph()->addRoute(sourceNode, sourceField, eventInNode, eventInField);
			
			sourceNode		= eventSetTimerNode;
			sourceField		= eventSetTimerNode->getEventOut(CTB_EVENTTYPE_TIMER_SCRIPT_STOPTIME_NAME);
			eventInNode		= eventNode;
			eventInField	= eventNode->getExposedField("stopTime");
			GetWorld()->getSceneGraph()->addRoute(sourceNode, sourceField, eventInNode, eventInField);
		}
		break;
	}

	int n, i;

	/**** RESET DIAGRAM NODE NAME ****/

	for (n=0; n<nDiagramNodes; n++) {
		CDiagram diagram(diagramNodes[n]);
		char *name = diagram.getName();
		diagram.setTransformNodeName(name, this);
		name = diagram.getName();
		diagram.setName(name);
	}

	/**** RESET DIAGRAM MODULES****/

	for (n=0; n<nDiagramNodes; n++) {
		CDiagram diagram(diagramNodes[n]);
		int nModules = diagram.getNModules();
		for (i=0; i<nModules; i++) {
			CModule module(diagram.getModule(i));
			diagram.setModuleDefaultRoute(&module);
		}
	}

	/**** DELETE DIAGRAM NODES ****/

	if (diagramNodes)
		free(diagramNodes);
}

////////////////////////////////////////////////////////////
//	CEvent::setName
////////////////////////////////////////////////////////////

char *CEvent::getName() 
{
	char *nodeName = getNode()->getName();
	if (nodeName == NULL)
		return NULL;

	if ((strlen(CTB_EVENT_NODE_NAME) + 1 ) < strlen(nodeName))
		return (nodeName + strlen(CTB_EVENT_NODE_NAME) + 1 /* '_'*/);
	else
		return NULL;
}

////////////////////////////////////////////////////////////
//	CEvent::setOptionString
////////////////////////////////////////////////////////////

void CEvent::setOptionString(char *optionString)
{
	setName(getNode(), getEventType(), optionString);
}

