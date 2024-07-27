#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> ropes;


void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        ropes.push_back(temp);
    }
}

/*
    Idea : W = total / K 
    must maximize total but minimize K
    sort ropes in descending order
*/
void solve()
{
    int res = ropes[0];
    int num = 0;

    sort(ropes.begin(), ropes.end(), greater<int>());

    for (int i = 0; i < ropes.size(); i++)
    {
        res = max(ropes[i] * (i + 1), res);
    }


    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();
}