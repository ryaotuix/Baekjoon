#include <bits/stdc++.h>

using namespace std;

const int MAX = 100 + 5;
typedef struct robot
{
    int row;
    int col;
    int dir;
    int level;
    
    bool operator==(const robot & r) const {
        if (row == r.row && col == r.col && dir == r.dir) return true;
        return false;
    }
    
}robot;

// array for direction
//             동 서  남  북
int dr[] = {0, 0, 0, 1, -1};
int dc[] = {0, 1, -1, 0, 0};

bool visited[MAX][MAX][5]; 
int grid[MAX][MAX];
int row, col;
robot start, finish;
queue<robot> Q;

void input()
{
    cin >> row >> col;
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            cin >> grid[i][j];

    cin >> start.row >> start.col >> start.dir;
    cin >> finish.row >> finish.col >> finish.dir;

    start.level = 0;

    Q.push(start);
}

void enqueue(robot & robot)
{
    Q.push(robot);
}

void makeVisited(robot & robot)
{
    visited[robot.row][robot.col][robot.dir] = true;
}

robot makeRobot(int r, int c, int dir, int level)
{
    return {r, c, dir, level};
}

bool OOB(int r, int c)
{
    if (r > row || r < 1) return true;
    if (c > col || c < 1) return true;
    return false;
}

    // change     1  2  3  4 to
int toRight[] = {0, 3, 4, 2, 1};
int toLeft[] =  {0, 4, 3, 1, 2};

// int cnt = 0;
int bfs()
{
    while(!Q.empty())
    {
        robot curr = Q.front(); Q.pop();
        
        // cout << cnt++ << ": " << curr.row << " " << curr.col << " " << curr.dir << " " << curr.level << "\n";
        
        // if current is finish, return level
        if (curr == finish) return curr.level;

        // direction 1~3
        for (int dist = 1; dist <= 3; dist++)
        {
            int nR = curr.row + (dist * dr[curr.dir]);
            int nC = curr.col + (dist * dc[curr.dir]);
            int nD = curr.dir;
            int nL = curr.level + 1;
            
            // out of bound,
            if (OOB(nR, nC)) break;

            // if wall
            if (grid[nR][nC] == 1) break;

            if (!visited[nR][nC][nD])
            {
                robot next = makeRobot(nR, nC, nD, nL);
                makeVisited(next);
                enqueue(next);
            }
        }

        int nR = curr.row;
        int nC = curr.col;
        int nL = curr.level + 1;

        // LEFT
        int nD = toLeft[curr.dir];
        if (!visited[nR][nC][nD])
        {
            robot next = makeRobot(nR, nC, nD, nL);
            makeVisited(next);
            enqueue(next);
        }

        // RIGHT
        nD = toRight[curr.dir];
        if (!visited[nR][nC][nD])
        {
            robot next = makeRobot(nR, nC, nD, nL);
            makeVisited(next);
            enqueue(next);
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    int tasks = bfs();
    cout << tasks;
}