#ifndef CANNY_H
#define CANNY_H
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


/***
 *  Canny Edge detection algorithms.
 *
 * */


using namespace cv;
/**
 * Uses OpenCV canny edge detection function to create greyscale edge image
 * of the original image.
 * @brief cannyEdges
 * @param image
 * @param threshold1
 * @param threshold2
 * @return
 */
Mat cannyEdges(const Mat& image, double threshold1, double threshold2);
#endif // CANNY_H
