#include <jni.h>
#include <string.h>
#include "include/libgodemo.h"


JNIEXPORT jstring JNICALL
Java_com_ejin_ndk_MainActivity_stringFromJNI(JNIEnv *env, jobject instance, jstring s_) {
    const char *s = (*env)->GetStringUTFChars(env, s_, 0);

    GoString goString;
    goString.p = s;
    goString.n = strlen(s);

    return (*env)->NewStringUTF(env, hello(goString));
}