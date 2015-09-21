#include "Cartoonifier.h"
#include "pixelate.h"
#include "Canny.h"

using namespace cv;

/**
 * @brief cartoonfiyImage
 * Cartoonifies the image by using Laplacian to extract contours,
 * reducing the quality of the original image and merging back together.
 * Method is from Mastering OpenCV book.
 * @param image
 * @return cartoon-like image
 */
cv::Mat cartoonfiyImage(const cv::Mat& image){
    Mat image2;
    image.copyTo(image2);
    Mat gray;
    cvtColor(image2, gray, CV_BGR2GRAY);
    const int blurFilterSize = 7;
    medianBlur(gray, gray, blurFilterSize);
    Mat edges;

    //Get the edges of original image using Laplacian and
    //threshold binary inversion.
    const int laplaceFilterSize = 7;
    Laplacian(gray, edges, CV_8U /*single channel*/, laplaceFilterSize);
    Mat mask;
    const int edgeThreshold = 80;
    threshold(edges, mask, edgeThreshold, 255, THRESH_BINARY_INV);

    //Reduce size (quality) of original image. Then iterate
    // through multiple bilateral filters.
    Size originalSize = image2.size();
    Size halfSize;
    halfSize.width = originalSize.width/2;
    halfSize.height = originalSize.height/2;
    Mat reducedImage = Mat(halfSize, CV_8UC3);
    resize(image, reducedImage, halfSize, 0,0, INTER_LINEAR);

    Mat tmp = Mat(halfSize, CV_8UC3);
    int repetitions = 7;
    for (int i=0; i<repetitions; i++) {
        int ksize = 9;
        double sigmaColor = 9;
        double sigmaSpace = 7;
        bilateralFilter(reducedImage, tmp, ksize, sigmaColor, sigmaSpace);
        bilateralFilter(tmp, reducedImage, ksize, sigmaColor, sigmaSpace);
    }

    //increase size back to original image size.
    resize(reducedImage, image2, originalSize, 0,0, INTER_LINEAR);

    //mask the image with the edges.
    Mat dst;
    dst.setTo(0);
    image2.copyTo(dst, mask);
    return dst;
}


/**
 * @brief cartoonfiyImage2
 * Different cartoonify algorithm. Uses gaussian blur, erosion and
 * contrast change, then perofrms iterated bilateral filter and masks with
 * canny edges.
 * @param image
 * @return
 */
cv::Mat cartoonfiyImage2(const cv::Mat& image){
    Mat image2;
    image.copyTo(image2);
    Mat se = getStructuringElement( MORPH_RECT,Size(2,2),Point(0,0));
    erode(image2,image2, se);
    image2.convertTo(image2,-1, 2, 0);
    Mat gray;
    cvtColor(image2, gray, CV_BGR2GRAY);

    Mat edges = cannyEdges(gray, 80,255);

    image2.copyTo(image2, edges);

    //Gaussian Blur the image.
    Size ksize(7,7);
    GaussianBlur(image2,image2, ksize, 1.5f,1.5f, BORDER_DEFAULT);

    Mat tmp;
    image2.copyTo(tmp);
    int repetitions = 8;
    for (int i=0; i<repetitions; i++) {
        int ks = 3;
        double sigmaColor = 5;
        double sigmaSpace = 7;

        bilateralFilter(image2, tmp, ks, sigmaColor, sigmaSpace);
        bilateralFilter(tmp, image2, ks, sigmaColor, sigmaSpace);
    }

    Mat dst;
    dst.setTo(0);
    image2.copyTo(dst, edges);
    return dst;

}
