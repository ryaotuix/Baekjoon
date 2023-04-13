#include <bits/stdc++.h>
#include <vector>

using namespace std;

typedef struct node {
    int x;
    int y;
} node;

typedef struct edge {
    double weight;
    int one, two;
} edge;


double pythagorean(node a, node b)
{
    double x1 = (double) a.x;
    double y1 = (double) a.y;

    double x2 = (double) b.x;
    double y2 = (double) b.y;

    double dx = x1 - x2;
    double dy = y1 - y2;

    return sqrt(dx*dx + dy*dy);
}

// UF
int find (vector<int>& disjoint, int a)
{
    if (disjoint[a] == -1)
    {
        return a;
    }

    disjoint[a] = find(disjoint, disjoint[a]);
    return disjoint[a];
}

// merge into union
void join(vector<int> & disjoint, int a, int b)
{
    a = find(disjoint, a);
    b = find(disjoint, b);

    if (a==b)
    {
        return;
    }

    disjoint[a] = b;
}


// compare method
bool compare_edge(edge a, edge b)
{
    return a.weight < b.weight;   // weight comparison
}


// kruskal's algorithm
void kruskal(vector<edge>& edges, vector<int> &disjoint, vector<double> & distances, vector<node> & nodes)
{
    
    for (int i = 0; i < nodes.size()-1; ++i)
    {
        for (int j = i+1; j < nodes.size(); ++j)            // do not make a distance for the same edge
        {
            double distance = pythagorean(nodes[i], nodes[j]);      
            // cout << distance << endl;
            edge e = {distance, i, j};
            edges.push_back(e);
        }
    }


    sort(edges.begin(), edges.end(), compare_edge); // sort the edges by the distance

    for (auto e : edges)
    {
        int findA = find(disjoint, e.one);
        int findB = find(disjoint, e.two);
        if (findA != findB) {
            join(disjoint, e.one, e.two);
            distances.push_back(e.weight);
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    while (N--)
    {
        int S; // number of satellites
        int P; // number of outposts
        cin >> S >> P;


        // Materials
        vector<node> nodes;                     // all nodes
        vector<edge> edges;                 // all edges
        vector<int> disjoint(P, -1);        // disjoint vector set length of outposts init with -1
        vector<double> distances;           // all distances


        for (int i = 0; i < P; i++)
        {
            int x, y; cin >> x >> y;
            node n;
            n.x = x;
            n.y = y;
            nodes.push_back(n);
        }


        kruskal(edges, disjoint, distances, nodes);

        int ind = distances.size() - S ;
        
        cout << fixed;
        cout << setprecision(2);
        cout << distances[ind] << endl;

        

    }

}