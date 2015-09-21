#ifndef PIXELATE_H
#define PIXELATE_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


/***
 *  Algorithms for the pixelation of an image Mat.
 *
 * */

using namespace cv;
/**
 * @brief pixelate
 * @param image
 * @param squareSize
 * @return Pixelated Mat
 */
Mat pixelate(const Mat& image, int squareSize);

#endif // PIXELATE_H
