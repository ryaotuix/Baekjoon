#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

void print2D(vector<vector<bool>> & v)
{
    for (vector<bool> each : v)
    {
        for (bool i : each)
        {
            if (i)
                cout << "t";
            else
                cout << "f";
            cout << " ";
        }
        
        cout << endl;
    }
}

void dfs(vector<vector<char>> & grid, vector<vector<bool>> & visited, int row, int col)
{
    // Base Case:
        // 0. it is out of bound
    if (row < 0 || row > grid.size()-1 || col < 0 || col > grid[0].size()-1)
        return;

        // 1. it is visited
    if (visited[row][col] == true)
        return;

        // 2. it is 0
    if (grid[row][col] == '0')
        return;

    // cout << "0 check" << endl;
    

    // Otherwise,

    // make this visited
    visited[row][col] = true;
    // print2D(visited);

    // traverse 상하좌우
    dfs(grid, visited, row-1, col); // 상
    dfs(grid, visited, row+1, col); // 하
    dfs(grid, visited, row, col-1); // 좌
    dfs(grid, visited, row, col+1); // 우
}

int numIslands(vector<vector<char>> & grid)
{
    int nRow = grid.size();
    int nCol = grid[0].size();
    //  create 2D visited grid
    vector<vector<bool>> visited(nRow, vector<bool>(nCol, false));
    
    for (int i = 0; i < nRow; i++)
    {
        for (int j = 0; j < nCol; j++)
        {
            if (visited[i][j] == false && grid[i][j] == '1')
            {
                dfs(grid, visited, i, j);
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    int i = numIslands(grid);
    cout << i;
}