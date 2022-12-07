#include <iostream>

using namespace std;


int digitSum(int x)
{
    int sum = x;
    while (x) // !!! Same as while (x != 0)
    {
        sum += x%10;
        x /= 10;
    }
    return sum;
}   



int main()
{
    int n; cin >> n;

    // get how many digits there are
    int temp = n;
    int cnt = 0;
    while(temp != 0)
    {
        cnt++;
        temp /= 10;
    }
    // cout << cnt << endl;


    // since each digit cannot be bigger than 9, the minimum generator would be
    // given int - (9 * 자릿수)
    int start = n - (9 * cnt);
    for (int i = start; i <= n; i++)
    {
        if (n == digitSum(i))
        {
            cout << i << "\n";
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}