#include <bits/stdc++.h>

using namespace std;

const int MAX = 100 + 5;
int row, col;               // row an col
int grid[MAX][MAX];         // input
bool visited[MAX][MAX][5];  // save visited
                            // ex) E, W, S, N = 1, 2, 3, 4

typedef struct robot
{
    int r;
    int c;
    int dir;
    int level;
}robot;

// Queue of robot
queue<robot> Q;
robot start;        // robot at start position
robot finish;       // robot at end position   

void input()
{
    // fill grid
    cin >> row >> col;
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            cin >> grid[i][j];

    // fill start and finish
    cin >> start.r >> start.c >> start.dir;
    cin >> finish.r >> finish.c >> finish.dir;

    // make all unvisited
    for (int i = 0; i <= row; i++)
        for (int j = 0; j <= col; j++)
            for (int k = 0; k < 5; k++)
                visited[i][j][k] = false;


    // visited path to start position is 0 and push it to queue
    visited[start.r][start.c][start.dir] = true;  // mark the visited path to start position 0
    start.level = 0;
    Q.push(start);
}

bool reachedEnd(robot curr)
{
    if (curr.c == finish.c && curr.r == finish.r && curr.dir == finish.dir) return true;
    return false;
}

bool OOB(int r, int c)
{
    if (r < 1 || r > row) return true;
    if (c < 1 || c > col) return true;
    return false;
}

int turnL(int n)
{
    int res = n-1;
    if (res == 0) res = 4;
    return res;
}

int turnR(int n)
{
    int res = n+1;
    if (res == 5) res = 1;
    return res;
}


void bfs()
{
    // 동 서 남 북
    // 1 2 3 4
    int dr[5] = {0, 0, 0, 1, -1};
    int dc[5] = {0, 1, -1, 0, 0};

    while(!Q.empty())
    {
        robot curr = Q.front(); Q.pop();

        // if current is end
        if (reachedEnd(curr))
        {
            cout << curr.level;
            return;
        }

        // go 1, 2, 3 in this direction
        for (int dist = 1; dist <= 3; dist++)
        {
            int nextR = curr.r + (dist * dr[curr.dir]);
            int nextC = curr.c + (dist * dc[curr.dir]);
            int nextD = curr.dir;

            // OOB
            if (OOB(nextR, nextC)) break;

            // Can't go
            if (grid[nextR][nextC] == 1) break;

            // if visited in visited
            if (visited[nextR][nextC][nextD]) continue;

            // otherwise
            visited[nextR][nextC][nextD] = true;
            Q.push({nextR, nextC, nextD, curr.level + 1});
        }

        // turn left and right
        int nextR = curr.r;
        int nextC = curr.c;

        int nextD = turnL(curr.dir);
        if (!visited[nextR][nextC][nextD])
        {
            visited[nextR][nextC][nextD] = true;
            Q.push({nextR, nextC, nextD, curr.level + 1});
        }

        nextD = turnR(curr.dir);
        if (!visited[nextR][nextC][nextD])
        {
            visited[nextR][nextC][nextD] = true;
            Q.push({nextR, nextC, nextD, curr.level + 1});
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    bfs();
}