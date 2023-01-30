#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int arr[] = {1,3,5,7, 2,4,8,10};


const int len = sizeof(arr)/sizeof(int);

int aux[len];

void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printArr(int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void printAux()
{
    for (int i = 0; i < len; i++)
        cout << aux[i] << " ";
    cout << "\n";
}



// void merge(arr, int low, int mid, int hi)
void merge(int * arr, int low, int mid, int hi)
{
    int i = low;
    int j = mid+1;
    cout << "low : " << low << " mid : " << mid << " hi : " << hi << "\n";


    // copy into Auxiliary array
    for (int k = low; k <= hi; k++)
        aux[k] = arr[k];

    int iter = 1;
    int k;
    for (k = low; k <= hi; k++)
    {   
        cout << "ITER : " << iter++ << "\n";
        cout << "i : " << i << " j : " << j << "\n";

        if (i > mid) arr[k] = aux[j++]; // if we used all right sides  ->  use all left sides
        else if (j > hi) arr[k] = aux[i++]; // if we used all all the right sides  ->  use all right sides
        else if (aux[j] < aux[i]) arr[k] = aux[j++];
        else arr[k] = aux[i++];

        cout << "Arr: ";
        printArr(k);
        cout << "Aux: ";
        printAux();
        cout << "\n";
    }
    printArr(k);
}

int main()
{
    // printArr();
    int lo = 0;
    int hi = len -1;
    int mid = hi/2;
    merge(arr, lo, mid, hi);
    // printArr();
}