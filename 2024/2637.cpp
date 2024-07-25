#include <bits/stdc++.h>

using namespace std;

const int MAX = 100 + 1;
int gibon[MAX];         // if gibon[i] == 0 it is gibon 제품
int indegree[MAX];
int graph[MAX][MAX];    // [from][to] stores how many lines there are
int res[MAX];
int N, M;

void input()
{
    cin >> N >> M;
    while(M--)
    {
        int to, from, num;
        cin >> to >> from >> num;
        graph[to][from] = num;

        indegree[from] += num;
        gibon[to]++;
    }
}

// reverse top Sort
void topSort()
{
    queue<int> q;
    q.push(N);
    res[N] = 1;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int next = 1; next <= N; next++)
        {
            // if next exists
            if (graph[curr][next] != 0)
            {
                // next requires n * current
                res[next] += graph[curr][next] * res[curr];

                indegree[next] -= graph[curr][next];

                if (indegree[next] == 0)
                {
                    q.push(next);
                }
            }
        }
    }
}

void solve()
{
    for (int i = 1; i <= N; i++)
    {
        if (gibon[i] == 0)
        {
            cout << i << " " << res[i] << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    topSort();
    solve();
}