#include <iostream>

using namespace std;

string dictionary [1010];

int ind = 0;

bool isInDic(string & target)
{
    for (int i = 0; i < ind; i++)
    {
        if (dictionary[i] == target)
            return true;
    }
    
    return false;
}

void parseLine(string &line)
{
    string temp = "";
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ' ' || i == line.length() - 1)
        {
            if (i == line.length() - 1 && i != ' ')     // if the last char is not a white space
            {
                temp += line[i];
            }

            if (isInDic(temp))                          // if it is alredy in dictionary, reset temp and continue
            {
                temp = "";
                continue;
            }
            else {
                // cout << "temp : " << temp << endl;
                dictionary[ind++] = temp;               // if it doesn't exist in dictionary, add it to dic and reset temp
                temp = "";
            }
        }
        else                                            // if not white space or the last char, add it to temp
        {
            temp += line[i];
        }
    }
}

void printDic()
{
    for (int i = 0; i < ind; i++)
        cout << dictionary[i] << " ";
    cout << endl;
}

int main()
{
    string line;

    while (true)
    {
        getline(cin, line);
        if (line == "END")
            return 0;
        parseLine(line);
        printDic();

        
    }
}