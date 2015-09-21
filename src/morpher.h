#ifndef MORPHER_H
#define MORPHER_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

/***
 * Algorithms for non-affine, non-projective morphing of the original
 * image. e.g Barrel view etc.
 *
 * */

/**
 * @brief barrel
 * Barrel view  morph of image.
 * @param image
 * @return the modified image.
 */
Mat barrel(const Mat& image);
/**
 * @brief fishEye
 * FishEye view morph of image
 * @param image
 * @return modified image.
 */
Mat fishEye(const Mat& image);

#endif // MORPHER_H
