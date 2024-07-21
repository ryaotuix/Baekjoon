#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll N;
const ll MAX = 2000000+1;
const ll MOD = 1000000007;

ll factorial[MAX];

void initFac()
{
    factorial[1] = factorial[0] = 1;
    for (ll i = 2; i < MAX; i++)
    {
        factorial[i] = (factorial[i-1] * i) % MOD;
    }
}

ll pow(ll base, ll power)
{
    if (power == 0)
        return 1;
    
    ll half = pow(base, power / 2) % MOD;
    ll result = (half * half) % MOD;
    
    if (power % 2 != 0)
        result = (result * base) % MOD;
    
    return result;
}


// 카탈린 수 (2N C N) * (1/(N+1))
void getCatalin()
{
    // get (2N!) * (N!N!)^-1 * (N+1)^-1
    
    // 2N ! 
    ll A = factorial[2*N] % MOD;

    // N! N! 
    ll base = (factorial[N] % MOD) * (factorial[N] % MOD) % MOD;
    ll power = MOD - 2;
    // cout << "base : " << base << "\n";
    ll B = pow(base, power) % MOD;

    base = N+1;
    // cout << "base : " << base << "\n";
    ll C = pow(base, power) % MOD;

    // cout << A << " " << B << ' ' << C << "\n";

    cout << ((A*B) % MOD * C) % MOD << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    initFac();

    while(T--)
    {
        cin >> N;
        getCatalin();
    }
}