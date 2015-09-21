#include "rippleeffect.h"
using namespace cv;


/**
 * @brief rippleEffect
 * @param image
 * @return
 */
Mat rippleEffect(const Mat& image){
    int cols, rows;
    cols = image.cols;
    rows = image.rows;
    Mat dvIm;
    image.copyTo(dvIm);


    int lastX = cols, lastY = rows;

    float midX = 0.5f * (float) (lastX);
    float midY = 0.5f * (float) (lastY);


    float maxR = sqrt(
                (cols - midX) * (cols - midX) + (rows - midY) * (rows - midY));
    for (int i = 0; i < lastX; i++) {
        for (int j = 0; j < lastY; j++) {

            float radius = sqrt(
                        (i - midX) * (i - midX) + (j - midY) * (j - midY));
            if (radius <= 0)
                continue;
            if (i == 0)
                continue;


            float theta = atan2((float) (j - midY), ((float) (i - midX)));
            //float maxDist = maxR;


            radius = radius + 20 * sin(0.1f * radius);

            int ii = (int) (radius * cos(theta)) + midX;
            int jj = (int) (radius * sin(theta)) + midY;

            ii = ii < 0 ? i : (ii >= lastX ? i : ii);
            jj = jj < 0 ? j : (jj >= lastY ? j : jj);

            dvIm.at < cv::Vec3b > (j, i)[0] = image.at < cv::Vec3b
                    > (jj, ii)[0];

            dvIm.at < cv::Vec3b > (j, i)[1] = image.at < cv::Vec3b
                    > (jj, ii)[1];

            dvIm.at < cv::Vec3b > (j, i)[2] = image.at < cv::Vec3b
                    > (jj, ii)[2];
        }
    }
    return dvIm;
}
