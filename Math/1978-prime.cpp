#include <iostream>

using namespace std;

bool isPrime(int x)
{
    if (x==1) return false;
    if (x==2) return true;

    for (int i = 2; i< x; i++)
    {
        if (x%i==0) return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int res = 0;
    int t;

    for (int i = 0; i<n; i++)
    {
        cin >> t;
        if (isPrime(t)) res++;
    }

    cout << res << endl;
    return 0;
}