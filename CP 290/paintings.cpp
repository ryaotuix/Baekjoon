#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std;

typedef pair<String, String> pcc; // pair of Strings

vector<vector<bool>> invalidPairs;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);



    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<String> colors; // list of colors
        vector<pcc> invalidColorPairs; // list of invalid color pairs
        
        // add each color to the list of colors
        int numColors; cin >> numColors;
        for (int j = 0; j < numColors; j++)
        {
            String color; cin >> color;
            colors.push_back(color);
        }

        // add each invalid color pair to the list of invalid color pairs
        int numPairs; cin >> numPairs;
        for (int j = 0; j < numPairs; j++)
        {
            String c1;
            String c2;
            cin >> c1 >> c2;
            pair p = make_pair(c1, c2);
            invalidColorPairs.push_back(p);
        }




    }

}