#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000 + 5;
int N, K;
vector<string> vec;
vector<int> adjList [MAX];
bool visited[MAX];
int start;
int finish;
vector<int> dp[MAX];   // stores the shortest paths to the index
queue<int> Q;          // queue for bfs


// return 서로 다른 비트 값 개수
int getHammingDistance(string & a, string & b)
{
    int res = 0;

    for (int i = 0; i < K; i++)
        if (a[i] != b[i]) res++;

    return res;
}


void input()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        string s; cin >> s;


        // Make AdjList
        int j = 1;
        for (string temp : vec)
        {
            if (getHammingDistance(temp, s) == 1)
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
            j++;
        }

        vec.push_back(s);
    }

    cin >> start >> finish;

    // push start into queue, and make this start visited
    Q.push(start);
    visited[start] = true;
    dp[start].push_back(start);
}

void bfs()
{
    // while Q is not empty
    while (!Q.empty())
    {
        int curr = Q.front(); Q.pop();
        vector<int> soFar = dp[curr];       // get the path until current node


        for (int adjNode : adjList[curr])
        {
            // if adjNode is not visited
            if (!visited[adjNode])
            {
                visited[adjNode] = true;    // make this node visited
                Q.push(adjNode);

                dp[adjNode] = soFar;
                dp[adjNode].push_back(adjNode);
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    bfs();

    // if not found,
    if (dp[finish].size() == 0) cout << -1;
    // if found,
    else
    {
        for (int i = 0; i < dp[finish].size(); i++)
        cout << dp[finish][i] << " ";
    }

}