#include <bits/stdc++.h>

using namespace std;


// int getLevel(int target, vector<int> & v)
// {
//     int level = 0;
//     while (v[target] != -1)
//     {
//         level++;
//         target = v[target];
//     }
//     return level;
// }

// int res = 0;
// int rec(vector<int> & v, int target)
// {
//     if (v[target] == -1) return res;
//     res++;
//     return rec(v, v[target]);
// }


// int main()
// {
//     vector<int> v = {3, 16, 17,-1,11,3,10,11,3,5,16,8,2,10,10,2,3,10};
//     int x = 17;
//     // cout << getLevel(x, v) << endl;
//     cout << rec(v, x);
// }

int add(char c)
    {
        if (c == 'I') return 1;
        if (c == 'V') return 5;
        if (c == 'X') return 10;
        if (c == 'L') return 50;;
        if (c == 'C') return 100;
        if (c == 'D') return 500;
        if (c == 'M') return 1000;
        return 0;
    }

    int subtract(char prev, char curr)
    {
        if (curr == 'V' && prev == 'I') return 2;
        if (curr == 'X' && prev =='I') return 2;

        if (curr == 'L' && prev == 'X') return 20;
        if (curr == 'C' && prev == 'X') return 20;

        if (curr == 'D' && prev == 'C') return 200;
        if (curr == 'M' && prev == 'C') return 200;
        return 0;
    }

    int romanToInt(string s) {
        char prev = 'M';
        char curr;
        int len = s.length(); int i = 0;
        int res;
        while (i != len)
        {
            prev= curr; // prev becomes last current
            curr = s[i]; // current is this
            res += add(curr);
            res -= subtract(prev, curr);
            i++;
        }
        return res;
    }

int main()
{
    string s = "MCMXCIV";
    cout << s.substr(0, 3);
}