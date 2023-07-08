#include <bits/stdc++.h>

using namespace std;

// binary search the lower bound <less than or equal to target>
int getInd(int targetNew, int lo, int hi, vector<int> &nums)
{
    if (targetNew > nums[hi - 1])
        return hi -1;

    int ind = -1;
    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;

        // cout << lo << " " << mid << " " << hi << endl;
        // cout << nums[mid] << " " << targetNew << endl << endl;
        if (nums[mid] < targetNew)
        {
            lo = mid + 1;
            ind = lo;
        }
        else
        {
            hi = mid - 1;
        }
    }

    // if (nums[ind] == targetNew)
    //     ind--;

    return ind;
}

int threeSumSmaller(vector<int> &nums, int target)
{
    if (nums.size() <= 2)
        return 0;

    sort(nums.begin(), nums.end());

    int res = 0;

    for (int i = 0; i < nums.size() - 2; i++)
    {
        int j;
        for (j = i + 1; j < nums.size() - 1; j++)
        {
            
            int targetNew = target - nums[i] - nums[j];
            int ind = getInd(targetNew, -1, nums.size(), nums);
            // if (ind != -1)
            //     cout << "Target : " << targetNew << " Ind : " << ind << " nums[ind] : " << nums[ind] << endl;

            if (ind > j)
            {
                // cout << i << " " << j << " " << ind << endl;
                // cout << nums[i] << " " << nums[j] << " " << nums[ind] << endl;
                if (nums[i] + nums[j] + nums[ind] < target)
                    res += ind-j;
            }
        }
    }

    return res;
}

int main()
{
    vector<int> v = {0,-4,-1,1,-1,2};
    int target = -5;

     sort(v.begin(), v.end());
    for (int i : v)
        cout << i << " ";
    cout << endl;


    cout << getInd(0, -1, v.size(), v) << endl;
    cout << "=============================\n";
    // return 0;
   
    cout << threeSumSmaller(v, target);
}