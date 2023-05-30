#include <bits/stdc++.h>

using namespace std;

int n;      // number of elements

// target Ind : index store the Sum target
bool isGood(vector<int> & v, int targetInd)
{       
    int i = 0;
    int j = n - 1;
    int target = v[targetInd];

    while(i < j)
    {
        // 0. if either one of the pointer is targetInd, skip it over
        if (i == targetInd)
        {
            i++;
            continue;
        }

        if (j == targetInd)
        {
            j--;
            continue;
        }

        // 1. get sum
        int sum = v[i] + v[j];

        // if we can make this target sum, it is true
        if (sum == target)
            return true;
        
        if (sum < target)   // if sum < target, increase smaller value
        {
            i++;
        }
        else                // if sum > target, decrease bigger value
        {
            j--;
        }
    }
    return false;
}

int main()
{
    cin >> n;
    vector<int> v(n);   // vector size n
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // input Done vector starting at Index 0


    // Logic:

    sort(v.begin(), v.end());   // sort


    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (isGood(v, i))
            cnt++;
    }

    cout << cnt;

}