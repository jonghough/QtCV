#ifndef CARTOONIFIER_H
#define CARTOONIFIER_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

/***
 *  Cartoonifier algorithms.
 *
 *
 * */

/**
 *
 * @brief cartoonfiyImage
 * Returns a cartoonified version of the original image.
 * @param image
 */
cv::Mat cartoonfiyImage( const cv::Mat& image);

cv::Mat cartoonfiyImage2(const cv::Mat& image);

#endif // CARTOONIFIER_H
