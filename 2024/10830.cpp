#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;
ll N, B;

// rewrite operator * for matrix
matrix operator * (matrix & A, matrix & B)
{
    int size = A[0].size();

    matrix res(size, vector<ll>(size)); // init size * size matrix

    for (int row = 0; row < size; row++)
    {
        for (int col = 0; col < size; col++)
        {
            ll ans = 0;
            for (int i = 0; i < size; i++)
            {
                ans += A[row][i] * B[i][col];
            }
            res[row][col] = ans % 1000;
        }
    }

    return res;
}

// A ^ b 
matrix power(matrix & A, ll b)
{
    // base case
    if (b == 1)
    {
        return A;
    }

    matrix temp = power(A, b/2);
    matrix sqr = temp * temp;
    // if odd
    if (b%2 == 1)
        return ((sqr) * A);
    // if even;
    else
        return (sqr);

}

void input()
{
    cin >> N >> B;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();

    matrix M(N, vector<ll>(N));

    // input matrix
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> M[i][j];
        }
    }

    matrix res = power(M, B);

    // print result
    for (int i = 0 ; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << res[i][j]%1000 << " ";
        }
        cout << "\n";
    }

    return 0;
}