#include <bits/stdc++.h>

using namespace std;

// vector<int> v = {4, 5, 6, 7, 0, 1, 2};
vector<int> v = {1};

// int search(vector<int>&nums, int target)
// {
//     int lo = 0; int hi = nums.size()-1;
//     while (lo < hi)
//     {
//         int mid = lo + (hi-lo)/2;
//         if (nums[mid] == target) return mid;
        
//         else if (nums[lo] <= nums[mid]) // left half is sorted
//         {
//             if (target >= nums[lo] && target <= nums[mid])
//                 hi = mid;
//             else 
//                 lo = mid + 1;
//         }
        
//         else 
//         {
//             if (target >= nums[mid] && target <= nums[hi])
//                 lo = mid +1;
//             else 
//                 hi = mid;
//         }
//     }
//     return -1;
// }



int search(vector<int>& nums, int target) {
        // find the smallest element
        int lo = 0;
        int hi = nums.size()-1;
        int pivot = 0;
        while (lo < hi)
        {

            int mid = lo + (hi - lo) / 2;
            //cout << lo << " " << hi << " " << mid << endl;

            // if mid is target
            if (nums[mid] == target)
            {
                pivot = mid;
                break;
            }
            else if (nums[mid] < nums[hi]) // which means from mid~ hi is sorted
            {
                hi = mid;
            }
            else // (nums[mid] > nums[hi]) which means from 0 ~ mid
            {
                lo = mid + 1;
            }
        }
        cout << pivot << endl;

        lo = 0;
        hi = nums.size()-1;
        while(pivot <= hi)
        {
           int mid = pivot + (hi-pivot)/2;
           cout << "mid = " << mid << endl;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) pivot = mid+1;
            else hi = mid; 
        }
        return -1;

    }

// int search(vector<int> &nums, int target)
// {
//     // find the smallest element
//     int lo = 0;
//     int hi = nums.size()-1;
//     int pivot = -1;
//     while (lo < hi)
//     {

//         int mid = lo + (hi - lo) / 2;
//         cout << lo << " " << hi << " " << mid << endl;

//         // if mid is target
//         if (nums[mid] == target)
//         {
//             pivot = mid;
//             break;
//         }
//         else if (nums[mid] < nums[hi]) // which means from mid~ hi is sorted
//         {
//             hi = mid;
//         }
//         else // (nums[mid] > nums[hi]) which means from 0 ~ mid
//         {
//             lo = mid + 1;
//         }
//     }

//     cout << pivot << endl;
//     return pivot;
// }

// int binarySearch(int lo, int hi, vector<int>&v, int target)
// {
//     while (lo < hi)
//     {
//         int mid = lo + (hi-lo)/2;
//         if (v[mid] == target) return mid;
//         else if (v[mid] < target) lo = mid+1;
//         else hi = mid;
//     }
//     return -1;
// }
*/



int main()
{
    int target = 1;
    int x = search(v, target);
    // int i = binarySearch(x, v.size()-1, v, target);
    cout << x;
}
