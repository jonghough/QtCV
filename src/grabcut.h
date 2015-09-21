#ifndef GRABCUT_H
#define GRABCUT_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

/***
 * Algorithms for separating and grabbing foregorund and background components
 * of an image.
 * */
/**
 * @brief grabForeground
 * @param image
 * @return Foregrround image
 */
Mat grabForeground(const Mat& image);
/**
 * @brief grabBackground
 * @param image
 * @return background image.
 */
Mat grabBackground(const Mat& image);
#endif // GRABCUT_H
