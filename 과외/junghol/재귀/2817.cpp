#include <iostream>

using namespace std;

int lotto[50];          // array to store a set of n possible numbers
int n;                  // size of a set
int answer[50];         // array to store the answer

void dfs(int cnt, int depth)
{
    // Base Case:
    if (depth == 7)
    {
        for (int i = 1; i <= 6; i++)
            cout << answer[i] << " ";
        cout << endl;
        return;
    }

    // Otherwise, fill the answer array
    for (int i = cnt; i <= n; i++)
    {
        answer[depth] = lotto[i];
        dfs(i + 1, depth + 1);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> lotto[i];
    }

    int cnt = 1;
    int depth = 1;

    dfs(cnt, depth);
}