#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) 
{
    int res = 0;
    sort(g.begin(), g.end()); // child
    sort(s.begin(), s.end()); // cookie


    int glen = g.size(); // children len
    int slen = s.size(); // cookie len

    int indCookie = 0;
    for (int i = 0; i < glen; i++)
    {
        for (int j = indCookie; j < slen; j++)
        {
            // if the cookie can satisfy this child
            if (g[i] <= s[indCookie])
            {
                indCookie++;
                res++;
                break; // see the next child
            }
            // otherwise if we can't satisf a child with this cookie
            indCookie++;
        }
    }
    return res;
}


int main()
{
    vector<int> g = {1,2};
    vector<int> s = {1,2,3};
    cout << findContentChildren(g, s) << "\n";
}