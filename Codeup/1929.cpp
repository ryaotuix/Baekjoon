#include <iostream>

using namespace std;

void reverseColatz(int n)
{   
    // base case
    if (n==1);
    else 
    {
        // even
        if (n % 2 == 0)
            //n = n/2;
            reverseColatz(n/2);
        else // odd
            //n = 3*n + 1;
            reverseColatz(3*n + 1);
        //reverseColatz(n);
    }
    cout << n << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    reverseColatz(n);
    //cout << n << endl;
    return 0;
}