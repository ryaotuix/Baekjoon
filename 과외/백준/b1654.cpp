#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;       // n is number of original wires, m : number of same length wires we want 
ll maximum = 0;

ll getWires(vector<ll> & wires, ll length)
{
    ll sum = 0;
    for (ll wire : wires)
    {
        sum += wire / length;
    }
    return sum;
}

ll binarySearch(vector<ll> & wires)
{
    ll lo = 0; 
    ll hi = maximum + 1;       // must be outside of range !
    ll mid;

    while (lo + 1 < hi)
    {
        mid = (lo + hi) / 2;
        ll numWires = getWires(wires, mid);    

        if (numWires >= m)      // if we have more wires, can we reduce number of wires by increasing the length?
        {
            lo = mid;
        }
        else                    // if we have less wires, we def need more wires by decreasing the length
        {
            hi = mid;
        }
    }

    // what do we return?
    return lo;
}

int main()
{
    ll n; cin >> n >> m;
    vector<ll> wires (n);
    for (ll i = 0; i < n; i++)
    {
        ll wire; cin >> wire;

        if (wire > maximum)     // if new wire is greater than maximum, make that wire a new maximum length wire
            maximum = wire;

        wires[i] = wire;        // fill in the wire collection
    }

    // input Done here

    cout << binarySearch(wires);

}   