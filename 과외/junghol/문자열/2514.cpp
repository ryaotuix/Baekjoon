/* KMP Algorithm 을 써보자! */

#include <iostream>

using namespace std;

const string pat1 = "KOI";
const string pat2 = "IOI";

// failure function for pat1 and pat2
int ff1 [3 + 1];
int ff2 [3 + 1];

// Preprocessing Failure Function
void initFF()
{
    int len = 0;
    int i = 1;
    while(i < pat1.length())
    {
        if (pat1[len] == pat1[i])
        {
            len++;
            ff1[i] = len;
            i++;
        }
        else
        {
            if (len > 0)
            {
                len = ff1[len-1];
            }
            else
            {   
                ff1[i] = len;
                i++;
            }
        }
    }
    
    len = 0;
    i = 1;
    while(i < pat2.length())
    {
        if (pat2[len] == pat2[i])
        {
            len++;
            ff2[i] = len;
            i++;
        }
        else
        {
            if (len > 0)
            {
                len = ff2[len-1];
            }
            else
            {   
                ff2[i] = len;
                i++;
            }
        }
    }
}

int start [3+1];

int kmpCount(int n, int m, string s, string pat)     // n : length of text, m: length of pattern
{
    // init
    int * mark = new int[n];
    for (int i = 0; i < n; i++)
        mark[i] = 0;


    // start
    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (s[i] == pat[j])             // string and pattern match
        {
            if (j == m-1)               // when pattern meets the last char
            {    
                mark[i-j] = 1;
                j = 0;
            }
            else
            {
                i++;
                j++;
            }
        }
        else
        {
            if (j > 0)
                j = ff1[j-1];
            else
                i++;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (mark[i] == 1)
            cnt++;
    }
    return cnt;
}

int kmpCount2(int n, int m, string s, string pat)     // n : length of text, m: length of pattern
{
    // init
    int * mark = new int[n];
    for (int i = 0; i < n; i++)
        mark[i] = 0;


    // start
    int i = 0;
    int j = 0;

    while (i < n)
    {
        if (s[i] == pat[j])             // string and pattern match
        {
            if (j == m-1)               // when pattern meets the last char
            {    
                mark[i-j] = 1;
                j = 0;
            }
            else
            {
                i++;
                j++;
            }
        }
        else
        {
            if (j > 0)
                j = ff2[j-1];
            else
                i++;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (mark[i] == 1)
            cnt++;
    }
    return cnt;
}

int bruteForce(string s, string pat)
{
    int i, j;

    int cnt = 0;

    for (i = 0; i <= s.length()-3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (s[i+j] != pat[j])
            {
                break;
            }
        }

        if (j == 3)
        {
            cnt++;
        }
       
    }

    return cnt;
}



int main()
{
    string s;
    cin >> s;

    int n = s.length();     // length of text
    int m = 3;              // length of pattern

    // cout << bruteForce(s, pat1) << "\n" << bruteForce(s, pat2);

    // cout << endl;

    initFF();
    cout << kmpCount(n, m, s, pat1) << "\n" << kmpCount2(n, m, s, pat2);
}