#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000 + 1;
typedef pair<int, int> pii;
char graph[MAX][MAX];
bool visited[MAX][MAX];
pii parent[MAX][MAX];

int N, M;

void init()
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            parent[i][j] = {i, j}; // 각 셀의 부모를 초기화
            visited[i][j] = false;
        }
    }
}

pii find(pii x)
{
    if (parent[x.first][x.second] == x)
        return x;

    return parent[x.first][x.second] = find(parent[x.first][x.second]);
}

void Union(pii a, pii b)
{
    a = find(a);
    b = find(b);

    // if same parent, return
    if (a == b)
        return;

    parent[b.first][b.second] = a;
}

bool OOB(int row, int col)
{
    return row < 1 || row > N || col < 1 || col > M;
}

pii nextDirection(pii curr)
{
    int row = curr.first;
    int col = curr.second;

    char dir = graph[row][col];

    int nextRow = row;
    int nextCol = col;

    if (dir == 'D')
        nextRow++;
    else if (dir == 'L')
        nextCol--;
    else if (dir == 'R')
        nextCol++;
    else if (dir == 'U')
        nextRow--;
    
    if (OOB(nextRow, nextCol))
        return {-1, -1};
    else
        return {nextRow, nextCol};
}

void input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> graph[i][j];
        }
    }
}

void bfs(pii start)
{
    queue<pii> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while(!q.empty())
    {
        pii curr = q.front();
        q.pop();

        pii next = nextDirection(curr);
        pii comp = {-1, -1};

        // if next is not out of bound,
        if (next != comp)
        {
            Union(curr, next);

            if (!visited[next.first][next.second])
            {
                visited[next.first][next.second] = true;
                q.push(next);
            }
        }
    }
}

int getSafeZone()
{
    int cnt = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (!visited[i][j])
            {
                bfs({i,j});
            }
        }
    }

    // 부모가 자기 자신인 경우를 센다.
    set<pii> uniqueParents;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            uniqueParents.insert(find({i, j}));
        }
    }
    
    return uniqueParents.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    init(); // 초기화
    cout << getSafeZone();
}
