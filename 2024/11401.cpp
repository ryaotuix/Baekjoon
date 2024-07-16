#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int N, K;
const int mod = 1000000007;

ll temp;

long long pow(long long a, long long m) {
	if (m == 0) return 1;

	temp = pow(a, m / 2) % mod;
	if (m % 2 == 1) return temp * temp % mod * a % mod;
	return temp * temp % mod;
}

ll fac(ll A)
{
    ll res = 1;
    for (int i = 1; i <= A; i++)
    {
        res = (res * i) % mod;
    }

    return res;
}

void input()
{
    cin >> N >> K;
}

ll fermat()
{
    // A = n!, B = (n-1)!r!
    // res = A/B % P
    // (A%P)(B ^ (P-2) % P) % P

    ll A = fac(N);
    ll B = fac(N-K) * fac(K) % mod;
    ll temp = mod - 2;
    return (A % mod) * (pow(B, temp) % mod) % mod;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    cout << fermat();
}