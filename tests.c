#include <stdio.h>

int main() {
    int i = 0;
    int j = 0;
    while (1)
    {
        i++;
        if (i == 3) break;
    }

    while (j != 3)
    {
        j++;
    }

    printf("%d %d\n", i, j);
}