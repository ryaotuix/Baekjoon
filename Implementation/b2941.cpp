#include <bits/stdc++.h>

using namespace std;

int countWord(string s)
{
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        cnt++;
        if (s[i] == 'c')
        {
            if (i+1 < s.length() && (s[i+1] == '=' || s[i+1] == '-'))
                i++;
        }
        else if (s[i] == 'd')
        {
            if (i+2 < s.length() && s[i+1] == 'z' && s[i+2] == '=')
                i += 2;
            else if (i+1 < s.length() && s[i+1] == '-')
                i++;
        }
        else if (s[i] == 'l')
        {
            if (i+1 < s.length() && s[i+1] == 'j')
                i++;
        }
        else if (s[i] == 'n')
        {
            if (i+1 < s.length() && s[i+1] == 'j')
                i++;
        }
        else if (s[i] == 's')
        {
            if (i+1 < s.length() && s[i+1] == '=')
                i++;
        }
        else if (s[i] == 'z')
        {
            if (i+1 < s.length() && s[i+1] == '=')
                i++;
        }
    }
    return cnt;
}

int main() 
{
    string s;
    cin >> s;
    cout << countWord(s);
}