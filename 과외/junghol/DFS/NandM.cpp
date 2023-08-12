#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int arr[10];
int ret[10];
bool used[10] = {false, };

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
    if(depth == m)
    {
        for (int i = 0; i < m; i++)
            cout << ret[i] << " ";
        cout << "\n";
        return;
    }

    int last = 0;
    
    for (int i = start; i < n; i++)
    {
        // if this is not used and not same as last
        if (!used[i] && last != arr[i])
        {
            used[i] = true;
            last = arr[i];
            ret[depth] = arr[i];
            dfs(depth + 1, i + 1);

            used[i] = false;
        }
    }
}


int main()
{
    input();
    dfs(0, 0);
}