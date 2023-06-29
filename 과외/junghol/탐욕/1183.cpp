#include <bits/stdc++.h>

using namespace std;

int sum;
vector<int> coins(6);
vector<int> coinVals = {500, 100, 50, 10, 5, 1};
/* {500, 100, 50, 10, 5, 1} */
vector<int> ans(6); // answer all filled with 0s


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
            // use maximum number of current coin if we can pay the rest with next coin value
            if ((sum - j*currCoinVal) % nextCoinVal == 0)
                break;
        }

        sum -= (j*currCoinVal);             // calculate sum 
        total += j;                         // increment total

        ans[i] = j;                         // store how many coins we used
    }

    // The last case when
    if (sum != 0)
    {
        ans[0] = sum / coinVals[0];
        total += ans[0];   
        return total;
    }
    else
    {
        ans[0] = 0;
        return total;
    }   
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
    cout << total << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
