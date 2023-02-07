#include <bits/stdc++.h>

using namespace std;

// Arr information
int arr[] = {1,2,3,4,5,6,7,8,9,10,11};
const int len = sizeof(arr)/sizeof(arr[0]);


void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapByIndex(int a, int b)
{
    int x = arr[a]; int y = arr[b];
    arr[a] = y; arr[b]= x;
}

void printArr(int * arr, int len) {
    for (int i = 0; i < len; i++) cout << arr[i] << " ";
    cout << "\n";
}

int partition(int * arr, int lo, int hi)
{
    int pivot = arr[lo];
    cout << "PIVOT : " << pivot << "\n"; 
    int i = lo, j = hi+1; // WHY "hi+1" ??? BC we are would have think there is INFINITY on the right side
    while (true)
    {
        cout << "CURR ARR: ";
        printArr(arr, len);
        cout << "i : " << i << " " << "j : " << j << "\n";
        // increment i until arr[i] >= pivot
        while (arr[++i] < pivot) if (i == hi) break;
        // decrement j until arr[j] <= pivot
        while (arr[--j] > pivot) if (j == lo) break;
        // if index i is greater or equal to j, END THE LOOP
        if (i >= j) break;
        cout << "SWAPPING " << arr[i] << " and " << arr[j] << "\n";
        // swap(arr[i], arr[j]);
        swapByIndex(i,j);
        cout << endl;
    }
    cout << endl;
    cout << "arr[j] : " << arr[j] << endl; 

    //swap(pivot, arr[j]);
    swapByIndex(0,j);
    return j;
}




int main()
{
    // Let's shuffle
    shuffle(arr, arr + len, default_random_engine(0));  

    printArr(arr, len);
    int j = partition(arr, 0, len-1);
    printArr(arr, len);
    cout << "FIXED: " << j << " and value : " << arr[j] << endl;
}