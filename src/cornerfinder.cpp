#include "cornerfinder.h"

/**
 * @brief sobelFilter - taken mostly from OpenCV 2 Computer Vision
 * Application Programming Cookbook, page~ 192.
 * @param image
 * @return
 */
cv::Mat showCorners(const cv::Mat& image){
    const int max_corners = 25;
   // setTrackbarPos("Max no. of corners", "Corners", max_corners);
    cv::Mat im2;
    float quality = 0.01;
    int min_distance = 2;
    cv::cvtColor(image,im2, CV_BGR2GRAY);
    std::vector<cv::Point2d> corners;

    cv::goodFeaturesToTrack(im2, corners, max_corners, quality, min_distance);

    // Draw the corners as little circles
    cv::Mat image_corners = im2.clone();
    for(int i = 0; i < corners.size(); i++) {
        circle(image_corners, corners[i], 4, CV_RGB(255, 0, 0), -1);
    }
    return colorNearCorners(image, corners);
    //return image_corners;
}


cv::Mat colorNearCorners(const cv::Mat& image, std::vector<cv::Point2d> cornerpoints){
    cv::Mat dvIm;
    image.copyTo(dvIm);
    int sz = (int)cornerpoints.size();
    const int cols = image.cols;
    const int rows = image.rows;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            bool close = false;
            for(int k = 0; k < sz; k++){
                cv::Point2d p2d = cornerpoints.at(k);

                const float d = sqrt((i - p2d.x) * (i - p2d.x) + (j -p2d.y) * (j - p2d.y));
                if(d < 30.f){
                    dvIm.at < cv::Vec3b > (j, i)[0] = image.at < cv::Vec3b
                            > (j,i)[0];

                    dvIm.at < cv::Vec3b > (j, i)[1] = image.at < cv::Vec3b
                            > (j,i)[1];

                    dvIm.at < cv::Vec3b > (j, i)[2] = image.at < cv::Vec3b
                            > (j,i)[2];
                    close = true;
                    break;
                }

            }
            if(close == false){
                dvIm.at < cv::Vec3b > (j, i)[0] = 0;
                dvIm.at < cv::Vec3b > (j, i)[1] = 0;
                dvIm.at < cv::Vec3b > (j, i)[2] = 0;
            }

        }
    }
    return dvIm;
}
