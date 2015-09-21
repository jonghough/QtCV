#ifndef FEATUREDETECTOR_H
#define FEATUREDETECTOR_H
#include <vector>
#include <opencv2/opencv.hpp>
#include "opencv2/core.hpp"
#include <stdio.h>
#include <iostream>
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
class featuredetector
{
private:
    Mat _image1, _image2;
public:
    featuredetector(Mat image1, Mat image2);
    Mat testFeatures();
};

#endif // FEATUREDETECTOR_H
