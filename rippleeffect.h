#ifndef RIPPLEEFFECT_H
#define RIPPLEEFFECT_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <math.h>



/**
 * @brief rippleEffect
 * Returns a distorted copy of original image with ripples outward from center.
 * @param image
 * @return
 */
cv::Mat rippleEffect(const cv::Mat& image);
#endif // RIPPLEEFFECT_H
