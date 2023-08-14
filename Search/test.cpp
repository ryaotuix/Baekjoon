#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr2, int target)
{
    int lo = 0;
    int hi = arr2.size();

    while (lo < hi)
    {
        int mid = (lo + hi) / 2;

        if (arr2[mid] <= target)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
    }
    
    return lo;
}

int main()
{
    vector<int> arr2 = {1,3,4};

    cout << binarySearch(arr2, 4);
}