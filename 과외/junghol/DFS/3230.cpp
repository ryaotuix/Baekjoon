#include <bits/stdc++.h>

using namespace std;

const int maxi = 1e5;

typedef pair<int, int> pii;     // store information <node To, weight>

int n;
int start;
int finish;
vector<pii> AdjList[maxi + 5];          // org direction
bool visited[maxi + 5];

void input()
{
    cin >> n >> start >> finish;

    for (int i = 0; i < n-1; i++)
    {
        int from;
        int to;
        int weight;
        cin >> from >> to >> weight;
        AdjList[from].push_back({to, weight});
        AdjList[to].push_back({from, weight});
    }
}

// void printConnected(vector<pii> & connected)
// {
//     for (pii node : connected)
//         cout << "{" << node.first << ", " << node.second << "}, ";
//     cout << "\n";
// }

// void printLists()
// {
//     for (int i = 1; i <= n; i++)
//     {
//         cout << "Node " << i << ": " << "is connected to ";
//         printConnected(AdjList[i]);
//     }
//     cout << "\n";
// }

int maxEdge = 0;
int total = -1;
int finMaxEdge = 0;
void dfs(int currNode, int cumWeight)
{
    visited[currNode] = true;
    // cout << currNode << " " << maxEdge << "\n";

    // base case
    if (currNode == finish)
    {
        // cout << "BASE! " << cumWeight;
        total = cumWeight;
        finMaxEdge = maxEdge;
        return;
    }

    for (pii next : AdjList[currNode])
    {
        int nextNode = next.first;
        int edgeWeight = next.second;

        // if not visited
        if (!visited[nextNode])
        {
            visited[nextNode] = true;
            int temp = maxEdge;
            maxEdge = max(maxEdge, edgeWeight);

            dfs(nextNode, cumWeight + edgeWeight);

            visited[nextNode] = false;  
            maxEdge = temp;                         // max temp back to original (did not use this edge)
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    // cout << "\n";
    // cout << start << " " << finish << "\n";
    // cout << "\n";
    // printLists();
    dfs(start, 0);
    cout << total - finMaxEdge;
}