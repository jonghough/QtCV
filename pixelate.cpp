#include "pixelate.h"

using namespace cv;

/**
 * @brief pixelate
 * Pixelates the image with the given pixel square size.
 * @param image
 * @param squareSize
 * @return pixelated mat.
 */
Mat pixelate(const Mat& image, int squareSize) {
    cv::Mat out;
    image.copyTo(out);

    int cols, rows;
    cols = image.cols;
    rows = image.rows;
    int colsplit = cols / squareSize;
    int rowsplit = rows / squareSize;
    for (int i = 0; i < cols; i += squareSize) {
        for (int j = 0; j < rows; j += squareSize) {
            cv::Vec3b vecs[3];

            int finalCol =
                    i + colsplit - 1 >= cols ? cols - 1 : i + colsplit - 1;
            int finalRow =
                    j + rowsplit - 1 >= rows ? rows - 1 : j + rowsplit - 1;

            int halfCol = (int) (0.5f * (i + finalCol));
            int halfRow = (int) (0.5f * (j + finalRow));

            vecs[0] = out.at < cv::Vec3b > (j, i);
            vecs[1] = out.at < cv::Vec3b > (halfRow, halfCol);
            vecs[2] = out.at < cv::Vec3b > (finalRow, finalCol);

            int b = vecs[0][0];
            int g = vecs[0][1];
            int r = vecs[0][2];

            for (int k = i; k < i + squareSize; k++) {
                for (int l = j; l < j + squareSize; l++) {
                    if (k < cols && l < rows) {
                        out.at < cv::Vec3b > (l, k)[0] = b;
                        out.at < cv::Vec3b > (l, k)[1] = g;
                        out.at < cv::Vec3b > (l, k)[2] = r;
                    }
                }
            }
        }
    }
    return out;
}
