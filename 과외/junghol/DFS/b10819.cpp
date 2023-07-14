#include <bits/stdc++.h>

using namespace std;

// materials 
int n;
int arr[10];
vector<int> v;      // store each permutation

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

int getSum()
{
    int res = 0;
    for (int i = 0; i < n -1; i++)
        res += abs(v[i+1] - v[i]);
    
    return res;
}

// get all possible permutation
bool used[10];
int res = 0;

void backTrack(int cnt)
{
    // base case:
    if (cnt == n)
    {
        int total = getSum();
        res = max(total, res);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        // if this is not visited
        if (!used[i])
        {
            used[i] = true;                 // mark used, add this item
            v.push_back(arr[i]);

            backTrack(cnt + 1);

            used[i] = false;                // mark unused, unadd this item
            v.pop_back();
        }
    }
}

int main()
{
    input();
    backTrack(0);

    cout << res;
}