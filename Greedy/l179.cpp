#include <bits/stdc++.h>

using namespace std;

/*
    Key Idea: Sort by nums
    in a way that
    i.e. 21 23 234
    , change them to string and make them the same length by extending the last char
    -> 211 233 234
    Then, we will be able to sort in descending order
    -> 234, 23, 21
*/


/*
    Wrong intuition abovve...
    In case of 34323, 3432
    it would return 343233432
    rather than 343234323

    Taking this into subproblem, if b+a > a+b, then we should put b before a
*/

static bool comp(int &a, int &b)
{
    string sA = to_string(a);
    string sB = to_string(b);
    
    return sB + sA < sA + sB;
}

string largestNumber(vector<int> &nums)
{
    // Don't forget to account when all int are 0s
    bool allZero = true;
    for (int n : nums)
        if (n != 0)
            allZero = false;
    
    if (allZero)
        return "0";
    
    // Regular Cases
    string res = "";
    sort(nums.begin(), nums.end(), comp);   // sort custom comparator
    for (int n : nums)
    {
        res += to_string(n);
    }

    return res;
}

int main()
{
    vector<int> nums = {34323, 3432};
    cout << largestNumber(nums) << endl;
}