#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000+1;
int path[MAX];
bool visited[MAX];
int N, K;
vector<int> stk;

void input()
{
    cin >> N >> K;
}

bool OOB(int n)
{
    return (n < 0 || n >= MAX);
}


void bfs()
{
    queue<int> q;
    q.push(N);
    path[N] = -1;       // start position is init as -1
    visited[N] = true;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        int dir[3] = {curr-1, curr+1, curr*2};
        for (int i = 0; i < 3; i++)
        {
            int next = dir[i];
            if (!OOB(next))
            {
                // if already visited
                if (visited[next]) continue;

                visited[next] = true;
                path[next] = curr;  // mark that it came from curr
                q.push(next);
            }
        }
    }
}

void dfs(int & depth, int curr)
{
    stk.push_back(curr);

    // base case
    if (curr == N)  return;
    
    depth++;
    dfs(depth, path[curr]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    bfs();

    int cnt = 0;
    dfs(cnt, K);


    cout << cnt << "\n";
    for (int i = stk.size() - 1; i >= 0; i--)
    {
        cout << stk[i] << " ";
    }
}