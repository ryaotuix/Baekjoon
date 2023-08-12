#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int arr[10];
int ret[10];

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
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

    for (int i = start; i < n; i++)
    {
        ret[depth] = arr[i];
        dfs(depth + 1, i);
    }

}

int main()
{
    input();
    dfs(0, 0);
}