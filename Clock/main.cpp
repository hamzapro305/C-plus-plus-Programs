#include "Lib.h"

int main(){
    cv::Mat image(640, 640, 1, cv::Scalar(255, 255, 255));
    auto [hours_init, hours_dest] = GetArrows();
    for(int i = 0; i < hours_init.size(); i++){
        int initX = std::get<0>(hours_init[i]);
        int initY = std::get<1>(hours_init[i]);
        int destX = std::get<0>(hours_dest[i]);
        int destY = std::get<1>(hours_dest[i]);
        if(i % 5 == 0){
            cv::line(image, cv::Point(initX, initY), cv::Point(destX, destY), cv::Scalar(0, 0, 0), 2);
        }else{
            cv::circle(image, cv::Point(initX, initY), 5, cv::Scalar(0, 0, 0), -1);
        }
    }
    while(1){
        cv::Mat ProcessedImage = Draw_Time(image);
        cv::circle(ProcessedImage, CENTER_POINT, 20, cv::Scalar(0, 255, 0), -1);
        cv::imshow("Clock", ProcessedImage);
        if(cv::waitKey(1) == 27) break;
    }
    return 0;
}