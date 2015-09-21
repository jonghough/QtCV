#ifndef WATERSHED_H
#define WATERSHED_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

cv::Mat segmentImage(const cv::Mat& image);
#endif // WATERSHED_H
