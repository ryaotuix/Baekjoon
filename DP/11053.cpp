#include <bits/stdc++.h>

using namespace std;

vector<int> v = {2,3,6,8,10,13};

void printVec()
{
    for (auto i : v)
        cout << i << " ";
    cout << endl;
}

// Binary Search the smallest number that is bigger than or equal to Target
int findSB(int target, int lo, int hi)
{
    int i = 1;
    int mid = lo + (hi-lo)/2;

    cout << "[" << i++ << "]" << ": " << lo << " " << mid << " " << hi << endl;

    while(lo+1 < hi)
    {
        mid = lo + (hi-lo)/2;
        
        if (v[mid] >= target)
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
        cout << "[" << i++ << "]" << ": " << lo << " " << lo + (hi-lo)/2 << " " << hi << endl;

    }
    
    cout << v[hi];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    printVec();

    int lo = 0; int hi = v.size()-1;
    int target = 14;
    cout << findSB(target, lo, hi);
}