#include <iostream>
#include <bits/stdc++.h>
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
        int minInd = i;
        for (int j = i; j < len; j++)
        {
            if (arr[j] < arr[minInd]) minInd = j;
        }
        swap(arr[minInd], arr[i]);
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
    shuffle(arr, arr + len, default_random_engine(0));
    printArr();

    int start = clock();
    cout << "------------------\n";
    selectionSort();
    int end = clock();
    printArr();

    cout << "RUN : " << end-start << " amount of time\n";
}