#include <bits/stdc++.h>

using namespace std;

vector<int> v = {5,4,3,3,3, 5,6,7,6, 7,6,5,3, 5,6,5,3};

int getCandy(vector<int> & v)
{
    if (v.size() <= 1)
        return v.size();

    int ret = 1;

    // size of increasing sequence and decreasing sequence 
    int inc = 0;
    int dec = 0;

    // start at second index
    int ind = 1;

    while (ind < v.size())
    {
        // 1. increasting
        while (ind < v.size() && v[ind] > v[ind - 1])
        {
            ret++;
            inc++;
            ret += inc;
            ind++;
        }

        // 2. decreasing
        while (ind < v.size() && v[ind] < v[ind - 1])
        {
            ret++;
            dec++;
            ret += dec;
            ind++;
        }

        // 3. same
        while (ind < v.size() && v[ind] == v[ind - 1])
        {
            ret++;
            ind++;
        }
        // for case 1,3 (dec seq size <= inc seq size) -> - dec size
        // for case 2 (dec seq size > inc seq size) -> - inc size
        ret -= min(inc, dec);

        // cout << "ret : " << ret << "\n";
        // cout << "inc : " << inc << "\n";
        // cout << "dec : " << dec << "\n";
        // cout << endl;

        // re-init
        inc = 0;
        dec = 0;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int res = getCandy(v);
}