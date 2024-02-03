/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	World.cpp
*
******************************************************************/

#include <direct.h>
#include <stdlib.h>
#include "World.h"
#include "StringFn.h"
#include "File.h"
#include "RegKey.h"
#include "CDiagram.h"
#include "CGlobalData.h"
#include "ModuleFilename.h"

/************************************************************
*
*	World
*
************************************************************/

//////////////////////////////////////////////////
// World::World
//////////////////////////////////////////////////

static char *GetJavaClassPath(const char *initDir) 
{
	static char classPath[FILE_MAX_FILENAME];

	char	*sysClassPath = getenv("CLASSPATH");

	char	ctbJavaLibPath			[FILE_MAX_PATHLEN];
	char	ctbScriptNodesPath		[FILE_MAX_PATHLEN];

	if (RegKeyGetValue(REGKEY_SECTION_PATHNAME, REGKEY_KEY_LIB_PATHNAME, ctbJavaLibPath) == FALSE)
		strcpy(ctbJavaLibPath, "lib\\");

	if (RegKeyGetValue(REGKEY_SECTION_PATHNAME, REGKEY_KEY_SCRIPTS_PATHNAME, ctbScriptNodesPath) == FALSE)
		strcpy(ctbScriptNodesPath, "scripts\\");

	sprintf(classPath, "%s\\%srt.jar;%s\\%svrml.jar;%s\\%sctb.jar;%s\\%s",
		initDir,
		ctbJavaLibPath,
		initDir,
		ctbJavaLibPath,
		initDir,
		ctbJavaLibPath,
		initDir,
		ctbScriptNodesPath);

	int len = strlen(classPath);

	return classPath;
}

void World::loadSceneGraphVisualObjects()
{
	SceneGraph	sg;
	TransformNode	*node;
	char		sysDirModels	[FILE_MAX_PATHLEN];
	char		objectFilename	[FILE_MAX_FILENAME];

	if (RegKeyGetValue(REGKEY_SECTION_PATHNAME, REGKEY_KEY_MODELS_PATHNAME,	sysDirModels) == FALSE)
		strcpy(sysDirModels, "models\\");
	
	sprintf(objectFilename, "%s\\%s%s", GetWorld()->getInitialDirectory(), sysDirModels, "ViewpointObject.wrl");
	sg.load(objectFilename);
	node = sg.getTransformNodes();
	if (node)
		node->remove();
	setViewpointObjectNode(node);

	sg.clear();
	sprintf(objectFilename, "%s\\%s%s", GetWorld()->getInitialDirectory(), sysDirModels, "DirectionalLightObject.wrl");
	sg.load(objectFilename);
	node = sg.getTransformNodes();
	if (node)
		node->remove();
	setDirectionalLightObjectNode(node);

	sg.clear();
	sprintf(objectFilename, "%s\\%s%s", GetWorld()->getInitialDirectory(), sysDirModels, "SpotLightObject.wrl");
	sg.load(objectFilename);
	node = sg.getTransformNodes();
	if (node)
		node->remove();
	setSpotLightObjectNode(node);

	sg.clear();
	sprintf(objectFilename, "%s\\%s%s", GetWorld()->getInitialDirectory(), sysDirModels, "PointLightObject.wrl");
	sg.load(objectFilename);
	node = sg.getTransformNodes();
	if (node) 
		node->remove();
	setPointLightObjectNode(node);
}

World::World() 
{
	GetCurrentDirectory(sizeof(mInitialDirectory)-1, mInitialDirectory);

	mSceneGraph = new SceneGraph();
	
	mSceneGraph->setJavaEnv(GetJavaClassPath(getInitialDirectory()), WorldJavaPrint);

	// Basis Event
	mEventTypeList = new LinkedList<CEventType>;
	bool bLoadEvent = loadEventTypes(CTB_EVENTTYPE_FILENAME);
	assert(bLoadEvent);

	mModuleTypeList = new LinkedList<CModuleType>;
	int nModule = loadModuleTypes();
	assert(0 < nModule);

	mDiagramWindowList = new LinkedList<CDiagramWindow>;

	setSimulationActive(false);

	setRenderingMode(OGL_RENDERING_TEXTURE);

	setJavaConsoleHandle(NULL);
	mJavaConsole = NULL;
#ifdef USE_JAVACONSOLE
	createJavaConsole();
#endif
	getSceneGraph()->setOption(/*SCENEGRAPH_NORMAL_GENERATION | */SCENEGRAPH_TEXTURE_GENERATION);
}

