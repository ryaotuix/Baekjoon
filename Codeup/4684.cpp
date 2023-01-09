#include <iostream>

using namespace std;

int main()
{
    int size; cin >> size;
    int arr[size+1];

    for (int i = 1; i<=size; i++)
        cin >> arr[i];

    // Print 
    // for (int i = 1; i <= size; i++)
    //     cout << arr[i] << " ";
    // cout << endl;

    int shift1;
    int reverseSize; // we will always reverse from 1
    int shift2;

    if ( (arr[1]+1)%10 == arr[size])
    {
        int rightCount = 1;
        int leftCount = 1;
        for (int i = size; i>1; i--)
        {
            if (arr[i-1] == (arr[i]+1)%10) rightCount++;
            else break;
        }

        for (int i = 1; i<= size; i++)
        {
            if (arr[i] == (arr[i+1] + 1)%10) leftCount++;
            else break;
        }

        shift1 = rightCount;
        reverseSize = rightCount + leftCount;
        for (int i = 1; i<= size; i++)
        {
            if (arr[i] == 1)
            {
                cout << shift1 << endl;
                cout << 1 << " " << reverseSize << endl;
                cout << 10-i+1;
                return 0;
            }
        }
    }
}