#include <bits/stdc++.h>

using namespace std;

/*
    https://seongmok.com/14 해설

    임계 경로 critical path
    문제 : 임계 경로를 지나는 모든 간선 수를 체크

    A. find all critical path from start node to other nodes
        find all critical path from end node to other nodes
    
    B.  임계경로 지나는 간선 조건
        1. critical path[v1] +  path[v1][v2] =  criticalpath[v2]
        2. critical path[v1] + reverse critical path[v1] = critical path length
*/

const int MAX = 10000 + 1;
int N, M;
int start, finish;
typedef pair<int, int> pii;
// materials

// 1. two adj List (1e5 * 4 * 2 memory)
vector<pii> adjList[MAX];
vector<pii> revAdjList[MAX];

// 2. two critical path storage
int path[MAX];
int revPath[MAX];

// 3. critical path ; need indegree arr
int indegree[MAX];
int revInDegree[MAX];

// 4. visited arr
bool visited[MAX];


void input()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int a, b, weight;
        cin >> a >> b >> weight;
        adjList[a].push_back({b, weight});
        revAdjList[b].push_back({a, weight});
        indegree[b]++;
        revInDegree[a]++;
    }
    cin >> start >> finish;
}

void findCriticalPath(int startNode, int * indegree, int * path, vector<pii> * adjList)
{
    queue<int> q;
    q.push(startNode);
    path[startNode] = 0;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        // !!!!!!! IMPORTANT !!!!!!!! 
        // skip when it is visited or  indegree is 0
        if (visited[cur] || indegree[cur] != 0) continue;

        visited[cur] = true;                    // mark true only when you can't skip

        for (pii p : adjList[cur])
        {
            int nxt = p.first;
            int weight = p.second;

            
            // update cri path
            path[nxt] = max(path[nxt], path[cur] + weight);

            q.push(nxt);
            indegree[nxt]--;
        }
    }
}

void print(int * path)
{
    for (int i = 1; i <= N; i++)
    {
        cout << i << " : " << path[i] << "\n";
    }
    cout << "\n";
}

void solveA()
{
    findCriticalPath(start, indegree, path, adjList);
    memset(visited, false, sizeof(visited));
    // print(path);
    findCriticalPath(finish, revInDegree, revPath, revAdjList);
    // print(revPath);
    memset(visited, false, sizeof(visited));
}

int solveB()
{
    int res = 0;

    queue<int> q;
    q.push(start);

    visited[start] = true;          // use visited to remove 중복

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (pii p : adjList[cur])
        {
            int nxt = p.first;
            int weight = p.second;

            // B.  임계경로 지나는 간선 조건
            // 1. critical path[v1] +  path[v1][v2] =  criticalpath[v2]
            if (path[cur] + weight == path[nxt])
            {
            // 2. critical path[v1] + reverse critical path[v1] = critical path length
                if (path[nxt] + revPath[nxt] == path[finish])
                {
                    // 안 가본 곳만 q 에 넣기
                    if (!visited[nxt])
                    {
                        visited[nxt] = true;
                        q.push(nxt);
                    }
                    res++;              // this path is part of critical Path
                }
            }
        }
    }

    return res;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();

    // A.
    solveA();

    // B. 
    cout << path[finish] << "\n";
    cout << solveB();
}