#include <bits/stdc++.h>

using namespace std;

const int MAX = 1005;
// materials
int n, k;
int grid[MAX][MAX];
bool visited[MAX][MAX];
int res = 0;
int currCnt = 0;
int dr[4]= {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
unordered_map<int, int> um; // 단지 # -> size

typedef pair<int, int> pii; // row, col
queue<pii> Q;


void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
}

bool OOB(int r, int c)
{
    if (r > n || r < 0)
        return true;
    if (c > n || c < 0)
        return true;
    return false;
}

int dfs(int row, int col, int & size, int & num)
{
    visited[row][col] = true;
    size++;

    // see if we can go 상하좌우
    for (int i = 0; i < 4; i++)
    {
        int nextR = row + dr[i];
        int nextC = col + dc[i];
        // only dive in when the number is same and not out of bound and not visited
        if (!OOB(nextR, nextC) && grid[nextR][nextC] == num && !visited[nextR][nextC])
        {
            dfs(nextR, nextC, size, num);
        }
    }

    return size;
}

int bfs(int num)
{
    int ret = 0;
    while (!Q.empty())
    {
        ret++;
        pii curr = Q.front(); Q.pop();
        int row = curr.first;
        int col = curr.second;
        for (int i = 0; i < 4; i++)
        {
            int nextR = row + dr[i];
            int nextC = col + dc[i];
            // only dive in when the number is same and not out of bound and not visited
            if (!OOB(nextR, nextC) && grid[nextR][nextC] == num && !visited[nextR][nextC])
            {
                visited[nextR][nextC] = true;
                Q.push({nextR, nextC});
            }
        }

    }
    return ret;
}

void printV()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << visited[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}

void find()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                int s = 0;
                visited[i][j] = true;
                Q.push({i, j});
                int size = bfs(grid[i][j]);
                // if this connected componenet is greater than k,

                // when size becomes greater than k
                if (size >= k)
                {
                    // cout << grid[i][j] << " " << size << "\n";
                    // printV();
                    um[grid[i][j]]++;   // add to grid[i][j]
                    // cout <<  grid[i][j] << " count : " << um[grid[i][j]] << "\n";

                    // if this cnt is greater than count
                    if (um[grid[i][j]] > currCnt)
                    {
                        currCnt = um[grid[i][j]];   // change current Count
                        res = grid[i][j];           // change result to current number
                    } 
                    
                    // when cnt is the same then choose a greater number
                    if (um[grid[i][j]] == currCnt)
                        res = max(res, grid[i][j]);     // change result 
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    find();
    cout << res;
}