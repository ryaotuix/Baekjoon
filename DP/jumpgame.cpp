#include <bits/stdc++.h>

using namespace std;
#define UNKNOWN 0
#define GOOD 1
#define BAD 2

void printVec(vector<int> &v)
{
    for (int i : v)
        cout << i << " ";
    cout << endl;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

/* Top DOWN DP */
bool canJumpFromHere(int here, vector<int> &nums, vector<int> &memo)
{
    if (memo[here] != UNKNOWN)
        return (memo[here] == GOOD) ? true : false;

    int furthest = min(nums.size() - 1, here + nums[here]);
    for (int nextPosition = here + 1; nextPosition <= furthest; nextPosition++)
    {

        if (canJumpFromHere(nextPosition, nums, memo))
        {
            printVec(memo);
            memo[here] = GOOD;
            return true;
        }
    }
    printVec(memo);
    memo[here] = BAD;

    return false;
}

// bool canJump(vector<int> &nums)
// {
//     vector<int> memo(nums.size(), UNKNOWN);
//     memo[memo.size() - 1] = GOOD;

//     return canJumpFromHere(0, nums, memo);
// }

int main()
{
    vector<int> nums = {1, 1, 2, 0, 4};
    bool canwe = canJump(nums);
    cout << canwe << endl;
}