/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CModuleType.h
*
******************************************************************/
#ifndef _CMODULETYPE_H_
#define _CMODULETYPE_H_

#include <assert.h>
#include "Common.h"
#include "String.h"
#include "LinkedList.h"
#include "Field.h"
#include "Icon.h"

#define MODULE_INOUTNODE_MAXNUM		4

#define MODULE_FILE_EXTENTION		"mod"
#define ICON_FILE_EXTENTION			"ico"

enum {
MODULETYPE_ATTRIBUTE_SYSTEM,
MODULETYPE_ATTRIBUTE_USER,
};

#define MODULETYPE_ATTRIBUTE_SYSTEM_STRING	"SYSTEM"
#define MODULETYPE_ATTRIBUTE_USER_STRING	"USER"

////////////////////////////////////////////////////////////
//	Module Type File Format
////////////////////////////////////////////////////////////

/**********************************************************

  =====================================

  #CTB MODULETYPE V1.0

  CLASSNAME		className
  MODULENAME	moduleName
  ATTRIBUTE		attributeType
  SCRIPTNAME	scriptFileName
  ICONNAME		iconFileName

  EVENTIN0		fieldType	filedName
  EVENTIN1		fieldType	filedName
  EVENTIN2		fieldType	filedName
  EVENTIN3		fieldType	filedName

  EVENTOUT0		fieldType	filedName
  EVENTOUTl		fieldType	filedName
  EVENTOUT2		fieldType	filedName
  EVENTOUT3		fieldType	filedName

  EXECUTIONNODE	(TURE | FALSE)

  TARGETNODE	thisEventOutFieldTypeName targetEventInFieldName

  =====================================

  attributeType	:	SYSTEM
				|	USER
				;

  fieldType		:	SFBool
				|	SFColor	
				|	SFFloat	
				|	SFImage	
				|	SFInt32	
				|	SFRotation	
				|	SFString	
				|	SFVec2f	
				|	SFVec3f	
				;

**********************************************************/


class CModuleType : public LinkedListNode<CModuleType> {
public:
	String	mClassName;
	String	mName;
	String	mIconName;
	String	mScriptName;
	Field	*mEventInType[MODULE_INOUTNODE_MAXNUM];
	Field	*mEventOutType[MODULE_INOUTNODE_MAXNUM];
	BOOL	mExecutionNode;
	GrIcon	mIcon;
	int		mAttribure;

	// Default EventOut Route
	String	mTargetNodeFieldTypeName;
	String	mTargetNodeFieldName;

public:

	CModuleType() {
		setHeaderFlag(0);
		for (int n=0; n<MODULE_INOUTNODE_MAXNUM; n++) {
			mEventInType[n] = new Field();
			mEventOutType[n] = new Field();
			setEventInField(n, NULL, fieldTypeNone);
			setEventOutField(n, NULL, fieldTypeNone);
		}
		setExecutionNode(FALSE);
		mIcon = NULL;
/*
		setTargetNodeFieldName("NONE");
		setTargetNodeFieldTypeName("NONE");
*/
	}

	~CModuleType()	{
		for (int n=0; n<MODULE_INOUTNODE_MAXNUM; n++) {
			delete mEventInType[n];
			delete mEventOutType[n];
		}
	}

	////////////////////////////////////////
	//	Class Name
	////////////////////////////////////////

	void setClassName(char *className) {
		mClassName.setValue(className);
	}

	char *getClassName() {
		return mClassName.getValue();
	}

	////////////////////////////////////////
	//	 Name
	////////////////////////////////////////

	void setName(char *name) {
		mName.setValue(name);
	}

	char *getName() {
		return mName.getValue();
	}

	////////////////////////////////////////
	//	 Attribure
	////////////////////////////////////////

	void setAttribure(int attr) {
		mAttribure = attr;
	}

	int getAttribure() {
		return mAttribure;
	}

	////////////////////////////////////////
	//	Icon Name
	////////////////////////////////////////

	void setIconName(char *iconName) {
		mIconName.setValue(iconName);
		if (mIcon) {
			delete mIcon;
			mIcon = NULL;
		}
	}

	char *getIconName() {
		return mIconName.getValue();
	}

	////////////////////////////////////////
	//	Script Name
	////////////////////////////////////////

	void setScriptName(char *scriptName) {
		mScriptName.setValue(scriptName);
	}

	char *getScriptName() {
		return mScriptName.getValue();
	}

	////////////////////////////////////////
	//	EventIn Type
	////////////////////////////////////////

	void setEventInField(int n, char *name, int type) {
		assert(0 <= n && n < MODULE_INOUTNODE_MAXNUM);
		mEventInType[n]->setName(name);
		mEventInType[n]->setType(type);
	}

