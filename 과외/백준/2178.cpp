#include <bits/stdc++.h>

using namespace std;

int n;  // row
int m;  // col
int grid[105][105];
int kan;    // minimum number of 칸

// move left and right
// move up and down
// 상 하 좌 우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void input()
{
    cin >> n >> m;
    kan = n*m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
}


bool inRange(int row, int col)
{
    if (row >= n || row < 0)
        return false;
    if (col >= m || col < 0)
        return false;
    return true;
}


void dfs(int currR, int currC)
{
    if ()
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();

}