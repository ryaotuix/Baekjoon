#include <bits/stdc++.h>

using namespace std;


int n;
// 1D array
int temp [13 + 5];      // index : row,  val : col
int cnt = 0;


bool promising(int row)
{
    // iterate over all rows from 1~x-1
    for (int i = 1; i < row; i++)
    {
        // same col || on same diagonal X
        if (temp[i] == temp[row] || row - i == abs(temp[row] - temp[i]) )
            return false;
    }
    return true;
}


void nQueen(int row)
{
    // Base case when row == n + 1
    if (row == n + 1)
    {
        cnt++;
        return;
    }

    // otherwise, put i (col) in row index
    for (int i = 1; i <= n; i++)
    {
        // place queen on ith column on row #
        temp[row] = i;
        if (promising(row))
            nQueen(row + 1);
    }
}

int main()
{
    cin >> n;
    nQueen(1);
    cout << cnt;
}