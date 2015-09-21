#include "laplace.h"
using namespace cv;

Mat laplacian(const Mat& image, int kernalSize){
    Mat gray;
    if(image.channels() == 3)
        cvtColor(image,gray,CV_BGR2GRAY);
    else image.copyTo(gray);
    Mat dst;
    Laplacian( gray, dst, CV_8U, kernalSize, 1, 0, BORDER_DEFAULT );
    return dst;
}
