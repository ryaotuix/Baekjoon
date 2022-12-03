#include <iostream>

using namespace std;

// get nCr
// use facts
// 1. nCr = n-1Cr-1 + n-1Cr
// 2. nC0 = nCn = 1


// 1) Simple recursion
int nCr(int n, int r)
{
    // base case
    if (n==r || r==0) return 1;
    // otherwise
    else return(nCr(n-1, r-1) + nCr(n-1,r));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, r;
    cin >> n >> r;
    cout << nCr(n,r) << endl;

}