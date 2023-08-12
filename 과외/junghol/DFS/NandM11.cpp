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

void dfs(int depth)
{
    // base:
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
        if (last != arr[i])
        {
            ret[depth] = arr[i];
            last = arr[i];
            dfs(depth + 1);
        }
    }
}

int main()
{
    input();
    dfs(0);
}