#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll X;   // total game
ll Y;   // wins
int Z;  // win rate

const int maximum = 1e9;    // how many more games?

// get win rate after how many games?
ll getWinRate(int mid)
{
    ll totalGames = X + mid;
    ll totalwins = Y + mid;

    return (totalwins*100)/totalGames;
}

// binary Search the first # more game to change the win rate
int binarySearch()
{
    int lo = -1;
    int hi = maximum;
    int mid;

    while(lo + 1 < hi)
    {
        mid = (lo + hi) / 2;
        ll winRate = getWinRate(mid);          // this is the winrate after mid # of games
                
        // cout << lo << " " << hi << " " << mid << " " << winRate << endl;

        if (winRate > Z)                        // when the winrate > org winrate, see if we can increase    winrate with SMALLER value
        {
            hi = mid;
        }
        else
            lo = mid;
    }

    return hi;
}

int main()
{
    cin >> X >> Y;
    Z = (Y*100)/X;

    // if the original Z >= 99% then we cannot change Z
    if (Z >= 99)
    {
        cout << -1;
        return 0;
    }

    int games = binarySearch();
    cout << games << endl;
}