#include <bits/stdc++.h>

using namespace std;

int k;
int arr[50 + 5];
unordered_map<int, int> used;

void input()
{
    cin >> k;

    // input is already sorted
    for (int i = 0; i < k; i++) cin >> arr[i];  
}

// combination of 6
int res[6] = {0,};

void lotto(int depth, int prev)
{
    // base case:
    if (depth == 6)
    {
        for (int i = 0; i < 6; i++) cout << res[i] << " ";
        cout << "\n";
        return;
    } 

    // recursion here
    for (int i = prev; i < k; i++)
    {
        if (!used[arr[i]])
        {
            res[depth] = arr[i];
            used[arr[i]]++;

            lotto(depth + 1, i);

            used[arr[i]]--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    lotto(0, 0);
}