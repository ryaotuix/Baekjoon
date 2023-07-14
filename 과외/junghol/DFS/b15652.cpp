#include <bits/stdc++.h>

using namespace std;

// materials
int m;
int n;
int arr[10];
unordered_map<int, int> um; // map : int -> count



void backtrack(int cnt, int prev)
{
    // base case:
    if (cnt == m)
    {
        // print seq
        for (int i = 0; i < m; i++)
            cout << arr[i] << " ";
        cout << "\n";

        return;
    }

    for (int i = 1; i <= n; i++)
    {   
        // if (not found OR not used to fill all) AND i >= prev

        if ( (!um[i] || um[i] < n) && i >= prev)
        {
            um[i]++;        // make it found
            arr[cnt] = i;   // cnt is index!!!!

            backtrack(cnt + 1, i);

            um[i]--;        // make it not found
        }
    }
}


int main()
{
    cin >> n >> m;
    backtrack(0, 0);
}