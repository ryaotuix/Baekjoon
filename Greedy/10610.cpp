#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;

    int sum = 0;
    bool foundZero = false;

    for (int i = 0; i < s.length(); i++)
    {
        // cout << s << endl;
        sum += s[i] - '0';  // 각 자리수의 합이 3의 배수면 3의 배수
        if (s[i] == '0') foundZero = true;   // 0 이 존재해야함
    }

    // cout << sum << endl;
    
    if (sum %3 == 0 && foundZero)
    {
        // cout << "YES\n";
        // cout << s << endl;
        sort(s.begin(), s.end(), greater<char>());
        cout << s << endl;
    }
    else 
    {
        cout << "-1";
    }

}