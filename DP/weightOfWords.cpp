#include <bits/stdc++.h>

using namespace std;



void printVec(vector<int>& v)
{
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
        sum += v[i];
    }
    cout << endl;
    cout << "sum : " << sum << endl; 
}

int main()
{
    int l, w; cin >> l >> w;

    if (w < l)
    {
        cout << "impossible";
        return 0;
    }
    if (w/l > 26 || (w/l == 26 && w%l > 0))
    {
        cout << "impossible";
        return 0;
    }

    string alphabets[27] = {"null", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};

    string res = "";
    vector<int> vec (l, 1);
    w -= l*1;

    int i = 0;
    while (w != 0)
    {
        if (w > 25)
        {
            vec[i++] += 25;
            w -= 25;
        } 
        else 
        {
            vec[i++] += w;
            w -= w;
        } 
    }

    for (int i = 0; i<vec.size(); i++)
    {
        char c = vec[i]+96;
        res += c;
    }

    //printVec(vec);
    cout << res;


    // int k = w/l; // weight of each alphabet
    // char c = k+96;

    // for (int i = 0; i < l-1; i++)
    // {
    //     res += c;
    // }

    // int rem = w - k*(l-1);
    // char last = rem+96;
    // res += last;

    // cout << res;
    // return 0;
}