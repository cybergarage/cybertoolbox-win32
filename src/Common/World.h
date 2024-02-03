/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	World.h
*
******************************************************************/
#ifndef _WORLD_H_
#define _WORLD_H_

#include "LinkedList.h"
#include "SceneGraph.h"
#include "CModuleType.h"
#include "CDiagramWindow.h"
#include "CEventType.h"
#include "CEvent.h"
#include "StringFn.h"
#include "OpenGLFn.h"
#include "CJavaConsole.h"

#define CTB_NODE_NAME					"WORLD_"
#define CTB_ROOT_NODE_NAME				"WORLD_ROOT_NODE"
#define CTB_DIAGRAM_ROOT_NODE_NAME		"WORLD_DIAGRAM_ROOT_NODE"
#define CTB_GLOBALDATA_ROOT_NODE_NAME	"WORLD_GLOBAL_DATA_ROOT_NODE"

enum {
WORLD_NAVIGATIONMODE_WALK,
WORLD_NAVIGATIONMODE_PICKING,
};

/************************************************************
*
*	World
*
************************************************************/

class World {

	SceneGraph					*mSceneGraph;
	LinkedList<CModuleType>	*mModuleTypeList;	
	LinkedList<CDiagramWindow>	*mDiagramWindowList;	
	LinkedList<CEventType>		*mEventTypeList;	
	bool						mbSimulation;
	int							mRenderingMode;
#ifdef WIN32
	HANDLE						mJavaConsoleHandle;
	CJavaConsole				*mJavaConsole;
#endif

	char mProgramDirectory[_MAX_PATH];
	char mInitialDirectory[_MAX_PATH];

public:

	World();
	~World();

	//////////////////////////////////////////////////
	// SceneGraph
	//////////////////////////////////////////////////

	SceneGraph *getSceneGraph() {
		return mSceneGraph;
	}

	//////////////////////////////////////////////////
	// Event Types
	//////////////////////////////////////////////////

	bool	loadEventTypes(char *filename);
	
	CEventType *getEventTypes() {
		return mEventTypeList->getNodes();
	}

	CEventType *getEventType(char *name) {
		for (int n=0; n<getNEventTypes(); n++) {
			CEventType *eventType = getEventType(n);
			if (!StringCompareIgnoreCase(name, eventType->getName()))
				return eventType;
		}
		return NULL;
	}

	CEventType *getEventType(int eventType) {
		return mEventTypeList->getNode(eventType);
	}

	int	getEventTypeNumber(CEventType *eventType) {
		for (int n=0; n<getNEventTypes(); n++) {
			if (eventType == getEventType(n))
				return n;
		}
		return -1;
	}

	int getNEventTypes() {
		return mEventTypeList->getNNodes();
	}

	void addEventType(CEventType *event) {
		mEventTypeList->addNode(event);
	}

	//////////////////////////////////////////////////
	// Root
	//////////////////////////////////////////////////

	bool isRootNode(Node *node) {
		if (!StringCompare(node->getName(), CTB_ROOT_NODE_NAME))
			return true;
		else
			return false;
	}

	GroupNode *getRootNode() {
		SceneGraph *sceneGraph = getSceneGraph();

		for (GroupNode *group=sceneGraph->getGroupNodes(); group; group=group->next()) {
			if (isRootNode(group))
				return group;
		}

		GroupNode *rootNode = createRootNode();
		return rootNode;
	}

	GroupNode *createRootNode() {
		GroupNode *rootNode = new GroupNode();
		rootNode->setName(CTB_ROOT_NODE_NAME);
		getSceneGraph()->addNode(rootNode);
		return rootNode;
	}

	//////////////////////////////////////////////////
	// Event RootNode 
	//////////////////////////////////////////////////

	bool isEventRootNode(Node *node) {
		if (!StringCompare(node->getName(), CTB_EVENT_ROOT_NODE_NAME))
			return true;
		else
			return false;
	}

