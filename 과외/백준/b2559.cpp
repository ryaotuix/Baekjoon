#include <bits/stdc++.h>

using namespace std;

int n, k;   // n : number of elements,  k : max num
int arr [100000 + 110];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <=n; i++)
    {
        cin >> arr[i];
    }

    // Input Done! Start arr with 1

    // start two pointers at 1
    int max = 0;    // will store max sum
    int curr = 0;   // store current sum
    int left = 1; 
    int right = 1;

    // set first sum and put right ptr to the right of the window
    while (right <= k)
    {
        max += arr[right];
        right++;
    }
    
    curr = max;

    // if the new curr value (org - left + right) is bigger, change
    while (right <= n)
    {
        curr = curr - arr[left] + arr[right];   // update curr sum

        if (curr > max)
        {
            max = curr;
        }

        left++;
        right++;
    }

    cout << max;

}