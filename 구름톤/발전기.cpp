#include <bits/stdc++.h>

using namespace std;

const int MAX = 1005;

typedef pair<int, int> pii;     // pair int int 
queue<pii> Q;                   // queue to store x y positiion

int grid[MAX][MAX];
bool visited[MAX][MAX];
int n;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
}

void printG()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << grid[i][j];
        cout << "\n";
    }
}

bool OOB(int r, int c)
{
    if (r > n || r < 0) return true;
    if (c > n || c < 0) return true;
    return false;
}

void bfs()
{
    while (!Q.empty())
    {
        pii curr = Q.front(); Q.pop();
        int row = curr.first;
        int col = curr.second;

        for (int i = 0; i < 4; i++)
        {
            int nextR = row + dr[i];
            int nextC = col + dc[i];
            if (!OOB(nextR, nextC) && grid[nextR][nextC] == 1 && !visited[nextR][nextC])
            {
                visited[nextR][nextC] = true;
                Q.push({nextR, nextC});
            }
        }
    }
}


int cnt()
{
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // if this grid is 1 and not visited
            if (grid[i][j] == 1 && !visited[i][j])
            {
                c++;      // increment c

                visited[i][j] = true;   // make this visited
                Q.push({i, j});         // push this position to Q
                bfs();                  // bfs
            }
        }
    }

    return c;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    int res = cnt();
    cout << res;
}