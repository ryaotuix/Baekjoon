#include <bits/stdc++.h>

using namespace std;

int n;
int m;
vector<int> adjList[1000 + 5];
unordered_map<int, int> visited;    // node num -> visited


void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int from; int to;
        cin >> from >> to;
        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }
}

void dfs(int currNode)
{
    // cout << currNode << " ";
    visited[currNode]++;
    for (int adjNode : adjList[currNode])
    {
        if (!visited[adjNode])
        {
            visited[adjNode]++;
            dfs(adjNode);
        }
    }
}

int getCC()
{
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            ret++;
            dfs(i);
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << getCC();
}