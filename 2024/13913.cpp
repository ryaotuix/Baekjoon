#include <bits/stdc++.h>

using namespace std;

const int MAX = 100000 + 1;
int arr[MAX];       // 몇번 사용해서 도착해하는가
int N, K;
int cnt = 0;

void input()
{
    cin >> N >> K;
}

bool OOB(int n)
{
    if (n < 0 || n >= MAX)  return true;
    return false;
}

void bfs()
{
    queue<int> q;
    q.push(N);
    arr[N] = 1;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();


        int dir[3] = {curr-1, curr+1, curr*2};

        for (int i = 0; i < 3; i++)
        {
            int next = dir[i];
            if (!OOB(next))
            {
                // if moving
                if (i < 2)
                {
                    // if visited and this time takes longer, skip
                    if (arr[next] != 0 && arr[next] < arr[curr] + 1)
                        continue;
                
                    
                    // 다음까지 가는데 지금 + 1
                    arr[next] = arr[curr] + 1;
                    q.push(next);
                }
                else
                {
                    // if visited and this time takes longer, skip
                    if (arr[next] != 0 && arr[next] < arr[curr])
                        continue;

                    // 다음까지 가는데 지금
                    arr[next] = arr[curr];
                    q.push(next);
                }
                

            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    bfs();
    cout << arr[K] - 1 << "\n";
}