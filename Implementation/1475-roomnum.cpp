#include <iostream>
#include <string.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s; cin>>s;

    // index {0,1,2,3,4,5,6,7,8}
    int check[9]; // check array 0 if is not used
    memset(check, 0, sizeof(check));

    for (int i =0; i<s.length(); i++)
    {
        int k = int(s[i]) - 48;

        if (k==6 || k==9)
        {
            check[6]++;
        }
        else
        {
            check[k]++;
        }
    }

    bool isOdd = false;
    if (check[6]%2 == 1) isOdd = true;
    check[6] = check[6]/2;
    if (isOdd) check[6]++;

    int max = check[0];
    for (int i=1; i<9; i++)
    {
        if (check[i] > max) max = check[i];
    }
    

    cout << max << endl;
    return 0;
}