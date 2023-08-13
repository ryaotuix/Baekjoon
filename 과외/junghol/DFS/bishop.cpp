#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int n;
int board[15][15];
int maxi = 0;
pii temp[30];

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> board[i][j];
    }

    // 2 ~ 2*n diagnoals exist
    for (int i = 0; i <= 2 * n; i++)
    {
        temp[i] = {0, 0};
    }
}

bool promising(int row, int col)
{
    // 0. / diagonal number is determined by row + col
    int diagonal = row + col;

    // check until this diagonal
    for (int i = 2; i < diagonal; i++)
    {
        int r = temp[i].first;
        int c = temp[i].second;

        if (r == 0 && c == 0)
            continue;

        // if this bishop is on X of previous diagonals
        if (abs(row - r) == abs(col - c))
        {
            cout << "false here\n";
            return false;
        }
    }

    int r = temp[diagonal].first;
    int c = temp[diagonal].second;

    // if r and c is not 0,0 -> already exist
    if (r != 0 || c != 0)
    {
        cout << "false here2 \n";
        return false;
    }

    return true;
}


void dfs(int diagonal, int cnt)
{
    // base case:
    if (diagonal == (2 * n + 1))
    {
        maxi = max(maxi, cnt - 1);
        return;
    }

    // iterate row from 1 to min(diagonal - 1 and n)

    for (int r = 1; r <= min(diagonal - 1, n); r++)
    {
        int c = diagonal - r;

        cout << diagonal << " " << r << " " << c << endl;
        cout << temp[diagonal].first << " " << temp[diagonal].second << endl;

        // if we can put it here
        if (board[r][c] == 1)
        {
            board[r][c] = 0;
            temp[diagonal] = {r, c}; // say we put bishop here
            cout << "we put it here\n";
            if (promising(r, c))
            {
                cout << "it is promising\n";
                dfs(diagonal + 1, cnt + 1);
            }
            
            // back to org state
            board[r][c] = 1;
            temp[diagonal] = {0,0};
        }
    }

    // if this diagonal cannot be filled
    dfs(diagonal + 1, cnt);
}

int main()
{
    input();
    dfs(2, 0);
    cout << maxi;
}