/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class SystemOutput */

#ifndef _Included_SystemOutput
#define _Included_SystemOutput
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     SystemOutput
 * Method:    createJavaConsole
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_SystemOutput_createJavaConsole
  (JNIEnv *, jobject);

/*
 * Class:     SystemOutput
 * Method:    output
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_SystemOutput_output__I
  (JNIEnv *, jobject, jint);

/*
 * Class:     SystemOutput
 * Method:    output
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_SystemOutput_output__Ljava_lang_String_2
  (JNIEnv *, jobject, jstring);

/*
 * Class:     SystemOutput
 * Method:    deleteJavaConsole
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_SystemOutput_deleteJavaConsole
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif