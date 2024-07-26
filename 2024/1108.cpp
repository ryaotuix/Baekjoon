#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
unordered_map<string, int> indegree;    // node name -> indegree
unordered_map<string, int> group;       // node name -> SCC number
unordered_map<string, vector<string>>  graph;  // node name -> next nodes

// SCC
unordered_map<int, vector<int>> sccGraph;                 // scc graph
vector<vector<string>> SCC;                               // store SCCs
unordered_map<int, int> weight;             // i-th scc importance (number of nodes in this SCC)
unordered_map<int, int> sccIndegree;    // i-th scc indegree

int id = 1;
unordered_map<string, int> d;
unordered_map<string, bool> finished;    
stack<string> stk;
unordered_map<string, ll> res;                         // 결과 저장    node itself -> importance

string target;

void input()
{
    int n; cin >> n;
    while(n--)
    {
        string to; cin >> to;
        int num; cin >> num;
        indegree[to];           // indegree of to is init as 0

        while(num--)
        {
            string from;    cin >> from;
            graph[from].push_back(to);

            indegree[from];
            indegree[to]++;
        }
    }
    cin >> target;
}

// dfs for tarjan algorithm
int dfs(string cur)
{
    d[cur] = id;
    id++;
    stk.push(cur);

    int parent = d[cur];
    
    for (string next : graph[cur])
    {
        // if d is not visited
        if (!d[next])
        {
            parent = min(parent, dfs(next));
        }
        // visited but not finished
        else if (!finished[next])
        {
            parent = min(parent, d[next]);
        }
    }

    // if self is parent of SCC
    if (parent == d[cur])
    {
        vector<string> scc;     // temporary scc
        int sccNum = SCC.size() + 1;

        while(true)
        {
            string temp = stk.top();
            stk.pop();
            
            /*
                1. push it to this scc group
                2. this node is finished
                3. mark scc num for this node
            */
            scc.push_back(temp);
            finished[temp] =  true;
            group[temp] = sccNum;

            if (temp == cur)
                break;
        }

        SCC.push_back(scc);
    }

    return parent;
}


// find SCC
void tarjan()
{
    // group SCC
    for (auto & it : indegree)
    {
        // if key is not found, do dfs
        if (!d[it.first])
        {
            dfs(it.first);  
        }
    }
}

void buildSCCGraph()
{
    // build SCC relationship
    for (auto & it : graph)
    {
        string cur = it.first;

        weight[group[cur]]++;       // node count for scc that cur is in is increased
        res[cur] = 1;

        sccIndegree[group[cur]];   // IMPORTANT : must store SCC that has indegree of 0 as well


        for (string & next : graph[cur])
        {
            // if in same SCC
            if (group[cur] == group[next])
            {
                continue;
            }
            
            // mark SCC relationship
            sccGraph[group[cur]].push_back(group[next]);   
            sccIndegree[group[next]]++;         // scc indegree of group next is increased

        }
    }
}

void topSortSCC()
{
    queue<int> q;
    for (int i = 1; i <= SCC.size();i ++)
    {
        if (sccIndegree[i] == 0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int sccIndex = q.front()-1;
        q.pop();
        for (auto curNode : SCC[sccIndex])
        {
            for (auto nxtNode : graph[curNode])
            {
                // cout << curNode << " to " << nxtNode << "\n";
                if (group[curNode] == group[nxtNode])
                    continue;
                
                res[nxtNode] += res[curNode];
                // cout << nxtNode << " ahs " << res[nxtNode] << "\n";
            }
        }

        for (auto nxtSCC : sccGraph[sccIndex + 1])
        {
            // cout << "next SCC num : " << nxtSCC << "\n";
            sccIndegree[nxtSCC]--;
            if (sccIndegree[nxtSCC] == 0)
                q.push(nxtSCC);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    tarjan();

    buildSCCGraph();
    topSortSCC();
    cout << res[target];
}