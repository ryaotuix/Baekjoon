#include <bits/stdc++.h>

using namespace std;

int n;      // total
int m;      // pick m

int arr[8 + 1];
int ret[8 + 1];
bool used[8 + 1];

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);
}

void dfs(int depth)
{
    // base case:
    if (depth == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << ret[i] << " ";
        }
        cout << "\n";
        return;
    }

    // fill ret
    for (int i = 0; i < n; i++)
    {
        ret[depth] = arr[i];
        dfs(depth + 1);
    }
}

int main()
{
    input();
    dfs(0);
}