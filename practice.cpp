
#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<char, int> map = {
        {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
    };

    string s = "III";

    int res = map[s.back()];
    for (int i = 0; i<s.length()-1; i++)
    {
        // ex) IV
        if (map[s[i]] < map[s[i+1]]) res -= map[s[i]];
        else res += map[s[i]];
    }

    cout << res;
}