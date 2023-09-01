#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<string> vec;
vector<int> adjList [1000 + 5];
bool visited[1000 + 5];
int start;
int finish;

// return 서로 다른 비트 값 개수
int getHammingDistance(string & a, string & b)
{
    int res = 0;

    for (int i = 0; i < K; i++)
    {
        if (a[i] != b[i]) res++;
    }

    return res;
}

void input()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        string s; cin >> s;

        for (int j = 0; j < vec.size(); j++)
        {
            string temp = vec[j];
            int hamming = getHammingDistance(temp, s);

            // if hamming distace is 1, node i and j are adj
            if (hamming == 1)
            {
                adjList[i+1].push_back(j+1);
                adjList[j+1].push_back(i+1);
            }
        }

        vec.push_back(s);
    }

    cin >> start >> finish;
}

int path[1000 + 5];     // 1000+5 size path


bool found = false;

void dfs(int depth, int curr)
{
    for (int adjNode : adjList[curr])
    {
        if (!visited[adjNode])
        {
            visited[adjNode] = true;
            path[depth + 1] = adjNode;

            // if adjNode is finish, then print out paths
            if (adjNode == finish)
            {
                found = true;
                for (int i = 0; i <= depth + 1; i++) cout << path[i] << " ";
                exit(0);
            }

            dfs(depth + 1, adjNode);
            
            visited[adjNode] = false;

        }
    }

}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    path[0] = start;
    visited[start] = true;
    dfs(0, start);
    if (!found) cout << -1;

}