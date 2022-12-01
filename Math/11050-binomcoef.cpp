#include <iostream>

using namespace std;

// find nCr

// use facts
// 1. nCr = n-1Cr-1 + n-1Cr
// 2. nC0 = nCn = 1

// Memoization!!!
int df[11][11]; // automatically 0

int BC(int n, int k)
{
    if (df[n][k] > 0) return df[n][k]; // if it is filled
    
    // 2. if reached base case
    if (n==k || k==0)
    {
        df[n][k] = 1;
        return df[n][k];
    }

    // if not filled and the base case, 
    df[n][k] = BC(n-1, k-1) + BC(n-1, k);
    return df[n][k];
}

int main()
{
    int N,K;
    cin >> N >> K;
    cout << BC(N,K) << endl;
    
    return 0;
}