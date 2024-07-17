#include <bits/stdc++.h>

using namespace std;

int M;
int N, K;

typedef long long ll;

const ll MAX = 4e6 + 1;
const ll MOD = 1000000007;
ll factorial[MAX];

void initFac()
{
    factorial[0] = 1;
    factorial[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        factorial[i] = (factorial[i-1] * (i%MOD)) % MOD;
    }
}

// get n^(p-2) % MOD which is n^-1 % MOD
ll powMod(ll base, ll power)
{      
    if (power == 1)
    {
        return base % MOD;
    }

    ll temp = powMod(base, power/2) % MOD;

    // if odd
    if (power % 2 == 1)
    {
        return ((temp * temp) % MOD * base) % MOD;
    }
    else
    {
        return (temp * temp) % MOD;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> M;
    initFac();

    while(M--)
    {
        cin >> N >> K;
        
        ll base = (factorial[N-K] % MOD * factorial[K] % MOD) % MOD;
        ll power = MOD-2;

        ll A = factorial[N] % MOD;
        ll B = powMod(base, power);

        cout << (A * B) % MOD << "\n";
    }
}