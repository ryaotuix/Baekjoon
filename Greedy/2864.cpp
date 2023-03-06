#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string A, B; cin >> A >> B;

    // Change all 5 to 6
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == '5') A[i] = '6';

    }
    for (int i = 0; i < B.size(); i++)
    {
        if (B[i] == '5') B[i] = '6';
    }

    int max = stoi(A) + stoi(B);

    // Change all 6 to 5
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == '6') A[i] = '5'; 
    }
    for (int i = 0; i < B.size(); i++)
    {
        if (B[i] == '6') B[i] = '5';
    }

    int min = stoi(A) + stoi(B);

    cout << min << " " << max << endl;



}