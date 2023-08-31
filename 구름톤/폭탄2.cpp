#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii; // row, col
vector<pii> bombs;
const int MAX = 200 + 5;
int n, k;

// grids
char shape[MAX][MAX];   // store shapes
int cnt[MAX][MAX];      // store cnt

// store maximum bomb cnt
int maxi = 0;   

// 5 locations
int dr[5] = {0, -1, 1, 0 ,0};
int dc[5] = {0, 0, 0, -1, 1};

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> shape[i][j];

    for (int i = 0; i < k; i++)
    {
        int r, c;
        cin >> r >> c;
        bombs.push_back({r-1, c-1});
    }
}

bool OOB(int r, int c)
{
    if (r < 0 || r > n) return true;
    if (c < 0 || c > n) return true;
    return false;
}

void printCnt()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << cnt[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";
}
void bombIt()
{
    for (pii loc : bombs)
    {
        int row = loc.first;
        int col = loc.second;
        
        for (int i = 0; i < 5; i++)
        {
            int nextR = row + dr[i];
            int nextC = col + dc[i];

            // increment if not out of bound
            if (!OOB(nextR, nextC))
            {
                if (shape[nextR][nextC] == '#') continue;
                else if (shape[nextR][nextC] == '@') cnt[nextR][nextC] += 2;
                else cnt[nextR][nextC]++;
                // printCnt();
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    bombIt();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            maxi = max(maxi, cnt[i][j]);

    cout << maxi;

}