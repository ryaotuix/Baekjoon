#include <bits/stdc++.h>

using namespace std;



int n; // N is size
int check[20][20];
int ans = 0;

void printVisited()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << check[i][j] << " ";
        }
        cout << endl;
    }
}

void boardCheck(int x, int y, int c)
{
    // 위 아래 왼 오
    int i, j;
    for (i = 1; i <= n; i++)
    {
        check[i][y] += c;
        check[x][i] += c;
    }

    // 왼쪽 위 대각선 
    i=x, j=y;
    while (i >= 1 && j >= 1)
        check[i--][j--] += c;
    // 오른쪽 위 대각선
    i = x, j = y;
    while (i >= 1 && j <= n)
        check[i--][j++] += c;
    // 왼쪽 아래 대각선
    i = x, j = y;
    while (i <= n && j >= 1)
        check[i++][j--] += c;
    // 오른쪽 아래 대각선
    i = x, j = y;
    while (i <= n && j <= n)
        check[i++][j++] += c;
}

void back(int x)
{
    if (x == n + 1)
    {
        ans++;
        return;
    }

    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (!check[i][j])
            {
                boardCheck(i, j, 1);
                back(x + 1);
                boardCheck(i, j, -1);
            }
        }
    }
}

int main()
{
    cin >> n;
    // printVisited();
    // cout << endl;

    // boardCheck(7, 7, 1);
    // // cout << "reacehd\n";
    // printVisited();
    // cout << endl;

    // boardCheck(7, 7, -1);
    // printVisited();

    // count(0);
    // cout << res;
    back(1);
    cout << ans;
}