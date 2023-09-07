#include <bits/stdc++.h>

using namespace std;

const int MAX = 100 + 5;

typedef struct cross
{
    int hor; // cross # of 가로개수
    int ver; // cross # of 세로개수
}cross;

cross grid [MAX][MAX];  // MAX * MAX 의 값

int N, M;

void printGrid()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cout << "{" << grid[i][j].hor << "," << grid[i][j].ver << "} ";
        }
        cout << "\n";
    }
}

void initGrid()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            grid[i][j].hor = 0;
            grid[i][j].ver = 0;
        }
    }
}

void fill(int row, int col, char dir)
{
    if (dir == 'R')
    {
        while (col <= N)
        {
            grid[row][col].hor++;       // 가로갯수 늘려주기
            col++;
        }
    }

    else if (dir == 'L')
    {
        while (col >= 1)
        {
            grid[row][col].hor++;
            col--;
        }
    }

    else if (dir == 'U')
    {
        while (row >= 1)
        {
            grid[row][col].ver++;
            row--;
        }
    }

    else if (dir == 'D')
    {
        while (row <= N)
        {
            grid[row][col].ver++;
            row++;
        }
    }
}

void input()
{   
    cin >> N >> M;

    initGrid();

    for (int i = 1; i <= M; i++)
    {
        int row, col;
        char dir;

        cin >> row >> col >> dir;

        fill(row, col, dir);
    }
}

int calculate()
{
    int ret = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            ret += (grid[i][j].hor * grid[i][j].ver);
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    int res = calculate();

    cout << res;
    cout << "\n";
    printGrid();
}
