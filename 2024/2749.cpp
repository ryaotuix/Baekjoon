#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;
const ll mod = 1000000;

ll n;

matrix operator * (matrix & A, matrix & B)
{
    int size = A.size();

    matrix res(size, vector<ll>(size));

    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            for (int k = 0; k < size; k++)
            {
                res[row][col] += A[row][k] * B[k][col];
            }

            res[row][col] %= mod;
        }
    }

    return res;
}

ll fibonacci()
{
    /*
    Fn+1    Fn         1    1 ^ n
                    =  
    Fn      Fn-1       1    0   
    */

    if (n <= 1)  return n;

    matrix ans = {{1, 0},
                  {0, 1}};

    matrix f = {{1, 1},
                {1, 0}};

    while(n > 0)
    {
        // n is odd
        if (n%2 == 1)
        {
            ans = ans * f;
        }
        
        f = f * f;
        n /= 2;
    }

    // for (int i = 0; i < 2; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    return ans[0][1];
}   

void input()
{
    cin >> n;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    cout << fibonacci();
}