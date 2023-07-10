#include <bits/stdc++.h>

using namespace std;

int grid[15 + 5][15 + 5];
int n;
int cnt = 0;

void printGrid()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
void boardMark(int row, int col)
{
    // + mark
    for (int i = 0; i < n; i ++)
    {
        grid[row][i]++;
        grid[i][col]++;
    }

    // top left
    int i = row;
    int j = col;
    while (i >= 0 && j >= 0)
    {
        grid[i][j]++;
        i--;
        j--;
    }

    // top right
    i = row;
    j = col;
    while (i >= 0 && j < n)
    {
        grid[i][j]++;
        i--;
        j++;
    }

    // bottom left
    i = row;
    j = col;
    while (i < n && j >= 0)
    {
        grid[i][j]++;
        i++;
        j--;
    }

    // bottom right
    i = row;
    j = col;
    while (i < n && j < n)
    {
        grid[i][j]++;
        i++;
        j++;
    }
}

void boardUnmark(int row, int col)
{
    // + mark
    for (int i = 0; i < n; i ++)
    {
        grid[row][i]--;
        grid[i][col]--;
    }

    // top left
    int i = row;
    int j = col;
    while (i >= 0 && j >= 0)
    {
        grid[i][j]--;
        i--;
        j--;
    }

    // top right
    i = row;
    j = col;
    while (i >= 0 && j < n)
    {
        grid[i][j]--;
        i--;
        j++;
    }

    // bottom left
    i = row;
    j = col;
    while (i < n && j >= 0)
    {
        grid[i][j]--;
        i++;
        j--;
    }

    // bottom right
    i = row;
    j = col;
    while (i < n && j < n)
    {
        grid[i][j]--;
        i++;
        j++;
    }
}

void cntNQueen(int row)
{
    // notice that in each row, we will have one queen we can put
    if (row == n)
    {
        cnt++;
        return;
    }

    for (int col = 0; col < n; col++)
    {
        // if we can visit
        if (grid[row][col] == 0)
        {
            // mark
            boardMark(row, col);
            cntNQueen(row+1);
            boardUnmark(row,col);
        }
    }
}


int main()
{
    cin >> n;
    // boardMark(3,4);
    // printGrid();
    // cout << endl;
    // boardUnmark(3,4);
    // printGrid();
    cntNQueen(0);
    cout << cnt;
}