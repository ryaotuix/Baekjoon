#include <bits/stdc++.h>

using namespace std;
/*
    Idea : 
    Start moving with the direction and the amount on the current position,

    Iterate through the direction until the amount becomes 1
        while iterating, if we encounter already visited position, return
    
    When doen iterating, move in new direction! according to new position where we ended
*/

const int MAX = 2 << 7;

typedef pair<int, int> pii;

// materials
int n;
pii goorm;      // <g row, g col>
pii player;     // <p row, p col>
string grid[MAX][MAX];
bool visited[MAX][MAX];



void input()
{
    cin >> n;

    int row, col;
    cin >> row >> col;  goorm = {row, col};
    cin >> row >> col;  player = {row, col};

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> grid[i][j];
}


int getCnt()
{
    int cnt = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (visited[i][j])
                cnt++;

    return cnt;
}

// function to change position according to out of bound position
void OOB(int & curr)
{
    if (curr == 0)
        curr = n;
    if (curr == n+1)
        curr = 1;
}

void moveToNext(char direction, pii & person)
{
    // Left
    if (direction == 'L')
    {
        person.second = person.second - 1;
        OOB(person.second);
    }
    // Right
    else if (direction == 'R')
    {
        person.second = person.second + 1;
        OOB(person.second);
    }
    // Up
    else if (direction == 'U')
    {
        person.first = person.first - 1;
        OOB(person.first);
    }
    // Down
    else if (direction == 'D')
    {
        person.first = person.first + 1;
        OOB(person.first);
    }
}

int dfs(pii person, stringstream & ss)
{
    // person fisrt -> curr Row, person second -> curr Col

    // base case
    if (visited[person.first][person.second] == true) return getCnt();

    visited[person.first][person.second] = true;

    int move;
    char direction;
    
    ss.str(grid[person.first][person.second]);
    ss >> move >> direction;

    // Moving to current direction until we are done moving
    while (move)
    {
        // when we still have to move,
        moveToNext(direction, person);

        // base case
        if (visited[person.first][person.second] == true) return getCnt();
        
        visited[person.first][person.second] = true;

        move--;
    }

    // must make the last position not visited to start next direction with new dfs
    visited[person.first][person.second] = false;

    return dfs(person, ss);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    
    stringstream ss;

    int goormCNT = dfs(goorm, ss);
    memset(visited, false, sizeof(visited));
    int playerCNT = dfs(player, ss);

    if (goormCNT > playerCNT)
        cout << "goorm " << goormCNT;
    else
        cout << "player " << playerCNT;
}