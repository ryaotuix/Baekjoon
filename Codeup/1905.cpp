#include <iostream>


using namespace std;

void add(int &sum, int n)
{
    if (n < 1) return;
    sum += n;
    add(sum, n-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int sum = 0;
    int n; cin >> n;
    add(sum, n);
    cout << sum << endl;
    return 0;

}