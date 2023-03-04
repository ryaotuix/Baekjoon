#include <bits/stdc++.h>

using namespace std;



int w[100+1]; // 무게
int v[100+1]; // 가치
// int dp[100+1][100000+1];

// void printDP()
// {
//     for (int i = 1; i < 4+1; i++)
//     {
//         for (int j = 1; j < 18+1; j++)
//         {
//             cout << dp[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

int num, max_weight; // number of items & maximum weight

/*
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> num >> max_weight;

    for (int i = 1; i < num + 1; ++i)
    {
        cin >> w[i] >> v[i];    // accpet weight and value
    }

    for (int i = 1; i < num + 1; ++i) // iterate over items
    {
        for (int j = 0; j < max_weight + 1; ++j) // iterate over weights
        {
            if (j - w[i] >= 0)   // if we can add ith element 
            {
                int notAdding = dp[i-1][j]; // not adding
                int adding = dp[i-1][j-w[i]] + v[i]; // adding : 그전까지 본것중 최댓값 + 현재 값
                dp[i][j] = max(notAdding, adding);
            }
            else    // if we cannot add ith element
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[num][max_weight];

	return 0;
}
*/
void printDP(int * dp, int max_weight)
{
    for (int i = 1; i < max_weight + 1; ++i)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> num >> max_weight;

    int dp[max_weight + 1]; // make a array of possible weights
    memset(dp,0,sizeof(dp));

    // 물건의 무게와 가치 받기
    for (int i = 1; i < num + 1; ++i)
        cin >> w[i] >> v[i];

    // iterate over all bags
    for (int i = 1; i < num +1; ++i)
    {
        // iterate over max weight
        for (int j = max_weight; j >= 0; --j)
        {
            // if we can add this weight into the bag
            if (j - w[i] >= 0)
            {
                dp[j] = max(dp[j], dp[j-w[i]] + v[i]); 
            }
            // printDP(dp, max_weight);
        }
        // cout << endl;
    }
    cout << dp[max_weight];
    return 0;
}