package com.ruiyuan.opencvapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Bundle;
import android.util.Log;


import com.ruiyuan.nativelib2.OpenCVSample;

import java.nio.ByteBuffer;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        showImg();

    }

    private void showImg(){
      Bitmap bitmap= BitmapFactory.decodeResource(getResources(),R.drawable.gaussian_current_navigatge);
      //调用opencv java
//        OpenCVNativeLoader  loader=new OpenCVNativeLoader();
//        loader.init();
//       int count= bitmap.getByteCount();
//        ByteBuffer byteBuffer=ByteBuffer.allocateDirect(count);
//        bitmap.copyPixelsToBuffer(byteBuffer);
//        Mat  mat=new Mat(bitmap.getWidth(),bitmap.getHeight(), CvType.CV_8UC4,byteBuffer);
//        Log.i("tag","-------------------------"+mat.channels()+"---"+mat.cols()+"--"+mat.rows());
        //调用opencv native
        OpenCVSample.createMat(bitmap);
    }

}