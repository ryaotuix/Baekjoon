#include <bits/stdc++.h>

using namespace std;


vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
int maxWidth = 16;

/*
    ex) numWords = 3 maxWidth = 16, len = 10    return {"   ", "   "}
    ex) numWords = 5 maxWidth = 17 len = 10     return {"  ","  ","  "," "}
*/
vector<string> getSpaces(int numWords, int maxWidth, int len)
{
    string space = "";
    vector<string> ret;
    
    // evenly distribute spaces
    for (int i = 0; i < (maxWidth - len) / (numWords - 1); i++)
            space += " ";
    for (int i = 0; i < numWords - 1; i++)
        ret.push_back(space);

    // numwords divided by max width is not equl to 0,
    int leftover = (maxWidth - len) % (numWords - 1);
    int i = 0;
    while (leftover)
    {
        ret[i++] += " ";
        leftover--;
    }

    return ret;
}

void printV(vector<string> v)
{
    for (string s : v)
        cout << "{" << s << "}" << " ";
}


vector<string> fullJustify(vector<string>& words, int maxWidth) {
    int numWords = 0;
    int len = 0;

    vector<string> ret;
    int wordInd = 0;

    for (int i = 0; i < words.size(); i++)
    {
        // when the last words
        if (i == words.size())
        {
            // check if we can last s can be added
            string last = ret[words.size() - 1];
            
            vector<string> thiswords;
        }
        // otherwise
        else
        {
            // if adding next word exceeds maxWidth, 
            if (numWords + len - 1 + 1 + words[i+1].size() > maxWidth)
            {
                string temp = "";

                // get spaces
                vector<string> spaces = getSpaces(numWords, maxWidth, len);
                int j = 0;

                while (wordInd != i)
                {
                    temp += words[wordInd];
                    temp += spaces[j++];
                    wordInd++;
                }
                
                ret.push_back(temp);

                // re-init
                numWords = 0;
                len = 0;
            }
            // otherwwise
            else
            {
                numWords++;
                len += words[i].size();
            }
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    printV(getSpaces(5, 17, 10));
}