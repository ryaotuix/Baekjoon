#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Materials
int numNodes = -1;       // number of nodes  
bool * visited;     // visited arr
vector<int> * adj;  // adjacency list

void showAdj()
{
    if (numNodes == -1) return;
    for (int i = 1; i <= numNodes; i++)
    {
        cout << "Node " << i << " has {";
        for (auto j : adj[i])
        {
            cout << j << ", ";
        }
        cout << "}\n";
        
    }
}

void dfs(int startNode)
{
    visited[startNode] = true;      // mark this node as visited

    cout << "Current Node is <" << startNode << ">" << endl;
    for (auto connectedNode : adj[startNode])
    {
        if (visited[connectedNode] == false) dfs(connectedNode); 
    }
}

int main()
{
    cout << "How many nodes do you want to have? Enter : ";
    cin >> numNodes;

    visited = new bool[numNodes + 1];
    adj = new vector<int>[numNodes + 1];
    
    int N;
    cout << "How many edges do you want to add? Enter : ";
    cin >> N;

    while (N--)
    {
        int x, y;
        cout << "Enter it in <x, y> format\n";
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    showAdj();
    dfs(1);
}