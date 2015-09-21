#include "projectivetransforms.h"

/**
 * Projective transform of the original image, using
 * cv::warpPerspective( ... ) function.
 * @brief transformA
 * @param image
 * @return
 */
Mat transformA(const Mat& image){
    Mat pMat;
    std::vector<Point2f> inputs;
    std::vector<Point2f> outputs;
    inputs.push_back(Point2f(0,0));
    inputs.push_back(Point2f(image.cols*1.0f,-image.rows * 0.5f));
    inputs.push_back(Point2f(image.cols*1.0f,image.rows*1.5f));
    inputs.push_back(Point2f(0,image.rows));

    outputs.push_back(Point2f(0,0));
    outputs.push_back(Point2f(image.cols,0));
    outputs.push_back(Point2f(image.cols,image.rows));
    outputs.push_back(Point2f(0, image.rows));

    pMat = Mat::zeros( image.rows, image.cols, image.type() );
    pMat = getPerspectiveTransform( inputs, outputs );
    cv::Mat dst;
    cv::warpPerspective(image,dst,pMat,image.size());
    return dst;
}

/**
 * Projective transform of the original image, using
 * cv::warpPerspective( ... ) function.
 * @brief transformB
 * @param image
 * @return
 */
Mat transformB(const Mat& image){
    Mat pMat;
    std::vector<Point2f> inputs;
    std::vector<Point2f> outputs;
    inputs.push_back(Point2f(0,-image.rows * 0.5f));
    inputs.push_back(Point2f(image.cols*1.0f,0));
    inputs.push_back(Point2f(image.cols*1.0f,image.rows));
    inputs.push_back(Point2f(0,image.rows*1.5f));

    outputs.push_back(Point2f(0,0));
    outputs.push_back(Point2f(image.cols,0));
    outputs.push_back(Point2f(image.cols,image.rows));
    outputs.push_back(Point2f(0, image.rows));

    pMat = Mat::zeros( image.rows, image.cols, image.type() );
    pMat = getPerspectiveTransform( inputs, outputs );
    cv::Mat dst;
    cv::warpPerspective(image,dst,pMat,image.size());
    return dst;
}



