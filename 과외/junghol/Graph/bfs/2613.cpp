#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000 + 5;
int M, N;   // col, row
int grid[MAX][MAX];
typedef pair<int, int> pii;     // row, col
queue<pii> Q;                   // Q to store locations


void input()
{
    cin >> M >> N;
    for (int i =0; i < N; i++)  // row 
    {
        for (int j = 0; j < M; j++) // col
        {
            cin >> grid[i][j];
            // if 1, push it to Q
            if (grid[i][j] == 1) Q.push({i, j});
        }
    }
}

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

bool OOB(int r, int c)
{
    if (r < 0 || r >= N) return true;
    if (c < 0 || c >= M) return true;
    return false;
}

void print()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << grid[i][j] << " ";
        cout << "\n";
    }
}

void bfs()
{

    while(!Q.empty())
    {
        pii curr = Q.front(); Q.pop();
        int r = curr.first;
        int c = curr.second;
        int depth = grid[r][c];


        for (int i = 0; i < 4; i++)
        {
            int nextR = r + dr[i];
            int nextC = c + dc[i];

            // only if nextR and nextC is 0
            if (!OOB(nextR, nextC) && grid[nextR][nextC] == 0)
            {
                grid[nextR][nextC] = depth + 1;
                Q.push({nextR, nextC});
            }
        }

        // print();
        // cout << "\N";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    input();
    bfs();

    int result = 0;

    for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (grid[i][j] == 0) {
				cout << -1 << "\n";
				return 0;
			}

			if (result < grid[i][j]) {
				result = grid[i][j];
			}
		}
	}

	cout << result - 1 << "\n";



}