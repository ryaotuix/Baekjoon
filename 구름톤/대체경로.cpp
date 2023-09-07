#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii; // stores city # and depth
const int MAX = 1000 + 5;
// Materials
vector<int> adjList[MAX];
bool visited[MAX];
int S, E;
int N, M;

void input()
{
    cin >> N >> M >> S >> E; 
    for (int i = 0; i < M; i++)
    {
        int from, to;   cin >> from >> to;
        adjList[from].push_back(to);
        adjList[to].push_back(from);
    }
}

int BFSgetShortest(int construction)
{
    // cout << "!CONSTRUCTION " << construction << "\n";
    // init visited
    memset(visited, false, sizeof(visited));

    queue<pii> Q;

    // case when S or E is construction
    if (S == construction || E == construction) return -1;

    Q.push({S,1});
    visited[S] = true;

    while (!Q.empty())
    {
        pii curr = Q.front(); Q.pop();
        int currCity = curr.first;
        int currDepth = curr.second;

        // cout << "{" << currCity << " " << currDepth << "}\n";

        // if currCity is destination, return depth
        if (currCity == E) return currDepth;

        for (int adjCity : adjList[currCity])
        {
            // Skip if adjCity is going on the construction or route doesn't exist
            if (visited[adjCity] || adjCity == construction) continue;

            visited[adjCity] = true;
            Q.push({adjCity, currDepth + 1});
        }
    }

    return -1;
}

void print()
{
    for (int i = 1; i <= N; i++)
    {
        cout << BFSgetShortest(i) << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    print();

}