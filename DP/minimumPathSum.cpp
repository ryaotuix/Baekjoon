#include <bits/stdc++.h>

using namespace std;




void printDP(vector<vector<int>> &arr, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    int row = grid.size();
    int col = grid[0].size();


    vector<vector<int>> dp(row, vector<int>(col, 0));
    printDP(dp, row, col);
    return 1 ;

    
    dp[0][0] = grid[0][0];
    for (int i = 0; i < col; ++i)
    {
        dp[0][i] = grid[0][i];
    }

    printDP(row, col);
    cout << endl; 

    for (int i = 0; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            int add = min(dp[i-1][j], dp[i][j-1]);
            dp[i][j] = grid[i][j] + add;
            cout << dp[i-1][j] << " " << dp[i][j-1] << " add : " << add << " grid ij: " << grid[i][j] << endl;
            printDP(row, col);
            cout << endl;
        }
    }

}