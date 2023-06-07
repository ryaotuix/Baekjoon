#include <bits/stdc++.h>

using namespace std;

int n, m;       // n is number of original wires, m : number of same length wires we want 
int maximum = 0;

int getWires(vector<int> & wires, int length)
{
    int sum = 0;
    for (int wire : wires)
    {
        sum += wire / length;
    }
    return sum;
}

int binarySearch(vector<int> & wires)
{
    int lo = 0; 
    int hi = maximum + 1;       // must be outside of range !
    int mid;

    while (lo + 1 < hi)
    {
        mid = (lo + hi) / 2;
        int numWires = getWires(wires, mid);    

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
    int n; cin >> n >> m;
    vector<int> wires (n);
    for (int i = 0; i < n; i++)
    {
        int wire; cin >> wire;

        if (wire > maximum)     // if new wire is greater than maximum, make that wire a new maximum length wire
            maximum = wire;

        wires[i] = wire;        // fill in the wire collection
    }

    // input Done here

    cout << binarySearch(wires);

}   