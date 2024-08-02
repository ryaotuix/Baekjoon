#include <bits/stdc++.h>

using namespace std;

int N, K;


void input()
{
    cin >> N >> K;
}

void solve()
{
    vector<int> nums(N);
    vector<bool> checked(N);

    for (int i = 0; i < N; i++)
    {
        nums[i] = i + 1;
        checked[i] = false;
    }

    vector<int> res;

    int cnt = K-1;
    int ind = 0;

    int iter = N;

    // N 명을 다뺄때까지
    while(iter)
    {
        if (cnt == -1)  cnt = K-1;
        if (ind == N)   ind = 0;

        // 이미 뺀 친구면
        if (checked[ind])
        {
            ind++;
            continue;
        }

        // 빼지 않은 친구, 빼야할 친구면
        if (cnt == 0)
        {
            // cout << nums[ind] << "is gone\n";
            checked[ind] = true;        // 뺀다
            res.push_back(nums[ind]);   
            iter--;                     // iter 을 돌린다
        }

        ind++;                      
        cnt--;
    }

    cout << "<";
    for (int i = 0; i < N; i++)
    {
        cout << res[i];
        if (i != N-1)
            cout << ", ";
    }
    cout << ">";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();
}