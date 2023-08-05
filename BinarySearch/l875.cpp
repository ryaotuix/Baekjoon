#include <bits/stdc++.h>

using namespace std;

// get hours with potential K 
int getHour(vector<int> &piles, int k)
{
    if  (k == 0)
        return -1;
    int ret = 0;
    for (int pile : piles)
    {
        if (pile % k == 0)
            ret += pile / k;
        else
            ret += (pile / k) + 1;
    }

    return ret;
}

// finding minimum K - how much Koko eats an hour
int minEatingSpeed(vector<int> &piles, int h)
{
    int lo = 0;
    int hi = 1e9;
    int cnt = 0;
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2; // current K
        int hours = getHour(piles, mid);
        if (hours == -1)
            return 1;
        // increase hours by reducing K 
        if (hours <= h)
            hi = mid;
        // decrease hours by increasing K
        else
            lo = mid + 1;

        cout << "hours : " << hours << " " << lo << " " << mid << " " << hi << endl;
        
    }
    return hi;
}

int main()
{   
    vector<int> pile = {312884470};
    cout << minEatingSpeed(pile, 968709470) << endl;
}