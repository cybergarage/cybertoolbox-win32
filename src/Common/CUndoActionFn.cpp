#include "CUndoAction.h"
#include "CUndoActionFn.h"
#include "..\stdafx.h"
#include "..\CyberToolBox.h"
#include "..\CyberToolBoxDoc.h"
#include "..\CyberToolBoxView.h"
#include "World.h"
#include "..\OrthoView.h"
#include "CDiagramClipboard.h"

/************************************************************
*
*	Diagram
*
************************************************************/

/************************************************************
*	Delete
************************************************************/

void *UndoDiagramModuleAddNew(TransformNode *diagram, ScriptNode *node)
{
	UndoDiagramModuleAdd *info = (UndoDiagramModuleAdd *)malloc(sizeof(UndoDiagramModuleAdd));
	info->mpDiagramNode	= diagram;
	info->mpNode		= node;
	return info;
}

void UndoDiagramModuleAddFn(void *info)
{
	UndoDiagramModuleAdd *undoInfo = (UndoDiagramModuleAdd *)info;
	CDiagram	diagram(undoInfo->mpDiagramNode);
	ScriptNode		*node = undoInfo->mpNode;

	CModule module(node);
	diagram.deleteModule(&module);
}

/************************************************************
*	Move
************************************************************/

void *UndoDiagramModuleMoveNew(ScriptNode *node, int x, int y)
{
	UndoDiagramModuleMove *info = (UndoDiagramModuleMove *)malloc(sizeof(UndoDiagramModuleMove));
	info->mNode = node;
	info->mx = x;
	info->my = y;
	return info;
}

void UndoDiagramModuleMoveFn(void *info)
{
	UndoDiagramModuleMove *modInfo = (UndoDiagramModuleMove *)info;
	CModule module(modInfo->mNode);
	module.setPosition(modInfo->mx, modInfo->my);
}

/************************************************************
*	Move (SelectingBox)
************************************************************/

void *UndoDiagramModuleMoveInSelectingBoxNew(int nModule, ScriptNode **node, int *x, int *y)
{
	UndoDiagramModuleMoveInSelectingBox *info = (UndoDiagramModuleMoveInSelectingBox *)malloc(sizeof(UndoDiagramModuleMoveInSelectingBox));
	info->mnModule = nModule;
	info->mNode = node;
	info->mx = x;
	info->my = y;
	return info;
}

void UndoDiagramModuleMoveInSelectingBoxActionFn(void *info)
{
	UndoDiagramModuleMoveInSelectingBox *modInfo = (UndoDiagramModuleMoveInSelectingBox *)info;
	int nModule = modInfo->mnModule;
	ScriptNode **moduleNode = modInfo->mNode;
	int *mx = modInfo->mx;
	int *my = modInfo->my;

	for (int n=0; n<nModule; n++) {
		CModule module(moduleNode[n]);
		module.setPosition(mx[n], my[n]);
	}
}

void UndoDiagramModuleMoveInSelectingBoxFreeFn(void *info)
{
	UndoDiagramModuleMoveInSelectingBox *modInfo = (UndoDiagramModuleMoveInSelectingBox *)info;
	delete []modInfo->mNode;
	delete []modInfo->mx;
	delete []modInfo->my;
}

/************************************************************
*	Delete
************************************************************/

void *UndoDiagramModuleDeleteNew(TransformNode *diagramNode, ScriptNode *node)
{
	UndoDiagramModuleDelete *info = (UndoDiagramModuleDelete *)malloc(sizeof(UndoDiagramModuleDelete));
	info->mpDiagramNode	= diagramNode;
	info->mpNode		= node;

	CModule module(node);
	if (module.getNRoutes() > 0) {
		RouteInfo *routeInfo = (RouteInfo *)malloc(sizeof(RouteInfo)*module.getNRoutes());
		int nRoute = 0;
		for (Route *route=GetWorld()->getSceneGraph()->getRoutes(); route; route=route->next()) {
			if (node == route->getEventOutNode() || node == route->getEventInNode()) {
				routeInfo[nRoute].mInNode	= route->getEventInNode();
				routeInfo[nRoute].mInField	= route->getEventInField();
				routeInfo[nRoute].mOutNode	= route->getEventOutNode();
				routeInfo[nRoute].mOutField	= route->getEventOutField();
				nRoute++;
			}
		}
		info->mnRouteInfo = module.getNRoutes();
		info->maRouteInfo = routeInfo;
	}
	else {
		info->mnRouteInfo = 0;
		info->maRouteInfo = NULL;
	}

	return info;
}

