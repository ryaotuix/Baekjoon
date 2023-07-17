#include <bits/stdc++.h>

using namespace std;

int n; // grid size

int startRow;
int startCol;
int endRow;
int endCol;
int memo[300 + 5][300 + 5];     // store minimum number of movement to get there
int miniMovement = 1e9;         // very big number


void input()
{
    miniMovement = 1e9;                 // reset miniMovement 
    memset(memo, 99, sizeof(memo));      // clear the memo
    cin >> n;
    cin >> startRow >> startCol;
    cin >> endRow >> endCol;
}


void move(int row, int col, int movement)
{
    // Exception Cases:
    // 1. if (movement >= miniMovement) return
    if (movement >= miniMovement)   return;
    // 2. if (memo[row][col] != 0 && memo[row][col] <= movement) return
    if (memo[row][col] <= movement) return;
    // 3. outside of the grid, return
    if (row >= n || row < 0 || col >= n || col < 0) return;

    // make memo
    memo[row][col] = movement;

    // if destination, update miniMovement
    if (row == endRow && col == endCol)
    {
        miniMovement = min (miniMovement, movement);
        return;
    }

    // recurse down 8 ways
    move(row + 2, col + 1, movement + 1);
    move(row + 2, col - 1, movement + 1);
    move(row - 2, col + 1, movement + 1);
    move(row - 2, col - 1, movement + 1);

    move(row + 1, col + 2, movement + 1);
    move(row + 1, col - 2, movement + 1);
    move(row - 1, col + 2, movement + 1);
    move(row - 1, col - 2, movement + 1);
}

void getMinMove()
{
    input();
    if (startRow == endRow && startCol == endCol)
    {
        cout << 0 << endl;
        return;
    }
    move(startRow, startCol, 0);
    cout << miniMovement << endl;
}


int T;
int main()
{
    cin >> T;
    while (T--)
    {
        getMinMove();
    }
}