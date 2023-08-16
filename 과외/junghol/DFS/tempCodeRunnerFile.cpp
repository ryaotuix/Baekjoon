#include <bits/stdc++.h>

using namespace std;

int N;  // # of nodes
int M;  // # of edges
const int len = 1e5;
vector<int> adjList[len + 5];
bool visited[len + 5] = {0, };

void printAdj()
{
    for (int i = 0; i <= N; i++)
    {
        cout << "room " << i << " : {";

        for (int j = 0; j < adjList[i].size(); j++)
            cout << adjList[i][j] << " ";
        
        cout << endl;
    }
}
void input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int from;
        int to;
        cin >> from >> to;

        adjList[from].push_back(to);
        adjList[to].push_back(from);

        // sort this adj list 
        // e.g. 1 <-> 3
        // sort adjList[1] and adjList[3]
        sort(adjList[from].begin(), adjList[from].end());
        sort(adjList[to].begin(), adjList[to].end());
    }
}

void dfs(int room)
{
    if (visited[room])
        return;

    visited[room] = true;
    cout << room << " ";
    
    for (int nextRoom : adjList[room])
    {
        if (!visited[nextRoom])
            dfs(nextRoom);
    }
}

int main()
{
    input();
    // printAdj();
    dfs(1);
}