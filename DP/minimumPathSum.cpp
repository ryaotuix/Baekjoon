#include <bits/stdc++.h>

using namespace std;

void printDP(vector<vector<int>> & v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}


int main()
{
    vector<vector<int>> grid = {{9,1,4,8}};

    int row = grid.size();
    int col = grid[0].size();
    if (row == 1 && col == 1) return grid[0][0];
    
    vector<vector<int>> arr (row, vector<int>(col, 0));

    arr[0][0] = grid[0][0]; // O(1)
    cout << "HEre\n";

    int i, j;
    for (i = 1; i < col; i++) // O(n)
    {
        arr[0][i] = grid[0][i] + arr[0][i-1];
        cout << arr[0][i] << " ";
    }
    cout << endl;
    // printDP(arr);

    cout << col << row << endl;

    if (row == 1) 
    {
        cout << arr[0][i-1];
        return arr[0][i-1];
    }

    for (i = 1; i < row; i++) // O(m)
    {
        arr[i][0] = grid[i][0] + arr[i-1][0];
    }
    if (col == 1) return arr[i-1][0];

    cout << endl;

    
    for (i = 1; i < row; i++)
    {
        for (j = 1; j < col; j++)
        {
            int getMin = min(arr[i-1][j], arr[i][j-1]);
            arr[i][j] = getMin + grid[i][j];
        }
    }

    cout << endl;

    cout << arr[i-1][j-1];
    return arr[i-1][j-1];


    // vector<vector<int>> dp(row, vector<int>(col, 0));
    // printDP(dp, row, col);
    // return 1 ;

    
    // dp[0][0] = grid[0][0];
    // for (int i = 0; i < col; ++i)
    // {
    //     dp[0][i] = grid[0][i];
    // }

    // printDP(row, col);
    // cout << endl; 

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 1; j < col; j++)
    //     {
    //         int add = min(dp[i-1][j], dp[i][j-1]);
    //         dp[i][j] = grid[i][j] + add;
    //         cout << dp[i-1][j] << " " << dp[i][j-1] << " add : " << add << " grid ij: " << grid[i][j] << endl;
    //         printDP(row, col);
    //         cout << endl;
    //     }
    // }

}