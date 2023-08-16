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
    }

    for (int i = 1; i <= N; i++)
        sort(adjList[i].begin(), adjList[i].end());
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