//////////////////////////////////////////////////
// World::~World
//////////////////////////////////////////////////

void World::deleteSceneGraphVisualObjects() 
{
	Node *node;

	node = getViewpointObjectNode();
	if (node)
		delete node;

	node = getDirectionalLightObjectNode();
	if (node)
		delete node;

	node = getSpotLightObjectNode();
	if (node)
		delete node;

	node = getPointLightObjectNode();
	if (node)
		delete node;
}

World::~World() 
{
	deleteSceneGraphVisualObjects();

	delete mSceneGraph;
	delete mModuleTypeList;

	CDiagramWindow *dgm = GetWorld()->getDiagramWindows();
	while (dgm) {
		CDiagramWindow *nextDgm = dgm->next();
		dgm->getHandle()->DestroyWindow();
		dgm = nextDgm;
	}
	delete mDiagramWindowList;

	delete mEventTypeList;

#ifdef USE_JAVACONSOLE
	if (getJavaConsoleHandle())
		deleteJavaConsole();
#endif
}

//////////////////////////////////////////////////
// ModuleType
//////////////////////////////////////////////////

int World::loadModuleTypes()
{
	char	sysDirModules		[FILE_MAX_PATHLEN];
	char	serchFilename		[FILE_MAX_FILENAME];
	char	moduleTypeFilename	[FILE_MAX_FILENAME];

	if (RegKeyGetValue(REGKEY_SECTION_PATHNAME, REGKEY_KEY_MODULES_PATHNAME, sysDirModules) == FALSE)
		strcpy(sysDirModules, "modules\\");
	sprintf(serchFilename, "%s\\%s*.%s", getInitialDirectory(), sysDirModules, MODULE_FILE_EXTENTION);

	int	nModule = 0;

#ifdef FIND_MODULEFILE_FORMDIRECTORY

	WIN32_FIND_DATA	fd;
	BOOL			bRet = TRUE;

	HANDLE	hFind = FindFirstFile(serchFilename, &fd);
	while (hFind != INVALID_HANDLE_VALUE && bRet) {
		sprintf(moduleTypeFilename, "%s%s", sysDirModules, fd.cFileName);
		CModuleType *moduleType = new CModuleType();
		moduleType->load(moduleTypeFilename);
		addModuleType(moduleType);
		nModule++;
		bRet = FindNextFile(hFind, &fd);
	}
	FindClose(hFind);

#else

	ModuleFilenameInitialize();
	
	nModule = GetNModuleFilenames();

	for (int n=0; n<nModule; n++) {
		sprintf(moduleTypeFilename, "%s%s", sysDirModules, GetModuleFilename(n));
		CModuleType *moduleType = new CModuleType();
		moduleType->load(moduleTypeFilename);
		addModuleType(moduleType);
	}

	ModuleFilenameDelete();

#endif

	return nModule;
}

CModuleType *World::getModuleTypes(char *className)
{
	for (CModuleType *cmType=getModuleTypes(); cmType; cmType=cmType->next()) {
		if (!StringCompareIgnoreCase(cmType->getClassName(), className)) 
			return cmType;
	}
	return NULL;
}

int World::getNModuleTypes()
{
	int nModule = 0;
	for (CModuleType *cmType=getModuleTypes(); cmType; cmType=cmType->next())
		nModule++;
	return nModule;
}

int World::getNModuleTypes(char *className)
{
	int nModule = 0;
	for (CModuleType *cmType=getModuleTypes(className); cmType; cmType=cmType->next(className))
		nModule++;
	return nModule;
}

CModuleType *World::getModuleType(int n)
{
	int nModule = 0;
	for (CModuleType *cmType=getModuleTypes(); cmType; cmType=cmType->next()) {
		if (nModule == n)
			return cmType;
		nModule++;
	}
	return NULL;
}

CModuleType *World::getModuleType(char *className, int n)
{
	int nModule = 0;
	for (CModuleType *cmType=getModuleTypes(className); cmType; cmType=cmType->next(className)) {
		if (nModule == n)
			return cmType;
		nModule++;
	}
	return NULL;
}

CModuleType *World::getModuleType(char *className, char *moduleName)
{
	for (CModuleType *cmType=getModuleTypes(); cmType; cmType=cmType->next()) {
		if (!StringCompareIgnoreCase(cmType->getClassName(), className) && !StringCompareIgnoreCase(cmType->getName(), moduleName) ) 
			return cmType;
	}
	return NULL;
}

