#include <bits/stdc++.h>

using namespace std;

int N, M;

// save minimum cost to buy six (set) and one
int minSix = 6000 + 1;
int minOne = 6000 + 1;

void input()
{
    cin >> N >> M;
    while(M--)
    {
        int six, one;
        cin >> six >> one;

        minSix = min(minSix, six);
        minSix = min(minSix, one*6);
        minOne = min(minOne, one);
    }
}

int solve()
{
    int res = 0;
    while(N >= 6)
    {
        N -= 6;
        res += minSix;
    }

    if (N * minOne < minSix)
        res += N*minOne;
    else
        res += minSix;

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();

    cout << solve();
}