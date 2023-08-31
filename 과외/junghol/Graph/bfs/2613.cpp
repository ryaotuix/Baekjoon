#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000 + 5;
int m, n;
int grid[MAX][MAX];
typedef pair<int, int> pii;     // pii
queue<pii> Q;                   // Q to store locations


void input()
{
    cin >> m >> n;
    for (int i =0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            // if 1, push it to Q
            if (grid[i][j] == 1) Q.push({i, j});
        }
    }
}

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool OOB(int r, int c)
{
    if (r < 0 || r > m) return true;
    if (c < 0 || c > n) return true;
    return false;
}

void print()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << grid[i][j] << " ";
        cout << "\n";
    }
}

void bfs()
{
    bool filled = true;

    while(!Q.empty())
    {
        pii curr = Q.front(); Q.pop();
        int r = curr.first;
        int c = curr.second;
        int depth = grid[r][c];


        for (int i = 0; i < 4; i++)
        {
            int nextR = r + dr[i];
            int nextC = c + dc[i];

            // only if nextR and nextC is 0
            if (!OOB(nextR, nextC) && grid[nextR][nextC] == 0)
            {
                filled = false; // originally not all filled
            
                grid[nextR][nextC] = depth + 1;
                
                Q.push({nextR, nextC});
            }
        }

        // print();
        // cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    bfs();

    // if there still exist 0, return -1
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 0) return -1;


    int maxi = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            maxi = max(maxi, grid[i][j]);
    return maxi-1;

}