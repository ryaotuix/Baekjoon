#include <iostream>

using namespace std;

void print(int n)
{
    int cnt = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << cnt + (j*n) << " ";
        }
        cnt++;
        cout << "\n";
    }
}


int main()
{
    int n;
    cin >> n;

    print(n);
}