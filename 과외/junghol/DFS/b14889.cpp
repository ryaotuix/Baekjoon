#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> teamStart;  // stores all team starts


int main()
{
    int n; cin >>n;
    vector<vector<int>> matrix(n+1, vector<int>(n+1));
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> matrix[i][j];
    }

}