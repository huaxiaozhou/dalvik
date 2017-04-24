#include <stdio.h>
#include <jni.h>
#include <stdlib.h>
#include<android/log.h>
#define LOG_TAG "System.out.c"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(fmt, args...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, fmt, ##args)

jstring Java_com_example_test_MainActivity_nativeMalloc(JNIEnv* env) {
	void * p = malloc(150 * 1024 * 1024);
	LOGI("malloc 150M Bytes memory");

	if (p != NULL) {
		//memory will not used without calling memset()
		memset(p, 0, 150 * 1024 * 1024);
		LOGI("malloc success");
	} else{
		LOGI("malloc fail");
	}
//	free(p); //free memory
}
