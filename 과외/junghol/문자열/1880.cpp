#include <iostream>


using namespace std;


int main()
{
    string encoding;
    string decoded;

    cin >> encoding >> ws;

    getline(cin, decoded);

    int key;
    char value;
    bool isUpper;

    for (int i = 0; i < decoded.length(); i++)
    {
        key = decoded[i];
        if (key == ' ')
        {
            cout << ' ';
            continue;
        }

        if (decoded[i] >= 'A' && decoded[i] <= 'Z')
        {
            key += ' ';
            isUpper = true;
        }
        else
        {
            isUpper = false;
        }

        value = encoding[key-'a'];
        if (isUpper)
        {
            cout << (char) (value - ' ');
        }
        else
        {
            cout << (char) value;
        }
    }
}