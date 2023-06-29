#include <bits/stdc++.h>

using namespace std;

int sum;
    vector<int> coins(6);
    vector<int> coinVals = {500, 100, 50, 10, 5, 1};
/* {500, 100, 50, 10, 5, 1} */

    vector<int> ans(6); // answer


int answer()
{
    int total = 0;

    for (int i = coins.size() - 1; i > 0; i--)
    {
        if (sum == 0)
            return total;

        int currCoinVal = coinVals[i];       // current coin Val
        int coinNum = coins[i];             // number of coins

        int nextCoinVal = coinVals[i-1];     // next coin Val

        // get optimal coinNum
        int j;
        for (j = coinNum; j >= 0; j--)
        {
            if ((sum - j*currCoinVal) % nextCoinVal == 0)
                break;
        }

        sum -= (j*currCoinVal);
        total += j;

        ans[i] = j;
    }

    if (sum == 0)
        return total;

    
    ans[0] = sum / coinVals[0];
    
    return total;
}


int main()
{
    // INPUT DONE
    cin >> sum;
    for (int i = 0; i <coins.size(); i++)
    {
        cin >> coins[i];
    }


    int total = answer();
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
