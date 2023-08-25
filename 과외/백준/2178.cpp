#include <bits/stdc++.h>

using namespace std;

int n;  // row
int m;  // col
int grid[105][105];
int kan;    // minimum number of 칸
bool visited[105][105];

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
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            grid[i][j] = s[j] - '0';
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


void dfs(int depth, int currR, int currC)
{
    cout << currR << " " << currC << endl;
    visited[currR][currC] = true;

    // base case
    if (currR == n -1 && currC == m -1)
    {
        kan = min(kan, depth);
        cout << kan << "!!!!!\n\n";
        return;
    }
    
    // iterate over !!!!
    for (int i = 0; i < 4; i++)
    {
        int nextR = currR + dr[i];
        int nextC = currC + dc[i];

        if (inRange(nextR, nextC) && !visited[nextR][nextC] && grid[nextR][nextC] == 1)
        {
            dfs(depth + 1, nextR, nextC);
        }
    }

    visited[currR][currC] = false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    // cout << "here\n";
    dfs(1, 0, 0);
    cout << kan;
}