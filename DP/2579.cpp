#include <bits/stdc++.h>

using namespace std;


int dp[300+1];
int stairs[300+1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num; cin >> num;
    
    for (int i = 1; i < num + 1; i++)
        cin >> stairs[i];

    // for (int i = 1; i < num + 1; i++) cout << stairs[i] << " ";
    // cout << endl;

    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];

    for (int i = 3; i < num + 1; i++)
    {
        int twoSteps = dp[i-3] + stairs[i-1];
        int oneStep = dp[i-2];
        dp[i] = max(twoSteps, oneStep) + stairs[i];
    }

    // for (int i = 1; i < num + 1; i++) cout << dp[i] << " ";
    // cout << endl;

    cout << dp[num];

}