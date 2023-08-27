#include <bits/stdc++.h>

using namespace std;

const int MAX = 200 + 5;
const int A = 1;
const int B = 2;
const int C = 3;

// capacity of A
int capacity[3 + 1];
// A, B C 의 값에 대한 방문 상태
bool state [MAX][MAX][MAX];
// 현재 상태
int container[3+1];
vector<int> res;

void input()
{
    for (int i = 1; i<=3; i++) cin >> capacity[i];
    container[C] = capacity[C];
}


void dfs(int curr)  // parameter : current container index
{
    // trim cases
    if (state[container[A]][container[B]][container[C]]) return;

    state[container[A]][container[B]][container[C]] = true;
    
    // important case
    if (container[A] == 0) 
    {
        // cout << container[A] << " " << container[B] << " " << container[C] << "\n";
        res.push_back(container[C]);
    } 



    // iterate over other containers ** i repesents container to pour from
    for (int i = 1; i <= 3; i++)
    {
        if (container[i] != 0)
        {
            for (int next = 1; next <= 3; next++)
            {
                // if not current container and it's not full
                if (next != curr && container[next] != capacity[next])
                {
                    int pour = min(container[i], capacity[next] - container[next]);   // pour min(current, capacity of next)

                    container[next] += pour;
                    container[i] -= pour;
                    dfs(next);
                    container[next] -= pour;
                    container[i] += pour;
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
    dfs(C);
    sort(res.begin(), res.end());
    for (int i : res)   cout << i << " ";
}