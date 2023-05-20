#include <iostream>
#include <stdio.h>

using namespace std;

char str[55];

int getHeight()
{
    int res = 10;
    char curr = str[0];

    int i = 1;
    while (str[i] != '\0')
    {
        if (str[i] == curr)
        {
            res += 5;
        }
        else
        {
            curr = str[i];
            res += 10;
        }

        i++;
    }

    return res;
}

int main()
{
    scanf("%s", str);
    int result = getHeight();
    printf("%d\n", result);
    return 0;
}