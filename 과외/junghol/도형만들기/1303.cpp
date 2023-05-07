#include <iostream>

using namespace std;

void print(int n, int m)
{
    int cnt = 1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << cnt << " ";
            cnt++;
        }
        cout << "\n";
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    print(n,m);
}