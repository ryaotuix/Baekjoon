#include <bits/stdc++.h>

using namespace std;

int n; 

void input()
{
    cin >> n;
}

bool isHanSu(int i)
{
    string str = to_string(i);

    // if it is 1 digit number, it is true
    if (str.size() == 1)
        return true;

    int dif = str[1] - str[0];

    // iterate thru 
    for (int i = 0; i < str.size() - 1 ; i++)
    {
        if (str[i+1] - str[i] != dif)
            return false;
    }
    
    return true;
}

void output()
{
    int res = 0;
    for (int i = 1 ; i <= n; i++)
    {
        if (isHanSu(i))
            res++;
    }

    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    output();
}