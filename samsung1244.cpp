#include <bits/stdc++.h>

using namespace std;

bool isSorted(string s)
{
    for (int i = 0; i < s.length()-1; i++)
    {   
        if (s[i] < s[i+1]) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s = "4321";
    int swaps = 3;

    char max;
    int max_ind;

    int i, j;
    while (true)
    {
        for (i = 0; i < s.length() - 1; i++)
        {
            max = s[i+1]; // must default with another element
            max_ind = i;
            for (j = i + 1; j < s.length(); j++)
            {
                if (s[j] >= max)
                {
                    max = s[j];
                    max_ind = j;
                }
            }
            cout << "s[i] = " << s[i] << " s[max_ind] = " << s[max_ind] << " i, max_ind = " << i << "," << max_ind << endl;

            swap(s[i], s[max_ind]);
            swaps--;
            if ( swaps == 0)
            {
                cout << s << endl;
                return 1;
            }
        }
    }
}