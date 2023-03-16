#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

typedef struct Node {
    char name = '0';
    int dfsNum = 0;                                             // DFS number
    int dfsFinNum = 0;                                          // DFS Finish number
    vector<Node *> adj;                                         // adjacent nodes array
} Node;

typedef pair<char, char> edge;


int getInd(char c);                                             // ex) Node name 'A' would return an index 1
void nodeInfo(Node * n);                                        // ex) "Node name 'A' has DFS num : 1 & DFS fin num : 16"

bool compareNode(const Node * a, const Node * b)
{
    return a->name < b->name;
}

class Graph
{
    public:
        // Fields
        int numNodes;   
        vector<Node *> nodes;                                   // Node vector of this graph
        vector<bool> visited;                                   // visited array
        int dfsCNT;                                             // DFS Count for DfsNum and DfsFinNum
        
        // extra fields
        vector<edge> backEdges;
        vector<edge> crossEdges;
        vector<edge> forwardEdges;

        // Constructor
        Graph(string filename, bool transpose);

        // Method
        void dfs(char startNodeName);                           // traverse the graph once from the given node
        void dfsALL();                                          // traverse the entire graph from the beginning       
        void graphInfo();                                       // print graph Info 

        // extra methods
        bool isBackEdge(const Node * a, const Node * b);
        bool isCrossEdge(const Node * a, const Node * b);
        bool isForwardEdge(const Node * a, const Node * b);

        // DO-ABLE
        bool bipartite();                                       // decide if it is bipartite
        bool isCyclic();                                        // decide if there is a cycle
        bool isEulerCycle();                                    // decide if it is Euler Cycle (can visit all nodes without visiting again)
        
        // DIFFICULT
        vector<Node *> findEulerianTrail();                     // find the Eulerian trail                        



};

// CONSTRUCTOR READ FROM A TXT FILE
Graph::Graph(string filename, bool transpose)
{
    // read from the txt file
    fstream f;
    f.open(filename, ios::in);                                  // open for input operation

    if (!f.is_open())                                           // if file is not opened
    {
        cout << "File is not opened\n";
        return;
    }

                                                                // if f.is_open()

    int nodeNum, edgeNum;
    f >> nodeNum >> edgeNum;                                    // read from the file and store information

    for (int i = 0; i < nodeNum; ++i)                           // fill out the vecotr nodes
    {
                                                                // create a Node "A, B, C, ..."
        Node * tempNode = new Node;
        tempNode->name = i + 'A';
        tempNode->dfsNum = 0;
        tempNode->dfsFinNum = 0;
        
        this->nodes.push_back(tempNode);                        // add to a vector
        this->visited.push_back(false);                         // defaut visited vector = false
        
    }

    
    //for (int i = 0; i < this->nodes.size(); ++i)    nodeInfo(this->nodes[i]);
    

    char from, to;
    while(f >> from >> to)  // read until the file ends hehehe
    {   
        if (transpose)
        {
            char temp = to;
            to = from;
            from = temp;
        }

        cout << from << " " << to << "\n";

        int fIndex = getInd(from);                              // index to use for adj    ex) index of 'A' is 0
        int tIndex = getInd(to);
        cout << fIndex << " " << tIndex << endl;

        Node * fNode = this->nodes[fIndex];
        Node * tNode = this->nodes[tIndex];
     
        fNode->adj.push_back(tNode);
    }
    
     // for (int i = 0; i < this->nodes.size(); ++i)   nodeInfo(this->nodes[i]); 

    // To recursively traverse lexiographically, we must sort the adj nodes
    for (int i = 0; i < this->nodes.size(); ++i)
    {
        Node * curr = this->nodes[i];
        sort(curr->adj.begin(), curr->adj.end(), compareNode);
    }   
}


// DFS traverse!
void Graph::dfs(char startNodeName)
{
    int index = getInd(startNodeName);
    Node * sNode = this->nodes[index];

    // DFS only when it is not visited
    if (this->visited[index] == false)
    {
        // i) this node is visited
        this->visited[index] = true;

        // ii) this node's DFS num
        this->dfsCNT = this->dfsCNT + 1;
        sNode->dfsNum = this->dfsCNT;

        // iii) recursively call dfs
        for (int i = 0; i < sNode->adj.size(); i++)
        {
            char adjName = sNode->adj[i]->name;                     // each name of adj node
            int adjInd = getInd(adjName);                           // each index of adj node 
            if (this->visited[adjInd] == false) dfs(adjName);       // recursively call dfs if it is not visited
        }

        // iv) this node's DFS Fin Num 
        this->dfsCNT = this->dfsCNT + 1;
        sNode->dfsFinNum = this->dfsCNT;
    }

}

void Graph::dfsALL() { for (auto curr : g.nodes) dfs(curr->name);}

void Graph::graphInfo()
{
    for (int i = 0; i < this->nodes.size(); ++i)
    {
        Node * curr = this->nodes[i];
        nodeInfo(curr);
    }
}

int getInd(char c) {
    if (c >= 65 && c <= 90) return c-'A'; 
    return -1;   
}

void nodeInfo(Node * n)
{
    cout << "Node name ' " << n->name << " ' has DFS num : " << n->dfsNum << " & DFS fin num : " << n->dfsFinNum << endl;
    if (n->adj.size() == 0)  cout << "No adjacent nodes\n";
    else 
    {
        cout << "Adjacent Nodes : {";
        for (int i = 0; i < n->adj.size(); i++) 
        {
            cout << n->adj[i]->name;
            if (i != n->adj.size() - 1) cout << ", ";
        } 
        cout << "}\n";
    }
}

int main()
{
    string filename = "nodesInput.txt";
    bool transpose = false;
    Graph g(filename, transpose);
    g.dfsALL();
    g.graphInfo();
}