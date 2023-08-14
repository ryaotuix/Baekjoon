#include <bits/stdc++.h>

using namespace std;

char arr[26];

int main()
{
    char c = 'A';
    for (int i = 0; i < 26; i++)
    {
        arr[i] = c;
        c++;
    }

    for (char x : arr)
        cout << x << " ";
    
}