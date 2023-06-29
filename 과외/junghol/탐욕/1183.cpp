// #include <bits/stdc++.h>

// using namespace std;

// int sum;
// vector<int> coins(6);
// vector<int> coinVals = {500, 100, 50, 10, 5, 1};
// /* {500, 100, 50, 10, 5, 1} */
// vector<int> ans(6); // answer all filled with 0s


// int answer()
// {
//     int total = 0;

//     for (int i = coins.size() - 1; i > 0; i--)
//     {
//         if (sum == 0)
//             return total;

//         int currCoinVal = coinVals[i];       // current coin Val
//         int coinNum = coins[i];             // number of coins

//         int nextCoinVal = coinVals[i-1];     // next coin Val

//         // get optimal coinNum
//         int j;
//         for (j = coinNum; j >= 0; j--)
//         {
//             // use maximum number of current coin if we can pay the rest with next coin value
//             if ((sum - j*currCoinVal) % nextCoinVal == 0)
//                 break;
//         }

//         sum -= (j*currCoinVal);             // calculate sum 
//         total += j;                         // increment total

//         ans[i] = j;                         // store how many coins we used
//     }

//     // The last case when
//     if (sum != 0)
//     {
//         ans[0] = sum / coinVals[0];
//         total += ans[0];   
//         return total;
//     }
//     else
//     {
//         ans[0] = 0;
//         return total;
//     }   
// }


// int main()
// {
//     // INPUT DONE
//     cin >> sum;
//     for (int i = 0; i <coins.size(); i++)
//     {
//         cin >> coins[i];
//     }


//     int total = answer();
//     cout << total << endl;
//     for (int i = 0; i < ans.size(); i++)
//     {
//         cout << ans[i] << " ";
//     }

//     return 0;
// }




/*
Idea:
    if you can get minimum number of coins, to make total - target,
    you will get the maximum number of coins
*/


#include <bits/stdc++.h>

using namespace std;

int target;
int sum = 0;
vector<int> coinValues = {500, 100, 50, 10, 5, 1};
vector<int> coinNum(6);     // initial number of coins
vector<int> coinSub(6);     // store number of coins to make total - target


int getTotal()
{
    int total = 0;
    int remaining = sum - target;   // sum - target

    for (int i = 0; i < 6; i++)
    {
        // if remaining becomes 0, it means we are done
        if (remaining == 0)
            break;

        // if we used all the coins or cannot use this coin because it exceeds
        if (coinNum[i] == coinSub[i] || remaining - coinValues[i] < 0)
            continue;
        
        // if we can use this number 
        coinSub[i]++;
        remaining -= coinValues[i];
        
    }
    
    for (auto i : coinSub)
        cout << i << " ";
    cout << endl;

    return total;
}

int main()
{
    cin >> target;
    for (int i = 0; i < 6; i++)
    {
        cin >> coinNum[i];
        sum += coinNum[i] * coinValues[i];    
    }
    // cout << "sum : " << sum << endl;
    // INPUT done


    cout << getTotal() << endl;
    for (int i = 0; i < coinSub.size(); i++)
    {
        cout << coinNum[i] - coinSub[i] << " ";
    }
    
}



















