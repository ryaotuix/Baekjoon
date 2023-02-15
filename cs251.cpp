// C++ program to find the length of the longest substring
// without repeating characters
#include <bits/stdc++.h>
using namespace std;

void printVec(vector<int> &a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int twoSum(vector<int> &v)
{
    int target = 0;
    int cnt = 0;
    int i = 0;
    int j = v.size() - 1;
    while (i < j)
    {
        cout << i << " " << v[i] << " " << j << " " << v[j] << endl;
        int sum = v[i] + v[j];
        if (sum < target)
            i++;
        else if (sum > target)
            j--;
        else
        {
            cout << "find" << endl;
            cnt++;
            i++;
            j--;
        }
    }
}

int threeSum(vector<int> &v)
{
    int i = 0;
    int j, k;
    int cnt = 0;
    for (int i = 0; i < v.size() - 2; i++)
    {
        k = v.size() - 1;
        j = i + 1;
        while (j < k)
        {
            cout << i << " " << v[i] << " " << j << " " << v[j] << " " << k << " " << v[k] << endl;
            int sum = v[i] + v[j] + v[k];
            if (sum < 0)
                j++;
            else if (sum > 0)
                k--;
            else
            {
                cout << "found!" << endl;
                cnt++;
                j++;
                k--;
            }
        }
    }
    return cnt;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(vector<int> &v)
{
    int len = v.size();
    bool repeat = true;

    while (repeat)
    {
        repeat = false;
        for (int i = 0; i < len - 1; i++)
        {
            printVec(v);
            if (v[i] > v[i + 1])
            {
                swap(v[i], v[i + 1]);
                repeat = true;
            }
        }
        cout << endl;
    }
}

int binary(vector<int> &nums, int target, int lo, int hi)
{
    int mid;
    int curr;
    while (lo <= hi)
    {
        mid = lo + (hi-lo)/2;
        curr = nums[mid];
        if (curr == target) return mid;
        // if middle is less than target, we know target exist on the right
        if (curr < target)
        {
            lo = mid +1;
        }
        // if middle is greater than target, we know target exist on the left
        else
        {
            hi = mid;
        }
    }
    return -1;
}

int search(vector<int> &nums, int target)
{
   int left = 0; int right = nums.size()-1;
   while(left < right)
   {
        int mid = left + (right-left)/2;
        if (nums[mid] > nums[right]) // if it is sorted, know that mid will less than right but not, 
            left  = mid +1;
      

   } 
}

int main()
{
    // vector<int> v = {1,3,5,9,10};
    // int target = 3;
    // cout << binary(v, target, 0, v.size()-1);
    int sum = 0;
    int n = 64;
    for (int i = 1; i <= n; i *=4)
    {
        for (int j =0; j<i; j = j+1)
        {
            cout << sum << endl;
            sum++;
        }
    }

    cout << sum << endl;
}