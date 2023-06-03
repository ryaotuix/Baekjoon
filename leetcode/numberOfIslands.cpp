// #include <bits/stdc++.h>

// using namespace std;

// int cnt = 0;

// void print2D(vector<vector<bool>> & v)
// {
//     for (vector<bool> each : v)
//     {
//         for (bool i : each)
//         {
//             if (i)
//                 cout << "t";
//             else
//                 cout << "f";
//             cout << " ";
//         }
        
//         cout << endl;
//     }
// }

// void dfs(vector<vector<char>> & grid, vector<vector<bool>> & visited, int row, int col)
// {
//     // Base Case:
//         // 0. it is out of bound
//     if (row < 0 || row > grid.size()-1 || col < 0 || col > grid[0].size()-1)
//         return;

//         // 1. it is visited
//     if (visited[row][col] == true)
//         return;

//         // 2. it is 0
//     if (grid[row][col] == '0')
//         return;

//     // cout << "0 check" << endl;
    

//     // Otherwise,

//     // make this visited
//     visited[row][col] = true;
//     // print2D(visited);

//     // traverse 상하좌우
//     dfs(grid, visited, row-1, col); // 상
//     dfs(grid, visited, row+1, col); // 하
//     dfs(grid, visited, row, col-1); // 좌
//     dfs(grid, visited, row, col+1); // 우
// }

// int numIslands(vector<vector<char>> & grid)
// {
//     int nRow = grid.size();
//     int nCol = grid[0].size();
//     //  create 2D visited grid
//     vector<vector<bool>> visited(nRow, vector<bool>(nCol, false));
    
//     for (int i = 0; i < nRow; i++)
//     {
//         for (int j = 0; j < nCol; j++)
//         {
//             if (visited[i][j] == false && grid[i][j] == '1')
//             {
//                 dfs(grid, visited, i, j);
//                 cnt++;
//             }
//         }
//     }

//     return cnt;
// }


#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

// current row, col
typedef pair<int, int> pii; 
            
int dx[4] = {0, 0, -1, 1};  // column
int dy[4] = {-1, 1, 0, 0};  // row

// out of bound check (nRow and nCol : v.size())
bool OOB(int nRow, int nCol, int row, int col)
{
    return (row < 0 || row > nRow-1 || col < 0 || col > nCol-1);
}

void bfs(vector<vector<char>> & grid, vector<vector<bool>> & visited, int row, int col)
{
    // 0. mark this visited
    visited[row][col] = true;


    int nRow = grid.size();
    int nCol = grid[0].size();

    // BFS
    queue<pii> q;
    q.push({row, col});             // start with pii (row, col)

    while(!q.empty())
    {
        pii curr = q.front(); q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextRow = curr.first + dy[i];
            int nextCol = curr.second + dx[i];

            // skip out of bound index
            if (OOB(nRow, nCol, nextRow, nextCol))
                continue;

            // if it next movement is valid, ('1' and not visited, add to the queue)
            if (grid[nextRow][nextCol] == '1' && !visited[nextRow][nextCol])
            {
                visited[nextRow][nextCol] = true;                               // make each one visited
                q.push({nextRow, nextCol});
            }
        }
    }
}

int numIslands(vector<vector<char>> & grid)
{
    int nRow = grid.size();
    int nCol = grid[0].size();
    vector<vector<bool>> visited(nRow, vector<bool>(nCol, false));

    // bfs
    for (int i = 0; i < nRow; i++)
    {
        for (int j = 0; j < nCol; j++)
        {
            if (visited[i][j] == false && grid[i][j] == '1')
            {
                bfs(grid, visited, i, j);
                cnt++;
            }
        }
    }
    return cnt;
}


int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    int i = numIslands(grid);
    cout << i;
}