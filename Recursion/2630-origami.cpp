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

// x = start, y = start, l = length of one side
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
    int color = dp[y][x]; 
    bool isSame = true;
    
    for (int i = y; i < y + l; i++) // i = y (rows)
    {
        for (int j = x; j < x + l; j++) // j = x (columns)
        {
            // if they are not the same
            if (dp[i][j] != color) 
            {
                isSame = false;
                test(x, y, l/2); // Check I (Upper left)
                test(x + (l/2), y, l/2); // Check II (Upper right)
                test(x, y + (l/2), l/2); // Check III (Lower left)
                test(x + (l/2), y + (l/2), l/2); // Check IV (Lower right)
                return;
            }
        }
    }

    if (isSame && color == 1) blue++;
    else if (isSame && color == 0) white++;

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
    // cout << "=============== PRINT ================" << endl;
    // for (int i=0; i<n; i++)
    // {
    //     for (int j =0; j<n; j++)
    //         cout << dp[i][j] << " ";
        
    //     cout << endl;
    // }

    // Do Receursion
    test(0,0,n);

    // print the values
    cout << white << endl; 
    cout << blue << endl;


    return 0;
}