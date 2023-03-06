#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int cityNum; cin >> cityNum;

    vector<ll> distances;
    distances.push_back(0);     // to make distance and price same length (size = cityNum)
    for (int i = 0; i < cityNum -1; i++)
    {
        ll k; cin >> k;
        distances.push_back(k);
    }

    vector<ll> prices;
    for (int i = 0; i < cityNum; i++)
    {
        ll k; cin >> k;
        prices.push_back(k);
    }

    ll result = 0;
    ll currPrice = prices[0];
    
    for (int i = 1; i < cityNum; i++)
    {
        result += currPrice * distances[i];
        if (prices[i] < currPrice)   currPrice = prices[i];
    }

    cout << result << endl;
    

}