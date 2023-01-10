#include <iostream>

using namespace std;

bool BinarySearch(int *Array, int Size, int Value){
    int init = 0, fin = Size - 1;
    int mid = (init + fin) / 2;
    while(init <= fin){
        if (*(Array + mid) == Value) return true;
        else if(*(Array + mid) > Value) fin = mid - 1;
        else if(*(Array + mid) < Value) init = mid + 1;
        mid = (init + fin) / 2;
    }
    return false;
}

int main(){
    int arr[] = {1, 2, 3, 4};
    bool result = BinarySearch(arr, 4, 1);
    cout << result << endl;
    return 0;
}