#include <bits/stdc++.h>

using namespace std;


void printArr(int * arr, int numSamp)
{
    for (int i = 1; i <= numSamp; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    multiset<int, greater<int>> m = {};
    multiset<int>::iterator it;
    vector<int> res;


    int numSamp, lenSilence, maxNoiseLevel;
    cin >> numSamp >> lenSilence >> maxNoiseLevel;

    // store information in the array
    int arr[numSamp+1];
    arr[0] = -1;
    for (int i = 1; i <= numSamp; ++i)
        cin >> arr[i];

    // check Arr
    //printArr(arr, numSamp);


    // make a first map
    for (int i = 1; i <= lenSilence; i++)
    {
        // cout << "inserting " << arr[i] << endl;
        m.insert(arr[i]);
    }
    int max = *m.begin();
    int min = *m.rbegin();
    if (max-min <= maxNoiseLevel) res.push_back(1);
    
    // cout << "max is " << max << "min is " << min<< endl;

    int deleteIndex = 1;
    for (int i = 2; i<= numSamp-lenSilence+1; ++i)
    {
        int whatToDelete = arr[deleteIndex++];
     
        auto itr = m.find(whatToDelete);
        if (itr != m.end()) m.erase(itr);
        m.insert(arr[i+lenSilence-1]);

        max = *m.begin();
        min = *m.rbegin();
        //cout << "inserting " << arr[i+1] << endl;
        //cout << "max is " << max << "min is " << min<< endl;
        if (max-min <= maxNoiseLevel) 
        {
            res.push_back(i);
            // cout << " we are pushing back\n\n";
        }

    }

    if (res.size()== 0)
    {
        cout << "NONE";
        return 0;
    }

    for (int i = 0; i<res.size(); i++)
        cout << res[i] << endl;
}