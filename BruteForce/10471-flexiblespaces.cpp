#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// From the internet ,they made another vector lenght of length +1 and initailized as false
// Then, in index where it can be found, changed it to true

int main()
{
    int length, partition;
    cin >> length >> partition;

    vector<int> walls;
    walls.push_back(0);

    for (int i = 0; i < partition; i++)
    {
        int topush; cin >> topush;
        walls.push_back(topush);
    }

    walls.push_back(length);

    // 벡터 초기화!!!!!!!!!!
    vector<bool> can (length+1, false); // this vector has (length +1) false elements 

    for (int i = 0; i< walls.size()-1; i++)
    {
        for (int j = i+1; j<walls.size(); j++)
        {
            int dif = walls[j] - walls[i];
            can[dif] = true; // index of difference make it true
        }
    }

    for (int i =0; i < can.size(); i++)
    {
        if (can[i])
            cout << i << " ";
    }

    return 0;
}




/*
// My Method !!!!
int main()
{
    int length, partition;
    cin >> length >> partition;

    int arr[partition + 2] = {0}; // get the all possible difference starting 0
    int i;

    for (i = 0; i<partition; i++)
    {
        cin >> arr[i+1];
    }
    arr[partition+1] = length;

    // print input
    // now in arr, there are all partitions ex) 0, 1, 4, 8, 10

    // for (i = 0; i<partition +2; ++i)
    // {
    //     cout << arr[i] << " ";
    // }
    
    // cout << "==============\n";



    vector<int> v;
    for (i =0; i < partition+1; ++i)
    {
        for (int j = i+1; j < partition + 2; ++j)
        {
            int dif = arr[j] - arr[i];
            // if it is in vector
            if (find(v.begin(), v.end(), dif) != v.end()) // !!!!!!!!!!!
            {
                continue;
            }
            else
            {
                v.push_back(dif);
            }
        }
    }

    // Sorting functions
    sort(v.begin(), v.end());

    // print out
    for (i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    return 0;
}
*/