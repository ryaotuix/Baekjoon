#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, wifi;        // number of houses, number of wifi we need
ll minimum = 1e9 + 1;
ll maximum = -1;

// Function to get number of wifi we need with the given distance
int getWifi(vector<ll> & houses, ll dist)
{
    int wifiNum = 1;
    ll temp = houses[0] + dist;     // According to the first house, stores the maximum loc that the current wifi can reach

    for (int loc : houses)
    {
        if (loc >= temp)
        {
            wifiNum++;          // locate wifi in current location
            temp = loc + dist;  // update new maximum location that this wifi can reach
        }
        // cout << "loc : " << loc << " wifiNum : " << wifiNum << endl;

    }

    return wifiNum;
}

// Binary Search the distances
int findDistance(vector<ll> & houses)
{
    ll lo = 0;
    ll hi = maximum - minimum + 3;
    ll mid;

    while (lo + 1 < hi)
    {   
        mid = (lo + hi) / 2;        // mid is current distance
        int numWifi = getWifi(houses, mid);     // get number of wifi we have with current distance

        // cout << lo << " " << hi << " " << mid << " " << numWifi << endl;

        if (numWifi >= wifi)        // Too many wifi? Reduce Increase distance
            lo = mid;
        else
            hi = mid;
    }   
    return lo;
}   

int main()
{
    cin >> n >> wifi;
    vector<ll> houses (n); // vector to store each house's location
    for (int i = 0; i < n; i++)     // receive inputs, and update min and max locations of hosues according to them
    {
        ll loc; cin >> loc;
        if (loc < minimum)
            minimum = loc;
        if (loc > maximum)
            maximum = loc;
        
        houses[i] = loc;            // put it in a vector
    }


    // ! MUST SORT THE HOUSES !
    sort(houses.begin(), houses.end());


    // cout << getWifi(houses, dist);
    
    cout << findDistance(houses);

}