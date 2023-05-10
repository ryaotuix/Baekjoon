#include <iostream>
#include <vector>

using namespace std;

char toValid(int val)
{
    if (val >= 'A' && val <= 'Z')
        return (char) val;
    else
    {
        return toValid(val - 26);   // recursively convert to valid char
    }
}

void printWithAscii(const int n)
{
    int cnt = 'A';                                          // change ascii char A to int cnt
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; j < n+1; j++)
        {
            int val;
            if (j%2==1)
            {
                val = (cnt + (j-1)*n + i - 1);
            }
            else
            {
                val = (cnt + (j-1)*n + (n-i));
            }
            cout << toValid(val) << " ";
        }
        cout << endl;
    }
}


// void printWithArr(const int n)
// {
//     // 0. make an array size n x n
//     int ** arr = new int*[n+1];
//     for (int i = 0; i < n+1; i++)
//     {
//         arr[i] = new int[n+1];
//     }

//      // 1. fill out the array
//     int cnt = 'A';
//     for (int col = 1; col <= n; col++)
//     {
//         if (col%2 == 1) // 1.1 if column is odd, row: 1~n
//         {
//             int i = 1;
//             while (i <= n)
//             {
//                 arr[i++][col] = cnt;
//                 cnt++;
//             }
//         }
//         else            // 1.2 if column is even, row: n~1
//         {
//             int i = 4;
//             while (i > 0)
//             {
//                 arr[i--][col] = cnt;
//                 cnt++;
//             }        
//         }
//     }

//     // 2. print the array
//     for (int i = 1; i < n + 1; i++)
//     {
//         for (int j = 1; j < n+1; j++)
//         {
//             cout << (char) arr[i][j] << " ";
//         }
//         cout << "\n";
//     }
// }


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    printWithAscii(n);
}