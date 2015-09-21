#include "imagehandler.h"
#include <QString>
#include <stdlib.h>
#include <QFileDialog>
#include <QImage>
#include "QWidget"
#include "QLabel"
#include <QDebug>
using namespace cv;

ImageHandler::ImageHandler()
{
}

/**
 * @brief ImageHandler::handleImage
 * @param window
 * @return
 */
cv::Mat ImageHandler::handleImage(QWidget* window){
    QString filename = QFileDialog::getOpenFileName(window, QMainWindow::tr("open image"),".",QMainWindow::tr("Image Files(*.jpg)"));
    std::string stdStr = filename.toStdString();
    cv::String fn = cv::String(stdStr.c_str());
    cv::Mat in = cv::imread(fn,CV_LOAD_IMAGE_UNCHANGED);
    return in;
    //http://docs.opencv.org/doc/tutorials/features2d/feature_flann_matcher/feature_flann_matcher.html
}

/**
 * @brief ImageHandler::setImage
 * @param qLabel
 * @param image
 */
void ImageHandler::setImage(QLabel& qLabel, cv::Mat image, QImage::Format imageFormat){
    cv::Mat convertIm;
    //convert to RGB for QT labels
    if(image.channels() > 1)
        cv::cvtColor(image, convertIm, CV_BGR2RGB);
    else
        convertIm = image;
    //refit the Mat to fit inside the QLabel
    convertIm = refit(qLabel.size(), convertIm);
    QImage im = QImage((const unsigned char*) (convertIm.data),
                       convertIm.cols, convertIm.rows,convertIm.step, imageFormat);
    qLabel.setPixmap(QPixmap::fromImage(im));
    qLabel.resize( qLabel.pixmap()->size());
}

/**
 * @brief ImageHandler::refit
 * Refits the Image to scale within the bounds of the QSize.
 * @param widgetSize
 * @param image
 * @return
 */
cv::Mat ImageHandler::refit(QSize widgetSize, cv::Mat& image){
    float wr = image.cols * 1.f / widgetSize.width();
    float hr = image.rows * 1.f / widgetSize.height();
    if( wr > hr){
        cv::Mat out;
        cv::resize(image, out, cv::Size(widgetSize.width(),(int) (image.rows * 1.f / wr)));
        return out;
    }
    else{
        cv::Mat out;
        cv::resize(image, out, cv::Size((int)(image.cols * 1.f / hr), widgetSize.height()));
        return out;
    }
}

/**
 * @brief ImageHandler::saveImage
 * @param image
 */
void ImageHandler::saveImage(const cv::Mat& image){
    QImage::Format f = QImage::Format_RGB888;
    qDebug()<<"channels";
    qDebug()<<image.channels();
    if(image.channels() == 1)
        f = QImage::Format_Indexed8;

    QImage qi((const unsigned char*) (image.data), image.cols, image.rows, image.step, f);

    qi.save("saved_image.jpg","JPEG");

}
