#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int arr[] = {10, 2, 4, 3, 1, 7, 9, 8, 5, 6, 10, 2, 4, 3, 1, 7, 9, 8, 5, 6};


const int len = sizeof(arr)/sizeof(int);

int aux[len];

void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printArr()
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << "\n";
}


// void merge(arr, int low, int mid, int hi)
void merge(int arr[])
{
    int low = 0;
    int mid = len/2;
    int hi = len;
    
    int i = 0;
    int j = len/2 + 1;
    for (int k = 0; k <= hi; k++)
    {
        aux[k] = arr[k];
    }

    for (int k = low; k <= hi; k++)
    {
        if (i > mid) arr[k] = aux[j++];
        else if (j > hi) arr[k] = aux[i++];
        else if (aux[j], aux[i]) arr[k] = aux[j++];
        else arr[k] = aux[i++];
    }
}

int main()
{
    shuffle(arr, arr+len, default_random_engine(0));
    printArr();

    merge(arr);
    printArr();
}