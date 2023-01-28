#include <iostream>

int dp[1000];


using namespace std;

// Top Down 
int fib(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    dp[n] = fib(n-1) + fib(n-2);
    return dp[n];
}

// Bottom Up
int fib2(int n)
{
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}



int main()
{
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 0; i < 10; i++)
    {
        cout << fib2(i) << " ";
    }
}