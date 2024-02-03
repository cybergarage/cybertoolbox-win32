/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	CJavaConsole.h
*
******************************************************************/

#ifndef _CJAVACONSOLE_H_
#define _CJAVACONSOLE_H_

#include <jni.h>

class CJavaConsole {

	JNIEnv		*jniEnv;
	jclass		classid;
	jmethodID	initMethodid;
	jmethodID	deleteMethodid;
	jobject		object;

public:

	CJavaConsole(JNIEnv *env);

	~CJavaConsole();

	void open();
	void close();
};

#endif
