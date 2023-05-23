
#include<stdio.h>
#include<iostream>
using namespace std;

int n, m;
int arr[10];                            // stores possible combinations of die

// init 2d Arr
int countArr[7780][6+1];

void printRec(int x)
{
    if(x==n+1)                         // when throw all n die
    {
        // print
        for (int j = 1; j < n+1; j++)
        {
            cout << arr[j] << " ";
        }
        cout << endl;
        return;
    }

    // fill it out 
    for (int i = 1; i < 6+1; i++)
    {
        arr[x] = i;                     // 2. comes back here and arr[x] becomes 2....6
        printRec(x+1);                  // 1. first do <1, 1, 1> then
    }
}

// Function to check if arr is Ascending 
bool isAscending(int n)
{
    int temp = -1;
    for (int i = 1; i < n+1; i++)
    {
        if (arr[i] < temp)
            return false;
        else
        {
            temp = arr[i];
        }
    }
    return true;
} 

void printRec2(int x)
{
    if(x==n+1)
    {
        // CHECK ASCENDING ORDER to see if it is unique
        // bool flag = isAscending(n);

        bool flag = true;

        // print comp
        if (flag)
        {
            for (int i = 1; i < n+1; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    // Check Ascending order without isAscending function
    // start filling with the previous index

    // 0. init 0 as 1 so that run from 1 when x == 1
    arr[0] = 1;

    // start from the previous ind
    for (int i = arr[x-1]; i < 6+1; i++)
    {
        arr[x] = i;

        printRec2(x+1);
    }
}

bool didUse[7];                        // array to check if we have rolled from 1 ~ 6

void printRec3(int x)
{
    if(x==n+1)                         // when throw all n die
    {
        // print
        for (int j = 1; j < n+1; j++)
        {
            cout << arr[j] << " ";
        }
        cout << endl;
        return;
    }

    // fill it out 
    for (int i = 1; i < 6+1; i++)
    {
        if (didUse[i])                  // if we have used this number i,
            continue;

        arr[x] = i;                     // 2. comes back here and arr[x] becomes 2....6
        didUse[i] = true;
        printRec3(x+1);                  // 1. first do <1, 1, 1> then

        // Get rid of mark 
        didUse[i] = false;
    }
}


int main() {
    cin >> n >> m;
    if (m == 1)
        printRec(1);
    else if (m == 2)
        printRec2(1);
    else if (m == 3)
        printRec3(1);

}