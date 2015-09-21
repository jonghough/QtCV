#include "filters.h"

/**
 * @brief filters::filters
 * @param qImage
 * @param filename
 */
filters::filters(QLabel& qImage, QString filename)
{
    std::string stdStr = filename.toStdString();
    cv::String fn = cv::String(stdStr.c_str());
    cv::Mat image = cv::imread(fn,CV_LOAD_IMAGE_UNCHANGED);
    _image = image;

}

/**
 * @brief filters::setMainImage
 * @param qImage
 */
void filters::setMainImage(QLabel& qImage){
    cv::cvtColor(_image, _image, CV_BGR2RGB);
    cv::Mat scaledIm = refit(qImage.size(),_image);
    QImage imx = QImage((const unsigned char*) (scaledIm.data), scaledIm.cols,
                        scaledIm.rows,scaledIm.step, QImage::Format_RGB888);

    qImage.setPixmap(QPixmap::fromImage(imx));
    qImage.resize(qImage.pixmap()->size());
}


/**
 * @brief filters::modifyImage
 * Modify the given image based on the type of modification given by the Modify enum.
 * Shows the modified image in QLabel widget.
 * @param qImage
 * @param mod
 */
void filters::modifyImage(QLabel& qImage, filters::Modify mod){
    cv::Mat image2;
    QImage im;
    switch(mod){
    case BARREL:
        image2 = barrel(_image);
        image2 = refit(qImage.size(),image2);
        im = QImage((const unsigned char*) (image2.data), image2.cols, image2.rows,image2.step, QImage::Format_RGB888);

        break;
    case FISHEYE:
        image2 = fishEye(_image);
        image2 = refit(qImage.size(),image2);
        im = QImage((const unsigned char*) (image2.data), image2.cols, image2.rows,image2.step, QImage::Format_RGB888);

        break;
    case CARTOON:
        image2 = cartoonfiyImage2(_image);
        image2 = refit(qImage.size(),image2);

        im = QImage((const unsigned char*) (image2.data), image2.cols, image2.rows,image2.step, QImage::Format_RGB888);
        break;
    case CANNY:
        image2 = cannyEdges(_image,185,255);
        image2 = refit(qImage.size(),image2);

        im = QImage((const unsigned char*) (image2.data), image2.cols, image2.rows,image2.step, QImage::Format_Indexed8);
        break;
    case SOBEL:
        image2 = sobelFilter(_image);
        image2 = refit(qImage.size(),image2);

        im = QImage((const unsigned char*) (image2.data), image2.cols, image2.rows,image2.step, QImage::Format_RGB888);
        break;
    case PIXELATE:
        image2 = pixelate(_image, 10);
        image2 = refit(qImage.size(),image2);

        im = QImage((const unsigned char*) (image2.data), image2.cols, image2.rows,image2.step, QImage::Format_RGB888);
        break;
    case GRABCUT:
        image2 = grabForeground(_image);
        image2 = refit(qImage.size(),image2);

        im = QImage((const unsigned char*) (image2.data), image2.cols, image2.rows,image2.step, QImage::Format_RGB888);
        break;
    case RIPPLE:
        image2 = rippleEffect(_image);
        image2 = refit(qImage.size(),image2);
        im = QImage((const unsigned char*) (image2.data), image2.cols, image2.rows,image2.step, QImage::Format_RGB888);
        break;
    case PROJECTIVE:
        image2 = transformA(_image);
        image2 = refit(qImage.size(),image2);
        im = QImage((const unsigned char*) (image2.data), image2.cols, image2.rows,image2.step, QImage::Format_RGB888);
        break;

    }

    qImage.setPixmap(QPixmap::fromImage(im));
    qImage.resize(qImage.pixmap()->size());
}

/**
 * @brief filters::saveImage
 * @param image
 * @param filename
 * @return
 */
bool filters::saveImage(QImage& image, QString filename){
    return image.save(filename,"JPEG");
}


/**
 * @brief filters::refit
 * @param widgetSize
 * @param image
 * @return
 */
cv::Mat filters::refit(QSize widgetSize, cv::Mat& image){
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
