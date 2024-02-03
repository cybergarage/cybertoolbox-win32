/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CModuleType.cpp
*
******************************************************************/
#include <iostream.h>
#include <fstream.h>
#include "CModuleType.h"
#include "StringFn.h"
#include "RegKey.h"
#include "File.h"
#include "World.h"

////////////////////////////////////////////////////////////
//	CModuleType::load
////////////////////////////////////////////////////////////

#define	LINE_LENGTH_MAX		256
#define	NAME_LENGTH_MAX		128

BOOL CModuleType::load(char *fname) 
{
	char	buffer[LINE_LENGTH_MAX];

	ifstream fin(fname);
	if (!fin)
		return FALSE;

	fin.ignore(LINE_LENGTH_MAX, '\n');

	char	className	[NAME_LENGTH_MAX];
	char	moduleName	[NAME_LENGTH_MAX];
	char	attribute	[NAME_LENGTH_MAX];
	char	scriptName	[NAME_LENGTH_MAX];
	char	iconName	[NAME_LENGTH_MAX];

	fin >> buffer >> className;
	fin >> buffer >> moduleName;
	fin >> buffer >> attribute;
	fin >> buffer >> scriptName;
	fin >> buffer >> iconName;

	setClassName(className);
	setName(moduleName);
	setAttribure(!StringCompare(attribute, MODULETYPE_ATTRIBUTE_SYSTEM_STRING) ? MODULETYPE_ATTRIBUTE_SYSTEM : MODULETYPE_ATTRIBUTE_USER);
	setScriptName(scriptName);
	setIconName(iconName);

	char	fieldType	[NAME_LENGTH_MAX];
	char	fieldName	[NAME_LENGTH_MAX];

	int	n;
	for (n=0; n<MODULE_INOUTNODE_MAXNUM; n++) {
		fin >> buffer >> fieldType >> fieldName;
		if (strcmp(fieldType, "NULL") != 0) {
			mEventInType[n]->setType(fieldType);
			mEventInType[n]->setName(fieldName);
		}
		else {
			mEventInType[n]->setType(fieldTypeNone);
			mEventInType[n]->setName(NULL);
		}
	}

	for (n=0; n<MODULE_INOUTNODE_MAXNUM; n++) {
		fin >> buffer >> fieldType >> fieldName;
		if (strcmp(fieldType, "NULL") != 0) {
			mEventOutType[n]->setType(fieldType);
			mEventOutType[n]->setName(fieldName);
		}
		else {
			mEventOutType[n]->setType(fieldTypeNone);
			mEventOutType[n]->setName(NULL);
		}
	}

	char	executionNode[NAME_LENGTH_MAX];
	fin >> buffer >> executionNode;
	(strcmp(executionNode, "TRUE") == 0) ? setExecutionNode(TRUE) : setExecutionNode(FALSE);

	// Default EventOut Route
	char	eventOutFieldTypeName[NAME_LENGTH_MAX];
	char	targetEventInFieldName[NAME_LENGTH_MAX];
	fin >> buffer >> eventOutFieldTypeName >> targetEventInFieldName;
/*
	setTargetNodeFieldTypeName(eventOutFieldTypeName);
	setTargetNodeFieldName(targetEventInFieldName);
*/	
	check();

	return TRUE;
}

GrIcon CModuleType::getIcon() 
{
	if (mIcon)
		return mIcon;

	mIcon = LoadIconFromFile(getIconName());
	if (!mIcon) {
		char	sysDirIcons		[FILE_MAX_PATHLEN];
		char	iconFilename[FILE_MAX_FILENAME];
		if (RegKeyGetValue(REGKEY_SECTION_PATHNAME, REGKEY_KEY_ICONS_PATHNAME, sysDirIcons) == FALSE)
			strcpy(sysDirIcons, "icons\\");
		sprintf(iconFilename, "%s\\%s%s", GetWorld()->getInitialDirectory(), sysDirIcons, getIconName());
		mIcon = LoadIconFromFile(iconFilename);
		assert(mIcon);
	}
	assert(mIcon);
	return mIcon;
}

////////////////////////////////////////////////////////////
//	CModuleType::save
////////////////////////////////////////////////////////////

BOOL CModuleType::save(char *fname) 
{
	if (!isOK())
		return FALSE;

	ofstream fout(fname);
	if (!fout)
		return FALSE;

	fout << "#CTB MODULETYPE V1.0" << endl;

	fout << "CLASSNAME " << ((getClassName() && strlen(getClassName()) > 0) ? getClassName() : "NULL") << endl; 
	fout << "MODULENAME " << ((getName() && strlen(getName()) > 0) ? getName() : "NULL") << endl; 
	fout << "ATTRIBUTE " << ((getAttribure() == MODULETYPE_ATTRIBUTE_SYSTEM) ? "SYSTEM" : "USER") << endl; 
	fout << "SCRIPTNAME " << ((getScriptName() && strlen(getScriptName()) > 0) ? getScriptName() : "NULL") << endl; 
	fout << "ICONNAME " << ((getIconName() && strlen(getIconName()) > 0) ? getIconName() : "NULL") << endl; 

	int	n;
	for (n=0; n<MODULE_INOUTNODE_MAXNUM; n++) {
		char *fieldTypeName	= mEventInType[n]->getTypeName();
		char *fieldName		 = mEventInType[n]->getName();
		fout << "EVENTIN" << n << " " << (fieldTypeName ? fieldTypeName : "NULL") << " " << (fieldName ? fieldName : "NULL") << endl; 
	}

	for (n=0; n<MODULE_INOUTNODE_MAXNUM; n++) {
		char *fieldTypeName	= mEventOutType[n]->getTypeName();
		char *fieldName		 = mEventOutType[n]->getName();
		fout << "EVENTOUT" << n << " " << (fieldTypeName ? fieldTypeName : "NULL") << " " << (fieldName ? fieldName : "NULL") << endl; 
	}

	fout << "EXECUTIONNODE " << (hasExecutionNode() ? "TRUE" : "FALSE") << endl; 
/*
	fout << "TARGETNODE " <<  getTargetNodeFieldTypeName() << " " << getTargetNodeFieldName() << endl; 
*/
	return TRUE;
}

