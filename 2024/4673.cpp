#include <bits/stdc++.h>

using namespace std;

const int N = 10001;

// O(n^2)

// make an array that marks self numbers
bool arr[N] = {true, };


int getSumDigit(int i)
{
    int res = i;
    while (i)
    {
        res += (i % 10); // add last digit
        i = i / 10;
    }

    return res;
}

// go into recursion
void dfs(int curr)
{
    // base case where curr is bigger than N
    if (curr >= N)
    {
        return;
    }

    // if it is less than N, mark arr[curr] as false (not a self number)
    arr[curr] = false;
    
    // do it again,
    int next = getSumDigit(curr);
    dfs(next);
}

void output()
{
    memset(arr, true, sizeof(bool) * N);

    for (int i = 1 ; i < N ; i++)
    {
        // if this is a self number,
        if (arr[i] == true)
        {
            cout << i << "\n";
            // dive in and mark everything false
            dfs(i);
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    output();
}

// void mark(int i)
// {
//     // if this is a self number,
//     if (arr[i] == true)
//     {
//         // mark everything from now on as false
//         int curr = i;
//         if (curr < N)
//         {
//             arr[getSumDigit(curr)] = true;
//         }
//     }
// }

// void input()
// {
//     arr[1] = arr[3] = arr[5] = arr[7] = arr[9] = arr[20] = arr[31] = arr[42] = arr[53] = arr[64] = arr[75] = arr[86] = arr[97] = true; // make these base cases false
    
// }

// void output()
// {
//     for (int i = 1; i < N; i++)
//     {
//         // if arr[i] says it is truly a self number, print it out
//         if (arr[i] == true)
//             cout << arr[i] << "\n";
//     }
// }

