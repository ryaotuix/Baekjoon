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

    ll currPrice = prices[0];
    ll currAmount = amounts[0];

    // week 1
    ret += currPrice * currAmount;
    for (int i = 1; i < len; i++)
    {
        currPrice = (currPrice + S < prices[i]) ? currPrice + S : prices[i];
        ret += currPrice * amounts[i];
    }

    return ret;
}

// void printVec(vector<ll> & v)
// {
//     for (ll i : v)
//         cout << i << " ";
//     cout << endl;
// }


// ll getMoney()
// {
//     ll ret = 0;
//     ll len = prices.size();

//     vector<ll> optPriceOption (len);                 // optimal prime option price for each week
//     optPriceOption[0] = prices[0];    // fist week has only one option
//     ret += prices[0] * amounts[0];    // prices * amount

//     // starting from the second week,
//     for (ll currWeek = 1; currWeek < len; currWeek++)
//     {
//         ll currPrice = prices[currWeek];
//         ll currAmount = amounts[currWeek];

//         ll currPay = currPrice * currAmount;

//         optPriceOption[currWeek] = prices[currWeek];

//         // Compare currPay to (previous payment + storage fee)
//         if (currPay > currAmount * (optPriceOption[currWeek - 1]+S))
//         {
//             // Replace if purchasing last week is better
//             currPay = currAmount * (optPriceOption[currWeek - 1]+S);   
//             optPriceOption[currWeek] = optPriceOption[currWeek - 1];
//         }
        

//         // previous payment 
//         // for (ll prevWeek = 0; prevWeek <= currWeek; prevWeek++)
//         // {          
//         //     ll prevPrice = prices[prevWeek];

//         //     ll prevPay = currAmount*S*(currWeek - prevWeek) + (prevPrice * currAmount);    // storing fee + purchase price

//         //     // cout << prevWeek << " " << prevPay << endl;

//         //     // update what to pay
//         //     if (prevPay < currPay)
//         //     {
//         //         currPay = prevPay;
//         //     }
//         // }

//         ret += currPay;
        
//     }

//     // printVec(optPriceOption);
//     return ret;
// }

int main()
{
    input();
    ll res = getMoney();
    cout << res;
}