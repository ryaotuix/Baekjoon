#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<char, int> um;
    char a = 'A';
    char b = 'B';
    char c = 'C';
    um['A'] = 0;
    um['B'] = 0;
    um['C'] = 0;
    um['C'] += 1;

    for (auto i = um.begin(); i != um.end(); i++)
        cout << i->first << " : " << i->second << "\n";
}