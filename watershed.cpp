#include "watershed.h"
#include "watershedsegmenter.h"

cv::Mat segmentImage(const cv::Mat& image){
    cv::Mat binary;

    cv::cvtColor(image,binary, CV_BGR2GRAY);

    cv::Mat fg;
    cv::erode(binary,fg, cv::Mat(), cv::Point(-1,-1), 6);

    cv::Mat bg;
    cv::dilate(binary,bg,cv::Mat(), cv::Point(-1,-1),6);

    cv::threshold(bg,bg,1,128,cv::THRESH_BINARY_INV);

    cv::Mat markers;

    markers = fg + bg;

    WatershedSegmenter seg;
    seg.setMarkers(markers);
    cv::Mat res = seg.process(image);
    res.convertTo(res,CV_8U);
    imshow("final_result", res);
    return res;
}
