#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int N;
const ll MAX = 100 + 1;

ll dp[MAX] = {0, };

ll recursion(int a)
{
    // base case
    if (a == 1 || a == 2 || a == 3) return 1;

    if (dp[a] != 0) return dp[a];
    else 
    {
        dp[a] = recursion(a-2) + recursion(a-3);
        return dp[a];
    }

}


void input()
{
    cin >> T;
    while (T--)
    {
        cin >> N;
        cout << recursion(N) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
}