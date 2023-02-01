// #include <iostream>

// using namespace std;
// int main()
// {
//     unsigned long int n;
//     cin >> n;

//     unsigned long int start = 1;
//     unsigned long int sum = 0;
//     unsigned long int cnt = 0;
//     while (sum < n)
//     {
//         // if we have used the value (start) already,
//         if (n - sum < start)
//         {
//             // same condition, reduce start and cnt
//             // reduce sum by start   
//             while (n-sum < start)
//             {
//                 --start; --cnt;
//                 sum -= start;
//                 //cout << "sum : " << sum << " start : " << start << endl;
//             }
//             cnt++;
//             break;
//         }
//         sum += start;
//         start++;
//         cnt++;
//         //cout << "sum : " << sum << " start : " << start << endl;
//     }
//     //cout << "----------\n";
//     cout << cnt;

// }
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
long long s;
int n = 1;
int main() {
	scanf("%lld", &s);
	while ((s -= n) > n++);
    // {
    //     cout << "remain : " << s << endl;
    //     cout << "num : " << n << endl;
    // };
	printf("%d", --n);
}