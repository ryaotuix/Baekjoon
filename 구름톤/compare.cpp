#include <bits/stdc++.h>

using namespace std;

const int MAX = 2 << 7;

/*
    Idea : 
    Start moving with the direction and the amount on the current position,

    Iterate through the direction until the amount becomes 1
        while iterating, if we encounter already visited position, return
    
    When doen iterating, move in new direction! according to new position where we ended
*/

// materials
int n;
int gRow, gCol, pRow, pCol;
string grid[MAX][MAX];
bool visited[MAX][MAX];


void input()
{
    cin >> n;
    cin >> gRow >> gCol;
    cin >> pRow >> pCol;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> grid[i][j];
        }
    }
}


int getMove(string s)
{
    return s[0] - '0';
}

char getDir(string s)
{
    return s[1];
}

int getCnt()
{
    int cnt = 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (visited[i][j]) cnt++;
        }
    }

    return cnt;
}

void OOB()
{
    if (direction == 'L')
        {
            currC = currC - 1;
            if (currC == 0) currC = n;
        }
        else if (direction == 'R')
        {
            currC = currC + 1;
            if (currC == n+1) currC = 1;
        }
        else if (direction == 'U') {
            currR = currR - 1;
            if (currR == 0) currR = n;
        }
        else if (direction == 'D') {
            currR = currR + 1;
            if (currR == n+1) currR = 1;
        }
}

int dfs(int currR, int currC)
{
    // base case
    if (visited[currR][currC] == true) return getCnt();
    
    // not based case
    visited[currR][currC] = true;

    int move = getMove(grid[currR][currC]);
    char direction = getDir(grid[currR][currC]);

    while (move) { // when we still have to move,
        

        // base case
        if (visited[currR][currC]) return getCnt();
        
        visited[currR][currC] = true;

        move--;
    }


    // must make last position not visited to start next direction in recursive step
    visited[currR][currC] = false;

    return dfs(currR, currC);
}

void printVisited()
{
    for (int i = 1; i <=n; ++i) {
        for (int j = 1;  j<= n; ++j) {
            cout << visited[i][j] << " ";
        }
        cout << "\n"; // plz use \n rather than endl
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    input();

    int goorm = dfs(gRow , gCol);
    // printVisited();
    // cout << endl;
    memset(visited, false, sizeof(visited));
    int player = dfs(pRow , pCol);
    // printVisited();

    // If there's one line dependent on if statement better to place it on the same line
    if (goorm > player) cout << "goorm " << goorm;
    else cout << "player " << player;

    return 0; // don't forget to write "return 0"
}