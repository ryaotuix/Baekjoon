#include <bits/stdc++.h>

using namespace std;

int n;
int start;
int finish;
int m;
vector<int> adjList[100+5];     // adj List (undirected)
bool visited[100 + 5] = {false, };

void input()
{
    cin >> n;
    cin >> start >> finish;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int parent;
        int child;
        cin >> parent >> child;
        adjList[parent].push_back(child);
        adjList[child].push_back(parent);
    }
}

int shortest = 1e9;

// find the shortest depth where we can visit from start to finish
void dfs(int depth, int curr)
{
    visited[curr] = true;

    // base case:
    if (curr == finish)
    {
        shortest = depth;
        return;
    }

    for (int next : adjList[curr])
    {
        if (!visited[next])
        {
            visited[next] = true;
            dfs(depth + 1, next);
            visited[next] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();

    dfs(0, start);
    
    if (shortest == 1e9)
        cout << -1;
    else
        cout << shortest;
}