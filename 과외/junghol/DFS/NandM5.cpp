#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int arr[8 + 1];
bool used[8 + 1];
int ret[8 + 1];

void input(){
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

    for (int i = 0; i < n; i++)
    {
        // if not used,
        if (!used[i])
        {
            used[i] = true;
            ret[depth] = arr[i];
            dfs(depth + 1);

            used[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();
    dfs(0);
    return 0;
}