//////////////////////////////////////////////////
// SceneGraph
//////////////////////////////////////////////////

void World::clearSceneGraph()
{
	deleteDiagramWindows();
	getSceneGraph()->clear();
}

bool World::loadSceneGraph(char *filename, bool bInitialize, void (*callbackFn)(int nLine, void *info), void *callbackFnInfo)
{
	SceneGraph *sceneGraph = getSceneGraph();
	sceneGraph->load(filename, bInitialize, callbackFn, callbackFnInfo);
	return sceneGraph->isOK();
}

void World::addRootNode(Node *rootNode)
{
	Node *node = rootNode->getChildNodes();
	while (node) {
		Node *nextNode = node->next();

		// Global Data Node
		if (isGlobalDataRootNode(node)) {
			AnchorNode *gdataNode = node->getAnchorNodes();
			while (gdataNode) {
				AnchorNode *nextGdataNode = gdataNode->next();
				addGlobalData(gdataNode);
				gdataNode = nextGdataNode;
			}
		}
		
		// Event Node
		if (isEventRootNode(node)) {
			Node *eventNode = node->getChildNodes();
			while (eventNode) {
				Node *nextEventNode = eventNode->next();
				addEventNode(eventNode);
				eventNode = nextEventNode;
			}
		}
		
		// Diagram Node
		if (isDiagramRootNode(node)) {
			Node *diagramNode = node->getChildNodes();
			while (diagramNode) {
				Node *nextdiagramNode = diagramNode->next();
				addDiagramNode((TransformNode *)diagramNode);
				diagramNode = nextdiagramNode;
			}
		}

		node = nextNode;
	}
}

bool World::addSceneGraph(char *filename, bool bInitialize, void (*callbackFn)(int nLine, void *info), void *callbackFnInfo)
{
	SceneGraph sceneGraph;

	sceneGraph.setJavaEnv(GetJavaClassPath(getInitialDirectory()), WorldJavaPrint);

	sceneGraph.setOption(getSceneGraph()->getOption());
	sceneGraph.load(filename, bInitialize, callbackFn, callbackFnInfo);

	if (!sceneGraph.isOK()) {
		UsrMsgWarning("Loading Error (%d) : %s", sceneGraph.getErrorLineNumber(), sceneGraph.getErrorLineString());
		return false;
	}

	Node *node = sceneGraph.getNodes();
	while (node) {
		Node *nextNode = node->next();
		if (isRootNode(node))
			addRootNode(node);
		else 
			getSceneGraph()->moveNode(node);
		node = nextNode;
	}

	// Route Infomation
	for (Route *route = sceneGraph.getRoutes(); route; route = route->next()) {
		getSceneGraph()->addRoute(route->getEventOutNode()->getName(), route->getEventOutField()->getName(),
									route->getEventInNode()->getName(), route->getEventInField()->getName());
	}

	if (bInitialize)
		getSceneGraph()->initialize();

	return true;
}

void World::addFullPathSceneGraphUrlFileNames()
{
	char fullpathFilename[1024];

	SceneGraph *sg = getSceneGraph();

	for (AudioClipNode *aclip=sg->findAudioClipNode(); aclip != NULL; aclip = aclip->nextTraversal()) {
		if (0 < aclip->getNUrls()) {
			char *filename = aclip->getUrl(0);
			if (filename && 0 < strlen(filename)) {
				if (FileGetFullPathName(filename, fullpathFilename, 1023) == true) {
					if (FileExists(fullpathFilename) == true)
						aclip->setUrl(0, fullpathFilename);
				}
			}
		}
	}

	for (ImageTextureNode *imgTex=sg->findImageTextureNode(); imgTex != NULL; imgTex = imgTex->nextTraversal()) {
		if (0 < imgTex->getNUrls()) {
			char *filename = imgTex->getUrl(0);
			if (filename && 0 < strlen(filename)) {
				if (FileGetFullPathName(filename, fullpathFilename, 1023) == true) {
					if (FileExists(fullpathFilename) == true)
						imgTex->setUrl(0, fullpathFilename);
				}
			}
		}
	}

	for (ScriptNode *script=sg->findScriptNode(); script != NULL; script = script->nextTraversal()) {
		if (0 < script->getNUrls()) {
			char *filename = script->getUrl(0);
			if (filename && 0 < strlen(filename)) {
				if (FileGetFullPathName(filename, fullpathFilename, 1023) == true) {
					if (FileExists(fullpathFilename) == true)
						script->setUrl(0, fullpathFilename);
				}
			}
		}
	}
}

