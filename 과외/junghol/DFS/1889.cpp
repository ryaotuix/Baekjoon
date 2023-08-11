#include <bits/stdc++.h>

using namespace std;

int n;
int grid[13 + 5][13 + 5];
int cnt = 0;

void printGrid()
{
    for (int i = 1 ; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void place(int row, int col)
{
    // row and col
    for (int i = 1; i <= n; i++)
    {
        grid[row][i]++;
        grid[i][col]++;
    }

    int r = row;
    int c = col;

    // top left
    while (row >= 1 && col >= 1)
    {
        grid[row][col]++;
        row--;
        col--;
    }
    row = r;
    col = c;

    // top right
    while (row >= 1 && col <= n)
    {
        grid[row][col]++;
        row--;
        col++;
    }
    row = r;
    col = c;

    // bottom left
    while (row <= n && col >= 1)
    {
        grid[row][col]++;
        row++;
        col--;
    }
    row = r;
    col = c;

    // bottom right
    while (row <= n && col <= n)
    {
        grid[row][col]++;
        row++;
        col++;
    }
    row = r;
    col = c;

    // we have counted grid[row][col] 6 times
    grid[row][col] -= 5;
}


void release(int row, int col)
{
    // row and col
    for (int i = 1; i <= n; i++)
    {
        grid[row][i]--;
        grid[i][col]--;
    }

    int r = row;
    int c = col;

    // top left
    while (row >= 1 && col >= 1)
    {
        grid[row][col]--;
        row--;
        col--;
    }
    row = r;
    col = c;

    // top right
    while (row >= 1 && col <= n)
    {
        grid[row][col]--;
        row--;
        col++;
    }
    row = r;
    col = c;

    // bottom left
    while (row <= n && col >= 1)
    {
        grid[row][col]--;
        row++;
        col--;
    }
    row = r;
    col = c;

    // bottom right
    while (row <= n && col <= n)
    {
        grid[row][col]--;
        row++;
        col++;
    }
    row = r;
    col = c;

    // we have counted grid[row][col] 6 times
    grid[row][col] += 5;
}

// notice that row is also the number of counts
void dfs(int row)
{
    if (row == n + 1)
    {
        cnt++;
        // printGrid();
        // cout << endl;
        return;
    }

    for (int col = 1; col <= n; col++)
    {
        // if we can put
        if (grid[row][col] == 0)
        {
            place(row, col);
            dfs(row + 1);
            release(row, col);
        }
    }
}


int main()
{
    cin >> n;
    dfs(1);
    cout << cnt;
}