	GroupNode *getEventRootNode() {
		GroupNode *eventRootNode = NULL;
		for (GroupNode *group=getRootNode()->getGroupNodes(); group; group=group->next()) {
			if (isEventRootNode(group)) {
				eventRootNode = group;
				break;
			}
		}
		if (!eventRootNode)
			eventRootNode = createEventRootNode();

		return eventRootNode;
	}

	GroupNode *createEventRootNode() {
		GroupNode *eventRootNode = new GroupNode();
		eventRootNode->setName(CTB_EVENT_ROOT_NODE_NAME);
		getRootNode()->addChildNode(eventRootNode);
		return eventRootNode;
	}

	//////////////////////////////////////////////////
	// Event 
	//////////////////////////////////////////////////

	Node *getEventNodes();

	Node *getEventNode(char *typeName, char *optionName = NULL);

	Node *getEventNode(int nEvent);

	Node *getEventNode(CEvent *event);

	Node *getEventNode(CEventType *eventType);

	int getNEventNodes();

	bool addEventNode(Node *eventNode);

	bool isEventNode(Node *eventNode);

	void deleteEventNode(Node *eventNode);

	//////////////////////////////////////////////////
	// System events
	//////////////////////////////////////////////////

	void createSystemEvents();

	bool hasSystemEventsNodes();

	//////////////////////////////////////////////////
	// Sub System events
	//////////////////////////////////////////////////

	bool isSubEventRootNode(Node *node) {
		if (!StringCompare(node->getName(), CTB_SUBEVENT_ROOT_NODE_NAME))
			return true;
		else
			return false;
	}

	void addSubSystemEvent(Node *eventNode) {
		GroupNode *subSystemEvents = getSubSystemEventsNode();
		if (!subSystemEvents)
			subSystemEvents = createSubSystemEventsNode();
		subSystemEvents->addChildNode(eventNode);
	}

	GroupNode *createSubSystemEventsNode() {
		GroupNode *subSystemEventGroup = new GroupNode();
		subSystemEventGroup->setName(CTB_SUBEVENT_ROOT_NODE_NAME);
		getRootNode()->addChildNode(subSystemEventGroup);
		return subSystemEventGroup;
	}

	bool hasSubSystemEventsNode() {
		return (getSubSystemEventsNode() ? true : false);
	}

	GroupNode *getSubSystemEventsNode();

	int getNSubSystemEvents() {
		return getSubSystemEventsNode()->getNChildNodes();
	}

	//////////////////////////////////////////////////
	// Diagram Root
	//////////////////////////////////////////////////

	bool isDiagramRootNode(Node *node) {
		if (!StringCompare(node->getName(), CTB_DIAGRAM_ROOT_NODE_NAME))
			return true;
		else
			return false;
	}

	GroupNode *getDiagramRootNode() {
		for (GroupNode *group=getRootNode()->getGroupNodes(); group; group=group->next()) {
			if (isDiagramRootNode(group))
				return group;
		}

		GroupNode *dgmRootNode = createDiagramRootNode();
		return dgmRootNode;
	}

	GroupNode *createDiagramRootNode() {
		GroupNode *dgmRootNode = new GroupNode();
		dgmRootNode->setName(CTB_DIAGRAM_ROOT_NODE_NAME);
		getRootNode()->addChildNode(dgmRootNode);
		return dgmRootNode;
	}

	//////////////////////////////////////////////////
	// Diagram
	//////////////////////////////////////////////////

	TransformNode	*addDiagram(char *name, CEvent *event);
	TransformNode	*addDiagram(char *name, Node *eventNode);
	void			addDiagramNode(TransformNode *node);
	TransformNode	*getDiagramNodes();
	TransformNode	*getDiagramNode(char *name);
	TransformNode	*getDiagramNode(char *name, Node *eventNode);
	int				getNDiagramNodes();
	TransformNode	*nextDiagramNode(TransformNode *node);
	bool			isDiagram(Node *node);
	
