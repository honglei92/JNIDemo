//
// Created by Admin on 2019/7/15.
//

#include <string.h>
#include "com_example_jnidemo_jni_NDKTools.h"
#include "android/log.h"
#include "FileLog.h"

#define TAG "ndkdemotest"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__)

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_jnidemo_jni_NDKTools_getStringFromNDK
        (JNIEnv *env, jclass obj) {
    return env->NewStringUTF("数据分析师--十二周高强度实战项目");
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_jnidemo_jni_NDKTools_accessFiled(JNIEnv *env, jobject instance) {
    // TODO native调用java
    jclass cls = env->GetObjectClass(instance);
    jfieldID fid = env->GetFieldID(cls, "s", "Ljava/lang/String;");
    jstring jstr = static_cast<jstring>(env->GetObjectField(instance, fid));
    char *c_str = (char *) env->GetStringUTFChars(jstr, JNI_FALSE);
    LOGD("收到Java层: %s", c_str);
    DEBUG_E("aaaaaaaaa: %s", c_str);
    DEBUG_W("aaaaaaaaa: %s", c_str);
    DEBUG_D("aaaaaaaaa: %s", c_str);
    DEBUG_I("aaaaaaaaa: %s", c_str);
    char text[20] = "jianpan";

    strcat(text, c_str);

    return env->NewStringUTF(c_str);
}