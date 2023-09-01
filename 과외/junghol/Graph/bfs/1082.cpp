#include <bits/stdc++.h>

using namespace std;

const int MAX = 50 + 5;

typedef struct fire {
    int r;
    int c;
    int layer;
}fire;

typedef struct JaeU {
    int r;
    int c;
    int movement;
}JaeU;

int R, C;
char grid[MAX][MAX];
bool visited[MAX][MAX];

queue<fire> fireQ;      // store fire locations
queue<JaeU> jaeuQ;      // store jaeu locations

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1 ,1};

bool OOB(int r, int c)
{
    if (r >= R || r < 0) return true;
    if (c >= C || c < 0) return true;
    return false;
}

void input()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> grid[i][j];
            // if fire,
            if (grid[i][j] == '*')  fireQ.push({i, j, 0});  // push fire with current row, col, and layer 0

            if (grid[i][j] == 'S')
            {
                jaeuQ.push({i, j, 0});  // push JaeU with current row, col, and movement 0
                visited[i][j] = true;
            }
        }
    }
}

void fireFill(int layer)
{
    // while fireQ is empty and the first fireQ has the same layer
    while(!fireQ.empty() && fireQ.front().layer == layer)
    {
        int r = fireQ.front().r;
        int c = fireQ.front().c;
        fireQ.pop();

        for (int i = 0; i < 4; i++)
        {
            int nR = r + dr[i];
            int nC = c + dc[i];

            /* CAN GO WHEN
                1. not out of bound
                2. not fortress
                3. not rock
                4. not fire already
            */
            if (!OOB(nR, nC) && grid[nR][nC] != 'D' && grid[nR][nC] != 'X' && grid[nR][nC] != '*')
            {
                // change the grid into fire
                grid[nR][nC] = '*';
                // and push it to the Queue
                fireQ.push({nR, nC, layer + 1});
            }
        }
    }
}

// move jaeU one more time, 
/*
    returns 1 when success
    returns 0 
    returns -1 when there is no more jaeU
*/
int JaeUFill(int movement)
{
    // while jaeuQ is empty and the first jaeU has the same movment,
    while (!jaeuQ.empty() && jaeuQ.front().movement == movement)
    {
        int r = jaeuQ.front().r;
        int c = jaeuQ.front().c;
        jaeuQ.pop();

        // if this 분신 of jaeU died by fire,
        if (grid[r][c] == '*') continue;        // continue

        // otherwise, let's spread this 분신 more
        for (int i = 0; i < 4; i++)
        {
            int nR = r + dr[i];
            int nC = c + dc[i];
            
            /* CAN GO WHEN
                1. not OOB
                2. not rock
                3. not fire
                4. not visited
            */
            if (!OOB(nR, nC) && grid[nR][nC] != 'X' && grid[nR][nC] != '*' && !visited[nR][nC])
            {
                // if jaeU reaches D
                if (grid[nR][nC] == 'D')    return 1;
                
                // make next movement visited
                visited[nR][nC] = true;
                // push into jaeUFill otherwise
                jaeuQ.push({nR, nC, movement + 1});
            }
        }
    }

    if (jaeuQ.empty())  return -1;

    return 0;
}



int getMovement()
{
    int move = 0;
    int layer = 0;
    
    // while jaeuQ is not empty
    while(!jaeuQ.empty())
    {
        // i. 분신술! 재우를 4갈래로 보내자
        int temp = JaeUFill(move); move++;

        // 1-1 재우가 무사히 도착했다!
        if (temp == 1)  return move;
        // 1-2 재우가 다죽었다!
        if (temp == -1) return -1;
        

        // ii. fire fill!
        fireFill(layer);
        layer++;
    }

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    int res = getMovement();
    if (res == -1) cout << "impossible";
    else cout << res;
}