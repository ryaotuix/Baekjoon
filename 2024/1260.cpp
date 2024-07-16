#include <bits/stdc++.h>

using namespace std;

const int MAX= 1000 + 1;
int adjMatrix[MAX][MAX];
bool visited[MAX];
int N, M; 
int start;

void input()
{
    cin >> N >> M >> start;
    for (int i = 0 ; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adjMatrix[a][b] += 1;
        adjMatrix[b][a] += 1;
    }
}

void dfs(int curr, int depth)
{
    cout << curr << " ";
    visited[curr] = true;
    for (int i = 0; i < MAX; i++)
    {
        if (adjMatrix[curr][i] != 0 && !visited[i])
        {
            dfs(i, depth+1);
        }
    }
}

void bfs()
{
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty())
    {
        int curr = q.front(); q.pop();
        visited[curr] = true;

        cout << curr << " ";
        for (int i = 0; i < MAX; i++)
        {
            if (adjMatrix[curr][i] != 0 && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void initVisited()
{
    for (int i = 0; i <= N; i++)
    {
        visited[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();

    dfs(start, 0);
    initVisited();
    cout << "\n";
    bfs();
}