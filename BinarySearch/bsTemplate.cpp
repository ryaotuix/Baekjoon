#include <bits/stdc++.h>

using namespace std;


// Always get the first index of the target
int lowerBound(vector<int> & v, int target)
{
    int lo = 0;
    int hi = v.size() - 1;
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        int curr = v[mid];

        if (curr < target)
            lo = mid + 1;
        else
            hi = mid;
    }

    return lo;
}

// Always get the first index of the target
int upperBound(vector<int> & v, int target)
{
    int lo = 0;
    int hi = v.size() - 1;
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        int curr = v[mid];

        if (curr <= target)
            lo = mid + 1;
        else
            hi = mid;
    }

    return lo;
}


int main()
{
    vector<int> arr = {5,7,7,8,8,10};
    vector<int> arr2 = {5,7,9,10};
    int target = 8;

    cout << lowerBound(arr, 8) << endl;
    cout << lowerBound(arr2, 8) << endl;

    cout << upperBound(arr, 8) << endl;
    cout << upperBound(arr2, 8) << endl;

    // Expected 3, 2, 5, 2

    cout << "=============================\n";

    vector<int> arr3 = {2, 2};
    cout << lowerBound(arr3, 2) << endl;
    cout << upperBound(arr3, 2) << endl;
    
    // Expected 0, 1

    cout << "Final : ";
    vector<int> v = {1, 2, 3, 4, 7};
    cout << upperBound(v, 3) << endl;

    cout << lower_bound(v.begin(), v.end(), 4) - v.begin() << endl;
    cout << upper_bound(v.begin(), v.end(), 4) - v.begin() << endl;

}