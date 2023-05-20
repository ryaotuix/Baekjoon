#include <stdio.h>

char grid [5][15 + 5];

void init()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            grid[i][j] = '.';
        }
    }
}

void printVertical()
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (grid[j][i] != '.')
                printf("%c", grid[j][i]);
        }
    }
}
int main()
{
    init();

    // input 
    for (int i = 0; i < 5; i++)
    {
        scanf("%s", grid[i]);
    }

    printVertical();
    
}