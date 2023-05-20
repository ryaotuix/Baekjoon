#include <iostream>

using namespace std;

int n, m;

int arr[8+2];   //  array to store each roll's number

void fill(int ind, int sum)
{
    // case 1: when you cannot make it
    if (ind == 0 && sum != 0)
        return;

    // case 2 : when you reached sum before using all indices
    if (sum == 0 && ind != 0)
        return;

    // case 3 : when you made it
    if (sum == 0)
    {
        for (int i = n; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    // fill it in
    for (int i = 1; i < 6 + 1; i++)
    {
        arr[ind] = i;
        fill(ind - 1, sum - i);
    }
}

int main()
{
    cin >> n >> m;
    fill(n, m);
}