void UndoDiagramModuleDeleteActionFn(void *info)
{
	UndoDiagramModuleDelete *dmInfo = (UndoDiagramModuleDelete *)info;

	TransformNode	*diagramNode = dmInfo->mpDiagramNode;
	ScriptNode		*moduleNode = dmInfo->mpNode;

	CDiagram	diagram(diagramNode);
	CModule		module(moduleNode);
	diagram.addModule(&module);

	if (0 < dmInfo->mnRouteInfo) {
		for (int n=0; n<dmInfo->mnRouteInfo; n++) {
			RouteInfo *routeInfo = &dmInfo->maRouteInfo[n];
			GetWorld()->getSceneGraph()->addRoute(routeInfo->mOutNode, routeInfo->mOutField, routeInfo->mInNode, routeInfo->mInField);
		}
	}

	if (dmInfo->maRouteInfo)
		delete dmInfo->maRouteInfo;
}

void UndoDiagramModuleDeleteFreeFn(void *info)
{
/*
	UndoDiagramModuleDelete *dmInfo = (UndoDiagramModuleDelete *)info;

	if (dmInfo->maRouteInfo)
		delete dmInfo->maRouteInfo;

	if (dmInfo->mpNode)
		delete dmInfo->mpNode;
*/
}

/************************************************************
*	Cut
************************************************************/

void *UndoDiagramModuleCutNew(TransformNode *diagramNode, CDiagramClipboard *clipboard)
{
	UndoDiagramModuleCut *info = (UndoDiagramModuleCut *)malloc(sizeof(UndoDiagramModuleCut));
	info->mpDiagramNode	= diagramNode;
	info->mpClipboard	= clipboard;
	return info;
}

void UndoDiagramModuleCutActionFn(void *info)
{
	TransformNode		*dgmNode = ((UndoDiagramModuleCut *)info)->mpDiagramNode;
	CDiagramClipboard	*clipboard = ((UndoDiagramModuleCut *)info)->mpClipboard;

	CDiagram dgm(dgmNode);

	int nModule = clipboard->getNModuleNodes();
	ScriptNode*	(*moduleNode)[2] = new (ScriptNode *[nModule][2]);
	for (int n=0; n<nModule; n++) {
		CModule		orgModule(clipboard->getModuleNode(n));
		CModule		copyModule(orgModule.getModuleType());
		copyModule.setPositionX(orgModule.getPositionX());
		copyModule.setPositionY(orgModule.getPositionY());
		dgm.addModule(&copyModule);
		moduleNode[n][0] = orgModule.getScriptNode();
		moduleNode[n][1] = copyModule.getScriptNode();
	}

	int nRoute = clipboard->getNRoutes();
	for (n=0; n<nRoute; n++) {
		Route	*route = clipboard->getRoute(n);
		ScriptNode	*outModule = (ScriptNode *)route->getEventOutNode();
		for (int i=0; i<nModule; i++) {
			if (moduleNode[i][0] == outModule) {
				outModule = moduleNode[i][1];
				break;
			}
		}
		ScriptNode	*inModule = (ScriptNode *)route->getEventInNode();
		for (i=0; i<nModule; i++) {
			if (moduleNode[i][0] == inModule) {
				inModule = moduleNode[i][1];
				break;
			}
		}
		GetWorld()->getSceneGraph()->addRoute(outModule->getName(), route->getEventOutField()->getName(), inModule->getName(), route->getEventInField()->getName());
	}
	
	delete []moduleNode;

	delete clipboard;
}

void UndoDiagramModuleCutFreeFn(void *info)
{
	CDiagramClipboard	*clipboard = ((UndoDiagramModuleCut *)info)->mpClipboard;

	delete clipboard;
}

