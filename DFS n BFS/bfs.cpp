#include <bits/stdc++.h>
#include <queue>

using namespace std;

// Material
const int numNode = 5;
queue<int> q;
vector<int> adj[numNode + 1];
bool visited[numNode + 1];          // default false

void bfs(int startNode)
{
    // first mark this node visited and add it to the queue
    if (!visited[startNode])
    {
        visited[startNode] = true;
        q.push(startNode);
    }

    // Until queue is empty
    while (!q.empty())
    {
        int currNode = q.front();   q.pop();

        cout << currNode << " ";

        // for all adjacent nodes of the current node
        for (int adjacent : adj[currNode])
        {
            if (visited[adjacent] == false)             // if it is not already visited
            {
                q.push(adjacent);                       // add it to the queue
                visited[adjacent] = true;               //  mark it as visited
            }
        }

    }
}

int main()
{
    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[2].push_back(4);
    adj[4].push_back(2);

    adj[1].push_back(5);
    adj[5].push_back(1);

    bfs(1);

    // Let's start from 1
}