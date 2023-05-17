#include <iostream>

using namespace std;

typedef pair<int, int> direction;

/*
direction <col, row>
1. right = <1, 0>
2. down = <0, 1>
3. left = <-1, 0>
4. up = <0, 1>
*/

bool compareDirection(direction a, direction b)
{
    if (a.first == b. first && a.second == b.second)
        return true;
    
    return false;
}

void printGrid(int n)
{
    cout << "comes";
    // init nxn grid
    int ** grid = new int * [n];
    for (int i = 0; i < n; i++)
        grid[i] = new int[n];

    // I believe in C++, arr is init as 0

    cout << "here";
    // Fill out the grid
    int cnt = 1;
    int leftBoundary = 0;
    int rightBoundary = n-1;
    int downBoundary = n-1;
    int upBoundary = 0 + 1;

    // Question! 왜 이걸 밖에 두면 안되나요?
    direction right = {1, 0};
    direction down = {0, 1};
    direction left = {-1, 0};
    direction up = {0, 1};

    direction d = right;
    int col = 0; int row = 0;

    cout << "before the loop";
    while (leftBoundary != rightBoundary || downBoundary != upBoundary)
    {
        grid[col][row] = cnt++;

        // change direction
        if (compareDirection(d, right) && col == rightBoundary)
        {
            rightBoundary--;
            d = down;
        }
        else if (compareDirection(d, down) && row == downBoundary)
        {
            downBoundary--;
            d = left;
        }
        else if (compareDirection(d, left) && row == leftBoundary)
        {
            leftBoundary++;
            d = up;
        }
        else if (compareDirection(d, up) && row == upBoundary)
        {
            upBoundary++;
            d = right;
        }

        // add to col and row
        col = col + d.first;
        row = row + d.second;

    }

    cout << "after the loop";

    
    // print
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = cnt++;
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{
    int n;
    cin >> n;

    printGrid(n);
}

