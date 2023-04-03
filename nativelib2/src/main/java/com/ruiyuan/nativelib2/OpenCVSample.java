package com.ruiyuan.nativelib2;

import android.graphics.Bitmap;

public class OpenCVSample {

    private static boolean isLoadSuccess = false;

    static {
        try {
            System.loadLibrary("native-lib");
        } catch (Throwable throwable) {
            throwable.printStackTrace();
        }
    }

    public static native void createMat(Bitmap bitmap);

}