void World::copySceneGraphUrlFiles(char *destDirectory)
{
	char fullpathDestFilename[1024];
	char destFilename[1024];

	SceneGraph *sg = getSceneGraph();

	for (AudioClipNode *aclip=sg->findAudioClipNode(); aclip != NULL; aclip = aclip->nextTraversal()) {
		if (0 < aclip->getNUrls()) {
			char *filename = aclip->getUrl(0);
			if (filename && 0 < strlen(filename)) {
				if (FileExists(filename) == true) {
					strcpy(destFilename, filename);
					FileStripPathName(destFilename);
					strcpy(fullpathDestFilename, destDirectory);
					strcat(fullpathDestFilename, destFilename);
					if (FileCopy(filename, fullpathDestFilename) == true)
						aclip->setUrl(0, destFilename);
				}
			}
		}
	}

	for (ImageTextureNode *imgTex=sg->findImageTextureNode(); imgTex != NULL; imgTex = imgTex->nextTraversal()) {
		if (0 < imgTex->getNUrls()) {
			char *filename = imgTex->getUrl(0);
			if (filename && 0 < strlen(filename)) {
				if (FileExists(filename) == true) {
					strcpy(destFilename, filename);
					FileStripPathName(destFilename);
					strcpy(fullpathDestFilename, destDirectory);
					strcat(fullpathDestFilename, destFilename);
					if (FileCopy(filename, fullpathDestFilename) == true)
						imgTex->setUrl(0, destFilename);
				}
			}
		}
	}

	for (ScriptNode *script=sg->findScriptNode(); script != NULL; script = script->nextTraversal()) {
		if (0 < script->getNUrls()) {
			char *filename = script->getUrl(0);
			if (filename && 0 < strlen(filename)) {
				strcpy(destFilename, filename);
				FileStripPathName(destFilename);
				strcpy(fullpathDestFilename, destDirectory);
				strcat(fullpathDestFilename, destFilename);
				if (FileExists(filename) == true) {
					if (FileCopy(filename, fullpathDestFilename) == true)
						script->setUrl(0, destFilename);
				}
				else {
					char sysScriptNodeDirectory[1024];
					char scriptFilename[1024];
					if (RegKeyGetValue(REGKEY_SECTION_PATHNAME, REGKEY_KEY_SCRIPTS_PATHNAME, sysScriptNodeDirectory) == FALSE)
						strcpy(sysScriptNodeDirectory, "scripts\\");
					sprintf(scriptFilename, "%s\\%s%s", getInitialDirectory(), sysScriptNodeDirectory, destFilename);
					if (FileExists(scriptFilename) == true) {
						if (FileCopy(scriptFilename, fullpathDestFilename) == true)
							script->setUrl(0, destFilename);
					}
				}
			}
		}
	}
}

bool World::saveSceneGraph(char *filename, void (*callbackFn)(int nNode, void *info), void *callbackFnInfo)
{
	SceneGraph *sceneGraph = getSceneGraph();

	initialize();

	// Delete invald field of Module
	for (TransformNode *diagramNode=getDiagramNodes(); diagramNode; diagramNode=nextDiagramNode(diagramNode)) {
		CDiagram diagram(diagramNode);
		for (ScriptNode *moduleNode = diagram.getModules(); moduleNode; moduleNode=moduleNode->next()) {
			CModule module(moduleNode);
			if (module.getSourceNode() == NULL && module.getSourceNodeField()) {
				SFNode *field = module.getSourceNodeField();
				//delete field;
			}
			if (module.getTargetNode() == NULL && module.getTargetNodeField()) {
				SFNode *field = module.getTargetNodeField();
				//delete field;
			}
		}
	}

	GroupNode *rootNode = getRootNode();

	// Move glabal date node at first
	GroupNode *globalDataNode = getGlobalDataRootNode();
	rootNode->moveChildNodeAtFirst(globalDataNode);

	// Move root node at last for USE
	sceneGraph->moveNode(rootNode);

	sceneGraph->save(filename, callbackFn, callbackFnInfo);
	
	return true;
}

