#include <bits/stdc++.h>

using namespace std;

#define SK 1
#define CY 2

const int MAX = 1000 + 1;
int n;
int dp[MAX];

void input()
{
    cin >> n;
    dp[1] = SK;
    dp[2] = CY;
    dp[3] = SK;

    for (int i = 4; i < MAX; i++)
    {
        if (dp[i-3] == dp[i-1] && dp[i-3] == SK)
            dp[i] = CY;
        else
            dp[i] = SK;
    }


    // for (int i = 1; i <= 10; i++)
    //     cout << dp[i] << " ";

    if (dp[n] == SK)
    {
        cout << "SK";
    }
    else
        cout << "CY";
}  

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
}