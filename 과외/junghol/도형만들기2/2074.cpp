#include <iostream>

using namespace std;

int grid [101][101];

void printGrid(const int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

void getGrid(const int n)
{
    int row = 1;
    int col = n/2 + 1;
    int cnt = 1;
    int iter = n*n;

    while(cnt <= iter)
    {
        // 0. Boundary Check
        if (row == 0)
            row = n;
        if (row == n+1)
            row = 1;
        if (col == 0)
            col = n;
        if (col == n+1)
            col = 1;

        // cout << "cnt : " << cnt << " row : " << row << " col : " << col << endl;
        grid[row][col] = cnt;
        
        // 1. if cnt is multiple of n
        if(cnt % n == 0)
        {
            row++;
        }
        else
        {
            col--;
            row--;
        }

        cnt++;
    }

    printGrid(n);
}


int main()
{
    int n;
    cin >> n;
    getGrid(n);

}