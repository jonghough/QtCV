#ifndef LAPLACE_H
#define LAPLACE_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

Mat laplacian(const Mat& image, int kernalSize);

#endif // LAPLACE_H
