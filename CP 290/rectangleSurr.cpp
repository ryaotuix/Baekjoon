#include <iostream>

const int MAX = 501;
bool arr[MAX][MAX] = {0};

using namespace std;

// void printArr(bool arr[MAX][MAX])
// {
//     printf("----------------------------\n");
//     for (int i = 0; i < MAX; i++)
//     {
//         for (int j = 0; j < MAX; j++)
//         {
//             printf("%d ", arr[i][j]);
//         }
//         printf("\n");
//     }
//     printf("----------------------------\n");

// }

void markArr(bool arr[MAX][MAX], int a, int b, int c, int d)
{
    for (int i = a; i < c; i++)
    {
        for (int j = b; j < d; j++)
        {
            arr[i][j] = true;
        }
    }
}

void resetArr(bool arr[MAX][MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            arr[i][j] = false;
        }
    }  
}


int howMany(bool arr[MAX][MAX])
{
    int cnt = 0;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            if (arr[i][j]) cnt++;
        }
    }
    return cnt;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //printArr(arr);

    int n;
    cin >> n;
    while(n != 0)
    {
        int a, b, c, d;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b >> c >> d;
            // printf("wow a:%d b:%d c:%d d:%d\n", a, b, c, d);
            markArr(arr, a, b, c, d);
        }

        //cout << "-------------------------\n";
        //printArr(arr);
        cin >> n;

        int res = howMany(arr);
        cout << res << "\n";
        resetArr(arr);
    }

    


    return 0;
}