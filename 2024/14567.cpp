#include <bits/stdc++.h>

using namespace std;

int N, M;
const int MAX = 1000 + 1;
vector<int> graph[MAX];
int indegree[MAX];
int semester[MAX];

void input()
{
    cin >> N >> M;
    while(M--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
}

void topSort()
{
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
            semester[i] = 1;
    }

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur])
        {
            semester[next] = max(semester[next], semester[cur] + 1);

            indegree[next]--;

            if (indegree[next] == 0)
                q.push(next);
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    topSort();
    for (int i = 1; i <= N; i++)
    {
        cout << semester[i] << " ";
    }
}