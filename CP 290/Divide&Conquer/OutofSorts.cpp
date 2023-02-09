#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int res = 0;

void printArr(auto * arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int binarySearch(auto* arr, int lo, int hi, int target)
{
    int mid = (lo+hi)/2;

    if (arr[mid] == target) {
        res++;
        return 1;
    }
    if (hi <= lo) return 0;
    // 1) left
    if (target < arr[mid])
    {
        hi = mid - 1;
        return binarySearch(arr, lo, hi, target);
    }
    // right
    else 
    {
        lo = mid + 1;
        return binarySearch(arr, lo, hi, target);
    }
}


int main()
{
    // xi = (a*x(i-1) + c) % m
    int n, m, c;
    ll a, x;
    cin >> n >> m >> a >> c >> x;
    
    int arr[n];
    arr[0] = (a*x + c) % m;
    for (int i = 1; i < n; i++) arr[i] = (arr[i-1]*a + c) % m;
    //printArr(arr, n);

    int lo = 0;
    int hi = n-1;
    
    for (int i = 0; i < n; i++)
    {
        int target = arr[i];
        //cout << "looking for " << target << endl;
        int x = binarySearch(arr, lo, hi, target);
    }
    cout << res;
}