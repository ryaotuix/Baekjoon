#include <bits/stdc++.h>

using namespace std;

/* Find Exact if doesn't exist, -1 */

vector<int> v = {5,6,7,8,9};
int target = 4;

int binarySearch()
{                                                                   // Key 0. where to start
    int lo = -1;
    int hi = v.size() - 1;

    while (lo + 1 < hi)                                             // Key 1. While loop condition
    {
        int mid = lo + (hi - lo) / 2;
        
        // Update condition
        if (v[mid] >= target)                                       // Key 2. If condition
        {
            hi = mid;
        }
        else
        {
            lo = mid;
        }
    }

    // if answer does not exist, return -1
    return (v[hi] == target) ? v[hi] : -1;                          // Key 3. What to return (depending on IF condition)
}

// int main()
// {
//     cout << binarySearch() << endl;
// }



/* Find the minimum number that is v[i ]>= target    If doesn't exist, return -1*/

vector<int> v1 = {-1, 2, 4, 5, 7};          // return index 2
vector<int> v2 = {-1, 1, 2, 4};             // return index 3
vector<int> v3 = {4,5,6,7};                 // return index 1
vector<int> v4 = {-3,-2,-1,1,2};            // return index -1
int target2 = 3;

int binarySearch2()
{
    int lo = -1;
    int hi = v4.size() - 1;
    int mid;

    while (lo + 1 < hi)
    {
        mid = lo + (hi - lo) / 2;

        if (v4[mid] >= target2)
            hi = mid;
        else
            lo = mid;        
    }

    // lo + 1 == hi
    if (v4[hi] >= target2)
        return v4[hi];
    else
        return -1;
}

// int main()
// {
//     cout << binarySearch2() << endl;
// }






/* Find the maximum number that is v[i] <= target     If doesn't exist, return -1 */

int target3 = 3;
vector<int> v31 = {1,2,3};
vector<int> v32 = {3,4,5};
vector<int> v33 = {4,5,6};
vector<int> v34 = {1,2,5,7};
vector<int> v35 = {2,5,7};
vector<int> v36 = {-1,0,1,2};
vector<int> v37 = {1};
vector<int> v38 = {4};


int binarySearch3()
{
    // 0. Start Boundary is IMPORTANT
    int lo = 0;
    int hi = v38.size();
    int mid;

    while (lo + 1 < hi)
    {        
        mid = lo + (hi - lo) / 2;

        // lo 를 움직이기로 결정
        if (v38[mid] <= target3)
        {
            lo = mid;
        }
        else
            hi = mid;
    }

    cout << lo << endl;

    if (v38[lo] <= target3)
        return v38[lo];
    else
        return -1;
}

int main()
{
    cout << binarySearch3() << endl;
}