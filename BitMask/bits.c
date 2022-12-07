#include <stdio.h>
#include <stdlib.h>

void printBits(unsigned int bitmap)
{
    for (int i = 31; i >= 0; i--)
    {
        unsigned int moved = bitmap >> i;
        printf("%d", moved&1);
        if (i%4 == 0) printf(" ");
    }
    printf("\n\n");
}


void setBitAt( unsigned int *bitmap, int i, int bitValue )
{ // set the ith bit in bitmap to the specified bitValue (either 0 or 1)
    //printf("%d", *bitmap);

    unsigned int bitmask;
    if (bitValue == 1)
    {
        bitmask = 1 << i;
        *bitmap = (*bitmap | bitmask);
    } 
    else 
    {
        bitmask = ~(1 << i);
        *bitmap = (*bitmap & bitmask);
    }
}


int getBitAt( unsigned int bitmap, unsigned int i) 
{ //-- return the ith bit in bitmap (either 0 or 1)
    return ((bitmap >> i) & 1 );
}



int countBits( unsigned int bitmap, unsigned int bitValue) 
{ // -- returns the count of the number of 0s or 1s in bitmap
    int cntOne = 0;
    int cntZero = 0;

    for (int i=0; i<32; i++)
    {
        int val = (bitmap >> i) & 1;
        if (val == 1) cntOne++;
        else cntZero++;
    }

    int res = (bitValue == 0) ? cntZero : cntOne;
    return res;
}


int maxContinuousOnes(unsigned int num, int * position)
{
   // Find the maximum number of consecutive ones bits in num. 
   // Set position equal to the start of the sequence where the max number of ones occurs. 
   // Return the count of the maximum number of ones in a consecutive sequence.
 
    int max = 0;
    int temp_max = 0;
    
    for (int i =0; i<32; i++)
    {
        int val = (num>>i) & 1;
        if (val == 1) temp_max++;
        else temp_max = 0;

        if (temp_max > max) 
        {
            max = temp_max;
            *position = i;
        }
    }

    // !!!
    *position = *position - max + 1;

    return max;
}




unsigned int get_range( unsigned int num, int low, int high ) 
{
    // -- Return the bits that are found in the given range
    unsigned int res = 0;

    int digit = 1;
    for (int i = low; i < high+1; i++)
    {
        int x = (num>>i) & 1;
        res += (x*digit);

        digit *= 2;
    }
    return res;
}


unsigned int inverse_bits ( unsigned int num ) 
{
    // invert the bits in the number ex. 1010 should be converted to 0101
    return ~num;
}



int find_sequence (unsigned int num, unsigned int pattern, int patternLength) 
{
    // returns the index of the first occurence the bit ‘pattern’ is found in num. 
    // e.g. the bits in num = 10010 and pattern = 1001 should return 1 because the pattern was found at index 1 in num
    for (int i=0; i <32; i++)
    {
        unsigned int shifted = num >> i;
        if (shifted == pattern) return i;
    }

    return -1;
}



int main()
{
    unsigned int bitmap = 17;
    printBits(bitmap); // 0000 0000 0000 0000 0000 0000 0001 0001


    setBitAt(&bitmap, 2 ,1); 
    printBits(bitmap); // 0000 0000 0000 0000 0000 0000 0001 0101


    setBitAt(&bitmap, 2, 0);
    printBits(bitmap); // 0000 0000 0000 0000 0000 0000 0001 0001

    int x = getBitAt(bitmap, 4); // 1
    int y = getBitAt(bitmap, 3); // 0
    printf("x = %d, y = %d\n\n", x, y);


    int cntOne = countBits(bitmap, 1); // 2
    int cntZero = countBits(bitmap, 0); // 30
    printf("There are %d many 1s \nThere are %d many 0s\n\n", cntOne, cntZero);



    setBitAt(&bitmap, 5, 1);
    setBitAt(&bitmap, 6, 1);
    printBits(bitmap); // 0000 0000 0000 0000 0000 0000 0111 0001

    int position;
    int maxContOne = maxContinuousOnes(bitmap, &position);
    printf("the length of max continuous One is %d, with position starting at %d\n\n", maxContOne, position); // max cont = 3, position = 4


    unsigned int range_bit = get_range(bitmap, 2, 6);
    printf("The range bit value is %d\n", range_bit);
    printBits(range_bit);
    printf("\n");

    
    printf("Original : ");
    printBits(bitmap); 
    unsigned int inverse = inverse_bits(bitmap);
    printf("Invers   : ");
    printBits(inverse);


    unsigned int num = 36;
    unsigned int pattern = 9;
    int start = find_sequence(num, pattern, 0);
    printf("Number : ");
    printBits(num);
    printf("Pattern : ");
    printBits(pattern);
    printf("Start position is %d\n", start);

    return 0;
}