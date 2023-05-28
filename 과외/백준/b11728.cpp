#include <bits/stdc++.h>

using namespace std;

int n, m;
int sorted[2 * 1000000 + 10];   // arr to store merged sort
int A[1000000 + 5];
int B[1000000 + 5];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> B[i];
    }

    // Input Done, starting at index 0

    int ptrA = 0;
    int ptrB = 0;
    int ptr = 0;

    while (ptr < n + m)
    {
        // 1. we used all A
        if (ptrA == n)
        {
            sorted[ptr++] = B[ptrB++];
        }
        // 2. we used all B
        else if (ptrB == m)
        {
            sorted[ptr++] = A[ptrA++];
        }
        // 3.  a <= b then use a
        else if (A[ptrA] <= B[ptrB])
        {
            sorted[ptr++] = A[ptrA++];
        }
        else
        {
            sorted[ptr++] = B[ptrB++];
        }
    }

    for (int i = 0; i < ptr; i++)
        cout << sorted[i] << " ";
}