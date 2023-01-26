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

void selectionSort()
{
    for (int i = 0; i < len; i++)
    {
        cout << "ITER " << i+1 << " : \n";
        int minInd = i;
        int j;
        for(j = i+1; j < len; j++)
        {
            printArr();
            if (arr[j] < arr[minInd]) minInd = j;
            //cout << "minInd : " << minInd << "\n";
        }
        swap(arr[i], arr[minInd]);
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
    int start = clock();
    cout << "------------------\n";
    selectionSort();
    int end = clock();
    printArr();

    cout << "RUN : " << end-start << " amount of time\n";
}