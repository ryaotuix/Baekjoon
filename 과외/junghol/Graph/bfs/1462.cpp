#include <bits/stdc++.h>

using namespace std;

int R, C;
const int MAX = 50 + 5;
char MAP[MAX][MAX];
int cnt [MAX][MAX];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1 ,1};

typedef pair<int, int> pii;
queue<pii> Q;



void input()
{
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> MAP[i][j];
}

bool OOB(int r, int c)
{
    if (r < 0 || r > R) return true;
    if (c < 0 || c > C) return true;
    return false;
}


// get depth from the firt position we got from findStart()
int getDepth(pii curr)
{
    memset(cnt, 0, sizeof(cnt));                // 0. make all cnt 0
    cnt[curr.first][curr.second] = 1;        // 0-1. make this position visited
    Q.push(curr);
    
    // store last depth
    int ret = 0;                                

    while (!Q.empty())
    {
        pii now = Q.front(); Q.pop();
        int r = now.first;
        int c = now.second;
        
        for (int i = 0; i < 4; i++)
        {
            int nextR = r + dr[i];
            int nextC = c + dc[i];

            if (!OOB(nextR, nextC) && cnt[nextR][nextC]==0 && MAP[nextR][nextC] == 'L')
            {
                cnt[nextR][nextC] = cnt[r][c] + 1;
                Q.push({nextR, nextC});
                ret = max(ret, cnt[nextR][nextC]);
            }
        }
    }

    return ret - 1;
}

int findMax()
{
    int maxDepth = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            pii start;
    
            // if current position is Land,  
            if (MAP[i][j] == 'L')
            {
                int currDepth = getDepth({i, j});

                maxDepth = max(maxDepth, currDepth);
            }
        }
    }

    return maxDepth;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << findMax();

}