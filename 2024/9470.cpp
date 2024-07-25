#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000 + 1;

int indegree[MAX];
int strahler[MAX];
int cnt[MAX][MAX];  // [a][b] 일때 뜻 : a node 전에 strahler 번호 b가 몇개 있었는지 저장
vector<int> graph[MAX];

int K, M, P;

void init()
{
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < MAX; i++)
    {
        indegree[i] = 0;
        strahler[i] = 0;
        graph[i].clear();
    }
}

void input()
{
    init();

    cin >> K >> M >> P;

    while(P--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
}

// 대충 위상정렬 사용
int solve()
{
    int res = 1;

    queue<int> q;
    // indegree 가 없는 노드들을 모두 q에 넣고 strahler 값을 1로 저장
    for (int i = 1; i<= M; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            strahler[i] = 1;
        }
    }


    while(!q.empty())
    {
        int curr = q.front();
        int prevStrahler = strahler[curr];                      // 현재 strahler 값
        q.pop();

        for (int next : graph[curr])
        {
            cnt[next][prevStrahler]++;                          // next에 오기전 현재 strahler 값의 개수 증가

            strahler[next] = max(strahler[next], prevStrahler); // 기본적으로 다음은 현재 strahler 값과 동일 (더 큰게 없을시 )

            if (cnt[next][prevStrahler] >= 2)                   // strahler 값이 2개 이상이면 현재 strahler 값 + 1 (더 큰게 없을 시)
                strahler[next] = max(strahler[next], prevStrahler + 1);

            res = max(res, strahler[next]);                     // 전체중 가장 큰 strahler 값 항상 업데이트

            indegree[next]--;
            if (indegree[next] == 0)
                q.push(next);
        }
    }

    return res;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while(T--)
    {
        input();
        cout << K << " " << solve() << "\n";
    }

    // for (int i = 1; i <= M; i++)
    // {
    //     cout << strahler[i] << " ";
    // }
}