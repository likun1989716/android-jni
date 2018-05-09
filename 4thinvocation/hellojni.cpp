#include "jni.h"
#include <stdio.h>

//JNI本地原型函数
void printHelloNative(JNIEnv *env, jobject obj);
void printStringNative(JNIEnv *env, jobject obj, jstring string);
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved)
{	
	jclass cls;
	JNINativeMethod nm[2];
	JNIEnv* env = NULL;
	jint result;
	//验证是否支持JNI_VERSION_1_4
	printf("JNI_Onload call\n");
	if(vm->GetEnv((void**) &env, JNI_VERSION_1_4) != JNI_OK) {
		printf("Error");
		return JNI_ERR;
	}
	cls = env->FindClass("HelloJNI");
	nm[0].name = "printHello";
	nm[0].signature = "()V";
	nm[0].fnPtr = (void *)printHelloNative;
	
	nm[1].name = "printString";
	nm[1].signature = "(Ljava/lang/String;)V";
	nm[1].fnPtr = (void *)printStringNative;
	printf("JNI_Onload finish\n");
	env->RegisterNatives(cls, nm, 2);
	return JNI_VERSION_1_4;
	
}
//添加名称为env和object的两个参数
void printHelloNative(JNIEnv *env, jobject obj)
{
	printf("HELLO WORLD\n");
	return;
}
void printStringNative(JNIEnv *env, jobject obj, jstring string)
{
	const char *str = env->GetStringUTFChars(string,0);
	printf("%s!\n",str);
	return;
}
