#include <bits/stdc++.h>

using namespace std;

/*
    N개의 문제는 모두 풀어야 한다.
    먼저 푸는 것이 좋은 문제가 있는 문제는, 먼저 푸는 것이 좋은 문제를 반드시 먼저 풀어야 한다.
    가능하면 쉬운 문제부터 풀어야 한다.

    1 번이 제일 쉽다
*/

int N, M;
const int MAX = 32000 + 1;
int indegree[MAX];
vector<int> graph[MAX];

void input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;  // A -> B
        indegree[B]++;
        graph[A].push_back(B);  // A -> B
    }
}

void topSort()
{
    priority_queue<int> pq; // it is max heap in c++

    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)   pq.push(-1 * i);
    }

    while(!pq.empty())
    {
        int curr = -1 *pq.top();
        pq.pop();
        
        cout << curr << " ";

        for (int next : graph[curr])
        {
            indegree[next]--;
            if (indegree[next] == 0)
            {
                pq.push(-1 * next);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    topSort();
}