#include<bits/stdc++.h>

using namespace std;
int n, k;

int getCoins(vector<int> & coins)
{
    int res = 0;                        // count the toal coins
    int currCoinInd = coins.size() - 1; // start from the biggest coin

    while(k != 0)
    {
        // curr Coin to use
        int currCoin = coins[currCoinInd];

        int num = k/currCoin;                         // number of current coint we are using
        res += num;                                     // increase res by num
        // cout << currCoin <<" " << num << endl;

        k -= (num * currCoin);                          // decrease the amount of money we paid
        currCoinInd--;                                  // decrease the unit

    }   

    return res;
}

int main()
{
    cin >> n >> k;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    

    // INPUT DONE

    cout << getCoins(coins);

}