/************************************************************
*	Paste
************************************************************/

void *UndoDiagramModulePasteNew(TransformNode *dgmNode, int nScriptNode, ScriptNode **scriptNode, int nRoute, Route **route)
{
	UndoDiagramModulePaste *info = (UndoDiagramModulePaste *)malloc(sizeof(UndoDiagramModulePaste));
	info->mpDiagramNode	= dgmNode;
	info->mnScriptNode	= nScriptNode;
	info->mpScriptNode	= scriptNode;
	info->mnRoute		= nRoute;
	info->mpRoute		= route;
	return info;
}

void UndoDiagramModulePasteActionFn(void *info)
{
	TransformNode		*dgmNode = ((UndoDiagramModuleCut *)info)->mpDiagramNode;
	int			nScriptNode		= ((UndoDiagramModulePaste *)info)->mnScriptNode;
	ScriptNode	**scriptNode	= ((UndoDiagramModulePaste *)info)->mpScriptNode;
	int			nRoute			= ((UndoDiagramModulePaste *)info)->mnRoute;
	Route		**route			= ((UndoDiagramModulePaste *)info)->mpRoute;

	for (int n=0; n<nRoute; n++) {
		GetWorld()->getSceneGraph()->removeRoute(route[n]);
	}

	CDiagram dgm(dgmNode);
	for (n=0; n<nScriptNode; n++) {
		CModule module(scriptNode[n]);
		dgm.removeModule(&module);
	}

	delete	[]scriptNode;
	delete	[]route;
}

void UndoDiagramModulePasteFreeFn(void *info)
{
	ScriptNode	**scriptNode	= ((UndoDiagramModulePaste *)info)->mpScriptNode;
	Route		**route			= ((UndoDiagramModulePaste *)info)->mpRoute;
	
	delete	[]scriptNode;
	delete	[]route;
}

/************************************************************
*	Create Input Line
************************************************************/

void *UndoDiagramModuleCreateInputLineNew(ScriptNode *inModule, Field *inField, ScriptNode *outModule, Field *outField)
{
	UndoDiagramModuleCreateInputLine *info = (UndoDiagramModuleCreateInputLine *)malloc(sizeof(UndoDiagramModuleCreateInputLine));
	info->mInModule		= inModule;
	info->mInField		= inField;
	info->mOutModule	= outModule;
	info->mOutField		= outField;
	return info;
}

void UndoDiagramModuleCreateInputLineFn(void *info)
{
	UndoDiagramModuleCreateInputLine *mInfo = (UndoDiagramModuleCreateInputLine *)info;
	GetWorld()->getSceneGraph()->deleteRoute(mInfo->mInModule, mInfo->mInField, mInfo->mOutModule, mInfo->mOutField);
}

/************************************************************
*	Delete Input Line
************************************************************/

void *UndoDiagramModuleDeleteInputLineNew(ScriptNode *inModule, Field *inField, ScriptNode *outModule, Field *outField)
{
	UndoDiagramModuleDeleteInputLine *info = (UndoDiagramModuleDeleteInputLine *)malloc(sizeof(UndoDiagramModuleDeleteInputLine));
	info->mInModule		= inModule;
	info->mInField		= inField;
	info->mOutModule	= outModule;
	info->mOutField		= outField;
	return info;
}

void UndoDiagramModuleDeleteInputLineFn(void *info)
{
	UndoDiagramModuleCreateInputLine *mInfo = (UndoDiagramModuleCreateInputLine *)info;
	GetWorld()->getSceneGraph()->addRoute(mInfo->mOutModule, mInfo->mOutField, mInfo->mInModule, mInfo->mInField);
}

/************************************************************
*
*	OrthoView
*
************************************************************/

/************************************************************
*	Scale
************************************************************/

void *UndoOrthoViewChangeScaleNew(OrthoView *oview, float scale)
{
	UndoOrthoViewChangeScale *info = (UndoOrthoViewChangeScale *)malloc(sizeof(UndoOrthoViewChangeScale));
	info->orthoView	= oview;
	info->scale		= scale;
	return info;
}

