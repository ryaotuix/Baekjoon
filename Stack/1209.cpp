#include<bits/stdc++.h>

using namespace std;

/*
string removeDuplicates(string s, int k)
{
    string res = "";

    int totalcnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        // cout << "i is at " << i << endl;
        int cnt = 0;
        int j;

        // see how many consecutive characters there are
        for (j = 0; i+j < s.length(); j++)
        {
            if (s[i+j] != s[i] || cnt == k)
                break;
            if (s[i+j] == s[i])
                cnt ++;
        }

        // more than 3 consecutive characters, 
        if (cnt >= k)
        {
            i = i+j-1;            // jump index
            totalcnt++;         // total cnt
        }
        // less than 3 consecutive characters,
        else
        {
            res += s[i];         // add the char to res
            // cout << "insert " << s[i] << endl;
        }
    }

    // cout << res << endl;
    // cout << endl;

    // if totalcnt is 0
    if (totalcnt == 0)
    {
        return res;
    }
    // otherwise, which means there might be more consecutive characters
    else
    {
        return removeDuplicates(res, k);
    }
}
*/


string removeDuplicates(string s, int k)
{
    
}

int main()
{
    string s = "pbbcggttciiippooaais";
    int k = 2;

    cout << removeDuplicates(s, k) << endl;
}