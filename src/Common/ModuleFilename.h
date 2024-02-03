/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	ModuleFilename.h
*
******************************************************************/

#ifndef _MODULEFILENAME_H_
#define _MODULEFILENAME_H_

#include "SceneGraph.h"

class CModuleFilename {
	String	mFilename;

public:

	CModuleFilename(char *filename) {
		mFilename.setValue(filename);
	}

	char *getFilename(void) {
		return mFilename.getValue();
	}
};

void	ModuleFilenameInitialize(void);
void	ModuleFilenameDelete(void);
int		GetNModuleFilenames(void);
char	*GetModuleFilename(int n);

#endif
