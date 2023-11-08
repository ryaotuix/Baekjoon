#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];

void input()
{
    cin >> n >> m;
}

void dfs(int depth, int sum)
{
    // base case:
    if (depth == n)
    {
        if (sum == m)
        {
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            cout << "\n";
        }
        return;
    }

    for (int i = 1; i <= 6; i++)
    {
        arr[depth] = i;
        dfs(depth + 1, sum + arr[depth]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    dfs(0, 0);
}