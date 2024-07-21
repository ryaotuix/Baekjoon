#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000 + 1;
int N, M;
vector<int> graph[MAX];
int indegree[MAX];



void input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;

        // A < B 
        indegree[B]++;
        graph[A].push_back(B);  // A -> B
    }
}

void topologicalSort()
{   
    queue<int> q;
    
    // print all indegree 0
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            cout << i << ' ';
        }
    }

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int next : graph[curr])
        {
            indegree[next]--;
            if (indegree[next] == 0)
            {
                q.push(next);
                cout << next << ' ';
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    topologicalSort();
}