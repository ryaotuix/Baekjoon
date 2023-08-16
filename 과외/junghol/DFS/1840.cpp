#include <bits/stdc++.h>

using namespace std;


// materials
int col;
int row;
int grid[105][105];
bool visited[105][105];
int cheeseCnt = 0;
int latestCheese;

// directions
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void printGrid()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

void input()
{
    cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> grid[i][j];

            if (grid[i][j])
                cheeseCnt++;
        }
    }
}

bool isCheese(int r, int c)
{
    if (grid[r][c] == 1)
        return true;
    return false;
}

bool inRange(int r, int c)
{
    if (r >= row || r < 0)
        return false;
    if (c >= col || c < 0)
        return false;

    return true;
}

void dfs(int r, int c)
{
    // if this is visited, do nothing and return
    if (visited[r][c])
        return;

    // otherwise, make this visited
    visited[r][c] = true;

    // if it is not visited and cheese
    if (isCheese(r, c))
    {
        grid[r][c] = 0; // uncheese
        cheeseCnt--;    
        return;
    }

    // if this is not visited and not cheese
    if (!isCheese(r,c))
    {
        for (int i = 0; i < 4; i++)
        {
            int nextR = r + dr[i];
            int nextC = c + dc[i];

            // if not in range, skip this possibility
            if (!inRange(nextR, nextC))
                continue;
            
            // otherwise
            dfs(nextR, nextC);
        }
    }
}


int main()
{
    input();
    int ret = 0;

    // until cheese becomes 0
    while(cheeseCnt)
    {
        latestCheese = cheeseCnt;
        ret++;

        // make all unvisited
        memset(visited, false, sizeof(visited));


        // printGrid();
        
        dfs(0,0);
    }


    cout << ret << "\n";
    cout << latestCheese;


}