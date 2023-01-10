#include<iostream>

using std::cout;
using std::endl;

template<typename Array>
void inSort(Array Arr, int Length){
    for(int i = 1; i < Length; i++){
        int j = i - 1;
        auto key = *(Arr + i);
        while(j >= 0 && key < *(Arr + j)){
            *(Arr + j + 1) = *(Arr + j); j--;
        }
        *(Arr + j + 1) = key;
    }
}

int main(){
    int Size = 10;
    int *Array = new int[Size];
    
    for(int i = 0; i < Size; i++) *(Array + i) = ((rand() % 10) + 1) / 2;
    for(int i = 0; i < Size; i++) std::cout << *(Array + i) << " ";
    cout << endl;
    inSort(Array, Size);
    for(int i = 0; i < Size; i++) std::cout << *(Array + i) << " ";
    cout << endl;
}