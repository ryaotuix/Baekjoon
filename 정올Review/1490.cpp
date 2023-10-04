#include <bits/stdc++.h>

using namespace std;

int n;
int k;

unordered_map<int, int> used;   // mark if int is used
int target[10 + 5];             // target

int arr[10 + 5];                // temporary array
bool check = false;             // check if previously completed array is target
bool found = false;             // check if next is found

void input()
{
    cin >> n >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> target[i];
    }
}



void rec(int prev, int depth)
{
    // base case:
    if (depth == k)
    {
        if (check)
        {
            for (int i = 0; i < k; i++) cout << arr[i] << " ";
            found = true;
            exit(0);
        }

        for (int i = 0; i < k; i++)
        {
            if (arr[i] != target[i]) return;
        }
        check = true;
    }

    // recursion
    for (int i = prev; i <= n; i++)
    {
        // if i is not used
        if (!used[i])
        {
            arr[depth] = i;
            used[i] = true;
            rec(i, depth + 1);
            used[i] = false;
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    rec(1, 0);
    if (!found) cout << "NONE";
}