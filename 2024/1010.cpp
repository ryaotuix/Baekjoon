#include <bits/stdc++.h>

using namespace std;

int T;
int N, M;
const int MAX = 30 + 1;
int C[MAX][MAX];

void init()
{
    // base case 
    for (int i = 0; i < MAX; i++)
    {
        // iCi and iC0 is 1
        C[i][i] = 1;
        C[i][0] = 1; 
    }
}

int comb(int n, int r)
{
    // if it is already filled return
    if (C[n][r] != 0) return C[n][r];

    C[n][r] = comb(n-1,r-1) + comb(n-1,r);

    return C[n][r];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();
    cin >> T;
    while (T--)
    {
        cin >> N >> M;
        cout << comb(M,N) << "\n";
    }
    
    return 0;
}

