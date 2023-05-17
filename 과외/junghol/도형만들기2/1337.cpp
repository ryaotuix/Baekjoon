// #include <iostream>

// using namespace std;

// #define down 1
// #define left 2
// #define up 3

// void printTriangle(const int n)
// {
//     // 1. init
//     int ** grid = new int * [n];
//     for (int i = 0; i < n; i++)
//     {
//         grid[i] = new int[n];
//     }

//     // <fill it as -1>
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             grid[i][j] = -1;
//         }
//     }

//     // 2. fill out triangles
//     int iter = n * (n+1) / 2;       // number of iterations
//     int downBoundary = n;   // both row = n, col = n
//     int leftBoundary = -1;   // (?, 0)
//     int upBoundary = 0;     // (1, ?)
//     int row = 0; int col = 0; int cnt = 0;

//     int direction = down;   // initial direction

//     for (int i = 0; i < iter; ++i)
//     {
//         if (cnt == 10)          // change cnt to 0 if it exceeds 10
//             cnt = 0;

//         // Each direction has different next
//         if (direction == down)
//         {
//             grid[row++][col++] = cnt++;
//         }
//         else if (direction == left)
//         {
//             grid[row][col--] = cnt++;
//         }
//         else if (direction == up)
//         {
//             grid[row--][col] = cnt++;
//         }

//         // Change direction
//         if (direction == down && col == downBoundary)
//         {
//             direction = left;
//             downBoundary--;
//             row--; col--;
//             col--;
//         }
//         else if (direction == left && col == leftBoundary)
//         {
//             direction = up;
//             leftBoundary++;
//             col++;
//             row--;
//         }
//         else if (direction == up && row == upBoundary)
//         {
//             direction = down;
//             upBoundary++;
//             row++;
//         }

//     }

//     // 3. print
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (grid[i][j] == -1)
//                 cout << " ";
//             else 
//                 cout << grid[i][j];
//             cout << " ";
//         }
//         cout << endl;
//     }

// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);

//     int n;
//     cin >> n;

//     printTriangle(n);
// }


// 51 분 했는데 못했어??? 진짜 씨ㅡ발 내가 병신이지