	//////////////////////////////////////////////////
	// Global Data Root
	//////////////////////////////////////////////////

	bool isGlobalDataRootNode(Node *node) {
		if (!StringCompare(node->getName(), CTB_GLOBALDATA_ROOT_NODE_NAME))
			return true;
		else
			return false;
	}

	GroupNode *getGlobalDataRootNode() {
		for (GroupNode *group=getRootNode()->getGroupNodes(); group; group=group->next()) {
			if (!StringCompare(group->getName(), CTB_GLOBALDATA_ROOT_NODE_NAME))
				return group;
		}

		GroupNode *gdataRootNode = createGlobalDataRootNode();
		return gdataRootNode;
	}

	GroupNode *createGlobalDataRootNode() {
		GroupNode *gdataRootNode = new GroupNode();
		gdataRootNode->setName(CTB_GLOBALDATA_ROOT_NODE_NAME);
		getRootNode()->addChildNode(gdataRootNode);
		return gdataRootNode;
	}

	//////////////////////////////////////////////////
	// Global Data 
	//////////////////////////////////////////////////

	AnchorNode	*addGlobalData(char *name);
	void		addGlobalData(AnchorNode *node);
	AnchorNode	*getGlobalDataNodes();
	AnchorNode	*getGlobalDataNode(char *name);
	int			getNGlobalDataNodes();
	bool		isGlobalData(AnchorNode *snode);

	//////////////////////////////////////////////////
	// SceneGraph
	//////////////////////////////////////////////////

	void	clearSceneGraph();
	void	addFullPathSceneGraphUrlFileNames();
	bool	loadSceneGraph(char *filename, bool bInitialize = true, void (*callbackFn)(int nLine, void *info) = NULL, void *callbackFnInfo = NULL);
	bool	addSceneGraph(char *filename, bool bInitialize = true, void (*callbackFn)(int nLine, void *info) = NULL, void *callbackFnInfo = NULL);
	void	addRootNode(Node *node);
	void	copySceneGraphUrlFiles(char *destDirectory);
	bool	saveSceneGraph(char *filename, void (*callbackFn)(int nNode, void *info) = NULL, void *callbackFnInfo = NULL);

	//////////////////////////////////////////////////
	// ModuleType
	//////////////////////////////////////////////////

	int loadModuleTypes();

	CModuleType *getModuleTypes() {
		return mModuleTypeList->getNodes();
	}

	CModuleType *getModuleTypes(char *className);

	CModuleType *getModuleType(int n);

	CModuleType *getModuleType(char *className, int n);

	CModuleType *getModuleType(char *className, char *moduleName);

	int getNModuleTypes();

	int getNModuleTypes(char *className);

	void addModuleType(CModuleType *cmType) {
		mModuleTypeList->addNode(cmType);
	}

	//////////////////////////////////////////////////
	// Window
	//////////////////////////////////////////////////

	void			addDiagramWindow(CDiagramWindow *dgmWindow);
	void			addDiagramWindow(CWnd *wnd);
	void			deleteDiagramWindows();
	void			deleteDiagramWindow(CWnd *wnd);
	CDiagramWindow	*getDiagramWindows();
	bool			isDiagramWindow(CWnd *wnd);

	//////////////////////////////////////////////////
	// Check
	//////////////////////////////////////////////////

	bool isSystemNode(Node *node) {
		if (!node)
			return false;
		return !StringNCompare(node->getName(), CTB_NODE_NAME, StringLength(CTB_NODE_NAME));
	}

	bool isSystemRoute(Route *route) {
		if (!route)
			return false;
		if (StringNCompare(route->getEventOutNode()->getName(), CTB_NODE_NAME, StringLength(CTB_NODE_NAME)) == 0)
			return true;
		if (StringNCompare(route->getEventInNode()->getName(), CTB_NODE_NAME, StringLength(CTB_NODE_NAME)) == 0)
			return true;
		return false;
	}

