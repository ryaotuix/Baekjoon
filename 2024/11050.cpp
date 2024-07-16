#include <bits/stdc++.h>

using namespace std;

const int mod = 10007;
const int MAX = 1000 + 1;

int dp[MAX][MAX];

int N, K;

int comb(int n, int r)
{
    if (dp[n][r] != 0)
        return dp[n][r];
    
    dp[n][r] = (comb(n-1, r-1) + comb(n-1, r)) % mod;

    return dp[n][r];
}

void input()
{
    cin >> N >> K;

    // init
    for (int i = 1; i < MAX; i++)
    {
        dp[i][i] = 1;
        dp[i][0] = 1;
    }

    cout << comb(N, K);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
}