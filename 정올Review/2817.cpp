#include <bits/stdc++.h>

using namespace std;

int k;
int lotto[50 + 5];
int res[6] = {0,};  // combination of 6

void input()
{
    cin >> k;

    // input is already sorted -> no need to sort
    for (int i = 0; i < k; i++) cin >> lotto[i];  
}


void dfs(int depth, int start)
{
    // base case:
    if (depth == 6)
    {
        for (int i = 0; i < 6; i++) cout << res[i] << " ";
        cout << "\n";
        return;
    } 

    // recursion here
    for (int i = start; i < k; i++)
    {
        res[depth] = lotto[i];
        dfs(depth + 1, i+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(true)
    {
        input();
        if (k == 0) return 0;
        dfs(0, 0);
        cout << "\n";
    }
    
}