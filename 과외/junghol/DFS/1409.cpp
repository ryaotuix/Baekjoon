#include <bits/stdc++.h>

using namespace std;

// materials
int n;                  // total door number
int l, r;        // opened door numbers
int rep;                // number of doors to open
vector<int> doors;      // seq of doors to open
int cnt = INT_MAX;

void input()
{
    cin >> n;
    cin >> l >> r;
    cin >> rep;
    for (int i = 0; i < rep; i++)
    {
        int x;
        cin >> x;
        doors.push_back(x);
    }
}

void dfs(int currl, int currr, int currcnt, int doorIndex)
{
    // Base Case : when doorIndex  = doors.size
    if (doorIndex == doors.size())
    {
        cnt = min(currcnt, cnt);
        return;
    }

    int toOpen = doors[doorIndex];
    // case 1 : cnt currl
    dfs(toOpen, currr, currcnt + abs(currl - toOpen), doorIndex + 1);
    // case 2 : cnt currr
    dfs(currl, toOpen, currcnt + abs(currr - toOpen), doorIndex + 1);
}

int main()
{
    intput();
    dfs(l, r, 0, 0);
    cout << cnt;
}