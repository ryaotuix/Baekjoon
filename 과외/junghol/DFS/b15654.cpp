#include <bits/stdc++.h>

using namespace std;

int n;
int m;
bool used[10000 + 5];
int arr[8 + 5];
int res[8 + 5];

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // have to sort
    sort(arr, arr + n);
}

// depth = 0, prev = -1
void dfs(int depth, int prev)
{
    // Base Case:
    if (depth == n)
    {
        for (int i = 0; i < m; i++)
        {
            cout << res[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        // if not used AND the number > prev (not by index but by )
        if (!used[ arr[i] ] && arr[i] > prev)
        {
            cout << arr[i] <<  "is not used" << endl;

            // mark it used
            used[arr[i]] = true;

            // fill out the array
            res[depth] = arr[i];

            dfs(depth + 1, arr[i]);

            // mark it unused
            used[arr[i]] = false;
        }
    }
}

int main()
{
    input();
    dfs(0, -1);
}