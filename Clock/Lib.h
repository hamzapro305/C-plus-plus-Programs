#include<opencv2/opencv.hpp>
#include <iostream>
#include <ctime>
#include <cmath>
#include <tuple>
#include <vector>

#define _USE_MATH_DEFINES

int RADIUS = 260;

std::tuple<int, int> CENTER(320, 320);
cv::Point CENTER_POINT(std::get<0>(CENTER), std::get<1>(CENTER));
std::tuple<int, int, int> CANVAS_SIZE(640, 640, 3);

auto GetTime(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return std::make_tuple(ltm->tm_sec, ltm->tm_min, (ltm->tm_hour > 12) ? ltm->tm_hour - 12 : ltm->tm_hour);
}

cv::Mat Draw_Time(cv::Mat image){
    auto [second, minute, hour] = GetTime();
    cv::Mat temp;
    image.copyTo(temp);
    // std::cout << second << " " << minute << " " << hour << std::endl;
    float second_angle = second * 6 - 90;
    int second_x = std::get<0>(CENTER) + (RADIUS - 20) * std::cos(second_angle * M_PI / 180);
    int second_y = std::get<1>(CENTER) + (RADIUS - 20) * std::sin(second_angle * M_PI / 180);
    cv::line(temp, CENTER_POINT, cv::Point(second_x, second_y), cv::Scalar(0, 0, 0), 2);

    float minute_angle = minute * 6 - 90;
    int minute_x = std::get<0>(CENTER) + (RADIUS - 20) * std::cos(minute_angle * M_PI / 180);
    int minute_y = std::get<1>(CENTER) + (RADIUS - 20) * std::sin(minute_angle * M_PI / 180);
    cv::line(temp, CENTER_POINT, cv::Point(minute_x, minute_y), cv::Scalar(0, 0, 0), 4);

    float hour_angle = std::fmod((hour*30) + (minute/2) + 270, 360);
    int hour_x = std::get<0>(CENTER) + (RADIUS - 20) * std::cos(hour_angle * M_PI / 180);
    int hour_y = std::get<1>(CENTER) + (RADIUS - 20) * std::sin(hour_angle * M_PI / 180);
    cv::line(temp, CENTER_POINT, cv::Point(hour_x, hour_y), cv::Scalar(79, 198, 66, 1), 8);

    return temp;
}

std::tuple<std::vector<std::tuple<int, int>>, std::vector<std::tuple<int, int>>> 
    GetArrows(){
    std::vector<std::tuple<int, int>> hours_init;
    std::vector<std::tuple<int, int>> hours_dest;
    for(int i = 0; i < 360; i += 6){
        int x_coordinate = std::get<0>(CENTER) + RADIUS * std::cos(i * M_PI / 180);
        int y_coordinate = std::get<1>(CENTER) + RADIUS * std::sin(i * M_PI / 180);
        hours_init.push_back(std::make_tuple(x_coordinate, y_coordinate));
    }

    for(int i = 0; i < 360; i += 6){
        int x_coordinate = std::get<0>(CENTER) + (RADIUS-20) * std::cos(i * M_PI / 180);
        int y_coordinate = std::get<1>(CENTER) + (RADIUS-20) * std::sin(i * M_PI / 180);
        hours_dest.push_back(std::make_tuple(x_coordinate,y_coordinate));
    }
    return std::make_tuple(hours_init, hours_dest);
}