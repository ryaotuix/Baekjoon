#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 1;

int parent[MAX];
int G, P;
vector<int> planes;

int find(int x)
{
    if (parent[x] == x)
        return x;

    parent[x] = find(parent[x]);
    return parent[x];
}

void _union(int x, int y)
{
    x = find(x);
    y = find(y);

    /*
        when u use dock 4
        you will union(3,4)
        parent[4] will be parent[3]
    */
    if (y < x)
        parent[x] = y;
    else    
        parent[y] = x;
}

void input()
{
    cin >> G;
    cin >> P;

    // parent of it is itself
    for (int i = 1; i <= G; i++)
    {
        parent[i] = i;
    }

    while(P--)
    {
        int temp;
        cin >> temp;
        planes.push_back(temp);
    }
}

void solve()
{
    int res = 0;

    for (int i = 0; i < planes.size(); i++)
    {
        int temp = planes[i];

        int a = find(temp);

        if (a == 0)
        {
            cout << res;
            return;
        }
        
        res++;
        _union(a, a - 1);   // parent of temp becomes temp-1
    }

    cout << res;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();
}