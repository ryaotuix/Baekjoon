#include <iostream>

using namespace std;

int arr[] = {10, 2, 4, 3, 1, 7, 9, 8, 5, 6};

const int len = 10;

void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printArr();

void bubbleSort()
{
    for(int i = 0; i < len; i++)
    {
        cout << "ITER " << i+1 << ": ";
        for (int j = 0; j < len-i-1; j++)
        {
            printArr();
            cout << "\n";
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
            
        }
        printArr();
    }
}

void printArr()
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    printArr();
    cout << "------------------\n";
    bubbleSort();
    printArr();
}