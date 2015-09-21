#ifndef CORNERFINDER_H
#define CORNERFINDER_H

#include <opencv2/opencv.hpp>
#include <stdlib.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


/***
 *  Corner detection and related algorithms.
 *
 * */

/**
 * @brief showCorners
 * @param image
 * @return Image with detected corners marked.
 */
cv::Mat showCorners(const cv::Mat& image);

/**
 * @brief colorNearCorners
 * @param image
 * @param cornerpoints
 * @return Image with only areas around detected corners shown from the original image.
 */
cv::Mat colorNearCorners(const cv::Mat& image, std::vector<cv::Point2d> cornerpoints);
#endif // CORNERFINDER_H
