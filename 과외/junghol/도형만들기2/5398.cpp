#include <iostream>

using namespace std;

#define DOWN 1
#define RIGHT 2
#define UP 3

// grid
int grid [205][205];


void init()
{
    for (int i = 0; i < 205; i++)
    {
        for (int j = 0; j < 205; j++)
        {
            grid[i][j] = -1;
        }
    }
}

void printGrid(const int n)
{
    int spaces = n-1;

    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < spaces; k++)
            cout << " ";

        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == -1)
                cout << " ";
            else
                cout << grid[i][j];
            cout << " ";
        }
        cout << endl;

        spaces--;
    }
}

void printTree(const int n)
{
    init();
    
    int iter = n*(n+1)/2;
    
    int downMargin = n-1;
    int rightMargin = n-1;
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
                currState = RIGHT;
                col++;
                downMargin--;
            }
            else
            {
                row++;
            }
        } 
        else if (currState == RIGHT)
        {
            if (col == rightMargin)
            {
                currState = UP;
                row--; col--;
                rightMargin-=2;
            }
            else
            {
                col++;
            }
        }
        else if (currState == UP)
        {
            if (row == topMargin)
            {
                currState = DOWN;
                row++;
                topMargin+=2;           // This was wrong ugh
            }
            else
            {
                row--;
                col--;
            }
        }

        // cout << "row : " << row << " col : " << col << endl;
    }

    printGrid(n);

}


int main()
{
    int n;
    cin >> n;
    printTree(n);
}