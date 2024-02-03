/******************************************************************
*
*	VRML library for C++
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	OpenGLFn.h
*
******************************************************************/

#ifndef _OPENGLFN_H_
#define _OPENGLFN_H_

#include <windows.h>   
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>
#include "SceneGraph.h"

enum {
OGL_RENDERING_WIRE,
OGL_RENDERING_SHADE,
OGL_RENDERING_TEXTURE,
};

HGLRC			OpenGLSetup( HWND hWnd );
void			OpenGLSetSize(SceneGraph *sceneGraph, int width, int height); 
void			DrawIdxFaceSet(IndexedFaceSetNode *idxFaceSet);
void			DrawSceneGraph(SceneGraph *sceneGraph, int drawMode);
void			DrawSceneGraphForSelection(SceneGraph *sceneGraph);
void			DrawShape(ShapeNode *shape);
ShapeNode		*PickShapeNode(SceneGraph *sceneGraph, int mx, int my);

#endif
