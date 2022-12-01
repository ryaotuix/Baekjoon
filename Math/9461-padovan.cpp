#include <iostream>

using namespace std;

typedef long long ll;
ll Parray[101] = {0,1,1,}; // Because N is <= 100 // others are 0

ll p(int n)
{
    if (n < 3) return Parray[n];
    if (Parray[n] == 0) Parray[n] = p(n-2) + p(n-3);
    return Parray[n];
}

/*
int p(int n)
{
    if (n==1 || n==2 || n==3) return 1;
    if (n==4 || n==5) return 2;
    return p(n-1) + p(n-5);
}
*/


int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input; cin >> input;
        cout << p(input) << endl;
    }

    return 0;
}