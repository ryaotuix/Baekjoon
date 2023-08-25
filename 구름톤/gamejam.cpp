#include <bits/stdc++.h>

using namespace std;


// materials
int n;
int gRow;
int gCol;
int pRow;
int pCol;
string grid[200 + 5][200 + 5];
bool visited[200 + 5][200 + 5];



void input()
{
    cin >> n;
    cin >> gRow >> gCol;
    cin >> pRow >> pCol;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> grid[i][j];
        }
    }
}


int getMove(string s)
{
    return s[0] - '0';
}

char getDir(string s)
{
    return s[1];
}

int getCnt()
{
    int cnt = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (visited[i][j])
                cnt++;
        }
    }

    return cnt;
}

int dfs(int currR, int currC, char direction, int move)
{
    // cout << currR << " " << currC << endl;
    // cout << "moving : " << direction << " left : " << move << endl;
    // base case
    if (visited[currR][currC] == true)
    {
        return getCnt();
    }

    // not based case
    visited[currR][currC] = true;

    // once we are done moving, update direction and move
    if (move == 0)
    {
        direction = getDir(grid[currR][currC]);
        move = getMove(grid[currR][currC]);
    }

    // when we still have to move,
    if (direction == 'L')
    {
        currC = currC - 1;
        if (currC == 0)
            currC = n;
    }
    if (direction == 'R')
    {
        currC = currC + 1;
        if (currC == n+1)
            currC = 1;
    }
    if (direction == 'U')
    {
        currR = currR - 1;
        if (currR == 0)
            currR = n;
    }
    if (direction == 'D')
    {
        currR = currR + 1;
        if (currR == n+1)
            currR = 1;
    }

    
    return dfs(currR, currC, direction, move - 1);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();

    int goorm = dfs(gRow , gCol, grid[gRow][gCol][1], getMove(grid[gRow][gCol]) );
    memset(visited, false, sizeof(visited));
    int player = dfs(pRow , pCol, grid[pRow][pCol][1], getMove(grid[pRow][pCol]) );

    if (goorm > player)
        cout << "goorm " << goorm;
    else
        cout << "player " << player;
}