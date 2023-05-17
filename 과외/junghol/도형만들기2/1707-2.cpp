#include <iostream>

using namespace std;

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

void print(const int n)
{
    // init 2d grid
    int ** grid = new int*[n];
    for (int i = 0; i < n; i++)
        grid[i] = new int[n];

    // fill
    int row = 0; int col = 0; int cnt = 1;

    int rightmax = n-1;
    int leftmax = 0;
    int downmax = n-1;
    int upmax = 0+1;
    
    int direction = RIGHT;

    for (int i = 1; i <= n*n; ++i)
    {
        grid[row][col] = cnt++;

        // Update Direction
        if (col == rightmax && direction == RIGHT)
        {
            rightmax--;
            direction = DOWN;
        }
        else if (row == downmax && direction == DOWN)
        {
            downmax--;
            direction = LEFT;
        }
        else if (col == leftmax && direction == LEFT)
        {
            leftmax++;
            direction = UP;
        }
        else if (row == upmax && direction == UP)
        {
            upmax++;
            direction = RIGHT;
        }

        // Update col and row
        if (direction == RIGHT)
            col++;
        else if (direction == DOWN)
            row++;
        else if (direction == LEFT)
            col--;
        else if (direction == UP)
            row--;
    }

     // print
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
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
    print(n);

}