#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> plates(n);
    for (int i = 0; i < n; i++)
        cin >> plates[i];

    vector<vector<bool>> dp (n, vector<bool>(2000));  // default 0 (false)
    dp[0][plates[0]] = true;


    for (int i = 0; i < n; i++) 
        dp[i][0] = 1; // it's always possible to make 0 weight using any plate (not using)

    

    for (int i =1; i <n; ++i)
    {
        // cout << " dddk";
        for (int j = 0; j < 2000; j++)
        {
            // if one above is true, or curr target - curr weight is true, it is true
            if (dp[i-1][j])
            {
                dp[i][j] = true;
            }
            if (j-plates[i] >= 0)
            {
                if (dp[i-1][j-plates[i]]) dp[i][j] = true;
            }
            // cout << j << " ";
        }
    }
    
    int closest = 0;
    // last row would have all the information 
    for (int j = 0; j < 2000; j++)
    {
        if (dp[n-1][j] == 1)
        {
            if (abs(1000 - closest) >= abs(1000 - j)) closest = j;
        } 

        // int check = dp[n-1][j];
        // if (check == 1)
        // {
        //     cout << check;
        //     if (abs(1000-closest) > abs(1000 - check)) closest = check;
        // }
    }

    cout << "res: " << closest << endl;
    return 0;
        
}