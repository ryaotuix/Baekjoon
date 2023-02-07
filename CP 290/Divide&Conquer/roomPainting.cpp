#include <bits/stdc++.h>

using namespace std;

void printArr(auto * arr, int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
}

// Sorted Ascending Order
int binarySearch(int * arr, int len, int target) // Get the biggest closest element
{
    // Corner cases
    if (target < arr[0]) return arr[0];
    if (target > arr[len]) return arr[len]; // Return the 

    // Binary Search
    int lo = 0;
    int hi = len; 
    int mid = lo + (hi - lo)/2;

    while (lo < hi)
    {
        if (arr[mid] == target) return arr[mid];

        if (target < arr[mid]) 
        {
            hi = mid
        }
        else 
        {
            
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);   
    int num_sizes, num_colors;
    cin >> num_sizes >> num_colors;

    int cans[num_sizes];  // can size
    for (int i = 0; i < num_sizes; i++) cin >> cans[i];
    sort(cans, cans + num_sizes);

    int colors[num_colors];
    for (int i = 0; i < num_colors; i++) cin >> colors[i];
    
    
}