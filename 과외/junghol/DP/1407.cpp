#include <bits/stdc++.h>

using namespace std;

string s;
int dp[40 + 5];

void input()
{
    cin >> s;
}

int getRes()
{
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= s.size(); i++)
    {
        int ind = i-1;      // ind represents the array index of a string

        dp[i] = dp[i-1];


        // if s[ind] == '0',
        if (s[ind] == '0')
        {
            // 전값이 3보다 커서 34 보다 큰수를 만들어야 하거나, 전값도 0 이라면
            if (s[ind-1] > '3' || s[ind-1] == '0') return 0;

            // 맨 마지막 값이 0 이라면
            if (i == s.size()) return dp[i] - 1;

            // 아니라면, 기존에 있는 경우의 수 만큼
            else continue;
        }

        // if "s[ind-1] + s[ind]" <= 34, dp[i] += dp[i-2]
        int temp = stoi(s.substr(ind-1, 2));
        if (temp <= 34 && s[ind-1] != '0') dp[i] += dp[i-2];
        
    }
    
    return dp[s.size()];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << getRes();
}