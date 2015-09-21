#include "Canny.h"

using namespace cv;

/**
 * @brief cannyEdges - Edge detection, from OpenCV 2 Computer Vision
 * Application Cookbook.
 * @param image
 * @param threshold1
 * @param threshold2
 * @return
 */
Mat cannyEdges(const Mat& image, double threshold1, double threshold2){
    Mat gray, out;
    if(threshold2 < threshold1)
        threshold2 = threshold1;
    if(image.channels() == 3)
        cvtColor(image,gray,CV_BGR2GRAY);
    else image.copyTo(gray);
    cv::Canny(gray, out, threshold1, threshold2);
    Mat outInv;
    threshold(out, outInv,128,255,cv::THRESH_BINARY_INV);
    return outInv;
}
