#include <iostream>
using namespace std;

bool isPalindrome(string s)
{
    for (int i = 0; i < s.length()/2; i++)
    {
        if (s[i] != s[s.length() - 1 -i])
        {
            //cout << s[i] << endl;
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s; cin >> s;
    while (s != "0")
    {
        if (isPalindrome(s))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
        cin >> s;
    }
    return 0;
}