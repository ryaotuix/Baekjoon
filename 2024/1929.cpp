#include <bits/stdc++.h>

using namespace std;

int M, N;
const int MAX = 1e6 + 1;

int isPrime[MAX];


void primeNumberSieve()
{
    isPrime[1] = 1;
    
    for (int i = 2; i <= N; i++)
    {
        // if it is a prime number, iterate and mark
        if (isPrime[i] == 0)
        {
            for (int j = i * 2; j <= N; j += i)
            {
                isPrime[j] = 1; // j is not a prime nubmer
            }
        }
    }

    // print
    for (int i = M; i <= N; i++)
    {
        if (isPrime[i] == 0)
        {
            cout << i << "\n";
        }
    }
}


void input()
{
    cin >> M >> N;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    primeNumberSieve();
}