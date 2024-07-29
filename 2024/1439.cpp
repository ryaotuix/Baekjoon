#include <bits/stdc++.h>

using namespace std;

// count the number of group 
int one;
int zero;

bool isZero = true; // flag to check if current group is zero

void input()
{
    string s;
    cin >> s;

    if (s[0] == '0')
    {
        zero++;
        isZero = true;
    }
    else
    {
        one++;
        isZero = false;
    }


    for (int i = 1; i < s.size(); i++)
    {
        char cur = s[i];
        
        // if it was 0 til now, and now it is 1, 
        if (isZero && cur == '1')
        {
            isZero = false;
            one++;
        }

        // if it was 1 til now, and now it is 0,
        if (!isZero && cur == '0')
        {
            isZero = true;
            zero++;
        }
    }

    cout << min(zero, one);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
}