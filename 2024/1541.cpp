#include <bits/stdc++.h>

using namespace std;

string s;
queue<int> q;


void input()
{
    cin >> s;
}

int output()
{
    int curr = 0;
    int prev = 0; 

    for (int i = 0 ; i < s.length(); i++)
    {
        if (s[i] == '-')
        {
            q.push(curr + prev);
            curr = prev = 0;
        }
        else if (s[i] == '+')
        {
            prev += curr;
            curr = 0;
        }
        else
        {
            curr = curr * 10;
            curr += s[i] - '0';
        }
    }

    // last digit added to queue
    q.push(curr + prev);


    int res = q.front(); q.pop();
    while (!q.empty())
    {
        res -= q.front();
        q.pop();
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    cout << output();
}