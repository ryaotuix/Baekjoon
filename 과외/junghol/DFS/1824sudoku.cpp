#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int sudoku[10][10];
vector<pii> missings;
bool inRow[10][10];
bool inCol[10][10];
bool inSec[10][10];
int cnt = 0; // cnt how many 0's there are

/*
Sections
1 2 3
4 5 6
7 8 9
*/
int getSectionNum(int row, int col)
{
    if (row >= 1 && row <= 3)
    {
        if (col >= 1 && col <= 3)
            return 1;
        else if (col >= 4 && col <= 6)
            return 2;
        else if (col >= 7 && col <= 9)
            return 3;
    }
    else if (row >= 4 && row <= 6)
    {
        if (col >= 1 && col <= 3)
            return 4;
        else if (col >= 4 && col <= 6)
            return 5;
        else if (col >= 7 && col <= 9)
            return 6;
    }
    else if (row >= 7 && row <= 9)
    {
        if (col >= 1 && col <= 3)
            return 7;
        else if (col >= 4 && col <= 6)
            return 8;
        else if (col >= 7 && col <= 9)
            return 9;
    }

    return -1;
}

void input()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cin >> sudoku[i][j];

            if (sudoku[i][j] == 0)
            {
                missings.push_back({i, j});
                cnt++;
            }

            int secNum = getSectionNum(i, j);

            // row -> this number
            inRow[i][sudoku[i][j]] = true;
            inCol[j][sudoku[i][j]] = true;
            inSec[secNum][sudoku[i][j]] = true;
        }
    }
}

void printSudoku()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
            cout << sudoku[i][j] << " ";
        cout << "\n";
    }
}

void fillSudoku(int count)
{
    // base case:
    if (count == cnt)
    {
        printSudoku();
        exit(0);
    }

    pii x = missings[count];
    int row = x.first;
    int col = x.second;

    int sec = getSectionNum(row, col);

    // if it doesn't exist in row, col, sec
    if (sudoku[row][col] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (!inRow[row][i] && !inCol[col][i] && !inSec[sec][i])
            {
                sudoku[row][col] = i;

                inRow[row][i] = true;
                inCol[col][i] = true;
                inSec[sec][i] = true;
                fillSudoku(count + 1);

                // back to original state
                sudoku[row][col] = 0;

                inRow[row][i] = false;
                inCol[col][i] = false;
                inSec[sec][i] = false;
            }
        }
    }
}

int main()
{
    input();
    fillSudoku(0);
}