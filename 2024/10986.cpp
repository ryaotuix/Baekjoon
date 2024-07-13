#include <bits/stdc++.h>

using namespace std;

int N, M;
const int MAX = 1e6 + 1;


typedef long long ll;
ll cnt = 0;
int arr[MAX];
ll prefixSum[MAX];
// binary search tree to count remainders
map<int, ll> rem;  // (remainder, count)


// // n > r
// int combination(int n, int r)
// {
//     // base case
//     if (r == 0 || n == r)   return 1;
//     else return combination(n-1, r-1) + combination(n-1, r);
// }

void input()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        prefixSum[i] = prefixSum[i-1] + arr[i];

        rem[prefixSum[i] % M]++;

        // if prefixSum from the beginning is divisible by M,   increase cnt
        if (prefixSum[i] % M == 0) cnt++;
    }
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    input();

    for (auto iter = rem.begin(); iter != rem.end(); iter++)
    {
        if (iter->second < 2) continue;
        else
            cnt += iter->second * (iter->second - 1) / 2;
    }

    cout << cnt;
}