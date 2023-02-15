#include <bits/stdc++.h>

using namespace std;

// Arr information
vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11};
const int len = arr.size();


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

void printArr(vector<int> arr, int len) {
    for (int i = 0; i < len; i++) cout << arr[i] << " ";
    cout << "\n";
}

int partition(vector<int>& arr, int lo, int hi)
{
    cout << "lo : " << lo << ", hi : " << hi << endl;
    int pivot = arr[lo];
    cout << "PIVOT : " << pivot << "\n"; 
    int i = lo, j = hi+1; // WHY "hi+1" ??? BC we are would have think there is INFINITY on the right side
    while (true)
    {
        cout << "CURR ARR: ";
        printArr(arr, len);
        cout << "i : " << i << " " << "j : " << j << "\n";
        // increment i until arr[i] >= pivot !! FIND ELEMENT GREATER THAN PIVOT
        while (arr[++i] < pivot) if (i == hi) break;
        // decrement j until arr[j] <= pivot !! FIND ELEMENT LESS THAN PIVOT
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


    // at index j, it becomes 
    swapByIndex(0,j);
    return j;
}


void quickSort(vector<int> &arr, int lo, int hi)
{
    if (lo < hi)
    {
        int j = partition(arr, lo, hi);
        quickSort(arr, lo, j);
        quickSort(arr, j+1, hi);
    }
}



int main()
{
    // Let's shuffle
    shuffle(arr.begin(), arr.end(), default_random_engine(0));  
    arr.push_back(999999999);
    quickSort(arr, 0, len);

    // printArr(arr, len);
    // int j = partition(arr, 0, len-1);
    // printArr(arr, len);
    // cout << "FIXED: " << j << " and value : " << arr[j] << endl;
}