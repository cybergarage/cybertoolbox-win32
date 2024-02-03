/******************************************************************
*
*	CyberToolBox
*
*	Copyright (C) Satoshi Konno 1996-1997
*
*	File:	SystemOutput.c
*
******************************************************************/

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <jni.h>
#include "SystemOutput.h"

/*
 * Class:     SystemOutput
 * Method:    createJavaConsole
 * Signature: ()V
 */

static HANDLE	gConsoleHandle;

JNIEXPORT void JNICALL Java_SystemOutput_createJavaConsole(
JNIEnv		*env,
jobject		object)
{
	AllocConsole();
	SetConsoleTitle("JAVA CONSOLE");
	gConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

/*
 * Class:     SystemOutput
 * Method:    output
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_SystemOutput_output__I(
JNIEnv		*env,
jobject		object,
jint		ivalue)
{
	char	cvalue;
	DWORD value;

	cvalue = (char)ivalue;
	WriteConsole(gConsoleHandle, &cvalue, 1, &value, NULL);
}

/*
 * Class:     SystemOutput
 * Method:    output
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_SystemOutput_output__Ljava_lang_String_2(
JNIEnv		*env,
jobject		object,
jstring		string)
{
	const char *str;
	DWORD value;
	str = (*env)->GetStringUTFChars(env, string, NULL);
	if (str && strlen(str)) 
		WriteConsole(gConsoleHandle, str, strlen(str), &value, NULL);
	(*env)->ReleaseStringUTFChars(env, string, str);
}

/*
 * Class:     SystemOutput
 * Method:    deleteJavaConsole
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_SystemOutput_deleteJavaConsole(
JNIEnv		*env,
jobject		object)
{
	FreeConsole();
}


