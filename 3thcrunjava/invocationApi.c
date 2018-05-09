#include <jni.h>
int main()
{
	JavaVMInitArgs vm_args;
	JavaVMOption options;
	jint res;
	JNIEnv *env;
	JavaVM *vm;
	jclass cls;
	jmethodID mid;
	jstring jstr;
	jclass stringClass;
	jobjectArray args;

	//1.生成java虚拟机选项
	options.optionString = "-Djava.class.path=.";
	vm_args.version = 0x00010002;
	vm_args.options = &options;
	vm_args.nOptions = 1;
	vm_args.ignoreUnrecognized = JNI_TRUE;
	
	//2.生成java虚拟机
	res = JNI_CreateJavaVM(&vm, (void**)&env, &vm_args);
	
	//3. 查找并加载类
	cls = (*env)->FindClass(env, "InvocationApiTest");
	
	//4. 获取main()方法ID
	mid = (*env)->GetStaticMethodID(env, cls, "main", "([Ljava/lang/String;)V");
	
	//5.生成字符串对象，用作main方法的参数
	jstr = (*env)->NewStringUTF(env,"Hello Invocation API!!");
	stringClass = (*env)->FindClass(env, "java/lang/String");
	args = (*env)->NewObjectArray(env, 1, stringClass, jstr);
	
	//6. 调用main方法
	(*env)->CallStaticVoidMethod(env, cls, mid, args);
	
	//7. 销毁Java虚拟机
	(*vm)->DestroyJavaVM(vm);
}
