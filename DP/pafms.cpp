#include <bits/stdc++.h>

using namespace std;

int arr[] = {1,5,1,5,7,3,6,1,8,9,3};
int len = sizeof(arr)/sizeof(int);

void printArr(int * arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int k = 4;
    cout << 0 << " ";
    printArr(arr, len);
    cout << endl;

    int dp[len+1] = {};
    for (int i = 1; i <= len; i++)
    {
        int j = 1, x = arr[i-j];
        dp[i] = x + dp[i-j];
        
        // 이부분이 dp의 정수다
        for (int j = 2; j <= min(k, i); j++)
        {
            printArr(dp, len+1);
            cout << "j: " << j << " and goes to min(k,i): " << min(k, i) << endl;
            cout << x << " " << arr[i-j] << endl;
            x = max(x, arr[i-j]);

            dp[i] = max(dp[i], x*j + dp[i-j]);
        }
        // 여길 시발 어케 생각하냐고

        printArr(dp, len+1);
        cout << endl;
    }

    printArr(dp,len+1);
    

    
}