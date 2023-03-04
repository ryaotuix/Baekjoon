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

int hashFunction(int x)
{
    double temp = x * 0.618;
    temp = temp - (int)temp;
    temp *= 10;
    cout << "x is " << x << endl;
    cout << "temp is " << temp << endl;
    
    return (int) ceil(temp);
}

void applyHash(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << hashFunction(v[i]) << "\n\n";
    }
    cout << endl;
}

int main()
{
    // vector<int> v = {1025, 2305, 5760, 2020, 1950, 6030, 8955, 3405, 6000};
    // applyHash(v);
    // cout << hashFunction(4956) << endl;
    // cout << hashFunction(7631) << endl;

    
// CPP Program to demonstrate the implementation of multimap

    multimap<int, int> gquiz1; // empty multimap container
 
    // insert elements in random order
    gquiz1.insert(pair<int, int>(1, 40));
    gquiz1.insert(pair<int, int>(2, 30));
    gquiz1.insert(pair<int, int>(3, 60));
    gquiz1.insert(pair<int, int>(6, 50));
    gquiz1.insert(pair<int, int>(6, 10));
 
    // printing multimap gquiz1
    multimap<int, int>::iterator itr;
    cout << "\nThe multimap gquiz1 is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
        cout << '\t' << itr->first << '\t' << itr->second
             << '\n';
    }

    
    cout << endl;
}