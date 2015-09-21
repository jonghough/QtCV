#include "grabcut.h"
using namespace cv;

/**
 * @brief grabForeground
 * Algorithm from OpenCV 2 Computer Vision Application
 * Programming Cookbook.
 * @param image
 * @return Foreground of original image.
 */
Mat grabForeground(const Mat& image){
    cv::Rect rectangle(1,1,image.cols-1, image.rows-1);

    Mat result;
    Mat bgModel, fgModel; //background and foreground
    // grabcut
    grabCut(image, result, rectangle, bgModel, fgModel, 10, GC_INIT_WITH_RECT);

    compare(result, GC_PR_FGD, result, CMP_EQ);
    Mat foreground(image.size(), CV_8UC3, Scalar(255,255,255));
    image.copyTo(foreground,result);
    return foreground;
}

/**
 * @brief grabBackground
 * Gets the background of an image using GrabCut algorithm.
 * Algorithm from OpenCV 2 Computer Vision Application
 * Programming Cookbook.
 * @param image
 * @return background of original image.
 */
Mat grabBackground(const Mat& image){
    cv::Rect rectangle(1,1,image.cols-1, image.rows-1);

    Mat result;
    Mat bgModel, fgModel; //background and foreground
    // grabcut
    grabCut(image, result, rectangle, bgModel, fgModel, 10, GC_INIT_WITH_RECT);

    compare(result, GC_PR_FGD, result, CMP_NE);
    Mat background(image.size(), CV_8UC3, Scalar(255,255,255));
    image.copyTo(background,result);
    return result;
}
