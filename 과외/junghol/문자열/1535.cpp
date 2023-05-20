#include <iostream>

using namespace std;

string dictionary [1010];

void parseStringAndPrint(string &line)
{
    char delim = ' ';
    stringstream ss(line);

    
}

int main()
{
    string line;

    while (true)
    {
        getline(cin, line);

        if (line == "END")
            return 0;

        cout << line << endl;
    }
}