#include <iostream>

typedef long long ll;

using namespace std;

ll toDec(ll start, string s)
{
    ll len = s.length() - 1;
    ll res = 0;

    ll x = 1;
    for (ll i  = len; i >= 0; i--)
    {
        ll curr = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] - 'A' + 10 : s[i] - '0';
        // cout << curr << " " << x << endl;

        res += curr * x;
        x = x * start;
    }
    return res;
}

ll store [101];

void toTarget(ll dec, ll target)
{
    ll i = 0;
    ll quotient, rem;
    do
    {
        quotient = dec / target;
        rem = dec % target;
        store[i++] = rem;

        dec = quotient;

    } while (quotient != 0);
    
    
    i--;
    
    while (i >= 0)
    {
        if (store[i] >= 10)
        {
            cout << (char) (store[i] + 55);
        }
        else
        {
            cout << store[i];
        }
        i--;
    }
    cout << endl;
}

int main()
{
    ll start;
    string s;
    ll end;

    while (true)
    {
        cin >> start;
        if (start == 0)
            return 0;
        
        cin >> s >> end;
        
        ll res = toDec(start, s);
        // cout << res << endl;
        toTarget(res, end);
    }    
}