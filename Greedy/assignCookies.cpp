#include <iostream>

int findContentChildren(vector<int>& g, vector<int>& s) 
{
    int res = 0;
    sort(g.begin(), g.end()); // child
    sort(s.begin(), s.end()); // cookie
    int indCookie = 0;
    for (int i = 0; i < g.size(); i++)
    {
        if (indCookie > s.size()) break; // if we don't have a cookie to give a child
        if(s[indCookie] >  g[i])
        {
            res++;
            indCookie++;
        }
    }
    return res;
}


int main()
{
    vector<int> g = 
}