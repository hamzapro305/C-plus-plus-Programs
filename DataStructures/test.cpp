#include<iostream>

using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main(){
    int *arr = new int(2);
    *(arr) = 5;
    *(arr + 1) = 2;
    cout << *arr << " " << *(arr + 1) << endl;
    swap(arr, arr + 1);
    cout << *arr << " " << *(arr + 1) << endl;
}