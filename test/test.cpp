#include<iostream>
#include <typeinfo>

int main(){
    int y = 7;
    auto x = [&y](){
        y = 5;
        std::cout << y << std::endl;
    };
    x();
    std::cout << y << std::endl;
    // std::cout << x << std::endl;
}