//////////////////////////////////////////////////
// Event 
//////////////////////////////////////////////////

Node *World::getEventNodes()
{
	if (!hasSystemEventsNodes())
		createSystemEvents();

	for (Node *node = getEventRootNode()->getChildNodes(); node; node = node->next()) {
		CEvent event(node);
		if (event.isEventNode())
			return node;
	}
	return NULL;
}

Node *World::getEventNode(char *typeName, char *optionName)
{
	if (!StringCompare(optionName, CTB_EVENT_NONE_OPTION_NAME))
		optionName = NULL;

	for (Node *node=getEventNodes(); node; node=node->next()) {
		CEvent	event(node);
		if (!StringCompare(typeName, event.getEventTypeName())) {
			if (!optionName)
				return node;
			else if (!StringCompare(optionName, event.getEventOptionName()))
				return node;
		}
	}
	return NULL;
}

Node *World::getEventNode(CEventType *eventType)
{
	for (Node *node=getEventNodes(); node; node=node->next()) {
		CEvent	event(node);
		if (event.getEventType() == eventType)
			return node;
	}
	return NULL;
}

Node *World::getEventNode(int nEvent)
{
	Node *node = getEventNodes();
	for (int n=0; n<nEvent; n++)
		node = node->next();
	return node;
}

int World::getNEventNodes()
{
	int nEventNode = 0;
	for (Node *node = getEventRootNode()->getChildNodes(); node; node = node->next()) {
		CEvent event(node);
		if (event.isEventNode())
			nEventNode++;;
	}
	return nEventNode;
}

bool World::addEventNode(Node *eventNode) {
	for (Node *node = getEventRootNode()->getChildNodes(); node; node = node->next()) {
		if (!StringCompare(eventNode->getName(), node->getName()))
			return false;
	}

	getEventRootNode()->moveChildNode(eventNode);
	return true;
}

bool World::isEventNode(Node *eventNode)
{
	for (Node *node = getEventRootNode()->getChildNodes(); node; node = node->next()) {
		CEvent event(node);
		if (event.isEventNode()) {
			if (node == eventNode)
				return true;
		}
	}
	return false;
}

void World::deleteEventNode(Node *eventNode) {
	if (!isEventNode(eventNode))
		return;

	delete eventNode;
}

//////////////////////////////////////////////////
// Event File
//////////////////////////////////////////////////

#define	LINE_LENGTH_MAX	256

bool World::loadEventTypes(char *filename) 
{
	ifstream fin(filename);
	if (!fin)
		return false;

	fin.ignore(LINE_LENGTH_MAX, '\n');

	char	eventName			[32];
	char	eventAttributeName	[32];
	char	eventNodeTypeName	[32];
	char	eventFieldTypeName	[32];
	char	eventFieldName		[32];

	while (!fin.eof()) {
		fin >> eventName >> eventAttributeName >> eventNodeTypeName >> eventFieldTypeName >> eventFieldName;
		if (fin.good()) {
			CEventType *event = new CEventType(eventName, eventAttributeName, eventNodeTypeName, eventFieldTypeName, eventFieldName);
			addEventType(event);
		}
	}

	return true;
}

//////////////////////////////////////////////////
// System events
//////////////////////////////////////////////////

void World::createSystemEvents() {
	for (int n=0; n<getNEventTypes(); n++) {
		CEventType *eventType = getEventType(n);
		if (eventType->getAttributeType() == CTB_EVENATTRIBUTE_SYSTEM) {
			CEvent event(eventType);
			addEventNode(event.getNode());
		}
	}
}

bool World::hasSystemEventsNodes() {

	for (CEventType *eventType=getEventTypes(); eventType; eventType=eventType->next()) {

		if (eventType->getAttributeType() == CTB_EVENATTRIBUTE_SYSTEM) {
			bool bHasEvent = false;
			for (Node *node = getEventRootNode()->getChildNodes(); node; node = node->next()) {
				CEvent	event(node);
				if (!StringCompare(eventType->getName(), event.getEventTypeName())) {
					bHasEvent = true;
					break;
				}
			}
			if (!bHasEvent)
				return false;
		}

	}

	return true;
}

//////////////////////////////////////////////////
// Sub System events
//////////////////////////////////////////////////

GroupNode *World::getSubSystemEventsNode()
{
	for (GroupNode *group=getRootNode()->getGroupNodes(); group; group=group->next()) {
		if (isSubEventRootNode(group) == true)
			return group;
	}

	return NULL;
}

