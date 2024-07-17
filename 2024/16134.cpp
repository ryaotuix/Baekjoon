#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
const ll MAX = 2e6 + 1;
ll factorial[MAX];

ll N, R;

void initFac()
{
    factorial[0] = factorial[1] = 1;
    for (ll i = 2; i < MAX; i++)
    {
        factorial[i] = factorial[i-1] * i % MOD;
    }
}

void input()
{
    cin >> N >> R;
}

ll pow(ll base, ll power)
{
    if (power == 1)
        return base % MOD;

    ll temp = pow(base, power/2) %  MOD;
    if (power % 2 == 1)
    {
        return ((temp * temp) % MOD * base) % MOD;
    }
    else
    {
        return (temp * temp) % MOD;
    }
}

void solve()
{
    ll A = factorial[N] % MOD;
    ll base = factorial[R] % MOD * factorial[N-R] % MOD;

    ll power = MOD - 2;
    ll B = pow(base, power);

    cout << (A*B) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    initFac();
    input();
    solve();
}