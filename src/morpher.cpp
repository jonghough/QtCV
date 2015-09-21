
#include "morpher.h"
#include "math.h"

using namespace cv;

/***
 * These are not standard fishEye or barrel lens algorithms.
 * */

/**
 * @brief fishEye lens effect.
 * @param image
 * @return
 */
Mat fishEye(const Mat& image){
        int cols, rows;
        cols = image.cols;
        rows = image.rows;
        Mat dvIm;
        image.copyTo(dvIm);

        int lastX = cols, lastY = rows;

        float midX = 0.5f * (float) (lastX);
        float midY = 0.5f * (float) (lastY);

        float cornerAngle = atan2(((float) (rows - midY)), (float) (cols - midX));
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
                float a = midX * midX;
                float b = midY * midY;
                float theta = atan2((float) (j - midY), ((float) (i - midX)));
                float theta2 = atan2((float)abs((float) (j - midY)), (float)abs(((float) (i - midX))));

                float hang = (cols * 0.5f) / (float)cos(theta2);

                float maxDist;
                if(theta2 < cornerAngle){
                    maxDist = hang;
                }
                else{
                    maxDist = (rows * 0.5f) / (float)cos((3.14159f/2.f)-theta2);
                }

                radius = 0.8f * radius * radius / (maxDist) + 0.2f * radius;

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


/**
 * @brief barrel
 * @param image
 * @return
 */
Mat barrel(const Mat& image){
        int cols, rows;
        cols = image.cols;
        rows = image.rows;
        Mat dvIm;
        image.copyTo(dvIm);
        int lastX = cols, lastY = rows;

        float midX = 0.5f * (float) (lastX);
        float midY = 0.5f * (float) (lastY);

        float cornerAngle = atan2(((float) (rows - midY)), (float) (cols - midX));
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
                float a = midX * midX;
                float b = midY * midY;
                float theta = atan2((float) (j - midY), ((float) (i - midX)));
                float theta2 = atan2((float)abs((float) (j - midY)), (float)abs(((float) (i - midX))));

                float hang = (cols * 0.5f) / (float)cos(theta2);

                float maxDist;
                if(theta2 < cornerAngle){
                    maxDist = hang;
                }
                else{
                    maxDist = (rows * 0.5f) / (float)cos((3.14159f/2.f)-theta2);
                }

                radius = -0.8f * radius * radius / (maxDist) + 1.8f * radius;

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
