#include <bits/stdc++.h>

using namespace std;


typedef pair<int, int> pii; // <to, cost>
int N, M;
int from, to;
const int MAX = 1e5 + 1;
int visited[MAX];
vector<pii> adjGraph[MAX];

void input()
{
    cin >> N >> M;
    while(M--){
        int a, b, c;
        cin >> a >> b >> c;
        adjGraph[a].push_back({b,c});
        adjGraph[b].push_back({a,c});
    }
    cin >> from >> to;;
}


// 이 무게를 담고 시작점부터 끝점까지 가기
/*
    if you can go return true,
    if you can't go (too heavy, return false)
*/
bool bfs(int weight)
{
    queue<int> q;
    q.push(from);
    visited[from] = true;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();


        for (pii p : adjGraph[curr])
        {
            int next = p.first;
            int cost = p.second;
            // cout << curr << " -> " << next << " " << graph[curr][next] << "\n";

            // if you can't go this way
            if (cost < weight)
                continue;

            // when you arrive, return true
            if (next == to)
                return true;
            
            // skip if next is visited
            if (visited[next])
                continue;

            visited[next] = true;
            q.push(next);
        }
    }

    return false;
}

int binarySearch(int lo, int hi)
{
    int res = 0;

    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;

        memset(visited, false, sizeof(visited));
        
        bool canGo = bfs(mid);
        // cout << mid << " " << canGo << "\n";
        if (canGo)
        {
            res = max(res, mid);
            lo = mid + 1;
        }   
        else
        {
            hi = mid - 1;
        }
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    cout << binarySearch(0, 1e9);
}