#include <bits/stdc++.h>

using namespace std;

void getCombinationSum(int &ind, int &sum, int &target, vector<int> &temp, vector<int> &candidates, vector<vector<int>> &res)
{
    // base case:
    if (sum == target)
    {
        res.push_back(temp);
        temp
        return;
    }

    // otherwise
    while (ind < candidates.size() && sum + candidates[ind] <= target)
    {
        sum += candidates[ind];
        temp.push_back(candidates[ind]);

        getCombinationSum(ind, sum, target, temp, candidates, res);
        ind++;

        sum -= candidates[ind - 1];
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    // i. first sort in increasing order
    sort(candidates.begin(), candidates.end());

    // ii. remove duplicate
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

    // iii. backtracking starts

    // materials
    int sum = 0;
    vector<vector<int>> res;
    vector<int> temp;
    int ind = 0;
    getCombinationSum(ind, sum, target, temp, candidates, res);

    return res;
}

void printVV(vector<vector<int>> & res)
{
    cout << "{\n";
    for (vector<int> v : res)
    {
        cout << "{";
        for (int i : v)
            cout << i << " ";
        cout << "}";
    }

    cout << "}";
}

int main()
{
    vector<int> candidates = {2,3,5};
    int target = 8;

    vector<vector<int>> res = combinationSum(candidates, target);
    printVV(res);
}