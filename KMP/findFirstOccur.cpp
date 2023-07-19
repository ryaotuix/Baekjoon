#include <bits/stdc++.h>

string haystack;
string needle;

// finding the first index of needle in haystack 
// if not exist, return -1
int strStr(string haystack, string needle)
{
    int n = haystack.size();
    int m = needle.size();

    if (n < m)
        return -1;
    
    // PreProcessing
    vector<int> lps(m, 0);
    int prev = 0;
    int i = 1;              // iterating from index 1, lps[0] = 0

    while (i < m)
    {
        // Case if needle[prev] == needle[i]
        if (needle[prev] == needle[i])
        {
            // length of border increases
            prev++;
            lps[i] = prev;
            i++;
        }
        else
        {
            // not matches and prev is 0
            if (prev == 0)
            {
                lps[i] = 0;
                i++;
            }
            // not matches but prev != 0
            else
            {
                prev = lps[prev - 1];
            }
        }
    }
}


int main()
{
    cout << "Haystack :"; cin >> haystack;

    cout << "Needle :"; cin >> needle;

    cout << strStr(haystack, needle);
}