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
    q.push(1);
    path[1].push_back(1);

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int next = 1; next <= N; next++)
        {
            // if curr -> next has path
            if (graph[curr][next] != 0)
            {
                // 바뀔거면
                if (dp[next] < dp[curr] + graph[curr][next])
                {
                    dp[next] = dp[curr] + graph[curr][next];        // 합 업데이트

                    path[next] = path[curr];                        // path vector 업데이트
                    path[next].push_back(next);
                }

                indegree[next]--;

                if (indegree[next] == 0)
                {
                    q.push(next);
                }
            }
        }
    }

    
    cout << dp[1] << "\n";
    for (int i : path[1])
    {
        cout << i << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}