void UndoOrthoViewChangeScaleFn(void *info)
{
	UndoOrthoViewChangeScale *undoInfo = (UndoOrthoViewChangeScale *)info;
	undoInfo->orthoView->setScale(undoInfo->scale);
}

/************************************************************
*	Offset
************************************************************/

void *UndoOrthoViewChangeOffsetNew(OrthoView *oview, float offset[3])
{
	UndoOrthoViewChangeOffset *info = (UndoOrthoViewChangeOffset *)malloc(sizeof(UndoOrthoViewChangeOffset));
	info->orthoView	= oview;
	info->offset[0]	= offset[0];
	info->offset[1]	= offset[1];
	info->offset[2]	= offset[2];
	return info;
}

void UndoOrthoViewChangeOffsetFn(void *info)
{
	UndoOrthoViewChangeOffset *undoInfo = (UndoOrthoViewChangeOffset *)info;
	undoInfo->orthoView->setOffset(undoInfo->offset);
}

/************************************************************
*	Scale & Offset
************************************************************/

void *UndoOrthoViewChangeScaleOffsetNew(OrthoView *oview, float scale, float offset[3])
{
	UndoOrthoViewChangeScaleOffset *info = (UndoOrthoViewChangeScaleOffset *)malloc(sizeof(UndoOrthoViewChangeScaleOffset));
	info->orthoView		= oview;
	info->scale			= scale;
	info->offset[0]		= offset[0];
	info->offset[1]		= offset[1];
	info->offset[2]		= offset[2];
	return info;
}

void UndoOrthoViewChangeScaleOffsetFn(void *info)
{
	UndoOrthoViewChangeScaleOffset *undoInfo = (UndoOrthoViewChangeScaleOffset *)info;
	undoInfo->orthoView->setScale(undoInfo->scale);
	undoInfo->orthoView->setOffset(undoInfo->offset);
}

/************************************************************
*	Scale & Offset & BoundingBox
************************************************************/

void *UndoOrthoViewChangeScaleOffsetBoundingBoxNew(OrthoView *oview, float scale, float offset[3], float bboxCenter[3], float bboxSize[3])
{
	UndoOrthoViewChangeScaleOffsetBoundingBox *info = (UndoOrthoViewChangeScaleOffsetBoundingBox *)malloc(sizeof(UndoOrthoViewChangeScaleOffsetBoundingBox));
	info->orthoView		= oview;
	info->scale			= scale;
	info->offset[0]		= offset[0];
	info->offset[1]		= offset[1];
	info->offset[2]		= offset[2];
	info->bboxSize[0]	= bboxSize[0];
	info->bboxSize[1]	= bboxSize[1];
	info->bboxSize[2]	= bboxSize[2];
	info->bboxCenter[0]	= bboxCenter[0];
	info->bboxCenter[1]	= bboxCenter[1];
	info->bboxCenter[2]	= bboxCenter[2];
	return info;
}

void UndoOrthoViewChangeScaleOffsetBoundingBoxFn(void *info)
{
	UndoOrthoViewChangeScaleOffsetBoundingBox *undoInfo = (UndoOrthoViewChangeScaleOffsetBoundingBox *)info;
	undoInfo->orthoView->setScale(undoInfo->scale);
	undoInfo->orthoView->setOffset(undoInfo->offset);
	undoInfo->orthoView->setSceneBoundingBoxSize(undoInfo->bboxSize);
	undoInfo->orthoView->setSceneBoundingBoxCenter(undoInfo->bboxCenter);
}

/************************************************************
*	Create Primitive
************************************************************/

void *UndoOrthoViewCreatePrimitiveNew(TransformNode *transform)
{
	UndoOrthoViewCreatePrimitive *info = (UndoOrthoViewCreatePrimitive *)malloc(sizeof(UndoOrthoViewCreatePrimitive));

	info->transform			= transform;

	return info;

}

void UndoOrthoViewCreatePrimitiveFn(void *info)
{
	UndoOrthoViewCreatePrimitive *undoInfo = (UndoOrthoViewCreatePrimitive *)info;

	SceneGraph *sg = GetWorld()->getSceneGraph();
	if (sg->hasNode(undoInfo->transform) == true) {
		CtbGetTreeView()->deleteSceneGraphNode(undoInfo->transform);
		delete undoInfo->transform;
	}
}

