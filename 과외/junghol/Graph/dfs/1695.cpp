#include <bits/stdc++.h>

using namespace std;

int n;
int grid[25+5][25+5];
bool visited[25 + 5][25 + 5];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
vector<int> res;

void printGrid()
{
    for (int i =0 ; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << grid[i][j];
        cout << endl;
    }
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = s[j] - '0';
        }
    } 
}

bool inRange(int r, int c)
{
    if (r >= n || r < 0)
        return false;
    if (c >= n || c < 0)
        return false;
    return true;
}

int dfs(int r, int c)
{
    visited[r][c] = true;
    int ret = 1;
    for (int i = 0; i < 4; i++)
    {
        int nextR = r + dr[i];
        int nextC = c + dc[i];
        if (inRange(nextR, nextC) && grid[nextR][nextC] == 1 && !visited[nextR][nextC])
            ret += dfs(nextR, nextC);
    }

    return ret;
}

int main()
{
    input();
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (grid[r][c] == 1 && !visited[r][c])
            {
                int temp = dfs(r, c);
                res.push_back(temp);
            }
        }
    }

    sort(res.begin(), res.end());

    cout << res.size() << "\n";
    for (int n : res)
        cout << n << "\n";
}