#include <iostream>
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int arr[] = {10, 2, 4, 3, 1, 7, 9, 8, 5, 6, 10, 2, 4, 3, 1, 7, 9, 8, 5, 6};


const int len = sizeof(arr)/ sizeof(int);

void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printArr();


void shellSort()
{
    int gap = 1;
    while (gap < len/3) gap = 3 * gap + 1;
    while (gap > 0)
    {
        for (int i = gap; i < len; i++)
        {
            for (int j = i; arr[j] < arr[j-gap] && j >= gap; j -= gap)
                swap(arr[j], arr[j-gap]);
        }
        gap /= 3;
    }
    
}

void printArr()
{
    for (int i = 0; i < len; i++) cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    // cout << "len : " << len << endl;
    // int gap = 1;
    // while (gap < len/3) gap = 3 * gap + 1;
    // cout << "gap : " << gap << endl;

    // printArr();
    // while (gap > 0)
    // {
    //     cout << "GAP : " << gap << endl;
    //     for (int i = gap; i < len; i++)
    //     {
    //         // continuously check
    //         for (int j = i; j >= gap && (arr[j] < arr[j-gap]); j-= gap)
    //         {
    //             cout << "Comparing j:" << j << " and j-gap:" << j-gap << "\n";
    //             cout << "arr[j] : " << arr[j] << " and arr[j-gap] : " << arr[j-gap] << "\n";
    //             swap(arr[j], arr[j-gap]);
    //             printArr();
    //             cout << "\n";
    //         }
    //         cout << "===\n";
    //     }
    //     cout << "------------------------------\n";


    //     gap = (gap-1)/3;
    // }




    printArr();
    shuffle(arr, arr + len, default_random_engine(0));
    printArr();

    int start = clock();
    cout << "------------------\n";
    shellSort();
    int end = clock();
    printArr();

    cout << "RUN : " << end-start << " amount of time\n";
}