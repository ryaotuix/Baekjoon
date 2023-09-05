#include <bits/stdc++.h>

using namespace std;

const int MAX = 2000 + 5;
int N, M;   // 섬, 다리
bool adjMatrix[MAX][MAX];
bool visited[MAX];

void input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        adjMatrix[s][e] = true;
    }
}

void bfs(int island)
{
    queue<int> Q;
    visited[island] = true;
    Q.push(island);

    while (!Q.empty())
    {
        int curr = Q.front(); Q.pop();

        // iterate over all islands, s
        for (int i = 1; i<= N; i++)
        {
            // if not visited and both are connected
            if (!visited[i] && adjMatrix[curr][i] && adjMatrix[i][curr])
            {
                visited[i] = true;
                Q.push(i);
            }
        }
    }
}

int getNum()
{
    int res = 0;
    for (int i = 1; i <= N; i++)
    {
        // 방문하지 않았다면
        if (!visited[i])
        {
            res++;
            bfs(i);
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();

    cout << getNum();
}