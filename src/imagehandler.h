#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QMainWindow>
#include <QLabel>

/**
 * @brief The ImageHandler class containing functions for dealing with
 * image resizing, OpenCV format to QT format etc.
 */
class ImageHandler
{

public:
    ImageHandler();
    /**
     * @brief handleImage
     * Select image from file and return Mat.
     * @param window
     * @return The mat of the selected image.
     */
    cv::Mat handleImage(QWidget* window);
    /**
     * @brief setImage
     * Sets the OpenCV Mat iamge to a QLabel widget with the correct image format.
     * @param qLabel
     * @param image
     * @param imageFormat
     */
    void setImage(QLabel& qLabel, cv::Mat image, QImage::Format imageFormat);
    /**
     * @brief refit
     * Resizes the OpenCV Mat to fit inside the QSize of some widget. Scale to fit, not stretch.
     * @param widgetSize
     * @param image
     * @return Scaled Mat of original image.
     */
    cv::Mat refit(QSize widgetSize, cv::Mat& image);
    /**
     * @brief saveImage
     * Saves the image to file.
     * @param image
     */
    void saveImage(const cv::Mat& image);
};



#endif // IMAGEHANDLER_H
