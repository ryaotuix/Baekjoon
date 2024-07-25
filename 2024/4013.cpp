#include <bits/stdc++.h>

using namespace std;

int ans;

int N, M;
const int MAX = 500000+1;

int start;
int id = 1;
int sccNum = 1;

vector<vector<int>> graph, SCC, sccGraph;
vector<int> d, money, group;                   // original graph       (1 ~ N inclusive)
vector<int> indegree, sccMoney, dp;            // SCC graph             (1 ~ sccNum-1 inclusive)
vector<bool> finished, restaurants;             
stack<int> stk;


void input()
{
    cin >> N >> M;

    graph.resize(N+1);
    finished.resize(N+1);
    d.resize(N+1);
    money.resize(N+1);
    group.resize(N+1);
    restaurants.resize(N+1);

    while(M--)
    {
        int a, b;
        cin >> a >> b;          // a -> b
        graph[a].push_back(b);
    }

    for (int i = 1; i <= N; i++)
    {
        cin >> money[i];
    }

    int n;
    cin >> start >> n;
    
    for (int i = 1; i <= n; i++)
    {
        int temp; cin >> temp;
        restaurants[temp] = true;
    }
}

// SCC 나누기
int dfs(int curr)
{
    d[curr] = id;
    id++;
    stk.push(d[curr]);

    int parent = d[curr];

    for (int next : graph[curr])
    {
        // if not visited,
        if (d[next] == 0)
        {
            parent = min(parent, dfs(next));
        }
        // else if visited but not finished
        else if (!finished[next])
        {
            parent = min(parent, d[next]);
        }
    }

    // remove this SCC from stack
    if (parent == d[curr])
    {
        vector<int> scc;

        while (true)
        {
            int t = stk.top();
            stk.pop();

            scc.push_back(t);
            group[t] = sccNum;
            finished[t] = true;

            if (t == curr)  break;
        }
        
        SCC.push_back(scc);
        sccNum++;
    }

    return parent;
}

void findSCC()
{
    for (int i = 1; i <= N; i++)
    {
        // if it is not visited, do dfs
        if (d[i] == 0)
        {
            dfs(i);
        }
    }
}

// 나눈 SCC 로 새로운 그래프 그리기
void buildSCCgraph()
{
    cout << 1;
    sccGraph.resize(sccNum );
    indegree.resize(sccNum );
    sccMoney.resize(sccNum );
    
    // iterate thru all edges if they are in different group, make scc graph
    for (int from = 1; from <= N; from++)
    {
        // sccMoney addition
        sccMoney[group[from]] += money[from];

        for (int to : graph[from])
        {
            // if from and to are in same SCC skip
            if (group[from] == group[to])
                continue;
            
            sccGraph[group[from]].push_back(group[to]);
            indegree[group[to]]++;
        }
    }
}

// bfs top sort
void topSort()
{
    cout << "wow";
    queue<int> q;
    
    // push SCC that has indegree of 0
    for (int i = 1; i < sccNum; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // dp resize and init dp
    dp.resize(indegree.size());
    for (int i = 1; i < sccNum; i++)
    {
        dp[i] = sccMoney[i];
    }

    
    while(!q.empty())
    {
        int curSCC = q.front();
        q.pop();

        for (int nextSCC : sccGraph[curSCC])
        {
            dp[nextSCC] = max(dp[nextSCC], dp[curSCC] + sccMoney[nextSCC]);
            indegree[nextSCC]--;

            if (indegree[nextSCC] == 0)
            {
                q.push(nextSCC);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    findSCC();
    buildSCCgraph();
    topSort();
    cout << dp[group[start]];
}