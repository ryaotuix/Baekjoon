#include <bits/stdc++.h>

using namespace std;

unordered_map<string, string> parent;   // ex) Fred Barney
// barney is fred's parent (alphabetically smalle one is always parent)

unordered_map<string, int> um;          // ex) track the size of union

string find(string x)
{
    // if this is new, (if key can't be found on parent)
    if (parent.find(x) == parent.end())
    {
        parent[x] = x;
        um[x] = 1;
        return x;
    }

    if (parent[x] == x)
        return x;

    return parent[x] = find(parent[x]);
}

int _union(string a, string b)
{
    a = find(a);
    b = find(b);
    
    // if their parents are the same
    if (a == b)
        return um[a];

    if (a > b)
        swap(a, b);

    int aSize = um[a];
    int bSize = um[b];
    int sum = aSize + bSize;

    // a <= b
    parent[b] = a;
    um[a] = sum;
    um[b] = sum;
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--)
    {
        int t;
        cin >> t;

        um.clear();
        parent.clear();

        while(t--)
        {
            string a, b;
            cin >> a >> b;
            cout << _union(a, b) << "\n";
        }
    }
}