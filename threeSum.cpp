#include <bits/stdc++.h>

using namespace std;

struct triple{
    int a;
    int b;
    int c;
    void printInfo() {
        cout << "{" << a << " " << b << " " << c << "}\n";
    }
};

int arr[] = {-10,25,-9,15,-6,11,-5,8,-4,6,0,5,1,3};
int len = sizeof(arr)/sizeof(arr[0]);

void printArr(int * arr, int len)
{
    for (int i = 0; i < len; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int threeSum(int * arr, int len, int goal)
{
    int res = 0;
    sort(arr, arr+len); // nlogn hopefully the library function is the best

    int i, j, k;
    for (i = 0; i < len; i++)
    {
        j = i+1; k = len-1; // j is after i and k is at the end
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < goal) j++;
            else if (sum > goal) k--;
            else // sum == goal
            {
                res++;
                j++;
                k--;
            } 
        }
    }
    return res;
}


int main()
{
    // sorting part
    printArr(arr, len);
    sort(arr, arr+len); printArr(arr, len);
    cout << "What is the sum you want to find? : ";
    int goal; cin >> goal;
    int x = threeSum(arr, len, goal);
    cout << "There are {" << x << "} many ways to have a sum of " << goal << endl;
}   