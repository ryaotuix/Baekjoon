#include <bits/stdc++.h>

using namespace std;

int m;
int n;
int k;

//          상 하  좌 우
int dc[4] = {0,0,-1,1};
int dr[4] = {-1,1,0,0};

int grid[105][105];
vector<int> sections;



void printGrid()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << grid[i][j] << " ";
        cout << "\n";
    }
}

void input()
{
    cin >> m >> n >> k;
    int x1;
    int y1;
    int x2;
    int y2;

    for (int i = 0; i < k; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        // fill out
        for (int i = x1; i < x2; i++)
        {
            for (int j = y1; j < y2; j++)
                grid[j][i]++;
        }
    }
}

bool isInRange(int row, int col)
{
    // if row and col are outside of the range, it is false
    if (row >= m || row < 0)
        return false;
    if (col >= n || col < 0)
        return false;

    return true;
}

// return size of connected component
int dfs(int row, int col)
{
    // mark this row and col visited
    grid[row][col]++;

    int ret = 1;

    for (int i = 0; i < 4; i++)
    {
        int nextR = row + dr[i];
        int nextC = col + dc[i];
        
        // if next row and next col is within range and available, dfs into it
        if (grid[nextR][nextC] == 0 && isInRange(nextR, nextC))
        {
            ret += dfs(nextR, nextC);
        }
    }

    return ret;
}

void getRes()
{
    for (int row = 0; row < m; row++)
    {
        for (int col = 0; col < n; col++)
        {
            // if this grid is 0
            if (grid[row][col] == 0)
            {
                sections.push_back(dfs(row, col));
            }
        }
    }

    cout << sections.size() << "\n";
    sort(sections.begin(), sections.end());
    for (int n : sections)
        cout << n << " ";
}



int main()
{
    input();
    getRes();
}