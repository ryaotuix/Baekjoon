#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii; // first : 0 count          second : 1 count
pii dp[41];


int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    } else if (n == 1) {
        printf("1");
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

void printDP(vector<pii> & v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << "(" << v[i].first << ", " << v[i].second << ") ";
    }
    cout << endl;
}
void addDP(vector<pii> &v, int k)
{
    if (k < 2) return;
    for (int i = 2; i <= k; i++)
    {
        int first = v[i-1].first + v[i-2].first;
        int sec = v[i-1].second + v[i-2].second;
        v[i] = pii(first, sec);
    }

}
void initializeDP()
{
    dp[0] = pii(1,0);
    dp[1] = pii(0,1);   

    for (int i = 2; i < 40 + 1; i++)
    {
        int first = dp[i-1].first + dp[i-2].first;
        int sec = dp[i-1].second + dp[i-2].second;
        dp[i] = pii(first, sec);
    }
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    initializeDP();

    int testCases; cin >> testCases;
   

    while(testCases--)
    {
        int k; cin >> k;

        cout << dp[k].first << " " << dp[k].second << endl;

    }   


}