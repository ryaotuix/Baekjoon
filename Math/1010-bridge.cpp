// UNDONE!!!!!!!!!!!!!!!!!!!!!!!!


#include <iostream>
#include <string.h>

using namespace std;

// Approach is Combination. 

int dp[31][31]; // memoization
// storing information for nCm

// use facts
// 1. nCr = n-1Cr-1 + n-1Cr
// 2. nC0 = nCn = 1

int BC(int N, int M)
{
    // if it is filed
    if (dp[N][M] > 0) return dp[N][M];

    // condition for nCm 
    if (N==M || M==0) {
        dp[N][M] = 1;   // change it to 1
        return dp[N][M];    // return it
    }

    dp[N][M] = BC(N-1, M-1) + BC(N-1, M);
    return dp[N][M];
}


int main()
{
    
    int num; 
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int N, M;
        cin >> N >> M;
        cout << BC(N, M) << endl;
        memset(dp, 0 ,sizeof(dp));
    }

    return 0;
}