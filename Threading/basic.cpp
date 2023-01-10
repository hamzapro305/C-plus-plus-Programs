#include <iostream>
#include <thread>
#include <map>
#include <string>
#include <chrono>

using namespace std::chrono_literals;

void RefreshForecast(std::map<std::string, int> ForecastMap){
    while(1){
        std::cout << std::endl << "New Data" << std::endl;
        for(auto& item: ForecastMap){
            item.second++;
            std::cout << item.first << " - " << item.second << std::endl;
        }
        std::this_thread::sleep_for(5000ms);
    }
}

int main()
{
    std::map<std::string, int> ForecastMap = {
        {"New York", 14},
        {"Karachi", 20},
        {"Mumbai", 12},
        {"England", 11},
    };

    std::thread BackgroundWorker(RefreshForecast, ForecastMap);
    BackgroundWorker.join();
    return 0;
}