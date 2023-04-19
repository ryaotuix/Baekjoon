#include <bits/stdc++.h>
#include <queue>
#include <limits>

using namespace std;
#define INF 1e9

typedef struct Node {
    char name;
    bool isRed;
}Node;

typedef pair<int, int> directedEdge; // <ind of Node Towards, weight>

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
unordered_map<int, char> toName = {
    {0, 'a'},
    {1, 'b'},
    {2, 'c'},
    {3, 'd'},
    {4, 'e'},
    {5, 'f'},
    {6, 'g'},
    {7, 'h'},
    {8, 'i'},
    {9, 's'},
    {10, 't'}
};

// PRINT
void printNode(const Node & n)
{
    cout << "Node : " << n.name << " ";
    if (n.isRed)
        cout << "RED";
    else
        cout << "BLUE";
    cout << "\n";
}
void printDirectedEdge(const directedEdge & de)
{  
    cout << "(" << toName[de.second] << ", " << de.first << "), ";
}

// Comparators
bool compareNode(const Node& a, const Node& b)
{
    return a.name < b.name;
}
struct compareDE {                      // make max heap??
    bool operator()(directedEdge const & a, directedEdge const & b)
    {
        return a.first < b.first;
    }
};


/* DFS */
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

void init(Node & startNode)
{
    // distances init INF and init start node as 0
    for (int i = 0; i < 11; ++i)
    {
        distances[i] = INF;
    }
    distances[toInd[startNode.name]] = 0;
}

void bfs(Node & startNode, vector<vector<int>> & adj)
{
    init(startNode);

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
        for (int i = 0; i < adj[adjInd].size(); ++i)
        {
            // Relax the shortest path if possible
            int ind = adj[adjInd][i];
            if (potential < distances[ind])
            {
                distances[ind] = potential;
            }
            Q.push(nodes[ind]);
        }
    }
}




/* DIJKSRA */

vector<vector<directedEdge>> weightedAdjList = {                                    // From
    {make_pair(toInd['d'], 9)},                                                     // a
    {make_pair(toInd['c'], 7)},                                                     // b
    {make_pair(toInd['f'], 15)},                                                    // c
    {make_pair(toInd['e'], 12)},                                                    // d
    {make_pair(toInd['g'], 4), make_pair(toInd['i'], 4)},                           // e
    {make_pair(toInd['h'], 8)},                                                     // f
    {make_pair(toInd['t'], 6)},                                                     // g
    {make_pair(toInd['t'], 10)},                                                    // h
    {make_pair(toInd['t'], 3)},                                                     // i
    {make_pair(toInd['a'], 5), make_pair(toInd['b'], 6), make_pair(toInd['e'], 27)},// s
    {}                                                                              // t
};

// Delete Invalid Edges
vector<vector<directedEdge>> makeNewWAL(vector<vector<directedEdge>> & WAL)
{
    vector<vector<directedEdge>> res;
    for (int i = 0; i < WAL.size(); i++)
    {
        vector<directedEdge> temp;
        for (int j = 0; j < WAL[i].size(); j++)
        {
            // u -> v (if u is blue and v is red it is invalid)
            if (!nodes[i].isRed && nodes[WAL[i][j].second].isRed)
            {
                continue;
            }
            temp.push_back(WAL[i][j]);
        }
        res.push_back(temp);
    }
    return res;
}
void printWeighteAdjList(vector<vector<directedEdge>> & WAL)
{
    for (int i = 0; i < WAL.size(); ++i)
    {
        cout << "Node[" << toName[i] << "]: {";
        for (directedEdge de : WAL[i])
        {
            printDirectedEdge(de);
        }
        cout << "}\n";
    }
}

// Materials
// Node nodes[11];      COMMON
// int distances[11];   COMMON

/* https://hub1234.tistory.com/33 참고*/
void dijkstra(Node & startNode, vector<vector<directedEdge>> & adj)
{
    init(startNode);

    priority_queue<directedEdge> pq;   // pq of directed edges according to weight
    // DE has <Node To-Ind, weight>
    
    pq.push({0, toInd[startNode.name]});   
    distances[toInd[startNode.name]] = 0;  // shortest path to the start node is 0

    while(!pq.empty())
    {
        int currCost = -pq.top().first;
        int currNode = pq.top().second;      // Actually currNode's index in nodes array
        pq.pop();

        cout << "Curr Node[" << toName[currNode] << "] : Cost " << currCost << endl;

        // !!!!  Shortest Path already
        if (distances[currNode] < currCost) continue;

        // adj node of curr node
        for (int i = 0; i < adj[currNode].size(); ++i)
        {
            int newCost = currCost + adj[currNode][i].first;
            int newNode = adj[currNode][i].second;

           cout << "Adj Node[" << toName[newNode] << "] : Cost " << newCost << endl;
           
            // relaxation step
            if (newCost < distances[newNode])  
            {
                int nodeToInd = adj[currNode][i].second;
                cout << "Node [" << toName[nodeToInd] << "] " << "original weight : " << distances[nodeToInd] << "\n";
                
                // Update
                distances[nodeToInd] = newCost;
                cout << "Node [" << toName[nodeToInd] << "] " << "new weight : " << distances[nodeToInd] << "\n";

                // push <-newCost, v> when u->v 
                pq.push(make_pair(-newCost, adj[currNode][i].first));
                cout << endl;
            }
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

/*
    // START
    printAdjList(adjList);
    vector<vector<int>> newAdjList = makeNewAdjList();      // get rid of invalid edges O(n+m)
    printAdjList(newAdjList);   


    // do BFS updates
    bfs(s, newAdjList);
    int indToCheck = toInd[t.name];
    cout << distances[indToCheck] << endl;
    // cout << "after bfs\n";
    // printDistances();
*/

    printWeighteAdjList(weightedAdjList);
    cout << endl;
    vector<vector<directedEdge>> newWAL = makeNewWAL(weightedAdjList);  // get rid of invalid edges O(n+m)
    printWeighteAdjList(newWAL);
    cout << endl;
    // do Dijkstra updates
    dijkstra(s, newWAL);
}