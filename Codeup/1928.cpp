#include <iostream>

using namespace std;

void colatz(int n)
{
    cout << n << endl;
    if (n==1) return;
    
    // if even
    if (n%2 == 0)
    {
        n /= 2;
    } 
    else // if odd
    {
        n = 3*n + 1;
    }
    colatz(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    colatz(n);
    return 0;

}