#include <bits/stdc++.h>

using namespace std;

int arr[80 + 5];
int n;

// given length in arr so far, compare <size>
bool promising(int length, int size)
{
    int rStart = length - size + 1;
    int lStart = rStart - size;

    for (int i = 0; i < size; i++)
    {
        // if they left part and right part has difference
        if (arr[lStart + i] != arr[rStart + i])
            return true;
    }

    // if left and right are identical
    return false;
}

void goodSeq(int length)
{
    // base case:
    if (length == n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << arr[i];
        }
        cout << endl;
        exit(0);
    }
    
    // potential candidates
    for (int i = 1; i <= 3; i++)
    {
        // put this candidate into the length
        arr[length] = i;
        bool isGood = true;

        // we need to check size from 1 to length/2 from the back
        for (int size = 1; size <= length/2; size++)
        {
            // if there is at least 1 is not promising out of all the sizes we compare, then it is a bad sequence
            if (!promising(length, size))
            {
                isGood = false;   // bad sequence
                break;
            }
        }

        if (isGood)
            goodSeq(length + 1);
    }

}

int main()
{
    cin >> n;
    goodSeq(1);
    
}