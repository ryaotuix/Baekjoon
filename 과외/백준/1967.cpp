#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000 + 5;

typedef pair<int, int> pii;
int n;
vector<pii> adjList[MAX];
bool visited[MAX];
int diameter = 0;

void input()
{
    cin >> n;
    int from, to, weight;
    for (int i = 0; i < n-1; i++)
    {
        cin >> from >> to >> weight;
        adjList[from].push_back({to, weight});
        adjList[to].push_back({from, weight});
    }
    
}

void dfs(int length, int curr)
{
    // cout << "curr : " << curr <<  " length : " << length << "\n";
    diameter = max(diameter, length);

    visited[curr] = true;

    for (pii nextNode : adjList[curr])
    {
        int next = nextNode.first;
        int weight = nextNode.second;
        // curr to next exitts and next is not visited
        if (!visited[next])
        {
            dfs(length + weight, next);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    for (int i = 1; i <= n; i++)
    {
        memset(visited, false, sizeof(visited));
        dfs(0, i);
    }
        
    cout << diameter;
}