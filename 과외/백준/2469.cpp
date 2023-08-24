#include <bits/stdc++.h>

using namespace std;

int n;
int mini = 100;
int maxi = 1;
int grid[105][105];
bool visited[105][105];
// 상 하 좌 우
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool inRange(int row, int col)
{
    if (col < 0 || col >= n)
        return false;
    if (row < 0 || row >= n)
        return false;
    return true;
}

void dfs(int & rain, int currR, int currC)
{
    visited[currR][currC] = true;

    for (int i = 0; i < 4; i++)
    {
        int nextR = currR + dr[i];
        int nextC = currC + dc[i];

        // go in depth only when nextR and nextC is in range and bigger than the rain height
        if (inRange(nextR, nextC) && grid[nextR][nextC] > rain && !visited[nextR][nextC])
        {
            dfs(rain, nextR, nextC);
        }
    }
}

// get # of connected component according to rain height
int getCC(int rain)
{
    int cc = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && grid[i][j] > rain)
            {
                cc++;
                dfs(rain, i, j);
            }
        }
    }

    return cc;
}

int getMaxSafeZone()
{
    int numSafeZone = 1;    // minimum number of safe zone is 1 when rain < mini

    // rain < mini => 1, rain >= maxi => 0
    for (int rain = mini; rain < maxi; rain++)
    {
        memset(visited, false, sizeof(visited));
        int cc = getCC(rain);
        numSafeZone = max(numSafeZone, cc);
    }

    return numSafeZone;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];

            maxi = max(maxi, grid[i][j]);
            mini = min(mini, grid[i][j]);
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << getMaxSafeZone();
}