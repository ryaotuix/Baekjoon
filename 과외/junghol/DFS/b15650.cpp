#include <bits/stdc++.h>

using namespace std;

// materials
int m;
int n;
int arr[10];
unordered_map<int, int> um; // map : int -> count



void backtrack(int cnt, int ind)
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
        // if not found AND curr index >= index before
        if (!um[i] && i >= ind)
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
    // cout << n << m << endl;
    backtrack(0, 0);
}