#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

vector<int> nums = {1, 1, 1, 1, 1};
int len = nums.size();
int target = 3;
int cnt = 0;

// Pure BackTracking O(N^2)
int cntAll(int ind, int currSum)
{
    // base case:
    if (ind == len)
    {
        if (currSum == target)
            return 1;
        else
            return 0;
    }

    int curr = nums[ind];
    return cntAll(ind + 1, currSum + curr) + cntAll(ind + 1, currSum - curr);
}

typedef pair<int, int> pii; // {index, sum}
// DP

unordered_map<pii, int> um; // {index, sum}  ->   count

int backtrack(int ind, int total)
{
    if (ind == len)
    {
        return (total == target) ? 1 : 0;   // found it, 1, otherwise 0
    }

    pii currPair = {ind, total};

    // if found,
    if (um.find(currPair) != um.end())
    {
        return um.at(currPair);
    }

    // if not found, recurse down
    um[currPair] = backtrack(ind + 1, total - nums[ind]) + backtrack(ind + 1, total + nums[ind]);
    return um[currPair];
}

int main()
{
    cout << cntAll(0, 0);
}