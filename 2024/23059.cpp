#include <bits/stdc++.h>

using namespace std;

int N;
unordered_map<string, int> um;  // item name, index
unordered_map<int, string> m;   // index, item name
typedef pair<int, int> pii;     // <index, topological level>

const int MAX = 200000 + 1;
vector<int> graph[MAX];
vector<string> topology[MAX];
int indegree[MAX];
int ind = 1;

void input()
{
    cin >> N;
    int temp = N;
    while(temp--)
    {
        string a, b;    // a-> b
        cin >> a >> b;

        if (!um[a])
        {
            um[a] = ind;
            m[ind] = a;
            ind++;
        }
        if (!um[b])
        {
            um[b] = ind;
            m[ind] = b;
            ind++;
        }

        int indA = um[a];
        int indB = um[b];

        // cout << m[indA] << " is stored as " << indA << " and pointing at " << m[indB] << " stored at " << indB << "\n";
        graph[indA].push_back(indB);
        indegree[indB]++;
    }

    // for (int i = 1; i <= N; i++)
    // {
    //     cout << i << ':';
    //     cout << graph[i].size();
    //     for (int n : graph[i])
    //     {
    //         cout << n << " ";
    //     }
    //     cout << "\n";
    // }
}


void topologicalSort()
{
    queue<pii> q;
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push({i, 1});
        }
    }

    int len = 1;
    int cnt = 1;

    while(!q.empty())
    {
        pii p = q.front();
        q.pop();
        cnt++;

        int curr = p.first;
        int topLev = p.second;
        len = max(len, topLev);

        topology[topLev].push_back(m[curr]);

        for (int next : graph[curr])
        {
            indegree[next]--;
            if (indegree[next] == 0)
            {
                q.push({next, topLev+1});
            }
        }
    }

    for (int i = 1; i <= len; i++)
    {
        sort(topology[i].begin(), topology[i].end());
        for (string s : topology[i])
            cout << s << "\n";
    }

    return;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    topologicalSort();
}