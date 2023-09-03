#include <bits/stdc++.h>

using namespace std;

const int MAX = 300 + 5;
int dp1[MAX];       // 첫번째 밟았을때
int dp2[MAX];       // 두번째 밟았을때
int stair[MAX];

int N;

void input()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> stair[i];
}

void DP()
{
    // base cae
    dp1[1] = stair[1];
    dp1[2] = stair[2];

    dp2[2] = stair[1] + stair[2];

    for (int i = 3; i <= N; i++)
    {
        dp1[i] = max(dp2[i-2], dp1[i-2]) + stair[i];    // 처음 밟을때는 두칸 전의 최적해에서 현재값을 더한 것

        dp2[i] = dp1[i-1] + stair[i];                   // 두번째 밟았을때는 한칸전의 최적해에서 현재값을 더한 것
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    DP();
    cout << max(dp1[N], dp2[N]);
}