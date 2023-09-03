#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000 + 5;
int dp[MAX];    // => number of 짚신벌레 alive on ith day
int a, b, d;    // mature, lose fertility, and die
int N;          // number of days   

void input()
{
    cin >> a >> b >> d;
    cin >> N;
}

void DP()
{
    for (int i = 0; i < a; i++) dp[i] = 1;

    for (int i = a; i <= N; i++)
    {
        dp[i] = (dp[i-1] + dp[i-a]) % 1000;  // add mature ones who lay eggs

        if (i-b >= 0) dp[i] = (dp[i] + 1000 - dp[i-b]) % 1000;     // if there are unfertile 짚신벌레, subtract

    }

    // subtract dead 짚신벌레
    if (d <= N) dp[N] = (dp[N] + 1000 - dp[N-d]) % 1000;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    DP();
    cout << dp[N];
}