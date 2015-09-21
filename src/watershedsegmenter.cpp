#include "watershedsegmenter.h"

WatershedSegmenter::WatershedSegmenter()
{
}

void WatershedSegmenter::setMarkers(const cv::Mat& image){
    image.convertTo(_markers, CV_32S);
}

cv::Mat WatershedSegmenter::process(const cv::Mat& image){
    cv::watershed(image, _markers);
    _markers.convertTo(_markers,CV_8U);
    return _markers;
}

cv::Mat WatershedSegmenter::getWatersheds(){
    cv::Mat tmp;
    _markers.convertTo(tmp,CV_8U, 255, 255);
    return tmp;
}
