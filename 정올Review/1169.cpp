#include <bits/stdc++.h>

using namespace std;

int n, m;   // number of dice rolls
int roll[5 + 5];

void input()
{
    cin >> n >> m;
}

void dfs1(int depth)
{
    // base case:
    if (depth == n)
    {
        for (int i = 0; i < n; i++) cout << roll[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= 6; i++)
    {
        roll[depth] = i;
        dfs1(depth + 1);
    }
}

void dfs2(int depth, int start)
{
    // base case:
    if (depth == n)
    {
        for (int i = 0; i < n; i++) cout << roll[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = start; i <= 6; i++)
    {
        roll[depth] = i;
        dfs2(depth + 1, i);
    }
}

unordered_map<int, int> um;
void dfs3(int depth)
{
    // base case:
    if (depth == n)
    {
        for (int i = 0; i < n; i++) cout << roll[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 1; i <= 6; i++)
    {
        if (!um[i])
        {
            um[i]++;
            roll[depth] = i;
            dfs3(depth + 1);
            um[i]--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    switch (m)
    {
    case 1:
        dfs1(0);
        break;
    
    case 2:
        dfs2(0, 1);
        break;

    case 3:
        dfs3(0);
        break;
    }
}