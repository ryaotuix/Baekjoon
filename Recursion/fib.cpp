#include <iostream>

int dp[1000];


using namespace std;

int fib(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    dp[n] = fib(n-1) + fib(n-2);
    
    return dp[n];
}

int lnFac(int n)
{
    if (n == 0) return 1;
    dp[n] = dp[n-1] * n;
    return dp[n];
}

int main()
{
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 0; i < 10; i++)
    {
        cout << fib(i) << " ";
    }
}