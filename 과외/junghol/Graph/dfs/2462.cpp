#include <bits/stdc++.h>

using namespace std;

// materials
int n;
int m;
bool visited[500 + 5];
vector<int> orgAdj[500 + 5];
vector<int> reverseAdj[500 + 5];
int numChild = 0;

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int from;
        int to;
        cin >> from >> to;
        orgAdj[from].push_back(to);
        reverseAdj[to].push_back(from);
    }
}

void reverseDFS(int student)
{
    visited[student] = true;
    for (int nextS : reverseAdj[student])
    {
        if (!visited[nextS])
        {
            numChild++;
            visited[nextS] = true;
            reverseDFS(nextS);
        }
    }
}

void orgDFS(int student)
{
    visited[student] = true;
    for (int nextS : orgAdj[student])
    {
        if (!visited[nextS])
        {
            numChild++;
            visited[nextS] = true;
            orgDFS(nextS);
        }
    }
}

int getLess(int student)
{
    // init visited and numchild
    numChild = 0;
    memset(visited, false, sizeof(visited));
    reverseDFS(student);
    return numChild;
}

int getMore(int student)
{
    // init visited and numchild
    numChild = 0;
    memset(visited, false, sizeof(visited));
    orgDFS(student);
    return numChild;
}


int getTotal()
{
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        if (getLess(i) + getMore(i) == n-1)
            ret++;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << getTotal();
}