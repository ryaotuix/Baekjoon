#include <iostream>

using namespace std;

// // 최소 공배수
// int lcm(int a, int b)
// {
//     int greater = (a > b) ? a : b;
//     int cnt = 1;

//     while (true)
//     {
//         int target = greater * cnt;
//         if (target % a == 0 && target % b == 0)
//             return target;
//         cnt++;
//     }

//     return -1;
// }

// // 최대 공약수
// int gcf(int a, int b)
// {
//     int smaller = (a < b) ? a : b;
//     while (smaller)
//     {
//         if (a % smaller == 0 && b % smaller == 0)
//             return smaller;
//         smaller--;
//     }
//     return -1;
// }

// USE EUCLIDEAN ALGORITHM
/*
1. gcf(a, b) = gcf(b, a%b)
2. lcm(a, b) = a*b / gcf(a, b)
*/

int gcf(int a, int b)
{
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    if (a%b == 0)
        return b;
    else 
        return gcf(b, a%b);
}

int lcm(int a, int b)
{
    return a*b / (gcf(a, b));
}

void doit(int n)
{
    // init array
    int * arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int least = lcm(arr[0], arr[1]);
    int great = gcf(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {
        least = lcm(least, arr[i]);
        great = gcf(great, arr[i]);
    }


    cout << great << " " << least;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    doit(n);
}