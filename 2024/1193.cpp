#include <bits/stdc++.h>

using namespace std;

int n;

void input()
{
    cin >> n;
}

void output()
{
    int line = 1;
    while(1)
    {
        if (line*(line - 1)/2 < n && n <= line*(line+1)/2)
            break;

        line++;
    }

    
    int numer, denom;
    int fin = line * (line + 1) / 2;

    // even number
    if (line % 2 == 0)
    {
        numer = line;
        denom = 1; 
        // 짝수는 분모가 올라감
        while (n != fin)
        {
            fin--;
            numer--;
            denom++;
        }
    }
    // odd number
    else
    {
        denom = line;
        numer = 1;
        //짝수는 분자가 올라감
        while (n != fin)
        {
            fin--;
            numer++;
            denom--;
        }
    }

    cout << numer << "/" << denom << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    output();
}