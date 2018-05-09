#include "JniFuncMain.h"
JNIEXPORT jobject JNICALL Java_JniFuncMain_createJniObject(JNIEnv *env, jclass clazz)
{
	jfieldID fid;
	jint a;
	jclass targetClass;
	jmethodID mid;
	jint result;
	jobject newObject;
	//获取JniFuncMain的成员变量
	fid = env->GetStaticFieldID(clazz, "a", "I");
	a = env->GetStaticIntField(clazz, fid);
	printf("[cpp]获取jniFuncMain的a值为%d\n", a);
	
	//查找生成对象的类
	targetClass = env->FindClass("JniTest");
	
	//查找构造方法ID
	mid = env->GetMethodID(targetClass, "<init>", "(I)V");
	
	//生成JniTest对象（返回对象的引用）
	printf("[cpp]生成JniTest对象\n");
	newObject = env->NewObject(targetClass, mid, 100);
	
	//调用对象的方法
	mid = env->GetMethodID(targetClass, "callByNative", "(I)I");
	result = env->CallIntMethod(newObject, mid, 200);
	
	//设置JniObject对象的b值
	fid = env->GetFieldID(targetClass, "b", "I");
	printf("[cpp]设置JniTest的b值为200\n");
	env->SetIntField(newObject, fid, result);
	//返回对象的引用
	return newObject;
}
