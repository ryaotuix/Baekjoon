#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000 + 1;
int N, M;
int p, q, r;    // p -> q costs r

int graph[MAX][MAX];
int indegree[MAX];
vector<int> path[MAX];
int dp[MAX];

void input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> p >> q >> r;
        graph[p][q] = r;
        indegree[q]++;
    }
}

void solve()
{
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            path[i].push_back({i});
        }
    }

    while(!q.empty())
    {
        
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}