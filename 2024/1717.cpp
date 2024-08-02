#include <bits/stdc++.h>

using namespace std;

int n, m;
const int MAX = 1e6 + 1;
int parent[MAX];

int find(int x)
{
    if (parent[x] == x)
        return x;
    
    return parent[x] = find(parent[x]);
}

void _union(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a > b)
        swap(a, b);

    parent[b] = a;
}

void input()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int z, a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> z >> a >> b;

        // if z == 0, add two unions
        if (z == 0)
        {
            _union(a, b);
        }
        // if z == 1, check if they are in same union
        else if (z == 1)
        {
            if (find(a) == find(b))
                cout << "YES";
            else
                cout << "NO";
            cout << "\n";
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
}