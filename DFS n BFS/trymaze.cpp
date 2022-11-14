#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

// MAX ind y = 5 x = 7
// 0 is the way, 1 is the wall
char maze[7][8]= {
{'s','0','1','1','1','1','1','1'},
{'1','0','0','0','1','0','0','1'},
{'1','1','0','1','0','0','1','1'},
{'1','1','0','1','0','0','0','1'},
{'1','0','0','0','0','1','0','e' },
{'1','1','0','1','1','1','1','1'},
};
int visited[7][8]; // make visited global variable <all entries are 0>
// 상하좌우
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0 ,0, -1, 1};

// functions
void maze_print();
bool OOB(int y, int x);

// flag
bool reached = false;

void dfs(int y, int x)
{
  visited[y][x] = 1; // visited (1)
  maze_print();

  for (int i=0; i<4; i++)
  {
    int nY = y + dy[i];
    int nX = x + dx[i];
    // if out of bound
    if(OOB(nY, nX)) continue;

    // if it has reached
    if (maze[nY][nX] == 'e')
    {
      reached = true;
      cout << "CONGRATS" << endl;
      exit(0);
    }

    // if not wall (0) and not wisited (0)
    if (maze[nY][nX] == '0' && visited[nY][nX]==0)
    {
      visited[nY][nX] = 1;
      maze[nY][nX] = 'x';
      dfs(nY, nX);
    }
  }
}


queue<pii> q;

void bfs(int y, int x)
{
  visited[y][x] = 1;
  q.push({y,x});

  while(!q.empty())
  {
    pii cur = q.front(); q.pop();
    int curX = cur.second;
    int curY = cur.first;

    for (int i=0; i<4; i++)
    {
      int nY = curY + dy[i];
      int nX = curX + dx[i];

      // if out of bound or if not the correct path
      if(OOB(nY, nX) || visited[nY][nX] == 1) continue;

      // if it has reached
      if (maze[nY][nX] == 'e')
      {
        reached = true;
        cout << "CONGRATS" << endl;
        exit(0);
      }

      // if not wall (0) and not visited (0)
      if (maze[nY][nX] == '0' && visited[nY][nX]==0)
      {
        visited[nY][nX] = 1;
        maze[nY][nX] = 'x';
        q.push({nY,nX});
        maze_print();
      }

    }

  }

}

int main()
{
  int y = 0;
  int x = 0;
  bfs(y,x);
  if (reached == false) cout << "dumb" << endl;
  return 0;
  //cout << "5,0  is " << maze[5][0] << endl;
}



void maze_print()
{
    for(int i=0; i<7; i++)
    {
        for(int j=0; j<8; j++)
            cout << maze[i][j];
        cout <<"\n";
    }
    cout << "\n";
}

bool OOB(int y, int x)
{
  return y<0 || y>=6 || x<0 || x>=8;
  // return true is out of bound
}
