#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 2000 + 5;

// arr of min heap
priority_queue<int, vector<int>, greater<int>> adjList[MAX];
bool visited[MAX];
int n, m, k;
int lastNode;

void input()
{
    cin >> n >> m >> k;
    lastNode = k;
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        adjList[from].push(to);
        adjList[to].push(from);
    }
}

int dfs(int curr, int depth)
{
    visited[curr] = true;
    // cout << "curr, depth : " << curr << ", " << depth << "\n";

    while (!adjList[curr].empty())
    {
        int nextNode = adjList[curr].top(); adjList[curr].pop();
        // it next ndoe is not visited,
        if (!visited[nextNode])
        {
            visited[nextNode] = true;
            lastNode = nextNode;
            return dfs(nextNode, depth + 1);
        }
    }

    return depth;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    cout << dfs(k, 1) << " " << lastNode;
}