#include <bits/stdc++.h>

using namespace std;

bool visited[15 + 1][15 + 1];       // visited bool 2D arr
int N;                              // N is size

void makeVisited(int row, int col)
{
    // row check
    for (int i = 0; i < N; i++)
    {
        visited[row][i] = true;
    }

    // col check
    for (int i = 0; i < N; i++)
        visited[i][col] = true;


    // / check
    for (int )
}


int main()
{
    cin >> N;
    

}