//////////////////////////////////////////////////
// Diagram
//////////////////////////////////////////////////

TransformNode *World::addDiagram(char *name, CEvent *event)
{
	if (!getDiagramNode(name, event->getNode())) {
		CDiagram	dgm(name, event);
		TransformNode	*transform = dgm.getTransformNode();
		addDiagramNode(transform);
		dgm.addBasisModule();
		return transform;
	}
	else
		return NULL;
}

TransformNode *World::addDiagram(char *name, Node *eventNode)
{
	CEvent event(eventNode);
	return addDiagram(name, &event);
}

void World::addDiagramNode(TransformNode *node)
{
	getDiagramRootNode()->moveChildNode(node);
}

int World::getNDiagramNodes()
{
	int	nDiagramNodes = 0;
	
	for (TransformNode *transform=getDiagramNodes(); transform; transform=nextDiagramNode(transform)) 
		nDiagramNodes++;

	return nDiagramNodes;
}

TransformNode *World::getDiagramNodes()
{
	for (TransformNode *transform=getDiagramRootNode()->getTransformNodes(); transform; transform=transform->next()) {
		if (!StringNCompare(transform->getName(), CTB_DIAGRAM_NODENAME, strlen(CTB_DIAGRAM_NODENAME)))
			return transform;
	}

	return NULL;
}

TransformNode *World::getDiagramNode(char *name)
{
	for (TransformNode *transform=getDiagramNodes(); transform; transform=nextDiagramNode(transform)) {
		CDiagram diagram(transform);
		if (!StringCompare(name, diagram.getName()))
			return transform;
	}
	return NULL;
}

TransformNode *World::getDiagramNode(char *name , Node *eventNode)
{
	for (TransformNode *transform=getDiagramNodes(); transform; transform=nextDiagramNode(transform)) {
		CDiagram diagram(transform);
		if (diagram.getEventNode() == eventNode && !StringCompare(name, diagram.getName()))
			return transform;
	}
	return NULL;
}

TransformNode *World::nextDiagramNode(TransformNode *node)
{
	for (TransformNode *transform=node->next(); transform; transform=transform->next()) {
		if (!StringNCompare(transform->getName(), CTB_DIAGRAM_NODENAME, strlen(CTB_DIAGRAM_NODENAME)))
			return transform;
	}

	return NULL;
}

bool World::isDiagram(Node *node)
{
	if (node == NULL)
		return false;

	if (node->isTransformNode() == false)
		return false;

	TransformNode *tnode = (TransformNode *)node;
	for (TransformNode *transform=getDiagramNodes(); transform; transform=nextDiagramNode(transform)) {
		if (transform == tnode)
			return true;
	}
	return false;
}


//////////////////////////////////////////////////
// GlobalData
//////////////////////////////////////////////////

AnchorNode *World::addGlobalData(char *name)
{
	CGlobalData	gdata(name);
	AnchorNode	*info = gdata.getNode();
	getGlobalDataRootNode()->moveChildNode(info);
	return info;
}

void World::addGlobalData(AnchorNode *node)
{
	getGlobalDataRootNode()->moveChildNode(node);
}

int World::getNGlobalDataNodes()
{
	int	nGlobalDataNodes = 0;
	
	for (AnchorNode *info=getGlobalDataNodes(); info; info=info->next()) 
		nGlobalDataNodes++;

	return nGlobalDataNodes;
}

AnchorNode *World::getGlobalDataNodes()
{
	for (AnchorNode *info=getGlobalDataRootNode()->getAnchorNodes(); info; info=info->next()) {
		if (!StringNCompare(info->getName(), CTB_GLOBALDATA_NODENAME, strlen(CTB_GLOBALDATA_NODENAME)))
			return info;
	}

	return NULL;
}

AnchorNode *World::getGlobalDataNode(char *name)
{
	for (AnchorNode *info=getGlobalDataNodes(); info; info=info->next()) {
		CGlobalData gdata(info);
		if (!StringCompare(name, gdata.getName()))
			return info;
	}
	return NULL;
}


bool World::isGlobalData(AnchorNode *node)
{
	for (AnchorNode *info=getGlobalDataNodes(); info; info=info->next()) {
		if (info == node)
			return true;
	}
	return false;
}

//////////////////////////////////////////////////
// Window
//////////////////////////////////////////////////

