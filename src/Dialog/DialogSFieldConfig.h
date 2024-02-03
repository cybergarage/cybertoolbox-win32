/******************************************************************
*
*	VRML library for C++
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CFontInfo.h
*
******************************************************************/

#ifndef _CDIALOGSFFIELDCONFIG_H_
#define _CDIALOGSFFIELDCONFIG_H_

#include <stdio.h>

#include "Field.h"
#include "Node.h"

class DialogSFieldConfig {

	Node	*mNode;
	Field	*mField;
public:

	void	setNode(Node *node)		{ mNode = node; }
	Node	*getNode()				{ return mNode; }

	void	setField(Field *field)	{ mField = field; }
	Field	*getField()				{ return mField; }

	DialogSFieldConfig() {
		setNode(NULL);
		setField(NULL);
	}

	void setTitle(CDialog *dialog) {
		char title[256];
		sprintf(title, "%s : %s", getNode()->getType(), getField()->getName());
		dialog->SetWindowText(title);
	}
};

#endif