/************************************************************
*	Delete Primitive
************************************************************/

void *UndoOrthoViewDeletePrimitiveNew(Node *parentNode, ShapeNode *shape)
{
	UndoOrthoViewDeletePrimitive *info = (UndoOrthoViewDeletePrimitive *)malloc(sizeof(UndoOrthoViewDeletePrimitive));

	info->parentNode	= parentNode;
	info->shape			= shape;

	return info;
}

void UndoOrthoViewDeletePrimitiveFn(void *info)
{
	UndoOrthoViewDeletePrimitive *undoInfo = (UndoOrthoViewDeletePrimitive *)info;

	SceneGraph *sg = GetWorld()->getSceneGraph();
	if (undoInfo->parentNode != NULL) {
		if (sg->hasNode(undoInfo->parentNode) == true)
			undoInfo->parentNode->addChildNode(undoInfo->shape);
	}
	else
		sg->addNode(undoInfo->shape);

	CtbGetTreeView()->addSceneGraphNode(undoInfo->shape, undoInfo->parentNode);
}

void UndoOrthoViewDeletePrimitiveFreeFn(void *info)
{
}

/************************************************************
*	TransformNode Translation
************************************************************/

void *UndoOrthoViewChangeTransformTranslationNew(TransformNode *transform, float translation[3])
{
	UndoOrthoViewChangeTransformTranslation *info = (UndoOrthoViewChangeTransformTranslation *)malloc(sizeof(UndoOrthoViewChangeTransformTranslation));

	info->transform			= transform;
	info->translation[0]	= translation[0];
	info->translation[1]	= translation[1];
	info->translation[2]	= translation[2];

	return info;
}

void UndoOrthoViewChangeTransformTranslationFn(void *info)
{
	UndoOrthoViewChangeTransformTranslation *undoInfo = (UndoOrthoViewChangeTransformTranslation *)info;

	SceneGraph *sg = GetWorld()->getSceneGraph();
	if (sg->hasNode(undoInfo->transform) == true)
		undoInfo->transform->setTranslation(undoInfo->translation);
}

/************************************************************
*	TransformNode Rotation
************************************************************/

void *UndoOrthoViewChangeTransformRotationNew(TransformNode *transform, float rotation[4])
{
	UndoOrthoViewChangeTransformRotation *info = (UndoOrthoViewChangeTransformRotation *)malloc(sizeof(UndoOrthoViewChangeTransformRotation));

	info->transform		= transform;
	info->rotation[0]	= rotation[0];
	info->rotation[1]	= rotation[1];
	info->rotation[2]	= rotation[2];
	info->rotation[3]	= rotation[3];

	return info;
}

void UndoOrthoViewChangeTransformRotationFn(void *info)
{
	UndoOrthoViewChangeTransformRotation *undoInfo = (UndoOrthoViewChangeTransformRotation *)info;

	SceneGraph *sg = GetWorld()->getSceneGraph();
	if (sg->hasNode(undoInfo->transform) == true)
		undoInfo->transform->setRotation(undoInfo->rotation);
}

/************************************************************
*	TransformNode Rotation
************************************************************/

void *UndoOrthoViewChangeTransformScaleNew(TransformNode *transform, float scale[3])
{
	UndoOrthoViewChangeTransformScale *info = (UndoOrthoViewChangeTransformScale *)malloc(sizeof(UndoOrthoViewChangeTransformScale));

	info->transform		= transform;
	info->scale[0]		= scale[0];
	info->scale[1]		= scale[1];
	info->scale[2]		= scale[2];

	return info;
}

void UndoOrthoViewChangeTransformScaleFn(void *info)
{
	UndoOrthoViewChangeTransformScale *undoInfo = (UndoOrthoViewChangeTransformScale *)info;

	SceneGraph *sg = GetWorld()->getSceneGraph();
	if (sg->hasNode(undoInfo->transform) == true)
		undoInfo->transform->setScale(undoInfo->scale);
}
