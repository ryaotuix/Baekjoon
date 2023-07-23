#include <bits/stdc++.h>

using namespace std;

// must binary search...  return index that makes sum equal to or smaller than target
int binarySearch(int limit, int target, vector<int> & people, int l, int r, int i)
{
    
    while (l < r)
    {
        int mid = (l + r) / 2;
        
        // get sum
        int sum = people[i] + people[mid];

        cout << "sum: " << sum << endl;
        cout << l << " " << mid << " " << r << endl;

        if (sum <= limit)
        {
            cout << "sum <= target" << endl;
            cout << "l changes to " << mid+1 << endl;
            l = mid + 1;
        }
        else
        {
            r = mid;
            cout << "sum > target" << endl;
            cout << "r changes to " << mid << endl;
        }
    }

    return l - 1;
}

int numRescueBoats(vector<int> &people, int limit)
{
    int cnt = 0;    // count of boats

    // sort ppl in ascending order
    sort(people.begin(), people.end());

    
    // iterate over entire ppl
    int i = 0;
    while (i < people.size())
    {
        if (i == people.size() - 1)
        {
            cnt++;
            i++;
            continue;
        }
        int target = limit - people[i];
        
        // binary search this target <return an index>
        int l = i+1;
        int r = people.size() - 1;

        int ind = binarySearch(limit, target, people, l, r, i); 

        for (int n : people)
            cout << n << " ";
        cout << endl;

        cout << i << " " << ind << endl;


        cnt++;

        // if not found, we have to put this person in one boat
        if (ind < i)
        {
            cout << "boat only contains " << people[i] << endl;
        }
        else
        {
            // if found, we have to put this person and the person found in one boat
            // and erase from the original vector
            cout << "boat contains " << people[i] << " and " << people[ind] << endl;
            people.erase(people.begin() + ind);
        }
        i++;

        cout << endl;
    }

    return cnt;
}

int main()
{
    vector<int> people = {1,2};
    int limit = 3;

    cout << numRescueBoats(people, limit) << endl;
}