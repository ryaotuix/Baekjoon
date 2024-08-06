#include <bits/stdc++.h>

using namespace std;

int n, m;
const int MAX = 500000 + 1;
int parent[MAX];


int find(int x)
{
    if (parent[x] == x)
        return x;
    
    return parent[x] = find(parent[x]);
}

int _union(int a, int b)
{
    a = find(a);
    b = find(b);

    // if same union (make cycle return 1)
    if (a == b)
        return 1;

    if (a > b)
        swap(a, b);

    parent[b] = a;

    return 0;
}

void input()
{
    cin >> n >> m;
    int from, to;

    // parent of itself is itslef
    for (int i = 0; i < n; i++)
        parent[i] = i;
    
    int i = 1;
    int res = -1;
    while (m--)
    {
        cin >> from >> to;
        
        int cycle = _union(from, to);

        if (cycle)
        {
            res = i;
            break;
        }

        i++;
    }

    if (res == -1)
        cout << 0;
    else
        cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
}