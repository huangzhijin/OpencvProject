#include "nativelib.h"
#include <jni.h>

extern "C"
JNIEXPORT void JNICALL
Java_com_ruiyuan_nativelib2_OpenCVSample_createMat(
        JNIEnv
        *env,
        jclass thiz, jobject
        bitmap) {
    cv::Mat rgbMat;
// 把java层的bitmap转换为Mat
    bitmapToMat(env, bitmap, rgbMat
    );
// log输出Mat的信息
    AndroidLOGD("native mat channels:%d, cols:%d, rows:%d", rgbMat.

            channels(), rgbMat.cols, rgbMat.rows);
}

void bitmapToMat(JNIEnv *env, jobject
bitmap,
                 cv::Mat &dst
) {
    AndroidBitmapInfo info;
    void *pixels = 0;
    try {
        CV_Assert(AndroidBitmap_getInfo(env, bitmap, &info)
                  >= 0);
        CV_Assert(info
                          .format == ANDROID_BITMAP_FORMAT_RGBA_8888 ||
                  info.format == ANDROID_BITMAP_FORMAT_RGB_565);
        CV_Assert(AndroidBitmap_lockPixels(env, bitmap, &pixels)
                  >= 0);
        CV_Assert(pixels);
        dst.
                create(info
                               .height, info.width, CV_8UC4);
        if (info.format == ANDROID_BITMAP_FORMAT_RGBA_8888) {
            cv::Mat tmp(info.height, info.width, CV_8UC4, pixels);
            tmp.
                    copyTo(dst);
        } else {
            cv::Mat tmp(info.height, info.width, CV_8UC2, pixels);
            cvtColor(tmp, dst, CV_BGR5652RGBA
            );
        }
        AndroidBitmap_unlockPixels(env, bitmap
        );
        return;
    } catch (...) {
        AndroidBitmap_unlockPixels(env, bitmap
        );
        jclass je = env->FindClass("java/lang/Exception");
        env->
                ThrowNew(je,
                         "Unknown exception in JNI code {nBitmapToMat}");
        return;
    }
}

