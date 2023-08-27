#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000 + 5;

typedef pair<int, int> pii; // row, col
int n, m;
pii start;
pii finish;
typedef pair<pii, int> depth;
queue<depth> Q; // store depth

bool visited[MAX][MAX];
int dr[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dc[8] = {1, 2, 2, 1, -1 ,-2, -2, -1};


bool OOB(int row, int col)
{
    if (row < 1 || row > n) return true;
    if (col < 1 || col > n) return true;
    return false;
}

void input()
{
    cin >> n >> m;
    cin >> start.first >> start.second >> finish.first >> finish.second;
}

int bfs()
{
    while (!Q.empty())
    {
        depth curr = Q.front(); Q.pop();
        // make this current position visited
        int r = curr.first.first; int c = curr.first.second;

        for (int i = 0; i < 8; i++)
        {
            int level = curr.second;
            int nextR = r + dr[i];
            int nextC = c + dc[i];
            
            // base case :
            if (finish.first == nextR && finish.second == nextC) return level + 1;

            // when it is not out of bound, put it to queue
            if (!OOB(nextR, nextC) && !visited[nextR][nextC])
            {
                depth next = {{nextR, nextC}, level + 1};
                visited[nextR][nextC] = true;
                Q.push(next);
            }
        }
    }

    return -1;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    visited[start.first][start.second] = true;
    Q.push({start, 0});
    cout << bfs();
}