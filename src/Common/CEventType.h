/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CEvenTypet.h
*
******************************************************************/

#ifndef _CEVNETTYPE_H_
#define _CEVNETTYPE_H_

#include "SceneGraph.h"
#include "String.h"
#include "LinkedListNode.h"
#include "StringFn.h"

#define CTB_EVENTTYPE_FILENAME						"CTBEVENTTYPE.DEF"

/* The event type must be matched to CTB_EVENTTYPE_FILENAME */
enum {
CTB_EVENTTYPE_START,
CTB_EVENTTYPE_FRAME,
CTB_EVENTTYPE_CLOCK,
CTB_EVENTTYPE_PICKUP,
CTB_EVENTTYPE_AREA,
CTB_EVENTTYPE_DRAG,
CTB_EVENTTYPE_TIMER,
};

enum {
CTB_EVENATTRIBUTE_SYSTEM,
CTB_EVENATTRIBUTE_USER,
};

#define CTB_EVENTATTRIBUTE_SYSTEM_STRING			"SYSTEM"
#define CTB_EVENTATTRIBUTE_USER_STRING				"USER"

#define CTB_EVENT_CLASSNAME_SYSTEM_STRING			"System"

#define CTB_MODULE_SYSTEM_EVENTIN_STRING			"SYSTEM_EVENTIN"

/* Start Event (System Event) */
#define CTB_EVENTTYPE_START_SCRIPT_NAME				"SystemStart.class"
#define CTB_EVENTTYPE_START_SCRIPT_EVENTIN_NAME		"EVENT_START_TIME"
#define CTB_EVENTTYPE_START_SCRIPT_EVENTOUT_NAME	"EVENT_START_ENABLED"

/* Timer Event (User Event) */
#define CTB_EVENTTYPE_TIMER_SCRIPT_NAME				"SystemSetTimer.class"
#define CTB_EVENTTYPE_TIMER_SCRIPT_VALUE_NAME		"EVENT_TIMER_VALUE"
#define CTB_EVENTTYPE_TIMER_SCRIPT_EVENTIN_NAME		"EVENT_TIMER_EVENTIN"
#define CTB_EVENTTYPE_TIMER_SCRIPT_STARTTIME_NAME	"EVENT_TIMER_STARTTIME"
#define CTB_EVENTTYPE_TIMER_SCRIPT_STOPTIME_NAME	"EVENT_TIMER_STOPTTIME"

////////////////////////////////////////////////////////////
//	Event Type File Format
////////////////////////////////////////////////////////////

/**********************************************************

  ==========================================================

  #CTB EVENTTYPE V1.0

  EVENTTYPENAME EVENATTRIBUTE SENSORNODETYPE EVENTFIELDTYPE EVENTFIELDNAME
  ............. ............. .............. .............. ..............

  ==========================================================

  EVENATTRIBUTE		:	"SYSTEM"
					|	"USER"
					;

  SENSORNODETYPE	:	CylinderSensor
					|	PlaneSesor
					|	ProximitySesor
					|	SphereSesor
					|	TimeSesor
					|	TouchSesor
					|	VisibilitySesor
					|	TimeSesor
					;

  EVENTFIELDTYPE	:	SFBool
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

class CEventType : public LinkedListNode<CEventType> {
	
	String		mName;
	String		mNodeTypeName;
	int			mEventAttributeType;
	int			mEventFieldType;
	String		mEventFieldName;
	String		mEventModuleFieldName;

public:

	CEventType(char *name, int attributeType, char *nodeTypeName, int fieldType, char *fieldName) {
		setName(name);
		setNodeTypeName(nodeTypeName);
		setFieldType(fieldType);
		setFieldName(fieldName);
		setModuleFieldName();
	}

	CEventType(char *name, char *attributeTypeName, char *nodeTypeName, char *fieldTypeName, char *fieldName) {
		setName(name);
		setAttributeType(!StringCompareIgnoreCase("SYSTEM", attributeTypeName) ? CTB_EVENATTRIBUTE_SYSTEM : CTB_EVENATTRIBUTE_USER);
		setNodeTypeName(nodeTypeName);
		Field	field;
		field.setType(fieldTypeName);
		setFieldType(field.getType());
		setFieldName(fieldName);
		setModuleFieldName();
	}

	//////////////////////////////////////////////////
	// Name
	//////////////////////////////////////////////////

	void	setName(char *name)			{mName.setValue(name);}
	char	*getName()					{return mName.getValue();}

	//////////////////////////////////////////////////
	// Attribute Type
	//////////////////////////////////////////////////

	void	setAttributeType(int type)		{mEventAttributeType = type;}
	int		getAttributeType()				{return mEventAttributeType;}
	char	*getAttributeTypeString()		{return (mEventAttributeType == CTB_EVENATTRIBUTE_SYSTEM) ? 
												CTB_EVENTATTRIBUTE_SYSTEM_STRING : CTB_EVENTATTRIBUTE_USER_STRING;}

	//////////////////////////////////////////////////
	// Node Name
	//////////////////////////////////////////////////

	void	setNodeTypeName(char *name)	{mNodeTypeName.setValue(name);}
	char	*getNodeTypeName()			{return mNodeTypeName.getValue();}

	//////////////////////////////////////////////////
	// Field Type
	//////////////////////////////////////////////////

	void	setFieldType(int type)		{mEventFieldType = type;}
	int		getFieldType()				{return mEventFieldType;}

	//////////////////////////////////////////////////
	// Field Name
	//////////////////////////////////////////////////

	void	setFieldName(char *name)	{mEventFieldName.setValue(name);}
	char	*getFieldName()				{return mEventFieldName.getValue();}

	//////////////////////////////////////////////////
	// Moudle Field Name
	//////////////////////////////////////////////////

	void	setModuleFieldName()	{
		char	eventOutFieldName[256];
		sprintf(eventOutFieldName, "%s_%s_%s_%s", CTB_MODULE_SYSTEM_EVENTIN_STRING, getName(), getNodeTypeName(), getFieldName());
		mEventModuleFieldName.setValue(eventOutFieldName);
	}

	char	*getModuleFieldName() {
		return mEventModuleFieldName.getValue();
	}

};

#endif