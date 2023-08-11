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

void dfs(int depth, int start)
{
    // base case: 
    if (depth == m)
    {
        for (int i = 0; i < m; i++)
            cout << ret[i] << " ";
        cout << "\n";
        return;
    }

    // fill it
    for (int i = start; i < n; i++)
    {
        if (!used[i])
        {
            used[i] = true;
            ret[depth] = arr[i];
            dfs(depth + 1, i);

            used[i] = false;
        }
    }
}

int main()
{
    input();
    dfs(0, 0);
}