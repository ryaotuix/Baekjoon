#include <bits/stdc++.h>

using namespace std;

int dp[45];
vector<int> gap;
int N, M;



long long input()
{
    int start = 1;

    long long ans = 1;

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int finish; cin >> finish;
        // push only when gap is bigger than 1
        if (finish-start > 1)   ans *= dp[(finish - start)];
        start = finish + 1;
    }

    // last one 
    if (N+1 - start > 1) ans *= dp[(N+1 - start)];
    return ans;
}

void fillDP()
{
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= 40; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fillDP();
    cout << input();
}