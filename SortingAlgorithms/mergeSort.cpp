#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// just random array
int arr[] = {1,3,5,7, 2,4,8,10};
const int len = sizeof(arr)/sizeof(int);
// Make Auxilirary array
int aux[len];

// FUNCTIONS 
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

/* MERGE SORT IMPLEMENTATION BEGINS !!!!!!!!!!!!!!!!!!!!*/

// void merge(arr, int low, int mid, int hi)
void merge(int * arr, int low, int mid, int hi)
{
    int i = low;
    int j = mid+1;
    cout << "low : " << low << " mid : " << mid << " hi : " << hi << "\n";


    // copy into Auxiliary array
    for (int k = low; k <= hi; k++) aux[k] = arr[k];

    int iter = 1; int k;
    for (k = low; k <= hi; k++)
    {   
        cout << "ITER : " << iter++ << "\n";
        cout << "i : " << i << "    aux[i]: " << aux[i] << "\n";
        cout << "j : " << j << "    aux[j]: " << aux[j] << "\n";

        if (i > mid) arr[k] = aux[j++]; // if we used all right sides  ->  use all left sides
        else if (j > hi) arr[k] = aux[i++]; // if we used all all the right sides  ->  use all left sides
        // NOW comparing
        else if (aux[i] > aux[j]) arr[k] = aux[j++]; // 1) if left is bigger than right, use right <smaller>
        else arr[k] = aux[i++]; // 2)right >= left, use left <smaller>

        cout << "Arr: ";
        printArr(k);
        cout << "Aux: ";
        printAux();
        cout << "\n";
    }
    cout << "!!!!!!!!!!!!!!!!!!!!MERGE DONE!!!!!!!!!!!!!!!!!!!!\n";
    printArr(k);
}

class TopDownMerge
{
    public:
        int * array = new int[len];
        int * auxilirary = new int[len];
        void setArray(int * arr, int len) { for (int i = 0; i < len; i++) array[i] = arr[i];}
        const int length = len;
        void sort(auto * arr, int len) {
            setArray(arr, len);
            sort(arr, 0, len-1);
        }
        void printAux() { for (int i = 0; i < len; i++) cout << auxilirary[i] << " "; cout << "\n";}
        void printArr() { for (int i = 0; i < len; i++) cout << array[i] << " "; cout << "\n";} 

    private:
        void sort(auto * arr, int lo, int hi)
        {
            if (hi <= lo) return;
            int mid = lo + (hi - lo)/2; // MATHEMATICALLY SAME AS (lo+hi)/2  (1) it gets rid of overflow 

            cout << "Cut it down to lo: " << lo << " to hi : " << hi << "\n\n";

            sort(arr, lo, mid);
            sort(arr, mid+1, hi);
            merge(arr, lo, mid, hi);
        }
};

class BottomUpMerge
{
    public:
        int * array = new int[len];
        int * auxilirary = new int[len];
        void setArray(int * arr, int len) { for (int i = 0; i < len; i++) array[i] = arr[i];}
        const int length = len;
        sort(int * arr, int n)
        {
            for (int len = 1; len < n; len *=2)
            {
                for (int lo = 0; lo < n-len; lo += len+len)
                    merge(arr,lo, lo+len-1, min(lo+len+len-1, n-1));
            }
        }

};


int main()
{
    
    printArr(len);
    shuffle(arr, arr + len, default_random_engine(0));
    cout << "After Shuffle: ";
    printArr(len);

    // <TOP DOWN MERGE>
    // TopDownMerge x;
    // x.sort(arr, len);

    // <BOTTOM UP MERGE>
    BottomUpMerge y;
    y.sort(arr, len);
    

    // CHECKING MERGE 
    // int lo = 0;
    // int hi = len -1;
    // int mid = hi/2;
    // merge(arr, lo, mid, hi);
}


// MODIFICATION TO MERGE SORT TO MAKE IT BETTER
// 1. Use insertion sort for small subarrays <length 15 or less> would make 10~15% faster
// 2. If a[mid] < a[mid+1] !!!!!!!!!!!! it is already sorted!!!! skip the round. Running time for any sorted subarray is linear
// 3. 
