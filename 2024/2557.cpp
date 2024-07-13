// #include <bits/stdc++.h>

// using namespace std;

// int i;
// int cnt = 0;

// void input()
// {
//     cin >> i;

//     // if divisible by 5, it is the answer
//     if (i % 5 == 0)
//     {
//         cout << i/5;
//     }
//     else
//     {
//         // until you can divide it by 5 
//         while (i % 5)
//         {
//             i -= 3;
//             cnt++;

//             if (i == 1 || i == 2)
//             {
//                 cout << -1;
//                 return;
//             }
//         }

//         // answer cnt (how many times you can subtract by 3) + i/5
//         cout << cnt + (i/5);
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     input();
// }

#include <bits/stdc++.h>

using namespace std;

int n; 

int dp[5001];


void input()
{
    cin >> n;
    
    // base cases
    dp[3] = dp[5] = 1;

    for (int i = 6; i <= n; i++)
    {
        // if (i-3) exists, dp[i] is dp[i-3] + 1
        if (dp[i-3])
        {
            dp[i] = dp[i-3] + 1;
        }
        // if [i-5] exists, dp[i] is dp[i-5] + 1
        if (dp[i-5])
        {
            dp[i] = dp[i-5] + 1;
        }
    }

    cout << (dp[n] == 0 ? -1 : dp[n]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
}