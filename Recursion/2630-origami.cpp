#include <iostream>

using namespace std;


/*
I    II
III  IV
*/
int dp[129][129];
int blue = 0;
int white = 0;
int n;

void test(int x, int y, int l) // <0, 0, n> to start
{
    // base case
    if (l == 1)
    {
        if (dp[y][x] == 0) // white
        {
            white++;
            return;
        } 
        else if (dp[y][x] == 1) // blue
        {
            blue++;
            return; 
        }
    }

    // Check if the square is same color
    int col = dp[y][x]; 
    bool isSame = true;
    
    for (int i = y; i < y + l; i++)
    {
        for (int j = x; j < x + l; j++)
        {}
    }


}


int main()
{
    cin >> n;
    
    // fill out array with input
    for (int i =0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            int c; cin >> c;
            dp[i][j] = c;
        }
    }

    // Print 2D array
    cout << "=============== PRINT ================" << endl;
    for (int i=0; i<n; i++)
    {
        for (int j =0; j<n; j++)
            cout << dp[i][j] << " ";
        
        cout << endl;
    }




    return 0;
}