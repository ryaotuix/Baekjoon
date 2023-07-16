#include <bits/stdc++.h>

using namespace std;

int sudoku[9+1][9+1];

bool rowCheck[9+1][9+1];
bool colCheck[9+1][9+1];
bool boxCheck[9+1][9+1];

int zeroCnt = 0;

// stores row and col location of 0
vector<int> rows;
vector<int> cols;
vector<bool> isFilled2;


int getBoxNum(int row, int col)
{
    if (row >= 1 && row <= 3)
    {
        if (col >= 1 && col <= 3)
            return 1;
        else if (col >= 4 && col <= 6)
            return 2;
        else
            return 3;
    }
    else if (row >= 4 && row <= 6)
    {
        if (col >= 1 && col <= 3)
            return 4;
        else if (col >= 4 && col <= 6)
            return 5;
        else
            return 6;
    }
    else if (row >= 7 && row <= 9)
    {
        if (col >= 1 && col <= 3)
            return 7;
        else if (col >= 4 && col <= 6)
            return 8;
        else
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

            // if this is not zero
            if (sudoku[i][j] != 0)
            {
                int numBox = getBoxNum(i, j);

                // CHECK : in that row, col, box, Number X exits :: check[number][X] = true
                rowCheck[i][sudoku[i][j]] = true;
                colCheck[j][sudoku[i][j]] = true;
                boxCheck[numBox][sudoku[i][j]] = true;

            }

            // if this is zero
            else
            {
                zeroCnt++;
                rows.push_back(i);  
                cols.push_back(j);
            }
        }
    }
} 


void print()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)    
            cout << sudoku[i][j] << " ";
        cout << endl;
    }
}

bool flag = false;

// is i valid to ptut here?
bool isValid(int row, int col, int i)
{
    int boxNum = getBoxNum(row, col);

    // if it exist return false
    if (rowCheck[row][i])
        return false;
    if (colCheck[col][i])
        return false;
     if (boxCheck[boxNum][i])
        return false;

    return true;
}

// index starts at 0
void fillSudoku(int ind)
{
    // Base Case:
    if (ind == zeroCnt)
    {
        flag = true;
        return;
    }

    int row = rows[ind];
    int col = cols[ind];
    for (int i = 1; i <= 9; i++)
    {
        // if this is valid, 
        if (isValid(row, col, i))
        {
            sudoku[row][col] = i;   // make this sudoku filled with candidate


            // mark all checks
            int boxNum = getBoxNum(row, col);
            rowCheck[row][i] = true;
            colCheck[col][i] = true;
            boxCheck[boxNum][i] = true;

            fillSudoku(ind+1);

            rowCheck[row][i] = false;
            colCheck[col][i] = false;
            boxCheck[boxNum][i] = false;

            if (flag == true)
                return;
        }
    }
}

int main()
{
    input();
    fillSudoku(0);
    cout << endl;
    print();
}