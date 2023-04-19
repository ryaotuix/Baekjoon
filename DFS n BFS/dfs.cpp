#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

// Node STRUCT
typedef struct Node {
    char name = '0';
    int dfsNum = 0;                                             // DFS number
    int dfsFinNum = 0;                                          // DFS Finish number
    vector<Node *> adj;                                         // adjacent nodes array
} Node;

typedef pair<Node *, Node *> edge;

int getInd(char c) {                                            // ex) Node name 'A' would return an index 1
    if (c >= 65 && c <= 90) return c-'A'; 
    return -1;   
}            

void nodeInfo(Node * n)                                         // ex) "Node name 'A' has DFS num : 1 & DFS fin num : 16"
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

bool compareNode(const Node * a, const Node * b)                // bool to sort by lexiographical order
    {return a->name < b->name;}


class Graph
{
    public:
        // Fields
        int numNodes;   
        vector<Node *> nodes;                                   // Node vector of this graph
        vector<bool> visited;                                   // visited array
        vector<edge> treeEdges;                                 // collection of tree Edges
        bool transposed = false;                                // true if transposed

        // Constructor
        Graph(string filename, bool transpose);

        // Method
        void dfs(char startNodeName, int & dfsNum);             // traverse the graph once from the given node
        void dfsALL(char starNodeName);                         // traverse the entire graph from the beginning       
        void graphInfo();                                       // print graph Info 
        Node * getNode(char nodeName);                          // get node 

        // extra methods
        bool isTreeEdge(const Node * u, const Node * v);
        bool isBackEdge(const Node * u, const Node * v);
        bool isCrossEdge(const Node * u, const Node * v);
        bool isForwardEdge(const Node * u, const Node * v);
        void edgeInfo(char uName, char vName);
        void sortByFinNum();                                    // Sort Nodes by decreasing Dfs Fin Num

        // DO-ABLE
        void getSTCC(Graph & transposed);                       // get Strongly Connected Components in a directed Graph in O(n+m) time 
        bool isBipartite();                                     // decide if it is bipartite
        bool isCyclic();                                        // decide if there is a cycle
        bool isEulerCycle();                                    // decide if it is an  Euler Cycle (can visit all nodes without visiting again)
        
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

    if (transpose) this->transposed = true;                                                           

    int nodeNum, edgeNum;
    f >> nodeNum >> edgeNum;                                    // read from the file and store information

    for (int i = 0; i < nodeNum; ++i)                           // fill out the vector nodes
    {
                                                                // create a Node "A, B, C, ..."
        Node * tempNode = new Node;
        tempNode->name = i + 'A';
        tempNode->dfsNum = 0;
        tempNode->dfsFinNum = 0;
        
        this->nodes.push_back(tempNode);                        // add to nodes vector
    }

    this->visited = vector<bool>(nodeNum, false);               // defaut visited vector = false

    
    //for (int i = 0; i < this->nodes.size(); ++i)    nodeInfo(this->nodes[i]);
    

    char from, to;
    while(f >> from >> to)                                     // read until the file ends hehehe
    {   
        if (transpose)                                         // if transposed, switch from and to
        {
            char temp = to;
            to = from;
            from = temp;
        }

        int fIndex = getInd(from);                              // index to use for adj    ex) index of 'A' is 0
        int tIndex = getInd(to);

        Node * fNode = getNode(from);
        Node * tNode = getNode(to);
        fNode->adj.push_back(tNode);
    }
    
    // To recursively traverse lexiographically, we must sort the adj nodes
    for (int i = 0; i < this->nodes.size(); ++i)
    {
        Node * curr = this->nodes[i];
        sort(curr->adj.begin(), curr->adj.end(), compareNode);
    }   
}

int dfsCNT = 0;                                         // DFS Count for dfsCNT and DfsFinNum

// DFS traverse!
void Graph::dfs(char startNodeName, int & dfsCNT)
{
    int index = getInd(startNodeName);
    Node * sNode = getNode(startNodeName);

    // DFS only when it is not visited
    if (this->visited[index] == false)
    {
        // i) mark node visited
        this->visited[index] = true;

        // ii) this node's DFS num
        sNode->dfsNum = dfsCNT++;
    

        // iii) recursively call dfs
        for (int i = 0; i < sNode->adj.size(); i++)
        {
            char adjName = sNode->adj[i]->name;                     // each name of adj node
            int adjInd = getInd(adjName);                           // each index of adj node 
            Node * currAdjNode = getNode(adjName);                  // current adjacent Node

            if (this->visited[adjInd] == false)                     // recursively call dfs if it is not visited
            {
                edge tempEdge = make_pair(sNode, getNode(adjName));
                treeEdges.push_back(tempEdge);
                dfs(adjName, dfsCNT);   
            }    
            
            if (this->transposed == true)                            // if transposed, print STCC info
            {
                cout << currAdjNode->name << " ";
            }
        }

        // iv) this node's DFS Fin Num 
        sNode->dfsFinNum = dfsCNT++;
    }

}

void Graph::dfsALL(char startNodeName) {
    int dfscnt = 0;
    dfs(startNodeName, dfscnt);
    for (auto curr : this->nodes)
    {
        dfscnt = 0;
        this->dfs(curr->name, dfscnt);
    }
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

void Graph::sortByFinNum()
{
    sort(this->nodes.begin(), this->nodes.end(), [](const Node * a, const Node * b) -> bool
    {
        return a->dfsFinNum > b->dfsFinNum;
    });
}

// void Graph::getSTCC(Graph & transposed)
// {
//     this->sortByFinNum();                                   // Sort Nodes by decreasing DFS Fin Num

//     // Call DFS on G Transposed, in order of decreasing DFS Fin Num
//     int i = 1;
//     for (auto node : this->nodes)
//     {
//         char name = node->name;
//         int ind = getInd(name);
//         if (this->visited[ind])
//     }                                              
// }





int main()
{
    string filename = "nodesInput.txt";
    bool transpose = true;
    Graph g(filename, !transpose);

    g.dfsALL('A');
    cout << endl;
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

    g.sortByFinNum();                       // now sorted by decreasing DFS Fin Num
    cout << "------------------------------------------------------------\n" << endl;
    g.graphInfo();
    
    Graph gT(filename, transpose);


}