#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> um;    // char -> value (ex: AAA -> 111)


bool cmp(pair<char, int> a, pair<char, int> b)
{
    return a.second > b.second;
}  

void solve()
{
    int n;
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;

        for (int i = 0; i < s.size(); i++)
        {
            int power = s.size() - i;
            int val = pow(10, power-1);
            um[s[i]] += val;
        }
    }

    vector<pair<char, int>> vec(um.begin(), um.end());
    sort(vec.begin(), vec.end(), cmp);

    int assign = 9;
    long long int res = 0;
    for (auto a : vec)
    {
        res += (assign * a.second);
        assign--;
    }

    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}