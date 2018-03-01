//
// Created by ntddung on 3/1/18.
//

#include <jni.h>
#include <string>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <android/log.h>

using  namespace cv;
using namespace std;

extern "C"
{
JNIEXPORT jstring JNICALL
Java_com_example_ntddung_camera_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    return env->NewStringUTF(hello.c_str());
}
JNIEXPORT jint JNICALL Java_com_example_ntddung_camera_MainActivity_getPixelJNI(JNIEnv *env, jobject, long addrImage ) {
      cv::Mat* pInputImage = (cv::Mat*)addrImage;
      int pixel = (int)pInputImage->at<unsigned char>(10, 10);
      return pixel;
}
}
