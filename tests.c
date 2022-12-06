#include <stdio.h>

int main() {
    register int i;
    register int k;

    i = 5;
    k = i * 3;

    printf("i = %d, k = %d\n" , i, k);
    return 0;
}