/******************************************************************
*
*	VRML library for C++
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CFontInfo.h
*
******************************************************************/

#ifndef _CFONTINFO_H_
#define _CFONTINFO_H_

#include "afxwin.h"

enum {
FONT_TYPE_NONE,
FONT_TYPE_SCENEGRAPH,
FONT_TYPE_DIAGRAM,
FONT_TYPE_ORTHOVIEW,
};

#define REGKEY_SECTION_FONT				"Font"
#define REGKEY_KEY_SCENEGRAPH_FONT		"SceneGraph"
#define REGKEY_KEY_DIAGRAM_FONT			"Diagram"
#define REGKEY_KEY_ORTHOVIEW_FONT		"OrthoView"

typedef struct {
char	name[64];
int		size;
int		bold;
int		italic;
int		underLine;
} FontInfo;

class CFontInfo { 

	int		mType;
public:

	CFontInfo(int type) {
		setType(type);
	}

	~CFontInfo() {
	}
	
	////////////////////////////////////////////////
	// Type
	////////////////////////////////////////////////

	void	setType(int type)		{ mType = type; }
	int		getType()				{ return mType; }
	char	*getTypeString();

	////////////////////////////////////////////////
	// CWnd
	////////////////////////////////////////////////

	void getInfo(FontInfo *fontInfo);
	void setInfo(FontInfo *fontInfo);
	void getInfo(LOGFONT *lf);
	void setInfo(LOGFONT *lf);
};

#endif

