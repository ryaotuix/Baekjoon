#include <bits/stdc++.h>

using namespace std;

int n;                  // number of houses
int routers;            // number of routers


// O(n)
// function to get the number of routers we need with the current power
int getRouter(vector<int> & houses, int currPower)
{
    int cnt = 1;
    int effective = houses[0] + currPower;      // effective range starting at fist house

    for (int house : houses)
    {
        if (house >= effective)                  // when this house is outside of the effective range
        {
            cnt++;                              // we need another router  
            effective = house + currPower;  // update the effective range
        }
    }
    return cnt;
}


int maxDist(vector<int> & houses, int power)
{   
    // potential power of routers
    int minPow = 1;
    int maxPow = power;

    int ans = 0;

    while (minPow < maxPow)
    {
        int currPow = (minPow + maxPow) / 2;
        int numRouter = getRouter(houses, currPow);

        cout << currPow << " " << numRouter << endl;

        // if we need less router than given router, --> We can reduce router power
        if (numRouter < routers)
        {
            maxPow = currPow;
        }
        // if we need more router than the given router, --> We can increase router power
        else
        {
            minPow = currPow + 1;
            ans = max(ans, currPow);
        }
    }

    return ans;
}

int main()
{
    cin >> n >> routers;
    vector<int> houses;             //  loc of houses

    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        houses.push_back(temp);
    }

    sort(houses.begin(), houses.end());

    for (int house : houses)
        cout << house << " ";
    cout << endl;

    int power = maxDist(houses, houses[houses.size() - 1] - houses[0]);

    cout << power << endl;
}