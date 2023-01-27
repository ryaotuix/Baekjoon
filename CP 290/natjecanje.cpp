#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// void printArr(auto * arr, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << "\n";
// }


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int total, damaged, reserved;
    cin >> total >> damaged >> reserved;
    
    // make an array of booleans (true if index is damaged)
    bool arr[total + 1] = {0}; // default false
    for (int i = 0; i < damaged; i++)
    {
        int ind; cin >> ind;
        arr[ind] = true;
    }

    // make a vector for index with reserved kayaks
    vector<int> indReserved;
    for (int i = 0; i< reserved; i++)
    {
        int ind; cin >> ind;
        indReserved.push_back(ind);
    }
    sort(indReserved.begin(), indReserved.end());

    // originally result should be # of damaged 
    int res = damaged;

    for (const auto &ind : indReserved)
    {
        //printArr(arr, total+1);
        //cout << "CURR damaged : " << res << "\n";

        // first check itself
        if (arr[ind] == true)
        {
            arr[ind] = false;
            res--;
            continue;
        }
        // then check ind - 1
        if (ind-1 >= 1 && arr[ind-1] == true)
        {
            arr[ind-1] = false;
            res--;
            continue;
        }
        // then check ind + 1
        if ((ind+1) <= total && arr[ind+1] == true)
        {
            arr[ind+1] = false;
            res--;
        }
    }

    cout << res;
    return 0;

}