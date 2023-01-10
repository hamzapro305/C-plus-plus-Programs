#include<iostream>

using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void PrintArr(int *Array, int Size)
{
    cout << "[ ";
    for (int i = 0; i < Size; i++) cout << *(Array + i) << " ";
    cout << "] " << endl;
}

int Partition(int *Array, int Low, int High){
    int pivot = Array[High]; // pivot
    int i = (Low - 1); 
  
    for (int j = Low; j <= High - 1; j++) {
        // If current element is smaller than the pivot
        if (*(Array + j) < pivot) {
            i++; // increment index of smaller element
            swap((Array + i), (Array + j));
        }
    }
    swap((Array + i + 1), (Array + High));
    return (i + 1);
}

void QuickSort(int *Array, int Low, int High){
    if(Low < High){
        int Pivot = Partition(Array, Low, High);
        QuickSort(Array, Low, Pivot - 1);
        QuickSort(Array, Pivot + 1, High);
    }
}

int main(){
    int arr[] = {2, 1, 5, 6, 7, 2, 8};
    PrintArr(arr, 7);
    QuickSort(arr, 0, 7);
    PrintArr(arr, 7);
}