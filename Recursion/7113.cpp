#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
int n, m;

void rec(int x, int y)
{
    cnt++;
    // base case:
    if (x == y)
        return;
    
    // o.w.
    if (x > y)
        x = x - y;
    else
        y = y - x;
    
    rec(x, y);
}

int main()
{
    cin >> n >> m;
    rec(n,m);
    cout << cnt;
}