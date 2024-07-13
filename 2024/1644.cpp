#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> primes; // store primes

void input()
{
    cin >> N;
}

void eras(int n)
{
    vector<bool> isPrime(n+1, true);

    for (int i = 2; i*i <= n; ++i)
    {
        if (isPrime[i])
        {
            for (int j = i*i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }


    // add prime numbers
    for (int i = 2; i <= n; ++i)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();


    if (N == 1)
    {
        cout << 0;
        return 0;
    }
    
    eras(N);

    int s = primes.size();
    int res = 0;
    int start = 0;
    int end = 0;
    int sum = 0;

    while(end <= s)
    {
        if (sum >= N)
        {
            sum -= primes[start++];
        }

        if (sum < N)
        {
            sum += primes[end++];
        }

        if (sum == N) res++;
    }

    cout << res;
}