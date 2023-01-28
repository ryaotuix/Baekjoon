/*
Longest Common Subsequence

ex) 
S = ABAZDC
T = BACBAD

res = ABAD

LOOK at the matrix like this
   B  A  C  B  A  D
A  0  1  1  1  1  1
B  1  1  1  2  2  2
A  1  2  2  2  3  3
Z  1  2  2  2  3  3
D  1  2  2  2  3  4
C  1  2  3  3  3  4
*/



#include <iostream>
#include <assert.h>
#include <algorithm>
#include <iomanip>


using namespace std;

string S = "ABAZDC";
string T = "BACBAD";
const int sLen = 6;
const int tLen = 6;



// without memoization
int LCS(string &S, int sLen, string &T, int tLen)
{
    int res;
    // BASE CASE :
    if (sLen == 0 || tLen == 0) return 0; // if we are at the first index of either string
    // CASE 1 : if the letter matches +1 from the one diagonally from top left of it
    if (S[sLen] == T[tLen]) 
        res = 1 + LCS(S, sLen-1, T, tLen-1); 
    // CASE 2 : if the letters don't match bring the max(top, left)
    else 
        res = max(LCS(S, sLen-1, T, tLen), LCS(S, sLen, T, tLen-1));

    return res;
}

// with memoization
int LCSmemoized(string &S, int sLen, string &T, int tLen, int ** matrix)
{
    int res;

    // if we are at the first index of either string
    if (sLen == 0 || tLen == 0) {
        matrix[sLen][tLen] = 0; 
        return 0;
    }

    if (matrix[sLen][tLen] != -1) return matrix[sLen][tLen]; // if matrix already has a value

    if (S[sLen] == T[tLen]) 
        res = 1 + LCS(S, sLen-1, T, tLen-1); 

    else 
        res = max(LCS(S, sLen-1, T, tLen), LCS(S, sLen, T, tLen-1));

    // !Memoization!
    matrix[sLen][tLen] = res; 
    return res;
}


void print2D(auto ** matrix, int row, int col)
{
    cout << "================================================\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << left << setw(2) << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "================================================\n";
}

// top-down Dynamic Programming



// MAIN 
int main()
{
    bool flag = true;
    ios_base::sync_with_stdio(false);
    
    // Dynamically allocate 2D int Array 
    int ** matrix = new int * [sLen+1];
    for (int i = 0; i < sLen+1; i++)
        matrix[i] = new int[tLen+1];

    // fill the 2D Array <matrix> with 0
    for (int i = 0; i < sLen+1; i++)
        for (int j = 0; j < tLen+1; j++)
            matrix[i][j] = 0;

    // fill the 2D Array <matrix> with -1
    for (int i = 1; i < sLen+1; i++)
        for (int j = 1; j < tLen+1; j++)
            matrix[i][j] = -1;

    print2D(matrix, sLen+1, tLen+1);


    // Dynamically allocate 2D string Array
    // string ** mat = new string * [sLen];
    // for (int i = 0; i < sLen; i++)
    //     mat[i] = new string [tLen];
    
    //print2D(mat, sLen, tLen);
    




    
    //cout << "MAX num : " << LCS(S, sLen, T, tLen) << "\n";
    //flag = false;
    
    cout << "MAX num : " << LCSmemoized(S, sLen, T, tLen, matrix) << "\n";
    print2D(matrix, sLen+1, tLen+1);

}