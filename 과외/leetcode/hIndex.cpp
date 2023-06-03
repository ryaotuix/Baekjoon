#include <bits/stdc++.h>

using namespace std;

 int hIndex(vector<int>& citations) {
        // 1. sort in descending
        sort(citations.begin(), citations.end(), greater<int>());

        int i = 0;
        while(i + 1 <= citations[i] && i < citations.size())
        {
            i++;
        }
        
        cout << i << endl;
        return i;
    }   


int main()
{
    vector<int> v = {1};
    cout << hIndex(v);
}