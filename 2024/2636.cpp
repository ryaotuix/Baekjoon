#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAX = 100 + 5;
bool visited[MAX][MAX];
int cheese[MAX][MAX];
int cheeseCnt = 0;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int R, C;

void input()
{
    cin >> R >> C;

    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> cheese[i][j];
            if (cheese[i][j] == 1)
                cheeseCnt++;
        }
    }
}

bool OOB(int row, int col)
{
    if (row < 0 || row > R)
        return true;
    if (col < 0 || col > C)
        return true;

    return false;
}

void init()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            visited[i][j] = false;
        }
    }
}

// use bfs
int bfs()
{
    int removeCheeseCnt = 0;

    init();
    queue<pii> q;
    q.push({0,0});
    visited[0][0] = true;

    while(!q.empty())
    {
        pii curr = q.front();
        q.pop();

        int currRow = curr.first;
        int currCol = curr.second;

        for (int i = 0; i < 4; i++)
        {
            int nextRow = currRow + dy[i];
            int nextCol = currCol + dx[i];

            // if not OOB and not visited
            if (!OOB(nextRow, nextCol) && !visited[nextRow][nextCol])
            {
                // if 1, change it to 0 and add Cnt
                if (cheese[nextRow][nextCol] == 1)
                {
                    cheese[nextRow][nextCol] = 0;
                    removeCheeseCnt++;
                }
                else
                {
                    q.push({nextRow, nextCol});
                }
                visited[nextRow][nextCol] = true;
            }
        }
    }

    return removeCheeseCnt;
}

void solve()
{
    int time = 0;
    int prev;

    while(cheeseCnt != 0)
    {
        prev = cheeseCnt;
        // cout << prev << "\n";
        int remove = bfs();
        cheeseCnt -= remove;
        time++;
    }

    cout << time << "\n";
    cout << prev;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();
}