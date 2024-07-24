#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4 + 1;
/* Tarjan Algorithm basis */
int V, E;
vector<int> graph[MAX];
bool finished[MAX];
vector<vector<int>> SCC;
stack<int> stk;
int id = 1;
int d[MAX]; 

void sort2DVectorByFirstElement(std::vector<std::vector<int>>& vec) {
    // std::sort를 사용하여 오름차순으로 정렬
    std::sort(vec.begin(), vec.end(), 
              [](const std::vector<int>& a, const std::vector<int>& b) {
                  return a[0] < b[0];
              });
}

// return parents
int dfs(int cur)
{
    d[cur] = id;
    id++;
    stk.push(cur);

    // init its parent as itself
    int parent = d[cur];

    // iter all nexts 
    for (int next : graph[cur])
    {
        // if next is not visited
        if (d[next] == 0)
        {
            parent = min(parent, dfs(next));
        }
        // visited but not finished (SCC not found)
        else if(!finished[next])
        {
            parent = min(parent, d[next]);
        }
    }

    // when parent is itelf
    if (parent == d[cur])
    {
        vector<int> scc;

        while(true)
        {
            int t = stk.top();
            stk.pop();
            scc.push_back(t);
            finished[t] = true;

            if (t == cur)   break;
        }
        
        sort(scc.begin(), scc.end());
        SCC.push_back(scc);
    }

    return parent;
}

void tarjan()
{
    // build SCC
    for (int i = 1; i <= V; i++)
    {
        // dfs when not visited
        if (d[i] == 0)
            dfs(i);
    }

    cout << SCC.size() << "\n";
    
    sort2DVectorByFirstElement(SCC);

    for (int i = 0; i < SCC.size(); i++)
    {
        for (int x : SCC[i])
        {
            cout << x << " ";
        }
        cout << "-1\n";
    }
}

void input()
{
    cin >> V >> E;
    
    for (int i = 0; i < E; i++)
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

    input();
    tarjan();
}