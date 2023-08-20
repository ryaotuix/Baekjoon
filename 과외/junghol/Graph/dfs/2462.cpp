#include <bits/stdc++.h>

using namespace std;

int n;
int m;
int student[500 + 5];
int inD[500 + 5];
int outD[500 + 5];
bool visited[500 + 5];
vector<int> adjList[500 + 5];


void input()
{
    int n; int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int from;
        int to;
        cin >> from >> to;

        adjList[from].push_back(to);
    }
}


int dfs(int student)
{
    visited[student] = true;

    int ret = 1;
    
    for (int nextS : adjList[student])
    {
        if (!visited[nextS])
        {
            visited[nextS] = true;
            inD[nextS]++;
            ret += dfs(nextS);
        }
    }

    return ret;
}


int getStudentNum()
{
    int ret = 0;

    // get outdegree
    for (int i = 1; i <= n; i++)
    {
        memset(visited, false, sizeof(visited));
        int student = i;
        int out = dfs(student);
        cout << out;
    }

       // print ind and out
    for (int i = 1; i <= n; i++)
    {
        cout << "Student " << i << ' ';
        cout << "IND : " << inD[i] << " ";
        cout << "OUT : " << outD[i] << "\n";
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (inD[i] + outD[i] == n)
            ret++;
    }



    return ret;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    cout << dfs(1);
    int res = getStudentNum();
    cout << res;
}