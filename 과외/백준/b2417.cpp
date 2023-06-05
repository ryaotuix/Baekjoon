#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;      // target

// 제곱근
/*
    Logic here :
    1. since we are looking for the smallest value greater than target, we would have to move "hi"
    2. In order to do so, we will have to start with lo = min -1, and hi = max
    3. while (lo + 1 < hi)
    mid = lo + (hi - lo) / 2
    if (mid * mid >= target)
        hi = mid
    else
        lo = mid
    return hi
    4. mid*mid can go over long long therefore, need to take an action
*/

ll binarySearchSqrt()
{
    ll lo = 0 - 1;     // min - 1
    ll hi = n;
    ll mid;

    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;

        // if there is a remainder,
        // mid * mid >= target becomes
        // mid >= target/mid + 1

        // bool flag = (n % mid == 0) ? true : false;
        // ll toCompare = flag ? n / mid : n / mid + 1;

        // mid의 sqrt 가 오버플로우가 되는지 mid >= 30억이면 hi 를 움직이기

        if (mid >= n / mid)
        {
            hi = mid;
        }   
        else
            lo = mid;
    }

    return hi;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ll res = binarySearchSqrt();

    cout << res;
}