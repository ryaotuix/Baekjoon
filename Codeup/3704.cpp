#include <iostream>

using namespace std;

/*
int count(int stairs)
{
    if (stairs == 1) return 1;
    if (stairs == 2) return 2;
    if (stairs == 3) return 4;

    return (count(stairs-1) + count(stairs-2) + count(stairs-3));
}
*/

// using dp
const int limit = 1e5 + 1;

int dp[limit] = {0,1,2,4};

int count(int stairs)
{   
    // if it exist in Memoization just return
    if (dp[stairs] != 0) return dp[stairs];

    // if not add it to the Memoization 
    
    dp[stairs] = (count(stairs-1) + count(stairs-2) + count(stairs-3)) % 1000;
    return dp[stairs];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int stairs; cin >> stairs;

    cout << count(stairs) << endl;

    return 0;
}