#include <iostream>
#include <stdlib.h>


using namespace std;

int main()
{
    int a, b; cin >> a >> b;
    

    // We can use the fact that +- 10 can be the done like this
    int cnt = abs(b-a) / 10; 

    // 
    int rem = abs(b-a) % 10;
    if (rem == 1 || rem == 5)
        cnt++;
    else if (rem == 2 || rem == 4 || rem == 6 || rem == 9)
    // (11) , (5 -1), (5 1), (10 -1)
        cnt += 2;
    else if (rem != 0) 
    // exept 0
        cnt += 3;

    cout << cnt;
    return 0;
}



/*
int main()
{
    int a, b;
    cin >> a >> b;

    int cnt = 0;

    while (true)
    {
        if (a == b) break;

        // if a has to get bigger
        if (b - a > 0)
        {
            // compare 10 and 5
            if (abs(b - (a+10)) < abs(b - (a+5)))
            {
                a += 10;
            }
            else 
            {
                if (abs(b - (a+5)) < abs(b - (a+1)))
                {
                    a += 5;
                }
                else
                {
                    a += 1;
                }
            }
        }
        else // if a has to get smaller
        {
            if (abs(b - (a-10) < abs(b - (a-5))))
            {
                a -= 10;
            }
            else
            {
                if (abs(b - (a-5)) < abs(b - (a-1)))
                {
                    a -= 5;
                }
                else 
                {
                    a -= 1;
                }
            }
        }

        cnt++;
    }
    cout << cnt;
    return 0;
}
*/