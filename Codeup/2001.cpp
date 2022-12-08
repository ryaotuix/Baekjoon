#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int pasta = 2000;
    int juice = 2000;

    for (int i = 0; i < 3; i++)
    {
        int x; cin >> x;
        if (x < pasta) pasta = x;
    }

    for (int i = 0; i < 2; i++)
    {
        int y; cin >> y;
        if (y < juice) juice = y;
    }

    double res = 1.1 * (double) (pasta + juice);
    printf("%0.1f", res);
    return 0;
}