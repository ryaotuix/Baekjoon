#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000 + 1;
int indegree[MAX];
vector<int> graph[MAX];
int tme[MAX];
int res[MAX];
int target;
int N, K;

void init()
{
    for (int i = 0; i < MAX; i++)
    {
        indegree[i] = 0;
        graph[i].clear();
    }
}

void input()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> tme[i];
        res[i] = tme[i];
    }
    
    for (int i = 1; i <= K; i++)
    {
        int A, B;       
        cin >> A >> B;

        // A then B   A -> B
        graph[A].push_back(B);
        indegree[B]++;
    }

    cin >> target;
}

int topologicalSort()
{
    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int next : graph[curr])
        {
            indegree[next]--;
            res[next] = max(res[curr] + tme[next], res[next]);  // if we need to take longer path, we must

            if (indegree[next] == 0)
            {
                q.push(next);
            }

        }
    }
    // cout << "target " << target << " " << res[target] << "\n";

    return res[target];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;

    while(T--)
    {
        init();
        input();
        cout << topologicalSort() << "\n";
    }
}