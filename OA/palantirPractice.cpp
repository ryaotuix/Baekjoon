#include <bits/stdc++.h>

using namespace std;

// given array of integers, give how many pairs of integers whose a & b is a power of 2
// https://www.geeksforgeeks.org/count-of-pairs-whose-bitwise-and-is-a-power-of-2/#

vector<int> arr = {6, 4, 2, 3};

bool isPowerOf2(int a, int b)
{
    int n = a & b;

    if (n != 0 && (n & -n) == n)
        return true;

    return false;
}

long long countPairs()
{
    long long ans = 0;
    long long maxi = 0;

    unordered_map<int, int> um;     // count the frequency of each integer
    for (int i = 0; i < arr.size(); i++)
    {
        um[arr[i]]++;
        maxi = max(maxi, (long long) arr[i]);
    }

    // iterate over integer i 0~max
    for (int i = 0; i <= maxi; i++)
    {
        // if not found, skip
        if (!um[i])
            continue;
        
        for (int j = i; j <= maxi; j++)
        {
            if (isPowerOf2(i, j))
            {
                // consider two cases

                // i. if i == j, 2Cfreq
                if (i == j)
                {
                    ans += ((long long) um[i] * (um[i] - 1) )/2;
                }
                // ii. if i != j, freq * freq
                else
                {
                    ans += ((long long)um[i] * um[j]);
                }
            }
        }
    }

    return ans;
}
int main()
{
    cout << countPairs();
}