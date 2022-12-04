#include <iostream>
#include <string.h>
using namespace std;


int n,m;
int arr[101][101];

int main()
{
    // n is number of columns, m is number of rows
    // n = y, m = x
    cin >> n >> m;
    
    for (int i=0; i<m; i++) // loop through rows (y)
    {
        for (int j=0; j<n; j++) // loop through columns (x)
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
     for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }


}