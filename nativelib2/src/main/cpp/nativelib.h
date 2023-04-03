#include <jni.h>
#include <android/log.h>
#include <android/bitmap.h>

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>

#define TAG    "NativeLibSample"
#define AndroidLOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)

extern "C"
JNIEXPORT void JNICALL
Java_com_ruiyuan_nativelib2_OpenCVSample_createMat(
        JNIEnv* env,
jclass thiz, jobject bitmap);

void bitmapToMat(JNIEnv *env, jobject bitmap, cv::Mat &dst);
