#include <bits/stdc++.h>

using namespace std;

int length, height; 
// 2 <= length <= 2E5 for length
// 2 <= height <= 5E5 for height
#define MAX_LENGTH 300000

int bottom[MAX_LENGTH];
int top[MAX_LENGTH];

void printArr(int * arr, int len)
{
    for(int i = 0; i < len; i++) cout << arr[i] << " ";
    cout << endl;
}

int binarySearchCrash(int * arr, int target_height)
{
    int lo = 0;
    int hi = length/2;
    return height/2 - (lower_bound(arr, arr+hi, target_height) - arr);
    // LOWER_BOUND returns the pointer to the i <= x
}

int getTotal(int curr)
{
    int floor = binarySearchCrash(bottom, curr);
    int ceiling = binarySearchCrash(top, height -curr);
    //cout << floor << " " << ceiling << endl;
    return floor + ceiling;
}



int main()
{
    cin >> length >> height;
    for (int i = 1; i <= length; i++)
    {   
        // if odd (1, 3, 5) go to bottom (0,1,2)
        if (i%2 == 1) cin >> bottom[i/2];
        // if even (2, 4, 6) go to top (0,1,2)
        else cin >> top[i/2 -1];
    }
    sort(bottom, bottom + length/2);
    sort(top, top + length/2);

    printArr(bottom, length);
    printArr(top, length);

    cout << binarySearchCrash(top, 5);
    cout << endl;
    cout << getTotal(7);

    // int min = 2*length;
    // int i;
    // for (i = 1; i <= height; ++i)
    // {
    //     int curr_crash = getTotal(i);
    //     if (curr_crash < min) min = curr_crash;
    // }
    // cout << i << " " << min;
}