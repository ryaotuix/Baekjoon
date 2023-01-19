#include <stdio.h>
#include <stdlib.h>
#include <string.h>



const int LENGTH = 1E6+1;



int main()
{
    
    int num; 
    scanf("%d", &num);

    // C-Way. So arr[num+1] with each element being the size of LENGTH
    char ** strArr = (char**) malloc((num+1) * sizeof(char) * LENGTH);

    // Loop to receive strings
    for (int i = 0; i < num; i++)
    {
        char * str = (char *) malloc(LENGTH * sizeof(char));
        scanf("%s", str);
        strArr[i+1] = str; // store the string in 1 ~ num+1 positions
    }

    // Checking if it has received correctly
    /*
    for (int i = 1; i <= num; i++)
    {
        printf("String %d is %s\n", i, strArr[i]);
    }
    */

    // Loop to do the tasks
    int a; int b;
    for (int i = 0; i < num-1; i++)
    {
        
        scanf("%d %d", &a, &b);
        strArr[a] = strcat(strArr[a], strArr[b]);
        strArr[b] = "";

        //printf("String %d is %s. String %d is %s\n", a, strArr[a], b, strArr[b]);
    }
    printf("%s", strArr[a]);

    return 0;

}