#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
const int NODES = 5;

bool visited[NODES+1]; // !!! in C++ global variable is initialized as 0 (false)
vector<int> adj[NODES+1]; // make
queue<int> q;

void dfs(int node)
{
  visited[node] = true; // change flag

  cout << "current node is " << node << endl;

  // loop through adjacent nodes
  for (int connectedNode : adj[node])
  {
    if (visited[connectedNode] == false)
      dfs(connectedNode);
  }
}

void bfs(int node)
{
  // add initial to queue & change flag
  visited[node] = true;
  q.push(node);

  while (!q.empty())
  {
    int currNode = q.front(); q.pop(); // get curr node
    cout << "Current node is " << currNode << endl;

    for(int nextNode : adj[currNode])
    {
      if (visited[nextNode] == false)
      {
        visited[nextNode] = true;
        q.push(nextNode);
      }
    }
  }
}

int main()
{
  // is it adjacent?
  adj[1].push_back(2);
  adj[2].push_back(1);

  adj[2].push_back(3);
  adj[3].push_back(2);

  adj[2].push_back(4);
  adj[4].push_back(2);

  adj[1].push_back(5);
  adj[5].push_back(1);

  cout << "=== dfs ===" << endl;
  dfs(1);

  cout << endl;
  cout << "=== bfs ===" << endl;

  memset(visited, 0, sizeof(visited));
  bfs(1);

}
