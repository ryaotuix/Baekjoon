#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000 + 1;
int arr[MAX];
int N, M;

void input()
{
    cin >> N >> M;
}

bool OOB(int n)
{
    if (n < 0 || n >= MAX) return true;
    return false;
}

void bfs()
{
    arr[N] = 1;
    queue<int> q;
    q.push(N);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        int currTime = arr[curr];

        vector<int> dir;
        if (curr + 1 < MAX) dir.push_back(curr + 1);
        if (curr - 1 >= 0) dir.push_back(curr - 1);
        if (curr * 2 < MAX) dir.push_back(curr * 2);

        for (int next : dir)
        {
            if (next < 0 || next >= MAX) continue; // Bounds check

            // if moving
            if (next != curr * 2)
            {
                // if going to next requires less or same arr, continue
                if (arr[next] <= currTime + 1 && arr[next] != 0) continue;

                // otherwise
                q.push(next);
                arr[next] = currTime + 1;
            }
            // if teleporting
            else
            {
                // if going to next requires less or same arr, continue
                if (arr[next] <= currTime && arr[next] != 0) continue;

                // otherwise
                q.push(next);
                arr[next] = currTime;
            }
        }
    }

    // Output the result
    cout << arr[M]-1 << "\n";
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    bfs();
}