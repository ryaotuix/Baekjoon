#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int N, K; cin >> N >> K;
    
    bool arr[N+1]; // make an array to use index as i 
    memset(arr, false, sizeof(arr)); // fill array with 0 

    int count = 0;
    for (int i=2; i<N+1; i++) // starting from 2
    {
        for (int j = i; j < N+1; j += i)
        {
            if(arr[j] == true) continue; // if 
            else 
            {
                arr[j] = true;
                ++ count;
            }

            if (count == K)
            {
                cout << j << endl;
                return 0;
            }
        }
        /*
        int j = 1;
        while (i*j <= N)
        {
            
            if (arr[i*j] != 1) 
            {
                arr[i*j] = 1;
                ++count;
            }
            
            if (count == K)
            {
                cout << i*j << endl;
                return 0;
            }
            ++j;
        }
        */
    }
    return 0;
}