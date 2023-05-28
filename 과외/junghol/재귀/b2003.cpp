// #include <bits/stdc++.h>

// using namespace std;

// int arr [10000 + 10];
// int n, m;       // n : number of elements  m : target sum

// int sum = 0;
// int cnt = 0;

// void rec(int start)
// {
//     // base case:
//     if (start == n)
//         return;
    
//     for (int i = start; i < n; i++)
//     {
//         sum += arr[i];
//         if (sum >= m)
//         {
//             if (sum == m)
//                 cnt ++;    
//             break;
//         }
//     }

//     sum = 0;
//     rec(start + 1);
// }

// int main()
// {
//     cin >> n >> m;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     // input done ! starting at Index 0
//     rec(0);
//     cout << cnt;
// }


// #include <bits/stdc++.h>

// using namespace std;

// int arr [10000 + 10];
// int n, m;       // n : number of elements  m : target sum

// int sum = 0;
// int cnt = 0;

// void twoP()
// {
//     int i;
//     int j;

//     for (j = 0; j < n; j++)
//     {
//         for (i = j; i < n; i++)
//         {
//             sum += arr[i];
//             if (sum >= m)
//                 break;
//         }

//         if (sum == m)
//             cnt++;
        
//         sum = 0;
//     }
// }

// int main()
// {
//     cin >> n >> m;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     // input done ! starting at Index 0
//     twoP();
//     cout << cnt;
// }




#include <bits/stdc++.h>

using namespace std;

int arr [10000 + 10];
int n, m;       // n : number of elements  m : target sum

int sum = 0;
int cnt = 0;

void twoP()
{
    int left = 0;
    int right = 0;
    for (right = 0; right < n; right++)
    {
        sum += arr[right];

        while (sum > m)
        {
            sum -= arr[left++];
        }
        
        if (sum == m)
        {
            cnt++;
            sum -= arr[left++];
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // input done ! starting at Index 0

    twoP();
    cout << cnt;
}