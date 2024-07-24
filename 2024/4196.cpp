#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000 + 1;
int N, M;

int id = 1;
int d[MAX];
bool finished[MAX];

int sccIndegree[MAX];
vector<vector<int>> SCC;   // 몇번 scc에 몇번 id 노드가 있는지 저장

int group[MAX];             // i 번째 노드의 scc 번호 저장
stack<int> stk;
vector<int> graph[MAX];

void init()
{
    for (int i = 0; i < MAX; i++)
    {
        d[i] = 0;
        finished[i] = false;
        sccIndegree[i] = 0;
        group[i] = 0;
        graph[i].clear();
    }
    SCC.clear();
}

// dfs for tarjan
int dfs(int cur)
{
    d[cur] = id;
    id++;
    stk.push(cur);

    int parent = d[cur];

    for (int next : graph[cur])
    {
        // not visited
        if (d[next] == 0)
        {
            parent = min(parent, dfs(next));
        }
        // visited but not finished
        else if (!finished[next])
        {
            parent = min(parent, d[next]);
        }
    }

    // if parent itself, 
    if (parent == d[cur])
    {
        vector<int> scc;
        while(true)
        {
            int t = stk.top();
            stk.pop();
            scc.push_back(t);

            group[t] = SCC.size() + 1;  // how many sccs there are
            finished[t] = true;

            // break when cur is found
            if(t == cur)
                break;
        }

        SCC.push_back(scc);
    }

    return parent;
}

void tarjan()
{
    // make SCC
    for (int i = 1; i<= N; i++)
    {
        // if not viisted, dfs it
        if (d[i] == 0)
            dfs(i);
    }

    for (int i = 1; i <= N; i++)
    {
        for (int next : graph[i])
        {
            // if same SCC
            if (group[i] == group[next])   
                continue;
            
            // increase indegree of next SCC
            sccIndegree[group[next]]++;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= SCC.size(); i++)
    {
        if (sccIndegree[i] == 0)
            cnt++;
    }

    cout << cnt << "\n";
}

void input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
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
        tarjan();
    }
}