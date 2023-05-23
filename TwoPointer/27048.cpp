/*Romeo Meets Juliet*/
#include <iostream>

using namespace std;

int n, p, c;    // n : number of total Cowpulets, p : number of Fence Posts, c : tolerable number of Cowpulates

int fence[1000 + 5];

int solve()
{
    int left = 1;     // does it have to be 0?
    int right = p+1;  // does it have to be p-1?

    int leftcnt = 0;
    int rightcnt = 0;

    int leftMove = 0;
    int rightMove = 0;

    while (true)
    {
        // in case left has to move
        if (leftcnt <= c)    
    }

    int ptr1 = left - 1;
    int ptr2 = p - right;

    return (ptr1 > ptr2) ? ptr1 : ptr2;
}

int main()
{
    cin >> n >> p >> c;
    for (int i = 1; i <= n; i++)
    {
        int temp; cin >> temp;
        fence[temp]++;
    }

    // for (int i = 1; i <= p; i++)
    //     cout << fence[i] << " ";
    // cout << "\n----------------------\n";



    // fence[i] represents the number of Cowpulets on the right side of ith - fence
    cout << solve();

    return 0;
}