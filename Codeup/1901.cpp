#include <iostream>

using namespace std;


void printN(int n)
{
    if (n<1) {
        //cout << n << endl;
        return;
    }
    printN(n-1);
    cout << n << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    printN(n);
    return 0;
}