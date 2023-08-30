#include <bits/stdc++.h>

using namespace std;

const int MAX = 100 + 5;

typedef pair<int, int> pii;
typedef pair<pii, int> depth;

int row, col;
int grid[MAX][MAX];
bool visited[MAX][MAX];
queue<depth> Q;
int cnt = 0;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1 ,1};
int maxDepth = 3;


void input()
{
    cin >> col >> row;
    for (int i = 1; i <= row; i++)
    {
        string s; cin >> s;
        for (int j = 1; j <= col; j++)
        {
            grid[i][j] = s[j-1] - '0';
            if (grid[i][j] == 1) cnt++;
        }
    }

    int startR, startC;
    cin >> startC >> startR;
    
    Q.push({{startR, startC} , 3});
    visited[startR][startC] = true;
}

bool OOB(int r, int c)
{
    if (r < 1 || r > row)
        return true;
    if (c < 1 || c > col)
        return true;
    return false;
}


int bfs()
{
    int jug = 0;

    while (!Q.empty())
    {
        jug++;
        depth curr = Q.front(); Q.pop();
        int r = curr.first.first;
        int c = curr.first.second;
        int depth = curr.second;
        maxDepth = depth;

        // cout << r << " " << c << " " << depth << "\n";

        for (int i = 0; i < 4; i++)
        {
            int nextR = r + dr[i];
            int nextC = c + dc[i];

            // not out of bound and not visited, then we can 
            if (!OOB(nextR, nextC) && visited[nextR][nextC] == false && grid[nextR][nextC] == 1)
            {
                // cout << "nextR, nextC " << nextR << " " << nextC << "\n";

                Q.push({{nextR, nextC}, depth + 1});
                visited[nextR][nextC] = true;
            }
        }
    }

    return jug;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    // for (int i = 1; i <= row; i++)
    // {
    //     for (int j = 1; j <= col; j++)
    //         cout << grid[i][j] << " ";
    //     cout << "\n";
    // }

    // cout << "\n";

    int res = bfs();
    cout << maxDepth << "\n";
    cout << cnt - res;
}