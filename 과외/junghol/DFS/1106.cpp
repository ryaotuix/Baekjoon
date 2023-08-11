#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

// Materials
int grid[105][105];

int row, col;
int sRow, sCol;
int eRow, eCol;
vector<pii> movements = {
    {2, 1},
    {2, -1},
    {-2, 1},
    {-2, -1},
    {1, 2},
    {1, -2},
    {-1, 2},
    {-1, -2}};

void input()
{
    cin >> row >> col;
    cin >> sRow >> sCol;
    cin >> eRow >> eCol;

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
            grid[i][j] = INT_MAX;
    }
    grid[sRow][sCol] = 0;
}

void printGrid()
{
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            // cout.width(10);
            if (grid[i][j] >= 1000)
                cout << "M";
            else
                cout << grid[i][j];
            cout << " ";
        }
        cout << endl;
    }
}
void dfs(int currCol, int currRow, int cnt)
{
    // iterate over each movement
    for (pii x : movements)
    {
        int nextCol = currCol + x.first;
        int nextRow = currRow + x.second;

        // if not out of bound -> calculate the cnt
        if (nextCol >= 1 && nextCol <= col && nextRow >= 1 && nextRow <= row)
        {
            // if the shortest way to get next is updated,
            if (grid[nextRow][nextCol] > cnt + 1)
            {
                // update
                grid[nextRow][nextCol] = cnt + 1;

                // printGrid();
                // cout << endl;
                // recurse down
                dfs(nextCol, nextRow, cnt + 1);
            }
        }
    }
}

int main()
{
    freopen("1106.txt", "w", stdout);
    input();
    dfs(sCol, sRow, 0);
    cout << grid[eRow][eCol];
    cout << endl;
    //printGrid();
}