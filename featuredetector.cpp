
#include "featuredetector.h"
using namespace std;
using namespace cv;

/**
 * @brief featuredetector::featuredetector
 * Class for comparing features and points of interest between
 * images.
 * @param image1
 * @param image2
 */
featuredetector::featuredetector(Mat image1, Mat image2)
{
    _image1 = image1;
    _image2 = image2;

}

/**
 * @brief featuredetector::testFeatures
 * FLANN based matching.
 * Algorithm is taken from
 * http://docs.opencv.org/doc/tutorials/features2d/feature_flann_matcher/feature_flann_matcher.html
 * @return Matched points image.
 */
Mat featuredetector::testFeatures(){
    cv::Mat im1, im2;

    //Grayscale the images.
    if(_image1.channels() == 3)
        cv::cvtColor(_image1,im1, CV_BGR2GRAY);
    else _image1.copyTo(im1);
    if(_image2.channels() == 3)
        cv::cvtColor(_image2,im2, CV_BGR2GRAY);
    else _image2.copyTo(im2);


    int minH = 100; // (should be around ~100)
    Ptr<xfeatures2d::SURF> detector =  xfeatures2d::SURF::create(minH);
    detector->setHessianThreshold(minH);

    std::vector<KeyPoint> keypoints1, keypoints2;
    Mat descriptors1, descriptors2;
    detector->detectAndCompute( im1, Mat(), keypoints1, descriptors1 );
    detector->detectAndCompute( im2, Mat(), keypoints2, descriptors2 );

    FlannBasedMatcher matcher;

    std::vector<DMatch> matches;
    matcher.match( descriptors1, descriptors2, matches );
    double maxDist = 0; double minDist = 80;



    for( int i = 0; i < descriptors1.rows; i++ )
    { double dist = matches[i].distance;
        if( dist < minDist ) minDist = dist;
        if( dist > maxDist ) maxDist = dist;
    }
    std::vector< DMatch > goodMatches;

    for( int i = 0; i < descriptors1.rows; i++ )
    { if( matches[i].distance <= max(2*minDist, 0.02) )
        { goodMatches.push_back( matches[i]); }
    }



    Mat matchMat;
    drawMatches( im1, keypoints1, im2, keypoints2,
                 goodMatches, matchMat, Scalar::all(-1), Scalar::all(-1),
                 vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );

    imshow( "Matches", matchMat );
    return matchMat;
}


