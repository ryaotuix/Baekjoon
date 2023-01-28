#include <bits/stdc++.h>

using namespace std;

bool compare(const vector<int> & a, const vector<int> & b)
{
    int difA = abs(a[0]-a[1]);
    int difB = abs(b[0]-b[1]);
    return difA > difB; // return true if difA is bigger
    // THIS WILL SORT IN DESCENDING ORDER
}

int twoCitySchedCost(vector<vector<int>>& costs) {
    int res = 0;
    sort(costs.begin(), costs.end(), compare);

    // for (int i = 0; i < costs.size(); i++)
    // {
    //     cout << "{";
    //     for (int j = 0; j < costs[0].size(); j++) {
    //         cout << costs[i][j] << ",";
    //     }
    //     cout << "}" << " ";
    // }

    // given that size of costs is even
    int len = costs.size();
    int a = len/2;
    int b = len/2;

    for (int i = 0; i < len; i++)
    {
        // make a var for current vecotr
        vector<int> curr = costs[i];
        int currA = curr[0];
        int currB = curr[1];

        // 1st case if we used either all a and b
        // 1-1 we used all a so we have to add b's
        if (a == 0)
        {
            res += currB;
            b--;           
            continue; 
        }
        // 1-2 we used all b so we have to add a's
        if (b == 0)
        {
            res += currA;
            a--;
            continue;
        }

        // otherwise we would have to see if we are saving 
        if (currA < currB)
        {
            res += currA;
            a--;
        } 
        else 
        {
            res += currB;
            b--;
        }
    }
    cout << res;
    return res;
}

int main()
{
    vector<vector<int>> costs = {{10,20}, {30,200}, {400,50}, {30,20}};
    return twoCitySchedCost(costs); 
}