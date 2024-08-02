#include <bits/stdc++.h>

using namespace std;

const int MAX = 50 + 1;
int cnt[MAX];
// 'A' is  65 

void input()
{
    string s;
    cin >> s;
    for (char c : s)
    {
        cnt[c-64]++;
    }
}

void solve()
{
    int oddCnt = 0;
    char oddChar;
    stack<char> stk;
    queue<char> q;

    for (int i = 1; i < MAX; i++)
    {
        char currChar = i + 64;
        int currCnt = cnt[i];

        if (currCnt == 0) continue;

        // if odd
        if (currCnt % 2 == 1)
        {
            oddCnt++;
            oddChar = currChar;
        }

        // if there is one more char with oddCnt, we can't make palindrome
        if (oddCnt > 1)
        {
            cout << "I'm Sorry Hansoo";
            return;
        }

        // print 1/2 number of curr char
        for (int j = 0; j < currCnt/2; j++)
        {
            q.push(currChar);
            stk.push(currChar);
        }

    }

    while(!q.empty())
    {
        cout << q.front();
        q.pop();
    }
    
    cout << oddChar;

    while(!stk.empty())
    {
        cout << stk.top();
        stk.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();
}