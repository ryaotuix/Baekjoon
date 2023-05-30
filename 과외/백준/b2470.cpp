#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // input done (starting at index 0)

    // sort first
    sort(v.begin(), v.end());

    // pointers
    int left = 0;
    int right = v.size() - 1;

    // index saver
    int i = left;
    int j = right;

    int sum  = v[left] + v[right];

    while (left < right)
    {
        int curr = v[left] + v[right];

        // if current sum is closer to 0, update saver and sum
        if (abs(curr) < abs(sum))
        {
            i = left;
            j = right;
            sum = curr;
        }

        if (curr >= 0)
        {
            right--;
        }
        else // (curr < 0)
        {
            left++;
        }
    }

    cout << v[i] << " " << v[j] << endl;
}