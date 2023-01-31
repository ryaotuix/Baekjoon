#include <bits/stdc++.h>

using namespace std;

// cmp method! use sort
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}


int main()
{
    vector<vector<int>> intervals = {{1,100}, {11,22}, {1,11}, {2,12}};

    sort(intervals.begin(), intervals.end(), cmp);

    int cnt = 0;
    int lind = intervals[0][1];
    for (int i =1 ; i< intervals.size(); i++)
    {
        if (intervals[i][0] < lind) cnt++;
        else lind = intervals[i][1];
    }

    cout << cnt;
}