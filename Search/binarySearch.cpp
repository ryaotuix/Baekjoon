#include <bits/stdc++.h>

using namespace std;
//           0,1,2,3,4,5,6,7,8, 9
int arr[] = {1,2,3,4,5,6,7,8,9,10};
int len = sizeof(arr)/sizeof(arr[0]);

int binarySearch(int len, int * arr, int goal)
{
    int cnt = 1;
    int lo = 0; int hi = len-1;
    while (lo <= hi)
    {
        int mid = (hi + lo)/2; // 1~10 case, it would be 9/2 = 4
        cout << "In round " << cnt << ", lo : " << lo << ", mid : " << mid << ", hi : " << hi << endl;
        //cout << "current mid index is " << mid << endl;
        if (goal == arr[mid]) 
        {
            return mid;
        }
        else if (goal < arr[mid])
        {
            hi = mid-1;
        } 
        else 
        {
            lo = mid+1;
        }
        cnt++;
    }

    return -1;
}

int main()
{
    cout << "What number do you want to find? ";
    int find; cin >> find;
    int x = binarySearch(len, arr, find);
    if (x == -1)
    {
        cout << "No match found";
    }
    else{
        cout << find << " is found in index " << x << endl;
    }
}