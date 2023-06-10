#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> &temp, int target)
{
    int lo = 0 - 1;
    int hi = temp.size() - 1;
    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;
        if (temp[mid] >= target)
        {
            hi = mid;
        }
        else
            lo = mid;
    }

    if (temp[hi] == target) // hi should point at the smallest value greater or equal to target
        return temp[hi];
    else // if temp[hi] is not target, then return -1
        return -1;
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    // sort it
    sort(nums.begin(), nums.end());

    // store result
    vector<vector<int>> res;

    int left = 0;
    int right = nums.size() - 1;
    while (left < right)
    {
        vector<int> temp = nums;
        temp.erase(temp.begin() + left);
        temp.erase(temp.begin() + right);

        int target = 0 - (nums[left] + nums[right]);
        int middle = binarySearch(temp, target);
        if (middle != -1)
        {
            vector<int> ans = {nums[left], nums[middle], nums[right]};
            res.push_back(ans);
        }

        if (target >= 0)
            right--;
        else
            left++;
    }

    return res;
}

int main()
{
    vector<int> v = {-1, 0, 1, 2, -1, -4};
    
    vector<vector<int>> res = threeSum(v);
    for (vector<int> v : res)
    {
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

}