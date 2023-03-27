#include <bits/stdc++.h>
#include <string>

using namespace std;


// Materials
         // 상 하  좌 우
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
queue<int> Q;                   // queue for bfs
vector<vector<int>> grid;       // grid
vector<vector<bool>> visited;   // visited matrix
int colors[] = {1,2,3,4,5,6};   // color options

int numMoves = 0;               // number of moves to fill it entirely

queue<int> whatWeChanged;       // queue to list colors we have changed

typedef struct pair<int, int> coordiante;


void printGrid()
{
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid.size(); ++j)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}


void makeGrid(int n)
{
    // Clear and initialize size nxn
    grid.clear();   
    visited.clear();

    grid = vector<vector<int>> (n, vector<int>(n));         
    visited = vector<vector<bool>> (n, vector<bool>(n));

    for (int i = 0; i < n; ++i)
    {
        string s; cin >> s;
        for (int j = 0; j < n; ++j)
        {
            grid[i][j] = s[j] - '0';
        }
    }
}

int connectedSize[6];

int bfsFF(queue<coordinate> & alreadyExistingCC)     // returns the color we need to choose 
{
    priority_queue<int> toColor;                   // pq to store the color we want <highest sized color being on top>
    int originalSize = alreadyExistingCC.size();   // already existing color size
    for (color : colors)                           // for each color
    {
        while(!alreadyExistingCC.empty())          // 
        {

        }
    }
}


int main()
{
    // int T; cin >> T;
    // while (T--)
    // {
    //     int n; cin >> n;
        

    // }
    int n; cin >> n;
    printGrid();
    makeGrid(n);
    printGrid();



}
