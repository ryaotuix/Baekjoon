#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = 200 + 1;
int N, K;
ll dp[MAX][MAX];   // [i][j] where i is # of numbers and j is target sum
// dp[K][N]

void input()
{   
    cin >> N >> K;
}

void print()
{
    for (ll i = 1; i < 10; i++)
    {
        for (ll j = 1 ; j < 10; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}
// init where 개수 is 2
void init()
{
    for (ll i = 0; i < MAX; i++)
    {
        // if # of number is 1, there is only 1 way
        dp[1][i] = 1;
        // if target sum is 1, there are k ways to do it
        dp[i][1] = i;
        // if target sum is 0, there is only 1 way
        dp[i][0] = 1;
    }
}

/*
    ex) (3, 10) can be done by (2, 10) + (2, 9) + ... + (2, 0)
2
        (10, 4) can be done by (9, 3) + ... + (1, 3)
*/
ll prevSum(ll num, ll sum)   // where 
{
    ll res = 0;

    for (ll i = 0; i <= sum; i++)
    {
        res += dp[num-1][i] %1000000000;
    }
    return res %1000000000;
}

void fillDP()
{
    // where i is target sum
    for (ll i = 2; i < MAX; i++)
    {
        // where j is # of numbers
        for (ll j = 2; j < MAX; j++)
        {
            dp[i][j] = prevSum(i, j);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    init();
    fillDP();
    // print();
    cout << dp[K][N];

    return 0;
}