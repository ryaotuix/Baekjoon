#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000+1;

int N;
int tme[MAX];
int dp[MAX];                // store critical path length
int indegree[MAX];
vector<int> graph[MAX];

void input()
{
    cin >> N;
    for (int i = 1 ; i <= N; i++)
    {
        cin >> tme[i];
        dp[i] = tme[i];

        int temp; cin >> temp;
        indegree[i] += temp;

        while(temp--)
        {
            int prereq; 
            cin >> prereq;
            graph[prereq].push_back(i);
        }
    }
}

void topSort()
{
    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int next : graph[curr])
        {
            dp[next] = max(dp[next], dp[curr] + tme[next]);
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
    
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans;
}