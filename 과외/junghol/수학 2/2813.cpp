#include <iostream>

using namespace std;

bool isPrime(int x)
{
    for (int i = 2; i < x; i++)
    {
        if (x%i == 0)
            return false;
    }
    return true;
}

int prime[3000002];    // if Prime 0, if not Prime 1

void erastosthenes(int x)
{
    prime[0] = 1;
    prime[1] = 1;

    int i, j;
    for (i = 2; i*i <= x; i++)
    {
        if (prime[i] == 1)
            continue;
        for (j = i*i; j <= x; j += i)        // start from a squared value
        {
            prime[j] = 1;
        }
    }
}

int main()
{
    int m, n;
    cin >> m >> n;
    
    int cnt = 0;

    // BruteForce

    // for (int i = m; i <= n; i++)
    // {
    //     if (isPrime(i))
    //         cnt++;
    // }

    erastosthenes(n);

    for (int i = m; i <= n; i++)
    {
        if (prime[i] == 0)
            cnt++;
    }

    cout << cnt;
}