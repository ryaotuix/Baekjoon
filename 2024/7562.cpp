#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

const int MAX = 300 + 1;
int grid[MAX][MAX];
int T;

// knight moving situations
int dx[8] = {2,1,2,1,-2,-1,-2,-1};
int dy[8] = {1,2,-1,-2,1,2,-1,-2};

void initGrid(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = 0;
        }
    }
}

bool OOB(int row, int col, int n)
{
    if (row < 0 || row > n) return true;
    if (col < 0 || col > n) return true;
    return false;

}

bool isDestination(pii a, pii b)
{
    if (a.first == b.first && a.second == b.second)   
        return true;
    return false;
}

int bfs(pii start, pii destination, int n)
{
    grid[start.first][start.second] = 1;

    queue<pii> q;
    q.push(start);

    while(!q.empty())
    {
        int currR = q.front().first;
        int currC = q.front().second;

        if (isDestination(q.front(), destination))               
            return grid[currR][currC];

        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nextR = currR + dy[i];
            int nextC = currC + dx[i];

            // if next is not out of bound
            if (!OOB(nextR, nextC, n))
            {
                // if visited, continue
                if (grid[nextR][nextC] != 0)
                    continue;

                grid[nextR][nextC] = grid[currR][currC] + 1;
                q.push({nextR, nextC});  
            }
        }
    }

    return 1;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;

    while(T--)
    {
        int n;
        cin >> n;
        initGrid(n);

        pii start, destination;
        cin >> start.first >> start.second;
        cin >> destination.first >> destination.second;


        cout << bfs(start, destination, n) - 1 << "\n";
    }
}