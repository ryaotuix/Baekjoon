#include <bits/stdc++.h>

using namespace std;

const int MAX = 11;

typedef pair<int, int> pii;     // row, col

// materials
int n;          // row
int m;          // cols
pii dest;       // destination
char grid[MAX][MAX];        // grid
bool visited[MAX][MAX][MAX][MAX];
int dr[4] = {-1, 1, 0, 0};  
int dc[4] = {0, 0, -1, 1};

typedef struct balls
{
    pii red;
    pii blue;
    int move;
}balls;

queue<balls> Q; // store balls for bfs

bool atDest(pii & ball)
{
    if (ball.first == dest.first && ball.second == dest.second) return true;
    return false;
}

bool isVisited(balls b)
{
    if (visited[b.red.first][b.red.second][b.blue.first][b.blue.second] == false) return false;
    else return true;
}

void markVisited(balls b)
{
    visited[b.red.first][b.red.second][b.blue.first][b.blue.second] = true;
}

// movements
balls moveLeft(balls & b)
{
    balls res = b;
    res.move++;

    // if red is on the left, 
    if (b.red.second < b.blue.second)
    {
        // not out of bound AND not wall
        if (b.red.second - 1 > 1 && grid[b.red.first][b.red.second - 1] != '#')
            res.red.second--;
    }
    // if blue is on the left,
    else
    {    
        // not out of bound AND not wall
        if (b.blue.second - 1 > 1 && grid[b.blue.first][b.blue.second - 1] != '#')
        {
            // if blue meets red, 
            if (b.blue.second - 1 != res.red.second)
                res.blue.second--;
        }
    }

    return res;
}

balls moveRight(balls & b)
{
    balls res = b;
    res.move++;

    // if red is on the right, 
    if (b.red.second > b.blue.second)
    {
        // not out of bound AND not wall
        if (b.red.second + 1 < m-1 && grid[b.red.first][b.red.second - 1] != '#')
            res.red.second++;
    }
    // if blue is on the left,
    else
    {    
        // not out of bound AND not wall
        if (b.blue.second + 1 < m-1 && grid[b.blue.first][b.blue.second - 1] != '#')
        {
            // if blue meets red, continue
            if (b.blue.second + 1 != res.red.second)
                res.blue.second++;
        }
    }

    return res;
}

balls moveUp(balls & b)
{
    balls res = b;
    res.move++;

    // if red is above, 
    if (b.red.first < b.blue.first)
    {
        // not out of bound AND not wall
        if (b.red.first - 1 > 1 && grid[b.red.first][b.red.second - 1] != '#')
            res.red.first--;
    }
    // if blue is on the left,
    else
    {    
        // not out of bound AND not wall
        if (b.blue.first - 1 > 1 && grid[b.blue.first][b.blue.second - 1] != '#')
        {
            // if blue meets red, continue
            if (b.blue.first - 1 != res.red.first)
                res.blue.first--;
        }
    }

    return res;
}

balls moveDown(balls & b)
{
    balls res = b;
    res.move++;

    // if red is below, 
    if (b.red.first > b.blue.first)
    {
        // not out of bound AND not wall
        if (b.red.first + 1 < n - 1 && grid[b.red.first][b.red.second - 1] != '#')
            res.red.first++;
    }
    // if blue is on the left,
    else
    {    
        // not out of bound AND not wall
        if (b.blue.first + 1 < n - 1 && grid[b.blue.first][b.blue.second - 1] != '#')
        {
            // if blue doesnt meet red,
            if (b.blue.first + 1 != b.red.first)
                res.blue.first++;
        }
        
    }

    return res;
}


void printBalls(balls & b)
{
    cout << "red: ";
    cout << b.red.first << ", " << b.red.second << "\n";
    cout << "blue: ";
    cout << b.blue.first << ", " << b.blue.second << "\n";
    cout << b.move << "\n";

}



int bfs()
{
    while(!Q.empty())
    {
        balls currBalls = Q.front(); Q.pop();
        printBalls(currBalls);

        // if we cannot finish within 10 movements, return -1
        if (currBalls.move >= 11) return -1;

        // i) move left
        if (!isVisited(moveLeft(currBalls)))
        {
            cout << "move left\n";
            markVisited(moveLeft(currBalls));
            Q.push(moveLeft(currBalls));
        }
        // ii) move right
        if (!isVisited(moveRight(currBalls)))
        {
            cout << "move right\n";

            markVisited(moveRight(currBalls));
            Q.push(moveRight(currBalls));
        }
        // iii) move up
        if (!isVisited(moveUp(currBalls)))
        {
            cout << "move up\n";

            markVisited(moveUp(currBalls));
            Q.push(moveUp(currBalls));
        }
        // iv) move down
        if (!isVisited(moveDown(currBalls)))
        {
            cout << "move down\n";

            markVisited(moveDown(currBalls));
            Q.push(moveDown(currBalls));
        }
    }

    return 0;
}

void input()
{
    balls ball; // initial ball
    ball.move = 0;
    
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];

            // get final destinations
            if (grid[i][j] == 'O')
            {
                dest.first = i;
                dest.second = j;
            }

            // get initial Red
            if (grid[i][j] == 'R')
            {
                ball.red.first = i;
                ball.red.second = j;
            }

            // get initial Blue
            if (grid[i][j] == 'B')
            {
                ball.blue.first = i;
                ball.blue.second = j;
            }
        }
    }

    // mark ball visited
    markVisited(ball);

    // push ball to queue
    Q.push(ball);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    cout << bfs();
}