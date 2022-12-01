#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int arr[10] = {0};


    int n; cin >> n;
    while (1)
    {
        // first digit
        arr[n%10]++;
        // if it was first digit break
        if (n/10 == 0) break;
        n /= 10;
    }

    int maxnum = 0;
    for (int i = 0; i < 10; i++)
        if (i != 6 && i!=9) maxnum = max(maxnum, arr[i]);

    maxnum = max(maxnum, (arr[6] + arr[9] + 1)/2);
    cout << maxnum << endl;
    return 0;
}



/*
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
*/
