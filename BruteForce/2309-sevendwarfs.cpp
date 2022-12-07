#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int arr[9];
int dwarfs[7];

int main()
{
    int sum = 0;
    for (int i = 0; i<9; i++)
    {
        int x; cin >> x;
        arr[i] = x;
        sum += x;
    }

    sort(arr, arr+9); // sort!!!


    for (int i = 0; i < 8; i++)
    {
        for (int j = i+1; j < 9; j++)
        {
            if (sum - arr[j] - arr[i] == 100)
            {
                for (int k = 0; k < 9; k++)
                {
                    if (k != i && k !=j)
                        cout << arr[k] << "\n";
                }
                return 0;
            }
        }
    }
}




/*
// MY WAY
int arr[10];
int res[7];

// C++ way
void swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}

// C way
void swap(int * a, int * b) // parameters : address
{
    int temp = *a;  // temp stores the value of a 
    *a = *b;    // value of a is now value of b address pointing
    *b = temp;  // value of b is now value of temp  
}


void sort()
{
      // Bubble sort
    for (int i = 1; i < 7; i++)
    {
        int cnt = 1;
        for (int j = 0; j < 7-i; j++)
        {
            if (res[j] > res[j+1]) // ascending order
            {
                swap(&res[j], &res[j+1]);
            }
        }
    }
}


int main()
{
    // save in array
    for (int i = 0; i < 9; i++)
    {
        int x; cin >> x;
        arr[i] = x;
    }

    // cout << "====================" << "\n";

    // for (int i = 0; i < 9; i++)
    //     cout << "index " << i << " is " << arr[i] << "\n";

    // int dwarf_count = 7;
    // int height_sum = 100;



    for (int i = 0; i < 3; i++)
    {
        for (int j = i+1; j < 4; j++)
        {
            for (int k = j+1; k < 5; k++)
            {
                for (int x = k+1; x < 6; x++)
                {
                    for (int y = x+1; y < 7; y++)
                    {
                        for (int z = y+1; z< 8; z++)
                        {
                            for (int a = z+1; a < 9; a++)
                            {
                                if ((arr[a] + arr[z] + arr[y] + arr[x] + arr[k] + arr[j] + arr[i]) == 100)
                                {
                                    // cout << "a z y x k j i " << "\n";
                                    // cout << a << z << y << x << k << j << i <<"\n";
                                    res[0] = arr[a];
                                    res[1] = arr[z];
                                    res[2] = arr[y];
                                    res[3] = arr[x];
                                    res[4] = arr[k];
                                    res[5] = arr[j];
                                    res[6] = arr[i];
                                    sort();
                                    // cout << "YAYYY" << "\n";
                                    for (int t =0; t<7; t++) cout << res[t] << "\n";
                                    return 0;
                                    
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}
*/
