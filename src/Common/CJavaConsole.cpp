/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CJavaConsole.cpp
*
******************************************************************/

#include <assert.h>
#include "CJavaConsole.h"

CJavaConsole::CJavaConsole(JNIEnv *env)
{
	jniEnv = env;

	classid			= jniEnv->FindClass("SystemOutput");
	initMethodid	= jniEnv->GetMethodID(classid, "<init>", "()V");
	deleteMethodid	= jniEnv->GetMethodID(classid, "delete", "()V");

	assert(classid && initMethodid && deleteMethodid);

	object = NULL;
	open();
}

CJavaConsole::~CJavaConsole()
{
	close();
}

void CJavaConsole::open()
{
	if (!object) {
		object = jniEnv->NewObject(classid, initMethodid);
		jniEnv->NewGlobalRef(object);
	}
}

void CJavaConsole::close()
{
	if (object) {
		jniEnv->CallVoidMethod(object, deleteMethodid);
		jniEnv->DeleteGlobalRef(object);
		object = NULL;
	}
}
