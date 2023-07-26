#include <bits/stdc++.h>

using namespace std;


vector<int> v1 = {1,3,6,6,6,8};
vector<int> v2 = {1,4,8,9};


// upper_bound : > target
// Goal : bs1(6, v1) = 2
// Goal : bs1(6, v2) = 2
int bisectLeft(int target, vector<int> & v)
{
    int lo = 0; int hi = v.size() - 1;

    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        int curr = v[mid];

        if (curr < target)
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}


// Goal : bs2(6, v1) = 5
// Goal : bs2(6, v2) = 2
int bisectRight(int target, vector<int> & v)
{
    int lo = 0; int hi = v.size() - 1;

    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        int curr = v[mid];

        if (curr > target)
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}


int main()
{
    cout << bisectLeft(6, v1) << endl;
    cout << bisectLeft(6, v2) << endl;

    cout << bisectRight(6, v1) << endl;
    cout << bisectRight(6, v2) << endl;
    return 0;
}