BOOL CModuleType::save()
{
	char	sysDirScripts	[FILE_MAX_PATHLEN];
	char	sysDirModules	[FILE_MAX_PATHLEN];
	char	sysDirIcons		[FILE_MAX_PATHLEN];

	if (RegKeyGetValue(REGKEY_SECTION_PATHNAME, REGKEY_KEY_SCRIPTS_PATHNAME,	sysDirScripts) == FALSE)
		strcpy(sysDirScripts, "scripts\\");
	if (RegKeyGetValue(REGKEY_SECTION_PATHNAME, REGKEY_KEY_MODULES_PATHNAME,	sysDirModules) == FALSE)
		strcpy(sysDirModules, "modules\\");
	if (RegKeyGetValue(REGKEY_SECTION_PATHNAME, REGKEY_KEY_ICONS_PATHNAME,		sysDirIcons) == FALSE)
		strcpy(sysDirIcons, "icons\\");

	char	outFnameScripts	[FILE_MAX_FILENAME];
	char	outFnameModules	[FILE_MAX_FILENAME];
	char	outFnameIcons	[FILE_MAX_FILENAME];

	sprintf(outFnameModules, "%s%s%s.%s", sysDirModules, getClassName(), getName(), MODULE_FILE_EXTENTION);
	strcpy(outFnameScripts, getScriptName());	FileChangePathName(outFnameScripts, sysDirScripts);
	sprintf(outFnameIcons, "%s%s%s.%s", sysDirIcons, getClassName(), getName(), ICON_FILE_EXTENTION);

	// Copy a icon and script files into system directry.
	BOOL bCopiedScriptFile = FileCopy(getScriptName(), outFnameScripts);
	BOOL bCopiedIconFile = FileCopy(getIconName(), outFnameIcons);
	
	if (!bCopiedScriptFile || !bCopiedIconFile)
		return FALSE;

	// Strip the directory name in a icon and scrpit file name.
	char	scriptFilename	[FILE_MAX_FILENAME];
	char	iconFilename	[FILE_MAX_FILENAME];
	strcpy(scriptFilename, getScriptName());	FileStripPathName(scriptFilename);	setScriptName(scriptFilename);
	sprintf(iconFilename, "%s%s.%s", getClassName(), getName(), ICON_FILE_EXTENTION);	setIconName(iconFilename);

	// Save this module infomation into a file
	return save(outFnameModules);
}

////////////////////////////////////////////////////////////
//	CModuleType::compact
////////////////////////////////////////////////////////////

void CModuleType::compact(Field *field[]) 
{
	for (int n=0; n<MODULE_INOUTNODE_MAXNUM-1; n++) {
		if (!field[n]->getType() && field[n+1]->getType()) {
			for (int i=n; i<MODULE_INOUTNODE_MAXNUM-1; i++) {
				field[i]->setType(field[i+1]->getType());
				field[i]->setName(field[i+1]->getName());
			}
			field[(MODULE_INOUTNODE_MAXNUM-1)-n]->setType(fieldTypeNone);
			field[(MODULE_INOUTNODE_MAXNUM-1)-n]->setName(NULL);
		}
	}
}

void CModuleType::compact() 
{
	compact(mEventInType);
	compact(mEventOutType);
}

////////////////////////////////////////////////////////////
//	CModuleType::check
////////////////////////////////////////////////////////////

void CModuleType::check() 
{
	for (int n=0; n<MODULE_INOUTNODE_MAXNUM; n++) {
		if (getEventInFieldType(n) && !StringLength(getEventInFieldName(n)))
			setEventInFieldType(n, fieldTypeNone);
		if (getEventOutFieldType(n) && !StringLength(getEventOutFieldName(n)))
			setEventOutFieldType(n, fieldTypeNone);
	}
}

////////////////////////////////////////////////////////////
//	CModuleType::OK
////////////////////////////////////////////////////////////

BOOL CModuleType::isOK() 
{
	check();
	return TRUE;
}

////////////////////////////////////////////////////////////
//	CModuleType::List
////////////////////////////////////////////////////////////

CModuleType	*CModuleType::next(char *className)
{
	for (CModuleType *cmType=next(); cmType; cmType=cmType->next()) {
		if (!StringCompareIgnoreCase(cmType->getClassName(), className)) 
			return cmType;
	}
	return NULL;
}

////////////////////////////////////////////////////////////
//	CModuleType::getNEventInFields
////////////////////////////////////////////////////////////

int CModuleType::getNEventInFields()
{
	int nEventIn = 0;
	for (int n=0; n<MODULE_INOUTNODE_MAXNUM; n++) {
		if (getEventInFieldType(n))
			nEventIn++;
	}

	return nEventIn;
}

////////////////////////////////////////////////////////////
//	CModuleType::getNEventOutFields
////////////////////////////////////////////////////////////

int CModuleType::getNEventOutFields()
{
	int nEventOut = 0;
	for (int n=0; n<MODULE_INOUTNODE_MAXNUM; n++) {
		if (getEventOutFieldType(n))
			nEventOut++;
	}

	return nEventOut;
}
