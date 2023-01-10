#include "opencv2/opencv.hpp"
#include <iostream>
#include "lib.h"
#include "thread"

Snake SnakePositions(Snake s1, int Key)
{
    switch (Key)
    {
        case 'a':
            s1.setX(s1[0] - 10);
            break;
        case 'd':
            s1.setX(s1[0] + 10);
            break;
        case 's':
            s1.setY(s1[1] + 10);
            break;
        case 'w':
            s1.setY(s1[1] - 10);
            break;
        case 'x':
            s1.setSize(s1[2] + 1);
            break;
        case 'z':
            s1.setSize(s1[2] - 1);
            break;
        default:
            break;
    }
    return s1;
}

cv::Mat GetSnakedImage(cv::Mat img, Snake &s){
    cv::Mat temp;
    img.copyTo(temp);
    cv::circle(temp, cv::Point(s[0], s[1]), s[2], cv::Scalar(255, 0, 0), -1);
    return temp;
}

int main()
{
    Snake s1(20, 20, 4);
    
    cv::Mat img = cv::imread("../WhiteBG.jpeg", 1);
    int Frame = 1;
    while(Frame){
        cv::Mat ProcessedImage = GetSnakedImage(img, s1);
        cv::imshow("Checking", ProcessedImage);
        if(cv::waitKey(1) == 27) break;
        s1 = SnakePositions(s1, cv::waitKey(1));
    }
    return 0;

}