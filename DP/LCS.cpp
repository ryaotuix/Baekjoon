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
int sLen = 0;
int tLen = 0;

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
    if (sLen == 0 || tLen == 0) return 0; // if one of the strings is empty
    if (matrix[sLen][tLen] != -1) return 

    if (S[sLen] == T[tLen]) 
        res = 1 + LCS(S, sLen-1, T, tLen-1); 

    else 
        res = max(LCS(S, sLen-1, T, tLen), LCS(S, sLen, T, tLen-1));

    return res;
}



// top-down Dynamic Programming

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //cin >> S;
    sLen = S.length();

    //cin >> T;
    tLen = T.length();

    // matrix for length
    int matrix = new int [sLen][tLen];

    // matrix for string
    string ** mat = new string * [sLen];
    for (int i = 0; i < sLen; i++)
        mat[i] = new string [tLen];
    
    // cout << "String S : " << S << "\n";
    // cout << "String T : " << T << "\n";
    // cout << "S length : " << sLen << "\n" << "T length : " << tLen << "\n";
    
    cout << "MAX num : " << LCS(S, sLen, T, tLen) << "\n";

}