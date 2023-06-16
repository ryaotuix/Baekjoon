#include <bits/stdc++.h>

using namespace std;

int total;

int getBag()
{
    int maxFive = total / 5;    // maximum number of bag (size of 5) we can use
    int rem = total % 5;        

    while(maxFive >= 0)
    {
        if (rem % 3 == 0)
        {
            return maxFive + (rem / 3);     // if we can use 3
        }
        else
        {
            maxFive--;      // decrement maxFive
            rem = total - (maxFive * 5);    // remainder : total - 5*maxfive
        }
    }

    return -1;
}


int main()
{
    cin >> total;
    cout << getBag();
}