#include <bits/stdc++.h>

using namespace std;

int arr[100];
int n;

// check what we have put in x is valid -> return true if it is good, return false if it is bad
bool check(int x)
{
    int leftPtr;
    int rightPtr;
    // must check the size of 1 ~ x/2
    for (int i = 1; i <= x/2; i++)
    {
        leftPtr = x - (2*i) + 1;
        rightPtr = x - i + 1;
        bool good = false;

        for (int j = 0; j < i; j++, leftPtr++, rightPtr++) // for each i - size substring, check
        {
            // if they are different
            if (arr[leftPtr] != arr[rightPtr])
            {
                good = true;
                break;
            }
        }

        if (!good)              // if this sequenc is not good, we cannot have any not good sequence -> return false
            return false;
    }

    return true;
}

// bottom up recursion
void back(int x)
{
    // base case
    if (x == n + 1)
    {
        for (int i = 1; i <= n; i++)
            cout << arr[i];
        exit(0);
    }
    
    // otherwise, we must need to see if we can fill this in
    for (int i = 1; i <= 3; i++)
    {
        arr[x] = i;
        if (check(x) == true)
            back(x + 1);
    }
}

int main()
{
    cin >> n;
    back(1);
    
}