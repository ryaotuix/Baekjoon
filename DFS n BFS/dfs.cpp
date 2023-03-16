#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

typedef struct Node {
    char name = '0';
    int dfsNum = 0;             // DFS number
    int dfsFinNum = 0;          // DFS Finish number
    vector<Node *> adj;       // adjacent nodes array
    int adjCnt = 0;
} Node;


int getInd(char c);     // ex) Node name 'A' would return an index 1
void nodeInfo(Node * n);    // ex) "Node name 'A' has DFS num : 1 & DFS fin num : 16"


class Graph
{
    public:
        // Fields
        int numNodes;   
        vector<Node *> nodes;       // Node vector of this graph
        bool * visited;             // visited array

        // Constructor
        Graph(string filename);

        // Method

};

// CONSTRUCTOR READ FROM A TXT FILE
Graph::Graph(string filename)
{
    // read from the txt file
    fstream f;
    f.open(filename, ios::in);      // open for input operation

    if (!f.is_open())               // if file is not opened
    {
        cout << "File is not opened\n";
        return;
    }

    // if f.is_open()

    int nodeNum, edgeNum;
    f >> nodeNum >> edgeNum;        // read from the file and store information

    for (int i = 0; i < nodeNum; ++i)
    {
        Node * tempNode = new Node;
        tempNode->name = i + 'A';
        tempNode->dfsNum = 0;
        tempNode->dfsFinNum = 0;
        tempNode->adjCnt = 0;
        
        this->nodes.push_back(tempNode);
    }

    // testing nodes vector
    for (int i = 0; i < this->nodes.size(); ++i)
    {
        nodeInfo(this->nodes[i]);
    }
    

    char from, to;
    while(f >> from >> to)
    {
        cout << from << " " << to << "\n";
        // if this node is not created in node list, 

        int fIndex = getInd(from);     // index to use for adj            ex) index of 'A' is 0
        cout << fIndex << endl;

        nodeInfo(this->nodes[fIndex]);

        if (this->nodes[fIndex]->name != from)
        {
            // dynamically allocate the node information
            Node * nFrom = new Node; 
            nFrom->name = from; nFrom->dfsNum = 0; nFrom->dfsFinNum = 0; nFrom->adjacent = new Node*[nodeNum]; 

            // and put it 
            this->nodes[fIndex] = nFrom;
            cout << "Checkpoint\n";

        }
        
        int tIndex = getInd(to);
        cout << tIndex << endl;
    
        nodeInfo(this->nodes[tIndex]);

        if (this->nodes[tIndex]->name != to)
        {
            cout << "hmm\n";
            // dynamically allocate the node information
            Node * nTo = new Node; 
            nTo->name = from; nTo->dfsNum = 0; nTo->dfsFinNum = 0; nTo->adjacent = new Node*[nodeNum]; 

            // and put it 
            this->nodes[tIndex] = nTo;
            cout << "Checkpoint\n";

        }
    

        // Then, ADD it to adjacent!!!
        Node * fNode = nodes[fIndex];       // (pointer) Node coming from
        Node * tNode = nodes[tIndex];       // (pointer) Node going to
        int curradjInd = fNode->adjCnt;     // in fNode, the index of adjacent array to inert
        
        fNode->adjacent[curradjInd] = tNode;    // update adjacent array 
        fNode->adjCnt++;                        // increase adjCnt        
    }
    

    
}

int getInd(char c) {
    if (c >= 65 && c <= 90) return c-65; 
    return -1;   
}

void nodeInfo(Node * n)
{
    cout << "Node name ' " << n->name << " ' has DFS num : " << n->dfsNum << " & DFS fin num : " << n->dfsFinNum << endl;
    if (n->adjCnt == 0)  cout << "No adjacent nodes\n";
    else 
    {
        cout << "Adjacent Nodes : {";
        for (int i = 0; i < n->adjCnt; i++) cout << n->adj[i]->name << ", ";
        cout << "}\n";
    }
}

int main()
{
    string filename = "nodesInput.txt";
    Graph g(filename);
}