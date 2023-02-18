#include<iostream>
#include "lib.h"

int main(){
    Complex n1(5, 3);
    Complex n2(3, 4);
    Complex n3 = n1 * n2 - n2 / n1 + n2;
    try{
        std::cout << n3[0] << std::endl;
        std::cout << n3[1] << std::endl;
        std::cout << n3[2] << std::endl;
    }
    catch(std::invalid_argument except){
        std::cout << except.what() << std::endl;
    }
}