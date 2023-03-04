#include <bits/stdc++.h>

using namespace std;

int arr[1000 + 1];
int dp[1000 + 1];
multimap<int, int> mp; // key: arr[i]   value : i
typedef pair<int, int> pii;
int max = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int len; cin >> len;

    for (int i = 1; i < len + 1; i++)
    {
        int arr_i; cin >> arr_i;
        mp.insert(pii(i, arr_i));       // have a map where key : arr[i]    value : i
        
    }
    
    
}