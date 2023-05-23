#include <bits/stdc++.h>

using namespace std;

void printVec(vector<int>& v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}


// 양극단에서 무한루프 발생
int binarySearch_Wrong(vector<int>& v, int target)
{
    int lo = 0; int hi = v.size() - 1; int mid;
    while (lo < hi)
    {
        mid = lo + (hi - lo) / 2;

        cout << lo << " " << mid << " " << hi << endl;
        cout << v[lo] << " " << v[mid] << " " << v[hi] << endl;
        cout << endl;

        if (target < v[mid])
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid;               
        }

    }

    cout << lo << " " << mid << " " << hi << endl;
    cout << v[lo] << " " << v[mid] << " " << v[hi] << endl;
    cout << endl;

    return v[hi];
}

int binarySearch1(vector<int> & v, int target)
{
    int lo = 0;  int hi = v.size() - 1; int mid;
    while (lo < hi)
    {
        mid = lo + (hi - lo) /2;

        if (target > v[mid])                          // This is important
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

int binarySearch2(vector<int> & v, int target)
{
    int lo = 0; int hi = v.size() - 1; int mid;
    while (lo <= hi)
    {
        mid = lo + (hi - lo)/2;

        if (target > v[mid])
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return lo;
}


int binarySearch3(vector<int> & v, int & target, int lo, int hi)
{
    int mid = lo + (hi - lo) / 2;
    if (v[mid] == target)
        return mid;
    else if (target > v[mid])
        return binarySearch3(v, target, mid + 1, hi);
    else    
        return binarySearch3(v, target, lo, mid);
}

int main()
{
    vector<int> arr = {1,3,5};    
    sort(arr.begin(), arr.end());

    printVec(arr);

    int target = 3;
    
    int res = binarySearch2(arr, target);
    // int res = binarySearch3(arr, target, 0, arr.size() - 1);
    cout << res << " " << arr[res];

}