#include <bits/stdc++.h>

using namespace std;

int grid[10 + 5][10 + 5];
int n;
int cnt = 100 + 5;

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> grid[i][j];
        }
    }
}

// -1
void place(int col, int row)
{
    int orgCol = col;
    int orgRow = row;

    // top left 
    while (col >= 1 && row >= 1)
    {
        grid[col][row]++;
        row--;
        col--;
    }
    col = orgCol;  row = orgRow;

    // top right
    while (col <= n && row >= 1)
    {
        grid[col][row]++;
        row--;
        col++;
    }
    col = orgCol;  row = orgRow;

    // bottom left
    while (col >= 1 && row <= n)
    {
        grid[col][row]++;
        row++;
        col--;
    }
    col = orgCol;  row = orgRow;

    // bottom right
    while (col <= n && row <= n)
    {
        grid[col][row]++;
        row++;
        col++;
    }

    grid[orgCol][orgRow] -= 3;
}

// +1
void release(int col, int row)
{
    int orgCol = col;
    int orgRow = row;

    // top left 
    while (col >= 1 && row >= 1)
    {
        grid[col][row]--;
        row--;
        col--;
    }
    col = orgCol;  row = orgRow;

    // top right
    while (col <= n && row >= 1)
    {
        grid[col][row]--;
        row--;
        col++;
    }
    col = orgCol;  row = orgRow;

    // bottom left
    while (col >= 1 && row <= n)
    {
        grid[col][row]--;
        row++;
        col--;
    }
    col = orgCol;  row = orgRow;

    // bottom right
    while (col <= n && row <= n)
    {
        grid[col][row]--;
        row++;
        col++;
    }

    grid[orgCol][orgRow] += 3;
}

void dfs(int currCol, int currRow, int currCnt)
{
    for (int i = currCol; i <= n; i++)
    {
        for (int j = currRow; j <= n; j++)
        {
            // if we can put this, put it
            if (grid[i][j] > 0)
            {
                place(i, j);
                dfs(i, j, currCnt + 1);
                release(i, j);
            }
        }
    }

    // Base Case : when we can't put no more chess
    cnt = min(cnt, currCnt);
}


int main()
{
    input();
    dfs(1, 1, 0);
    cout << cnt;
}