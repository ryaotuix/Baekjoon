#include <bits/stdc++.h>

using namespace std;

int N, M;
const int MAX = 1000 + 1;
vector<int> graph[MAX];
int indegree[MAX];

void input()
{
    cin >> N >> M;
    int num;

    for (int pd = 1; pd <= M; pd++)
    {
        cin >> num;
        vector<int> temp;
        for (int i = 0; i < num; i++)
        {
            int a; cin >> a;
            temp.push_back(a);
        }

        for (int i = 0; i < num; i++) 
        {
            for (int j = i+1; j < num; j++)
            {
                int before = temp[i];
                int after = temp[j];
                // cout << "before ; " << before << " after : " << after << "\n";
                // i -> j (i is prereq for j)
                graph[before].push_back(after);
                indegree[after]++;
            }
        }
    }
}

void printIndegree()
{
    for (int i = 1; i <= N; i++)
        cout << indegree[i] << " ";
    cout << "\n";
}

void topSort()
{
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> res;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        res.push_back(curr);
        
        for (int next : graph[curr])
        {
            indegree[next]--;

            // add when next is met
            if (indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }

    // if not the same number
    if (res.size() != N)
    {
        cout << 0;
    }
    else
    {
        for (int v : res)
        {
            cout << v << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    // printIndegree();
    topSort();
}