#include<iostream>
#include "lib.h"

int main(){
    Complex n1(5, 3);
    Complex n2(3, 4);
    Complex n3 = n1 * n2 - n2 / n1 + n2;
    n2[0] = 5;
    std::cout << n2 << std::endl;
}