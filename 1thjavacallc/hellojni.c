#include "HelloJNI.h"
#include <stdio.h>
//添加名称为env和object的两个参数
JNIEXPORT void JNICALL Java_HelloJNI_printHello(JNIEnv *env, jobject obj)
{
	printf("HELLO WORLD");
	return;
}
JNIEXPORT void JNICALL Java_HelloJNI_printString(JNIEnv *env, jobject obj, jstring string)
{
	const char *str = (*env)->GetStringUTFChars(env,string,0);
	printf("%s!\n",str);
	return;
}