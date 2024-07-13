#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MIN, MAX;

int cnt = 0;
unordered_map<ll, int> um;

void input()
{
    cin >> MIN >> MAX;
}

ll calc()
{
    for (ll i = 2; i * i <= MAX; i++)
    {
        // here i is a number that will be squared (2^2, 3^2, 4^2)...

        ll div = MIN / (i * i);

        // ex) if MIN is 30, div must start from 8 instead of 7
        if(MIN % (i*i)) div++;

        // while (i*i) * div is smaller than MAX, iterate
        while((i*i) * div <= MAX)
        {
            // if this is not found, 
            if (um[i * i * div] == 0) 
            {
                um[i*i*div]++;  // increase this (mark as found)
            }

            div++;
        }
    }

    ll res = 0;
    for (ll i = MIN; i <= MAX; i++)
    {
        if (um[i] == 0) res++;
    }
    return res;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    cout << calc();
}