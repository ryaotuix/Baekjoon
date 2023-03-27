#include <bits/stdc++.h>

using namespace std;

int Nodes, Edges;   // 1 <= Nodes <= 20,000     0 <= Edges <= 50,000
// vector<vector<int>> adjNodes(20000+1, vector<int>());
bool visited[20000+1] = {0};  // visited array
bool indegree[20000+1] = {0}; // check if the node has indegree
bool outdegree[20000+1] = {0}; // check if the node has outdegree

int totalIndegree = 0;
int totalOutdegree = 0;


void setUpAdjNodes()
{
    int nodeFrom, nodeTo;
    for (int i = 0; i < Edges; i++)
    {
        // adjNodes.clear();
        // adjNodes = vector<vector<int>> (20000+1, vector<int>());
        // // Hopefully erase adjNodes and make a memory for that again
        // cin >> nodeFrom >> nodeTo;
        // adjNodes[nodeFrom].push_back(nodeTo);

        if (indegree[nodeFrom] == false)
        {   
            indegree[nodeFrom] = true; 
            totalIndegree++;
        }

        if (outdegree[nodeTo] == false)
        {
            outdegree[nodeTo] = true;
            totalOutdegree++;
        }
    }

    cout << max(Nodes - totalIndegree, Nodes - totalOutdegree) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;

    while (T--)
    {
        cin >> Nodes >> Edges;
        setUpAdjNodes();
    }
}