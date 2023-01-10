#include<iostream>
#include<tuple>

using std::cout;
using std::endl;

template<typename T>
void swap(T &addr1, T &addr2){
    T temp = addr1;
    addr1 = addr2;
    addr2 = temp;
}

auto GetTwoRet(int a, int b){
    return std::make_tuple("Hamza Siddiqui", 22);
}

template<typename Type1, typename Type2>
auto Sum(Type1 Variable1, Type2 Variable2){
    return Variable1 + Variable2;
}

int main(){
    auto [name, age] = GetTwoRet(1, 2);
    cout << name << " " << age << endl;
    return 0;
}