#include <bits/stdc++.h>

using namespace std;

void printArr(auto * arr, int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
}

typedef long long ll;

// Sorted Ascending Order
int binarySearch(int * arr2, int len, int target) // Get the biggest closest element
{
    // Corner cases
    if (target < arr2[0]) return arr2[0];
    // if (target > arr2[len-1]) return arr2[len]; 

    // Binary Search
    int lo = 0;
    int hi = len-1; 
    int mid;
    
    
    int mul = 1;
    while (true) {
        int arr[len];
        for (int i = 0; i < len; i++) arr[i] = arr2[i] * mul;
        lo = 0; hi = len -1;
        while (lo < hi)
        {
            mid = lo + (hi - lo)/2;
            //cout << "lo : " << arr[lo] << " hi : " << arr[hi] << " mid : " << arr[mid] << endl;
            if (arr[mid] == target) return arr[mid];

            // 1) Find in the first half 
            if (target < arr[mid]) 
            {
                if (mid > 0 && target > arr[mid-1]) return arr[mid];
                hi = mid;
            }
            // 2) Find in the second half
            else // target > arr[mid]
            {
                if (mid < len-1 && target < arr[mid+1]) return arr[mid+1];
                lo = mid + 1;
            }
            mid = lo + (hi - lo)/2;
        }

        //cout << "getout" << endl;
        mul++;
    }

    return arr2[mid];
}




int main()
{
    ios_base::sync_with_stdio(false);   
    
    // int arr[] = {1,3,5,7,9};
    // int len = 5;
    // int target = 11;
    // int x = binarySearch(arr, len, target);
    // cout << x;


    int num_sizes, num_colors;
    cin >> num_sizes >> num_colors;

    int cans[num_sizes];  // can size
    for (int i = 0; i < num_sizes; i++) cin >> cans[i];
    sort(cans, cans + num_sizes);

    int colors[num_colors];
    for (int i = 0; i < num_colors; i++) cin >> colors[i];

    // Now iterate through colors and get the best can sizes
    ll res = 0;
    for (int color : colors) {
        int best_size = binarySearch(cans, num_sizes, color);
        //cout << "Best size for " << color << " is " << best_size << endl;
        res += best_size - color;
    }
    cout << res;
    
    
}