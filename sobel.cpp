
#include "sobel.h"
/**
 * @brief sobelFilter - taken mostly from OpenCV 2 Computer Vision
 * Application Programming Cookbook, page~ 153.
 * @param image
 * @return filtered image
 */
Mat sobelFilter(const Mat& image){
    cv::Mat sx,sy;
    cv::Sobel(image,sx, CV_16S, 1, 0);
    cv::Sobel(image,sy, CV_16S, 0, 1);

    cv::Mat sobel;
    sobel = abs(sx)+abs(sy);
    double min,max;
    cv::minMaxLoc(sobel, &min, &max);
    cv::Mat out;
    sobel.convertTo(out, CV_8U, -255./max,255);
    return out;
}

/**
 * @brief sobelFilter - taken mostly from OpenCV 2 Computer Vision
 * Application Programming Cookbook, page~ 153.
 * @param image
 * @return filtered image
 */
Mat sobelFilterThreshold(const Mat& image, const int threshold1, const int maxVal){
    cv::Mat sx,sy;
    cv::Sobel(image,sx, CV_16S, 1, 0);
    cv::Sobel(image,sy, CV_16S, 0, 1);

    cv::Mat sobel;
    sobel = abs(sx)+abs(sy);
    double min,max;
    cv::minMaxLoc(sobel, &min, &max);
    cv::Mat out;
    sobel.convertTo(out, CV_8U, -255./max,255);
    cv::threshold(out, out, threshold1, maxVal, cv::THRESH_BINARY);
    return out;
}
