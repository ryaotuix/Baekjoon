#include <iostream>

using namespace std;

#define DOWN 1
#define LEFT 2
#define UP 3

int grid [105][105];

void printTriangle(const int n)
{

    int iter = n*(n+1)/2;
    
    int downMargin = n-1;
    int leftMargin = 0;
    int topMargin = 1;

    int row = 0;
    int col = 0;
    int cnt = 0;

    int currState = DOWN;

    while(iter--)
    {
        if (cnt == 10)
            cnt = 0;

        // cout << row << " " << col << " = " << cnt << endl;
        grid[row][col] = cnt++;


        if (currState == DOWN)
        {
            if (row == downMargin)
            {
                currState = LEFT;
                col--;
                downMargin--;
            }
            else
            {
                row++;
                col++;
            }
        } 
        else if (currState == LEFT)
        {
            if (col == leftMargin)
            {
                currState = UP;
                row--;
                leftMargin++;
            }
            else
            {
                col--;
            }
        }
        else if (currState == UP)
        {
            if (row == topMargin)
            {
                currState = DOWN;
                col++; row++;
                topMargin+=2;           // This was wrong ugh
            }
            else
            {
                row--;
            }
        }

        // cout << "row : " << row << " col : " << col << endl;
    }

    // cout << endl;

    // Print
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

}


int main()
{
    int n;
    cin >> n;
    printTriangle(n);
}