#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
vector<ll> prices;
vector<ll> amounts;
ll N;  // num weeks
ll S;  // ll 

void input()
{
    cin >> N >> S;
    for (ll i = 0; i < N; i++)
    {
        ll currPrice; cin >> currPrice;
        ll currAmount; cin >> currAmount;

        prices.push_back(currPrice);
        amounts.push_back(currAmount);
    }
}

ll getMoney()
{
    ll ret = 0;
    ll len = prices.size();

    for (ll currWeek = 0; currWeek < len; currWeek++)
    {
        ll currPrice = prices[currWeek];
        ll currAmount = amounts[currWeek];

        ll currPay = currPrice * currAmount;

        for (ll prevWeek = 0; prevWeek <= currWeek; prevWeek++)
        {          
            ll prevPrice = prices[prevWeek];

            ll prevPay = currAmount*S*(currWeek - prevWeek) + (prevPrice * currAmount);    // storing fee + purchase price

            // cout << prevWeek << " " << prevPay << endl;

            // update what to pay
            if (prevPay < currPay)
            {
                currPay = prevPay;
            }
        }

        ret += currPay;
        
    }
    return ret;
}

int main()
{
    input();
    ll res = getMoney();
    cout << res;
}