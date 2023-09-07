#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000 + 5;
bool visited[MAX] = {false, };

int N, M;
vector<int> adjList[MAX];


void input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int s, e; cin >> s >> e;
        adjList[s].push_back(e);
        adjList[e].push_back(s);
    }
}

// store the connected components
int res[MAX];
double maxDensity = 0;
int maxSize = 0;


// function to get the density and size
pair<double, int> getCC(int node)
{
    // mark this node visited
    visited[node] = true;

    // set up a queue
    int Q[MAX]; Q[0] = node;
    int front = 0; int size = 1;
    int edges = 0;

    while (front < size)
    {
        int curr = Q[front];
        front++;
        edges += adjList[curr].size();

        for (int nextNode : adjList[curr])
        {
            if (!visited[nextNode])     // if not visited
            {
                visited[nextNode] = true;   // make it visited
                Q[size] = nextNode;         // put nextNode to the last index
                size++;                     // increase the size
            }   
        }
    }

    // density = size / # of edges
    double density = (double) edges / size;

    // copy to array only when desnity is higher
    if (density > maxDensity)
    {
        maxDensity = density;
        maxSize = size;

        for (int i = 0; i < size; i++) res[i] = Q[i];
    }

    return {density, size};
}

void getBiggestCC()
{
    for (int node = 1; node <= N; node++)
    {
        if (!visited[node])
        {
            pair<double, int> p = getCC(node);
        }
    }

    sort(res, res + maxSize);
    for (int i = 0; i < maxSize; i++) cout << res[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    getBiggestCC();
}