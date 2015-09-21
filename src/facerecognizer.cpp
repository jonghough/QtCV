#include "facerecognizer.h"
using namespace cv;
facerecognizer::facerecognizer()
{
}


Mat facerecognizer::normalizeImg(const Mat& image){
    Mat dst;

       switch(image.channels()) {
       case 1:
           cv::normalize(image, dst, 0, 255, NORM_MINMAX, CV_8UC1);
           break;
       case 3:
           cv::normalize(image, dst, 0, 255, NORM_MINMAX, CV_8UC3);
           break;
       default:
           image.copyTo(dst);
           break;
       }
       return dst;
}
