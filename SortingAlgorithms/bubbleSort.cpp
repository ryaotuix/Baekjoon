#include <iostream>
#include <time.h>

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
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len-i-1; j++)
        {
            if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
        }
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
    int start = clock();
    cout << "------------------\n";
    bubbleSort();
    int end = clock();
    printArr();
    
    cout << "RUN : " << end-start << " amount of time\n";

}