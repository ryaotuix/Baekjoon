#include <iostream>


using namespace std;

int arr[1001];

bool canBeSum(int target, int max)
{
    for (int i = 1; i <= max; i++)
    {
        for (int j = 1; j <= max; j++)
        {
            for (int k = 1; k <= max; k++)
            {
                if (arr[i]+arr[j]+arr[k] == target) return true;
            }
        }
    }
    return false;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num; cin >> num;
    for (int i = 0; i < num; ++i)
    {
        // x is a number to test if it can be sum of three 삼각수
        int x; cin >> x;

        // after receiving x, we insert the Tn = n(n+1)/2 into the array
        for (int j = 1; j<x; j++)
        {
            arr[j] = j*(j+1)/2;
        }

        int j;
        // find the index of the closest Tn value ex) Wanna make 11? then stop at T4 = 10
        for (j= 0; j<x; j++)
        {
            if (arr[j+1] > x) break;
        }

        bool can = canBeSum(x, j);
        if (can) cout << 1 << "\n";
        else cout << 0 << "\n";

    }

    return 0;

}