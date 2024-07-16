#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000 + 1;
int dp[MAX];

int n;

void init()
{
    dp[2] = 1;
    dp[4] = 2;
    dp[5] = 1;

    for (int i = 6; i < MAX; i++)
    {
        if (dp[i-2] == 0 && dp[i-5] != 0)
            dp[i] = dp[i-5] + 1;
        else if (dp[i-2] != 0 && dp[i-5] == 0)
            dp[i] = dp[i-2] + 1;
        else if (dp[i-2] != 0 && dp[i-5] != 0)
            dp[i] = min(dp[i-2], dp[i-5]) + 1;
    }
}
void input()
{
    cin >> n;
    if (dp[n] == 0)
    {
        cout << -1;
    }
    else 
    {
        cout << dp[n];
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    input();
}