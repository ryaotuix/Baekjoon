#include <bits/stdc++.h>
#include <queue>
#include <limits>

using namespace std;
#define INF 9999

typedef struct Node {
    char name;
    bool isRed;
}Node;

void printNode(const Node & n)
{
    cout << "Node : " << n.name << " ";
    if (n.isRed)
        cout << "RED";
    else
        cout << "BLUE";
    cout << "\n";
}

// comparator
bool compareNode(const Node& a, const Node& b)
{
    return a.name < b.name;
}

// hashmap to change Node name to node array index
unordered_map<char, int> toInd = {
    {'a', 0},
    {'b', 1},
    {'c', 2},
    {'d', 3},
    {'e', 4},
    {'f', 5},
    {'g', 6},
    {'h', 7},
    {'i', 8},
    {'s', 9},
    {'t', 10}
};

// Materials
Node nodes[11];
int distances[11];

vector<vector<int>> adjList = {
    {3},
    {2},
    {5},
    {4},
    {6, 8},
    {7},
    {10},
    {10},
    {10},
    {0, 1, 4},
    {}
};

// Delete Invalid Edges
vector<vector<int>> makeNewAdjList()
{
    vector<vector<int>> res;

    for (int i = 0; i < adjList.size(); i++)
    {
        vector<int> temp;
        for (int j = 0; j < adjList[i].size(); j++)
        {
            int ind = adjList[i][j];    // index to Look up nodes array
            if (!nodes[i].isRed && nodes[ind].isRed) 
            {
                continue;   // if u is Blue and v is Red then invalid index
            } 
            temp.push_back(ind);
        }
        res.push_back(temp);
    }
    return res;
}

// Print Materials
void printNodes()
{
    for (auto node : nodes)
    {
        printNode(node);
    }
    cout << endl;
}
void printAdjList(vector<vector<int>> & adjList)
{
    cout << "Adj List: \n";
    for (int i = 0; i < adjList.size(); ++i)
    {
        cout << "{";
        for (int j = 0; j < adjList[i].size(); ++j)
        {
            cout << adjList[i][j] << ", ";
        }
        cout << "}\n";
    }
    cout << endl;
}
void printDistances()
{
    cout << "{";
    for (int i = 0; i < 11; ++i)
    {
        cout << distances[i] << ", ";
    }
    cout << "}\n";
}


void bfs(Node & startNode)
{
    // materials
    queue<Node> Q;
    Q.push(startNode);

    while(!Q.empty())
    {
        // printDistances();
        Node curr = Q.front(); Q.pop();
        int adjInd = toInd[curr.name];
        int potential = distances[adjInd] + 1;
        // cout << potential << "\n";
        // for each adj node
        for (int i = 0; i < adjList[adjInd].size(); ++i)
        {
            // Relax the shortest path if possible
            int ind = adjList[adjInd][i];
            if (potential < distances[ind])
            {
                distances[ind] = potential;
            }
            Q.push(nodes[ind]);
        }
    }

}



int main()
{
    Node a  = {'a', true}; nodes[0] = a;
    Node b  = {'b', true}; nodes[1] = b;
    Node c  = {'c', true}; nodes[2] = c;
    Node d  = {'d', true}; nodes[3] = d;
    Node e  = {'e', false}; nodes[4] = e;
    Node f  = {'f', false}; nodes[5] = f;
    Node g  = {'g', false}; nodes[6] = g;
    Node h  = {'h', false}; nodes[7] = h;
    Node i  = {'i', true}; nodes[8] = i;
    Node s  = {'s', true}; nodes[9] = s;
    Node t  = {'t', false}; nodes[10] = t;

    // distances init INF and init start node as 0
    for (int i = 0; i < 11; ++i)
    {
        distances[i] = INF;
    }
    distances[toInd[s.name]] = 0;



    // START
    printAdjList(adjList);
    vector<vector<int>> newAdjList = makeNewAdjList();      // get rid of invalid edges O(n+m)
    printAdjList(newAdjList);   


    // do BFS updates
    bfs(s);
    int indToCheck = toInd[t.name];
    cout << distances[indToCheck] << endl;
    // cout << "after bfs\n";
    // printDistances();


}