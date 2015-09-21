#ifndef FILTERS_H
#define FILTERS_H
#include "QString"
#include <QSize>
#include "qdebug.h"
#include <QLabel>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "Cartoonifier.h"
#include "cornerfinder.h"
#include "sobel.h"
#include "watershed.h"
#include "Canny.h"
#include "morpher.h"
#include "grabcut.h"
#include "pixelate.h"
#include "rippleeffect.h"
#include "projectivetransforms.h"

class filters
{
private:
    cv::Mat _image;
    /**
     * @brief refit Refits the Mat image to the size of the widget, keeping the proportions
     * correct.
     * @param widgetSize
     * @param image
     * @return
     */
    cv::Mat refit(QSize widgetSize, cv::Mat& image);
public:
    /**
     * @brief filters
     * @param qImage
     */
    filters(QLabel& qImage, QString);
    /**
     * Save a QImage object to JPEG file.
     * @brief saveImage
     * @param image
     * @param filename
     * @return
     */
    enum Modify { BARREL, FISHEYE, CARTOON, CANNY, SOBEL, PIXELATE, GRABCUT, RIPPLE, PROJECTIVE };
    void setMainImage(QLabel& qImage);
    void modifyImage(QLabel& qImage, Modify mod);
    bool saveImage(QImage& image, QString filename);

};

#endif // FILTERS_H
