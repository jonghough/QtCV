#ifndef SOBEL_H
#define SOBEL_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

/***
 *  Sobel algorithms.
 *
 * */

/**
 * @brief sobelFilter
 * @param image
 * @return Sobel image.
 */
Mat sobelFilter(const Mat& image);

/**
 * @brief sobelFilterThreshold
 * @param image
 * @param threshold1
 * @param maxVal
 * @return Sobel image.
 */
Mat sobelFilterThreshold(const Mat& image, const int threshold1, const int maxVal);
#endif
