#include <bits/stdc++.h>

using namespace std;

/*
    Idea : store friends' parent information with lowest cost
*/

int N, M, k;
const int MAX = 10000 + 5;
int friendCost[MAX];
int parent[MAX];
bool isParent[MAX];

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

    // return if a and b has same parent
    if (a == b)
        return;

    if (friendCost[a] > friendCost[b])
    {
        swap(a, b);
    }

    isParent[b] = false;
    parent[b] = a;
}


void input()
{
    cin >> N >> M >> k;
    for (int i = 1; i <= N; i++)
    {
        cin >> friendCost[i];
        parent[i] = i;
        isParent[i] = true;
    }

    while(M--)
    {
        int a, b;
        cin >> a >> b;
        _union(a, b);
    }
}


void solve()
{
    int res = 0;
    for (int i = 1; i <= N; i++)
    {
        if (isParent[i])
            res += friendCost[i];
    }

    if (res > k)
        cout << "Oh no";
    else
        cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}