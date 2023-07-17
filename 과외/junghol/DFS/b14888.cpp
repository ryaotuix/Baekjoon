#include <bits/stdc++.h>

using namespace std;

typedef long long ull;

int n;  // number of numbers
int operCnt[4] = {0, }; // cnt of +, -, x, /
vector<ull> nums; // vector to store numbers
ull mini = 1e9 + 5;
ull maxi = -1e9 - 7;

vector<int> operators;

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num; cin >> num;
        nums.push_back(num);
    }

    for (int i = 0; i < 4; i++)
    {
        int cnt; cin >> cnt;
        operCnt[i] = cnt;
    }
}

void back(ull sum, int ind, int op)
{
    // get new sum according to op
    ull currSum = sum;
    if (op == 0)
        currSum += nums[ind];
    else if (op == 1)
        currSum -= nums[ind];
    else if (op == 2)
        currSum *= nums[ind];
    else if (op == 3)
        currSum /= nums[ind];

    // Base Case ind gets out of boundary
    if (ind == nums.size()-1)
    {
        //  cout << "rec ";

        // get mini and maxi
        mini = min(mini, currSum);
        maxi = max(maxi, currSum);


        // // print curr op sequence
        // for (int n : operators)
        //     cout << n << " ";
        // cout << "==============================\n";
        return;
    }


    // iterate ove operCnt
    for (int i = 0; i < 4; i++)
    {
        if (operCnt[i] != 0)
        {
            operCnt[i]--;
            // operators.push_back(i);

            back(currSum, ind+1, i);
            // operators.pop_back();

            operCnt[i]++;
        }
    }
    
}

int main()
{
    input();
    back(0, 0, 0);
    
    cout << maxi << endl;
    cout << mini << endl;
}