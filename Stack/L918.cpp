#include <bits/stdc++.h>

using namespace std;

// void printV(vector<int> & v)
// {
//     for (auto i : v)
//         cout << i << " ";
    
//     cout << endl;
// }


// vector<int> getLeftSum(vector<int> & nums)
// {
//     // init
//     vector<int> res (nums.size());

//     // the best sum for the first index : first
//     res[0] = nums[0];
    
//     // KADANE'S ALGORITHM
//     for (int i = 1; i < nums.size(); i++)
//     {
//         int curr = nums[i];
//         res[i] = max(res[i-1] + curr, curr);
//     }

//     return res;
// }


// vector<int> getSuffixSum(vector<int> & nums)
// {
//     int len = nums.size();
//     // init
//     vector<int> res (len);

//     // the best right sum : last num
//     int cumulative = nums[len - 1];
//     res[len - 1] = nums[len - 1];

//     // Get the best suffix sum of each index
//     for (int i = len - 2; i >= 0; i--)
//     {
//         cumulative += nums[i];
//         res[i] = max(res[i+1], cumulative);
//     }

//     return res;
// }

// int maxSubarraySumCircular(vector<int>& nums) 
// {
//     vector<int> left = getLeftSum(nums);
//     vector<int> suffix = getSuffixSum(nums);

//     int maxSum = nums[0];
//     int normalSum;
//     int contLeft = 0;
//     int specialSum = 0;

//     for (int i = 0; i < nums.size(); i++)
//     {
//         // normal sum
//         normalSum = left[i];

//         // cotinuous Left
//         contLeft += nums[i];

//         if (i != nums.size() - 1)
//             specialSum = contLeft + suffix[i + 1];
//         else    // last index, sum of everything
//             specialSum = contLeft;

//         maxSum = max(maxSum, max(normalSum, specialSum));        
//         // cout << i << endl;
//         // cout << "normal Sum : " << normalSum << endl;
//         // cout << "special Sum : " << specialSum << endl;
//         // cout << "max Sum : " << maxSum << endl;
//         // cout << endl;
//     }
    
//     // printV(nums);
//     // printV(left);
//     // printV(suffix);

//     return maxSum;

// } 



int maxSubarraySumCircular(vector<int> & nums)
{
    int currMax = 0;          // current max
    int currMin = 0;          // current min  
    int maxSum = nums[0];
    int minSum = nums[0];
    int total = 0;

    for (int n : nums)
    {
        total += n;

        // normal Kadaine's algorithm
        currMax = max(0, currMax) + n;
        maxSum = max(maxSum, currMax);

        // find minimum
        currMin = min(0, currMin) + n;
        minSum = min(minSum, currMin);
    }

    // DON'T FORGET THE CASE WHERE MINSUM ITERATE THRU ALL ELEMENTS (ALL NEGATIE ELEMENTS)
    if (minSum == total)
        return maxSum;      // -> then return max sum
    
    return max(maxSum, total - minSum);     // -> return max of max Sum and total - minSum
}

int main()
{
    vector<int> nums = {1,-2,3,-2};
    int x = maxSubarraySumCircular(nums);
    
    cout << x;


    

    // get 
    // cout << normalMax << endl;
    // printV(nums);
    // printV(left);
    // printV(right);
}