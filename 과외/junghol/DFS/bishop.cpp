#include <bits/stdc++.h>

using namespace std;

int n;
int board[15][15];
int maxi = 0;
int reverseDiag[20 + 10];

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> board[i][j];
    }
}

int temp;

void dfs(int diagonal, int cnt)
{
    // base case:
    if (diagonal == (2 * n + 1))
    {
        maxi = max(maxi, cnt);
        return;
    }

    bool flag = false;

    int dif = 0;
    if (diagonal > n)
    {
        dif = diagonal - n - 1;
    }

    // iterate row from 1 to min(diagonal - 1 and n)
    for (int r = 1 + dif; r <= min(diagonal - 1, n); r++)
    {
        int c = diagonal - r;

        // if (diagonal > n)
        //     cout << diagonal << " " << r << " " << c << endl;
 
        // if we can put it here
        if (board[r][c] == 1)
        {
            board[r][c] = 0;

            // If no matching on '\' diagonal, '\' is remembered as row - col + n 
            if (reverseDiag[r - c + n] == 0)
            {
                flag = true;
                reverseDiag[r - c + n] = 1;
                dfs(diagonal + 1, cnt + 1);
                reverseDiag[r - c + n] = 0;
            }
         
            board[r][c] = 1;
        }
    }

    // if this / diagonal could be filled, another dfs can be pruned
    if (!flag)
        dfs(diagonal + 1, cnt);
}

int main()
{
    input();
    dfs(2, 0);
    cout << maxi;
}