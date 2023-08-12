#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int total = 0;
unordered_map<int, int> cnt;
int arr[10];
int ret[10];
string s = "";

void input()
{
    // while receiving input, check if it exist
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    
    for (int i = 0; i < m; i++)
    {
        s += 
    }

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

    
}


int main()
{
    input();
    dfs(0, 0);
}