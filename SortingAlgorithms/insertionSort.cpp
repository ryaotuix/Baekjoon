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

void insertionSort()
{
   for (int i = 1; i < len; i++)
   {
        cout << "ITER " << i+1 << ": ";
        for (int j = i; j > 0; j--)
        {
            printArr();
            if (arr[j] < arr[j-1]) swap(arr[j], arr[j-1]);
            else break;
        }
        printArr();
   }
}

void printArr()
{
    for (int i = 0; i < len; i++) cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    printArr();
    cout << "------------------\n";
    int start = clock();
    insertionSort();
    int end = clock();
    printArr();

    cout << "RUN : " << end-start << " amount of time\n";

}