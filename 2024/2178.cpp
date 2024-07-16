#include <bits/stdc++.h>

using namespace std;

int N, M;
const int MAX = 100 + 1;
int grid[MAX][MAX];
int m[MAX][MAX];

typedef pair<int, int> pii; // store row, col value

// 상 하 좌 우
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool OOB(int row, int col)
{
    if (row < 0 || row >= N) return true;
    if (col < 0 || col >= M) return true;
    if (grid[row][col] == 0) return true;
    return false;
}

void print()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << grid[i][j];
        }
        cout << "\n";
    }

    cout << "\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << m[i][j];
        }
        cout << "\n";
    }
}

void fill()
{
    m[0][0] = 1; // mark start as 1
    queue<pii> q; 
    q.push({0,0});

    while(!q.empty())
    {
        int currR = q.front().first;
        int currC = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nextR = currR + dy[i];
            int nextC = currC + dx[i];

            
            // if not out of bound
            if (!OOB(nextR, nextC))
            {
                // if it is already visited, skip
                if (m[nextR][nextC] != 0)
                    continue;
                
                // otherwise, mark visited (breadth + 1)
                m[nextR][nextC] = m[currR][currC] + 1;
                q.push({nextR, nextC});
            }
        }
    }
}

void input()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string s ; cin >> s;
        for (int j= 0; j < M; j++)
        {
            grid[i][j] = s[j] - '0';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    fill();
    cout << m[N-1][M-1] << "\n";


    // print();
}