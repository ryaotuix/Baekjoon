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

typedef pair<Node *, Node *> edge;


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
        int dfsCNT = 0;                                         // DFS Count for DfsNum and DfsFinNum
        vector<edge> treeEdges;

        // Constructor
        Graph(string filename, bool transpose);

        // Method
        void dfs(char startNodeName);                           // traverse the graph once from the given node
        void dfsALL(char starNodeName);                         // traverse the entire graph from the beginning       
        void graphInfo();                                       // print graph Info 
        Node * getNode(char nodeName);                          // get node 

        // extra methods
        bool isTreeEdge(const Node * u, const Node * v);
        bool isBackEdge(const Node * u, const Node * v);
        bool isCrossEdge(const Node * u, const Node * v);
        bool isForwardEdge(const Node * u, const Node * v);
        void edgeInfo(char uName, char vName);

        // DO-ABLE
        void getSTCC();                                         // get Strongly Connected Components in a directed Graph in O(n+m) time 
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

        // cout << from << " " << to << "\n";

        int fIndex = getInd(from);                              // index to use for adj    ex) index of 'A' is 0
        int tIndex = getInd(to);
        // cout << fIndex << " " << tIndex << endl;

        Node * fNode = getNode(from);
        Node * tNode = getNode(to);
     
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
    Node * sNode = getNode(startNodeName);

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
            if (this->visited[adjInd] == false)                     // recursively call dfs if it is not visited
            {
                edge tempEdge = make_pair(sNode, getNode(adjName));
                treeEdges.push_back(tempEdge);
                dfs(adjName);   
            }    
            
             
        }

        // iv) this node's DFS Fin Num 
        this->dfsCNT = this->dfsCNT + 1;
        sNode->dfsFinNum = this->dfsCNT;
    }

}

void Graph::dfsALL(char startNodeName) {
    dfs(startNodeName);
    for (auto curr : this->nodes)
        this->dfs(curr->name);
}

// EDGE GOING FROM U TO V (u,v)

bool Graph::isTreeEdge(const Node * u, const Node * v)
{
    // This is Linear Search, but we can make it nlogn by sorting and doing a binary search... 그치만 귀찮은걸..
    for (auto treeEdge : this->treeEdges)
    {
        if (treeEdge.first == u && treeEdge.second == v)  return true;
    }

    return false;
}

bool Graph::isBackEdge(const Node * u, const Node * v)
{
    if (isTreeEdge(u, v)) return false;

    int uDfsNum = u->dfsNum;
    int uFinNum = u->dfsFinNum;
    int vDfsNum = v->dfsNum;
    int vFinNum = v->dfsFinNum;

    if ( (vDfsNum < uDfsNum) && (uDfsNum < uFinNum) && (uFinNum < vFinNum) ) 
        return true;
    else 
        return false;
}

bool Graph::isCrossEdge(const Node * u, const Node * v)
{
    if (isTreeEdge(u, v)) return false;

    int uDfsNum = u->dfsNum;
    int uFinNum = u->dfsFinNum;
    int vDfsNum = v->dfsNum;
    int vFinNum = v->dfsFinNum;

    if ( (vDfsNum < vFinNum) && (vFinNum < uDfsNum) && (uDfsNum < uFinNum))
        return true;
    else
        return false;
}

bool Graph::isForwardEdge(const Node * u, const Node * v)
{
    if (isTreeEdge(u, v)) return false;

    int uDfsNum = u->dfsNum;
    int uFinNum = u->dfsFinNum;
    int vDfsNum = v->dfsNum;
    int vFinNum = v->dfsFinNum;

    if ( (uDfsNum < vDfsNum) && (vDfsNum < vFinNum) && (vFinNum < uFinNum))
    {
        return true;
    }
    else
        return false;
}

void Graph::edgeInfo(char uName, char vName)
{
    Node * u = getNode(uName);
    Node * v = getNode(vName);
    bool TE = this->isTreeEdge(u, v);
    bool BE = this->isBackEdge(u, v);
    bool CE = this->isCrossEdge(u, v);
    bool FE = this ->isForwardEdge(u, v);
    

    if (TE) cout << uName << " -> " << vName << " is TreeEdge\n";
    else if (BE) cout << uName << " -> " << vName << " is BackEdge\n";
    else if (CE) cout << uName << " -> " << vName << " is CrossEdge\n";
    else if (FE) cout << uName << " -> " << vName << " is ForwardEdge\n";
   
}


void Graph::graphInfo()
{
    for (int i = 0; i < this->nodes.size(); ++i)
    {
        Node * curr = this->nodes[i];
        nodeInfo(curr);
    }

    cout << endl;
    cout << "Tree Edges:\n";
    for (auto edge : this->treeEdges)
    {
        cout << "{" << edge.first->name << " " << edge.second->name << "}" << endl;
    }
}

Node * Graph::getNode(char name)
{
    int ind = getInd(name);
    return this->nodes[ind];
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

    g.dfsALL('A');
    g.graphInfo();

    cout << endl;
    // Tree Edge example (A, F)
    g.edgeInfo('A', 'F');
    // Forward Edge example (A, J)
    g.edgeInfo('A', 'J');
    // Cross Edge example (H, G)
    g.edgeInfo('H', 'G');
    // Back Edge example (E, F))
    g.edgeInfo('E', 'F');
    

}