#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int arr[10];
bool used[10];
int ret[10];

void input()
{
    // while receiving input, check if it exist
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
            cout << ret[i] << " ";
        cout << "\n";
        return;
    }

    int last = 0;
    for (int i = 0; i < n; i++)
    {
        // if not used and last is not the same as this number
        if (!used[i] && last != arr[i])
        {
            used[i] = true;
            ret[depth] = arr[i];
            last = arr[i];
            dfs(depth + 1);
            used[i] = false;
        }
    }
}

int main()
{
    input();
    dfs(0);
}