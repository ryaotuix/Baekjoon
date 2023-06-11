#include <bits/stdc++.h>

using namespace std;

int n;  // number of eles

typedef long long ll;

int main()
{
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    // input done (starting at index 0) 

    // first must sort
    sort(v.begin(), v.end());

    // store the optimal locations
    int optI = 0;
    int optLeft = 1;
    int optRight = v.size() - 1;
    ll minSum = 9e9;            // minSum init infinity

    for (int i = 0; i < n-2; i++)
    {
        int left = i + 1;
        int right = v.size() - 1;

        while (left < right)
        {

            ll sum = v[i] + v[left] + v[right];

            // if current sum is less than the minSum we have, update the optimal pointers
            if (abs(sum) < minSum)
            {
                // update minSum
                minSum = abs(sum);

                // update optimal pointers
                optI = i;
                optLeft = left;
                optRight = right;
            }

            // sum is greater than 0, reduce right
            if (sum > 0)
                right--;
            else
                left++;
        }
    }

    cout << v[optI] << " " << v[optLeft] << " " << v[optRight] << endl;
}