	void setEventInField(int n, char *name, char *type) {
		assert(0 <= n && n < MODULE_INOUTNODE_MAXNUM);
		mEventInType[n]->setName(name);
		mEventInType[n]->setType(type);
	}

	void setEventInFieldName(int n, char *name) {
		assert(0 <= n && n < MODULE_INOUTNODE_MAXNUM);
		mEventInType[n]->setName(name);
	}

	void setEventInFieldType(int n, int type) {
		assert(0 <= n && n < MODULE_INOUTNODE_MAXNUM);
		mEventInType[n]->setType(type);
	}

	void setEventInFieldType(int n, char *type) {
		assert(0 <= n && n < MODULE_INOUTNODE_MAXNUM);
		mEventInType[n]->setType(type);
	}

	char *getEventInFieldName(int n) {
		assert(0 <= n && n < MODULE_INOUTNODE_MAXNUM);
		return mEventInType[n]->getName();
	}

	int getEventInFieldType(int n) {
		assert(0 <= n && n < MODULE_INOUTNODE_MAXNUM);
		return mEventInType[n]->getType();
	}

	Field *getEventInField(int n) {
		assert(0 <= n && n < MODULE_INOUTNODE_MAXNUM);
		return mEventInType[n];
	}

	int getNEventInFields();

	bool hasEventInFields() {
		return (0 < getNEventInFields()) ? true : false;
	}

	////////////////////////////////////////
	//	EventOut Type
	////////////////////////////////////////

	void setEventOutField(int n, char *name, int type) {
		assert(0 <= n && n < MODULE_INOUTNODE_MAXNUM);
		mEventOutType[n]->setName(name);
		mEventOutType[n]->setType(type);
	}

	void setEventOutField(int n, char *name, char *type) {
		assert(0 <= n && n < MODULE_INOUTNODE_MAXNUM);
		mEventOutType[n]->setName(name);
		mEventOutType[n]->setType(type);
	}

	void setEventOutFieldName(int n, char *name) {
		assert(0 <= n && n < MODULE_INOUTNODE_MAXNUM);
		mEventOutType[n]->setName(name);
	}

	void setEventOutFieldType(int n, char *type) {
		assert(0 <= n && n < MODULE_INOUTNODE_MAXNUM);
		mEventOutType[n]->setType(type);
	}

	void setEventOutFieldType(int n, int type) {
		assert(0 <= n && n < MODULE_INOUTNODE_MAXNUM);
		mEventOutType[n]->setType(type);
	}

	char *getEventOutFieldName(int n) {
		assert(0 <= n && n < MODULE_INOUTNODE_MAXNUM);
		return mEventOutType[n]->getName();
	}

	int getEventOutFieldType(int n) {
		assert(0 <= n && n < MODULE_INOUTNODE_MAXNUM);
		return mEventOutType[n]->getType();
	}

	Field *getEventOutField(int n) {
		assert(0 <= n && n < MODULE_INOUTNODE_MAXNUM);
		return mEventOutType[n];
	}

	int getNEventOutFields();

	bool hasEventOutNode() {
		return (0 < getNEventOutFields()) ? true : false;
	}

	////////////////////////////////////////
	//	Execution Node
	////////////////////////////////////////

	void setExecutionNode(BOOL bvalue) {
		mExecutionNode = bvalue;
	}

	BOOL hasExecutionNode() {
		return mExecutionNode;
	}

	////////////////////////////////////////
	//	File
	////////////////////////////////////////

	BOOL	load(char *filename);
	GrIcon	getIcon();
	BOOL	save(char *filename);
	BOOL	save();

	////////////////////////////////////////
	//	Compact
	////////////////////////////////////////

	void compact(Field *field[]);
	void compact();

	////////////////////////////////////////
	//	OK?
	////////////////////////////////////////

	void	check();
	BOOL	isOK();

	////////////////////////////////////////
	//	List
	////////////////////////////////////////

	CModuleType	*next(char *className);
	
	CModuleType	*next()	{
		return LinkedListNode<CModuleType>::next();
	}

	////////////////////////////////////////
	//	Target Node
	////////////////////////////////////////
/*
	void setTargetNodeFieldTypeName(char *name) {
		mTargetNodeFieldTypeName.setValue(name);
	}
	char *getTargetNodeFieldTypeName() {
		return mTargetNodeFieldTypeName.getValue();
	}
	int getTargetNodeFieldType() {
		Field field;
		field.setType(getTargetNodeFieldTypeName());
		return field.getType();
	}

	void setTargetNodeFieldName(char *name) {
		mTargetNodeFieldName.setValue(name);
	}
	char *getTargetNodeFieldName() {
		return mTargetNodeFieldName.getValue();
	}
*/
};

#endif