void World::addDiagramWindow(CDiagramWindow *dgmWindow)
{
	mDiagramWindowList->addNode(dgmWindow);
}

void World::addDiagramWindow(CWnd *wnd)
{
	CDiagramWindow *dgmWindow = new CDiagramWindow(wnd);
	addDiagramWindow(dgmWindow);
}

void World::deleteDiagramWindows()
{
	CDiagramWindow *dgm = GetWorld()->getDiagramWindows();
	while (dgm) {
		CDiagramWindow *nextDgm = dgm->next();
		dgm->getHandle()->GetParentFrame()->DestroyWindow();
		dgm = nextDgm;
	}
}

void World::deleteDiagramWindow(CWnd *wnd)
{
	for (CDiagramWindow *dgm=getDiagramWindows(); dgm; dgm=dgm->next()) {
		if (dgm->getHandle() == wnd) {
			dgm->getHandle()->DestroyWindow();
			delete dgm;
			return;
		}
	}
}

CDiagramWindow *World::getDiagramWindows()
{
	return mDiagramWindowList->getNodes();
}

bool World::isDiagramWindow(CWnd *wnd)
{
	for (CDiagramWindow *dgm=getDiagramWindows(); dgm; dgm=dgm->next()) {
		if (dgm->getHandle() == wnd)
			return true;
	}
	return false;
}

//////////////////////////////////////////////////
// Simulation
//////////////////////////////////////////////////

void World::initialize()
{
	getSceneGraph()->initialize();
	initializeSimulation();
}

void World::initializeSimulation()
{
	TimeSensorNode *startEvent = (TimeSensorNode *)getEventNode(CTB_EVENTTYPE_START);
	assert(startEvent);
	if (!startEvent)
		return;
	startEvent->setEnabled(true);
}

//////////////////////////////////////////////////
// Node Operation
//////////////////////////////////////////////////

void World::removeNode(Node *node)
{
	getSceneGraph()->removeNode(node);
}

void World::deleteNode(Node *node)
{
	getSceneGraph()->deleteNode(node);
}

//////////////////////////////////////////////////
// Java Console
//////////////////////////////////////////////////

#ifdef USE_JAVACONSOLE

bool HandlerRoutine(DWORD dwCtrlType)
{
	ExitProcess(0);
	return true;
}

void World::createJavaConsole()
{
	AllocConsole();
	SetConsoleTitle("JNI CONSOLE");
	SetConsoleCtrlHandler((PHANDLER_ROUTINE)HandlerRoutine, true);
	setJavaConsoleHandle(GetStdHandle(STD_OUTPUT_HANDLE));
	mJavaConsole = new CJavaConsole(getSceneGraph()->getJniEnv());
}

void World::deleteJavaConsole()
{
	if (getJavaConsoleHandle())
		FreeConsole();
	if (mJavaConsole)
		delete mJavaConsole;
}

#endif

/************************************************************
*
*	Global Functions
*
************************************************************/

//////////////////////////////////////////////////
// World
//////////////////////////////////////////////////

static World *gWorld = NULL;

World *GetWorld(void)
{
	return	gWorld;
}

void WorldInit()
{
	gWorld = new World();
}

void WorldQuit()
{
	//delete gWorld;
}

//////////////////////////////////////////////////
// Event
//////////////////////////////////////////////////

char *GetEventTypeString(int eventType)
{
	CEventType	*event = GetWorld()->getEventType(eventType);
	assert(event);
	return event->getName();
}

int GetEventTypeFromString(char *eventTypeString)
{
	int eventType = -1;
	for (int n=0; n<GetWorld()->getNEventTypes(); n++) {
		if (!StringCompareIgnoreCase(eventTypeString, GetEventTypeString(n))) {
			eventType = n;
			break;
		}
	}
	assert(eventType >= 0);
	return eventType;
}

//////////////////////////////////////////////////
// Java Console
//////////////////////////////////////////////////

jint JNICALL WorldJavaPrint(FILE *fp, const char *format, va_list args)
{
#ifdef USE_JAVACONSOLE
	char	msg[1024];
	vsprintf(msg, format, args);
	World *world = GetWorld();
	if (world == NULL)
		return 0;
	HANDLE handle = world->getJavaConsoleHandle();
	if (handle) {
		DWORD value;
		WriteConsole(handle, msg, StringLength(msg), &value, NULL);
	}
#endif
	return 0;
}

