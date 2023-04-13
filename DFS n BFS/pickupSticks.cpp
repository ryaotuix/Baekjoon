#include <bits/stdc++.h>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> degree;
queue<int> res;
int cnt = 0;
vector<bool> inProcess;

int main()
{
    int n, m; cin >> n >> m;
    // n is number of sticks

    degree = vector<int> (n+1, 0);  // make vecotr size n initialized 0
    adj = vector<vector<int>> (n+1, vector<int>()); 
    inProcess = vector<bool> (n+1, false);

    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        degree[v]++;
    }


    // TOP SORT
    queue<int> Q;
    // Add all the node with indegree of 0
    for (int i = 1; i<=n; ++i)
    {
        if (degree[i] == 0)
            Q.push(i);
    }


    // Add it 
    while (!Q.empty())
    {
        int curr = Q.front(); Q.pop();

        // iterate through the next nodes of curr
        for (int adjN : adj[curr])
        {
            degree[adjN]--;                         // decrement indegre
            if (degree[adjN] == 0) Q.push(adjN);    // if its indegree becomes 0, add it to the next topological sort
        }
        res.push(curr);
        cnt++;
    }

    // NOT DAG if cnt is bigger than m
    // there still exist a node with indegree more than 0
    for (int i = 1; i <= n; ++i)
    {
        if (degree[i] != 0)
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }

    // Print out the result
    while (!res.empty())
    {
        cout << res.front() << endl;
        res.pop();
    }
}