#ifndef WATERSHEDSEGMENTER_H
#define WATERSHEDSEGMENTER_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <exception>
#include <iostream>

/**
 * @brief The WatershedSegmenter class. Based on the example in
 * from OpenCV 2 Computer Vision
 * Application Cookbook.
 */
class WatershedSegmenter
{
private:
    cv::Mat _markers;


public:
    WatershedSegmenter();
    void setMarkers(const cv::Mat& image);
    cv::Mat process(const cv::Mat& image);
    cv::Mat getWatersheds();
};

#endif // WATERSHEDSEGMENTER_H