	//////////////////////////////////////////////////
	// User Node
	//////////////////////////////////////////////////

	bool hasUserNode() {
		for (Node *node = getSceneGraph()->getNodes(); node; node=node->next()) {
			if (StringNCompare(node->getName(), CTB_NODE_NAME, StringLength(CTB_NODE_NAME)))
				return true;
		}
		return false;
	}

	//////////////////////////////////////////////////
	// Simulation
	//////////////////////////////////////////////////

	void			initialize();
	void			initializeSimulation();
	void			setSimulationActive(bool bActive)	{mbSimulation = bActive;}
	bool			isSimulationActive()				{return mbSimulation;}

	//////////////////////////////////////////////////
	// Node Opetation
	//////////////////////////////////////////////////

	void			removeNode(Node *node);
	void			deleteNode(Node *node);

	//////////////////////////////////////////////////
	// Rendering Mode
	//////////////////////////////////////////////////

	void			setRenderingMode(int mode)	{ mRenderingMode = mode;}
	int				getRenderingMode()			{ return mRenderingMode;}

	//////////////////////////////////////////////////
	// Java Console
	//////////////////////////////////////////////////

#ifdef WIN32
	void			createJavaConsole();
	void			deleteJavaConsole();
	void			setJavaConsoleHandle(HANDLE handle)	{mJavaConsoleHandle = handle;}
	HANDLE			getJavaConsoleHandle()				{return mJavaConsoleHandle;}	
#endif

	//////////////////////////////////////////////////
	// Initial Directory
	//////////////////////////////////////////////////

	void setProgramDirectory(char *dir) {
		strcpy(mProgramDirectory, dir);
	}

	void setInitialDirectory(char *dir) {
		strcpy(mInitialDirectory, dir);
	}

	char *getProgramDirectory() {
		return mProgramDirectory;
	}
	
	char *getInitialDirectory() {
		return mInitialDirectory;
	}

	//////////////////////////////////////////////////
	// Visual Object
	//////////////////////////////////////////////////

	TransformNode		*mViewpointObjectNode;
	TransformNode		*mDirectionalLightObjectNode;
	TransformNode		*mSpotLightObjectNode;
	TransformNode		*mPointLightObjectNode;

	void loadSceneGraphVisualObjects();
	void deleteSceneGraphVisualObjects();

	void setViewpointObjectNode(TransformNode *node) {
		mViewpointObjectNode = node;
	}

	TransformNode *getViewpointObjectNode() {
		return mViewpointObjectNode;
	}

	void setDirectionalLightObjectNode(TransformNode *node) {
		mDirectionalLightObjectNode = node;
	}

	TransformNode *getDirectionalLightObjectNode() {
		return mDirectionalLightObjectNode;
	}

	void setSpotLightObjectNode(TransformNode *node) {
		mSpotLightObjectNode = node;
	}

	TransformNode *getSpotLightObjectNode() {
		return mSpotLightObjectNode;
	}

	void setPointLightObjectNode(TransformNode *node) {
		mPointLightObjectNode = node;
	}

	TransformNode *getPointLightObjectNode() {
		return mPointLightObjectNode;
	}
};

/************************************************************
*
*	Global Functions
*
************************************************************/

//////////////////////////////////////////////////
// World
//////////////////////////////////////////////////

void WorldInit();
void WorldQuit();
World *GetWorld(void);

//////////////////////////////////////////////////
// Evnet
//////////////////////////////////////////////////

char *GetEventTypeString(int eventType);

int GetEventTypeFromString(char *eventTypeString);

//////////////////////////////////////////////////
// Java Console
//////////////////////////////////////////////////

jint JNICALL WorldJavaPrint(FILE *fp, const char *format, va_list args);

#endif 
