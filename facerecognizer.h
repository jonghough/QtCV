#ifndef FACERECOGNIZER_H
#define FACERECOGNIZER_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
class facerecognizer
{
public:
    facerecognizer();
    Mat normalizeImg(const Mat& image);
};

#endif // FACERECOGNIZER_H
