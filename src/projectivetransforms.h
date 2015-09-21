#ifndef PROJECTIVETRANSFORMS_H
#define PROJECTIVETRANSFORMS_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
Mat transformA(const Mat& image);
Mat transformB(const Mat& image);

#endif // PROJECTIVETRANSFORMS_H
