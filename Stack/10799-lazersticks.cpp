#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;

    stack<char> pars;
    int i = 0;
    int sticks = 0; // number of sticks currently
    int segments = 0; // number of segments in total

    bool justopened = false;

    while (s[i] != '\0')
    {
        
        if(s[i] == '(')
        {
            pars.push(s[i]);
            sticks++;
            justopened = true;
        }
        else if (s[i] == ')')
        {
            if (justopened)
            {
                pars.pop();
                sticks--;
                segments += sticks;
                justopened = false;
            }
            else 
            {
                pars.pop();
                segments++;
                sticks--;
            }
        }
        i++;
    }

    cout << segments << endl;
    return 0;
}
