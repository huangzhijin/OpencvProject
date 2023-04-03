// empty
#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_org_opencv_NativeLib_stringFromJNI(
        JNIEnv* env,
        jobject
 ) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}