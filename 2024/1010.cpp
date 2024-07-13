#include <bits/stdc++.h>

using namespace std;

int T;
int N, M;
const int MAX = 30 + 1;

int dp[MAX][MAX];

void init()
{
    // init base case
    for (int i = 0 ; i < MAX; i++)
    {
        dp[i][0] = dp[i][i] = 1;
    }
}

void getComb()
{
    for (int i = 1; i < MAX; i ++)
    {
        for (int j = i; j < MAX; j++)
        {
            if (dp[j][i]!= 0) continue;
            else
            {
                dp[j][i] = dp[j-1][i-1] + dp[j-1][i];
            }
        }
    }

    // for (int i = 0; i < MAX; i++)
    // {
    //     for (int j = 0; j < MAX; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
}

void input()
{
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        cout << dp[M][N] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    getComb();
    input();

}