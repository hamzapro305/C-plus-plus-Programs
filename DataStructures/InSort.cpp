#include <iostream>

using namespace std;

void PrintArr(int *Array, int Size)
{
    cout << "[ ";
    for (int i = 0; i < Size; i++) cout << *(Array + i) << " ";
    cout << "] " << endl;
}

void InSort(int *Array, int Size)
{
    for (int i = 1; i < Size; i++)
    {
        int j = i - 1;
        int key = *(Array + i);
        while (j >= 0 && *(Array + j) > key)
        {
            *(Array + j + 1) = *(Array + j);
            j--;
        }
        *(Array + j + 1) = key;
    }
}

int main()
{
    int Size = 10;
    int *Array = new int[Size];

    for(int i = 0; i < Size; i++)
        *(Array + i) = (rand() % 10) + 1;

    cout << "Before Sorting" << endl;
    PrintArr(Array, Size);
    InSort(Array, Size);
    cout << "After Sorting" << endl;
    PrintArr(Array, Size);

    free(Array);
}