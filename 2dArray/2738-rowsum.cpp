#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int n, m; // n is number of columns, m is number of rows
    // n = y, m = x
    cin >> n >> m;

    int arr[m+1][n+1]; // row, column 
    memset(arr, 0, sizeof(arr));

    
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            int topush; cin >> topush;
            arr[i][j] += topush;
        }
    }

    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            int topush; cin >> topush;
            arr[i][j] += topush;
        }
    }


    // print
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }


}