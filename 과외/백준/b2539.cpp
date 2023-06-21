#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;             // <row, col>

int totalRow;
int totalCol;
int targetNumPaper;
int numWrong;
vector<pii> wrongLocation;
int lo = 0;                             // starting lo : must be 0
int hi;                                 // starting hi : max(totalRow, totalCol)

void input()
{
    cin >> totalRow >> totalCol >> targetNumPaper >> numWrong;
    
    hi = max(totalRow, totalCol);       // starting hi : max(totalRow, totalCol)

    for (int i = 0; i < numWrong; i++)
    {
        int currRow, currCol;
        cin >> currRow >> currCol;
        wrongLocation.push_back({currRow, currCol});
    }
}

// comparator to sort by column
bool compPair(pii & a, pii & b)
{
    int aCol = a.second;
    int bCol = b.second;

    return aCol < bCol;
}

// check if input was entered correctly
void printLocations()
{
    for (pii loc : wrongLocation)
    {
        cout << "col : " << loc.second << " row : " << loc.first << endl;
    }
}

/* Function to get number of Papers we need when given the length of a square*/
int getNumPaper(int side)
{
    int numPaper = 0;

    int rightMax = 0;
    
    for (pii loc : wrongLocation)
    {
        int col = loc.second;               // current column

        /* IS THIS WHY */
        int row = loc.first;
        if (row > side)
            return 1e8;
        /* IS THIS WHY */
        
        if (col > rightMax)                 // restart when this column is greater than the right max covered by the previous paper
        {
            numPaper++;
            rightMax = col + side - 1;
        }
    }

    return numPaper;
}

/* Function to get the length of the side of a square */
int binarySearch()
{
    lo--;

    while (lo + 1 < hi)
    {
        int side = (lo + hi) / 2;
        
        int numPaper = getNumPaper(side);

        // cout << lo << " " << side << " " << hi << " " << numPaper << endl;

        if (numPaper > targetNumPaper)              // if the number of paper is greater than what we want, we must reduce the length of the side
        {
            lo = side;
        }
        else
        {
            hi = side;
        }
    }

    return hi;
}


int main()
{
    input();
    sort(wrongLocation.begin(), wrongLocation.end(), compPair);                     // Must Sort by column!
    // printLocations();
    // cout << getNumPaper(3);
    cout << binarySearch();
}