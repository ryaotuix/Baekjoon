#include <bits/stdc++.h>

using namespace std;

int n;
int target;

int arr[20 + 5];

int cnt = 0;
int len = 0;


void input()
{
    cin >> n >> target;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";
    // cout << endl;
}

void bottomUp(int sum, int ind)
{
    // Base Case: we saw all eles
    if (ind == n)
    {
        if (sum == target)
            cnt++;
        return;
    }
    
    // case we add
    bottomUp(sum + arr[ind], ind + 1);
    // case we don't add
    bottomUp(sum, ind + 1);
}

int main()
{
    input();
    bottomUp(0, 0);
    if (target == 0)    cnt--;
    cout << cnt << endl;
}