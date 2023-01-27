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


using namespace std;

string S = "ABAZDC";
string T = "BACBAD";
const int sLen = 6;
const int tLen = 6;

int max(int &a, int &b)
{
    return (a > b) ? a : b;
}

// bottom-up Dynamic Programming

// without memoization
int LCS(string S, int sLen, string T, int tLen)
{
    int res;
    if (sLen == 0 || tLen == 0) return 0; // if one of the strings is empty

    if (S[sLen] == T[tLen]) 
        res = 1 + LCS(S, sLen-1, T, tLen-1); 

    else 
        res = max(LCS(S, sLen-1, T, tLen), LCS(S, sLen, T, tLen-1));

    return res;
}

// with memoization
int LCSmemoized(string S, int sLen, string T, int tLen, int ** matrix)
{
    int res;

    // if one of the strings is empty
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
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "================================================\n";
}

// top-down Dynamic Programming



// MAIN 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);    

    // Dynamically allocate 2D int Array 
    int ** matrix = new int * [sLen];
    for (int i = 0; i < sLen; i++)
        matrix[i] = new int[tLen];

    // fill the 2D Array <matrix> with -1
    for (int i = 0; i < sLen; i++)
        for (int j = 0; j < tLen; j++)
            matrix[i][j] = -1;

    print2D(matrix, sLen, tLen);


    // Dynamically allocate 2D string Array
    string ** mat = new string * [sLen];
    for (int i = 0; i < sLen; i++)
        mat[i] = new string [tLen];
    
    print2D(mat, sLen, tLen);
    
    
    cout << "MAX num : " << LCS(S, sLen, T, tLen) << "\n";
    cout << "MAX num : " << LCSmemoized(S, sLen, T, tLen, matrix) << "\n";

}