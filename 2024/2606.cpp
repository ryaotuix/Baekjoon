#include <bits/stdc++.h>

using namespace std;

const int MAX = 100 + 1;
int grid[MAX][MAX];
bool visited[MAX];
int n;
int m;

void input()
{
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        grid[a][b] = 1;
        grid[b][a] = 1;
    }
}

int bfs()
{
    int ans = 0;
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty())
    {
        int currComp = q.front();
        q.pop();
        cout << currComp << "\n";
        ans++;

        for (int i = 0; i <= n; i++)
        {
            // no edge, continue
            if (grid[currComp][i] != 1)
                continue;

            // if nextcomputer is not visited,
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    return ans-1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();

    cout << bfs();
}