#ifndef _CUNDOACTIONFN_H_
#define _CUNDOACTIONFN_H_

#include "CDiagram.h"
#include "CModule.h"
#include "Field.h"

/************************************************************
*
*	Diagram
*
************************************************************/

/************************************************************
*	Add
************************************************************/

typedef struct {
	TransformNode	*mpDiagramNode;
	ScriptNode		*mpNode;
} UndoDiagramModuleAdd;

void *UndoDiagramModuleAddNew(TransformNode *dgmNode, ScriptNode *node);
void UndoDiagramModuleAddFn(void *info);

/************************************************************
*	Move
************************************************************/

typedef struct {
	ScriptNode	*mNode;
	int			mx, my;
} UndoDiagramModuleMove;

void *UndoDiagramModuleMoveNew(ScriptNode *node, int x, int y);
void UndoDiagramModuleMoveFn(void *info);

/************************************************************
*	Move (SelectingBox)
************************************************************/

typedef struct {
	int			mnModule;
	ScriptNode	**mNode;
	int			*mx;
	int			*my;
} UndoDiagramModuleMoveInSelectingBox;

void *UndoDiagramModuleMoveInSelectingBoxNew(int nModule, ScriptNode **node, int *x, int *y);
void UndoDiagramModuleMoveInSelectingBoxActionFn(void *info);
void UndoDiagramModuleMoveInSelectingBoxFreeFn(void *info);

/************************************************************
*	Delete
************************************************************/

typedef struct {
	Node	*mInNode;
	Field	*mInField;
	Node	*mOutNode;
	Field	*mOutField;
} RouteInfo;

typedef struct { 
	TransformNode	*mpDiagramNode;
	ScriptNode		*mpNode;
	int			mnRouteInfo;
	RouteInfo	*maRouteInfo;
} UndoDiagramModuleDelete;

void UndoDiagramModuleDeleteActionFn(void *info);
void UndoDiagramModuleDeleteFreeFn(void *info);
void *UndoDiagramModuleDeleteNew(TransformNode *diagramNode, ScriptNode *node);

/************************************************************
*	Cut
************************************************************/

class CDiagramClipboard;

typedef struct { 
	TransformNode		*mpDiagramNode;
	CDiagramClipboard	*mpClipboard;
} UndoDiagramModuleCut;

void UndoDiagramModuleCutActionFn(void *info);
void UndoDiagramModuleCutFreeFn(void *info);
void *UndoDiagramModuleCutNew(TransformNode *diagramNode, CDiagramClipboard *clipboard);

/************************************************************
*	Paste
************************************************************/

class CDiagramClipboard;

typedef struct { 
	TransformNode	*mpDiagramNode;
	int				mnScriptNode;
	ScriptNode		**mpScriptNode;
	int				mnRoute;
	Route			**mpRoute;
} UndoDiagramModulePaste;

void UndoDiagramModulePasteActionFn(void *info);
void UndoDiagramModulePasteFreeFn(void *info);
void *UndoDiagramModulePasteNew(TransformNode *dgmNode, int nModuleNode, ScriptNode **moduleNode, int nRoute, Route **route);

/************************************************************
*	Create Input Line
************************************************************/

typedef struct { 
	ScriptNode	*mInModule;
	Field		*mInField;
	ScriptNode	*mOutModule;
	Field		*mOutField;
} UndoDiagramModuleCreateInputLine;

void UndoDiagramModuleCreateInputLineFn(void *info);
void *UndoDiagramModuleCreateInputLineNew(ScriptNode *inModule, Field *inField, ScriptNode *outModule, Field *outField);

/************************************************************
*	Delete Input Line
************************************************************/

typedef struct { 
	ScriptNode	*mInModule;
	Field		*mInField;
	ScriptNode	*mOutModule;
	Field		*mOutField;
} UndoDiagramModuleDeleteInputLine;

void UndoDiagramModuleDeleteInputLineFn(void *info);
void *UndoDiagramModuleDeleteInputLineNew(ScriptNode *inModule, Field *inField, ScriptNode *outModule, Field *outField);

/************************************************************
*
*	OrthoView
*
************************************************************/

class	OrthoView;
class	TransformNode;

/************************************************************
*	Scale
************************************************************/

typedef struct { 
	OrthoView	*orthoView;
	float		scale;
} UndoOrthoViewChangeScale;

void *UndoOrthoViewChangeScaleNew(OrthoView *oview, float scale);
void UndoOrthoViewChangeScaleFn(void *info);

/************************************************************
*	Offset
************************************************************/

typedef struct { 
	OrthoView	*orthoView;
	float		offset[3];
} UndoOrthoViewChangeOffset;

void *UndoOrthoViewChangeOffsetNew(OrthoView *oview, float offset[3]);
void UndoOrthoViewChangeOffsetFn(void *info);

/************************************************************
*	Scale & Offset
************************************************************/

typedef struct { 
	OrthoView	*orthoView;
	float		scale;
	float		offset[3];
} UndoOrthoViewChangeScaleOffset;

void *UndoOrthoViewChangeScaleOffsetNew(OrthoView *oview, float scale, float offset[3]);
void UndoOrthoViewChangeScaleOffsetFn(void *info);

/************************************************************
*	Scale & Offset
************************************************************/

typedef struct { 
	OrthoView	*orthoView;
	float		scale;
	float		offset[3];
	float		bboxCenter[3];
	float		bboxSize[3];
} UndoOrthoViewChangeScaleOffsetBoundingBox;

void *UndoOrthoViewChangeScaleOffsetBoundingBoxNew(OrthoView *oview, float scale, float offset[3], float bboxCenter[3], float bboxSize[3]);
void UndoOrthoViewChangeScaleOffsetBoundingBoxFn(void *info);

/************************************************************
*	Create Primitive
************************************************************/

typedef struct { 
	TransformNode	*transform;
} UndoOrthoViewCreatePrimitive;

void *UndoOrthoViewCreatePrimitiveNew(TransformNode *transform);
void UndoOrthoViewCreatePrimitiveFn(void *info);

/************************************************************
*	Delete Primitive
************************************************************/

typedef struct { 
	Node		*parentNode;
	ShapeNode	*shape;
} UndoOrthoViewDeletePrimitive;

void *UndoOrthoViewDeletePrimitiveNew(Node *parentNode, ShapeNode *shape);
void UndoOrthoViewDeletePrimitiveFn(void *info);
void UndoOrthoViewDeletePrimitiveFreeFn(void *info);

/************************************************************
*	TransformNode Translation
************************************************************/

typedef struct { 
	TransformNode	*transform;
	float		translation[3];
} UndoOrthoViewChangeTransformTranslation;

void *UndoOrthoViewChangeTransformTranslationNew(TransformNode *transform, float translation[3]);
void UndoOrthoViewChangeTransformTranslationFn(void *info);

/************************************************************
*	TransformNode Rotation
************************************************************/

typedef struct { 
	TransformNode	*transform;
	float		rotation[4];
} UndoOrthoViewChangeTransformRotation;

void *UndoOrthoViewChangeTransformRotationNew(TransformNode *transform, float rotation[4]);
void UndoOrthoViewChangeTransformRotationFn(void *info);

/************************************************************
*	TransformNode Scale
************************************************************/

typedef struct { 
	TransformNode	*transform;
	float		scale[4];
} UndoOrthoViewChangeTransformScale;

void *UndoOrthoViewChangeTransformScaleNew(TransformNode *transform, float scale[3]);
void UndoOrthoViewChangeTransformScaleFn(void *info);

#endif
