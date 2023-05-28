// #include <bits/stdc++.h>

// using namespace std;

// int n, p;
// int arr [97 + 3];

// void rec(int x)
// {
//     int res = n * x % p;
//     // cout << "res : " << res << endl;
//     // base case : when found a cycle
//     if (arr[res] == 2)
//         return;

//     arr[res]++;   // increment counter
//     rec(res);
// }

// void printArr()
// {
//     for (int i : arr)
//     {
//         cout << i << " ";
//     }
// }

// int main()
// {
//     cin >> n >> p;

//     rec(n);

//     int cnt = 0;
//     for (int i = 0; i < 100; i++)
//     {
//         if (arr[i] == 2)
//             cnt++;
//     }
//     // printArr();
//     // cout << endl;

//     cout << cnt;
// }


#include <bits/stdc++.h>

using namespace std;

int nth[1000 + 3];
int n, p;

int dfs(int depth, int curr)
{
    // base case: already encountered value,
    if (nth[curr] != 0)
    {
        return depth - nth[curr];
    }

    nth[curr] = depth;

    int next = n * curr % p;

    return dfs(depth + 1, next);
}


int main()
{
    cin >> n >> p;
    int res = dfs(1, n);
    cout << res;
}