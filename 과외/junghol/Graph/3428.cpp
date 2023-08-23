#include <bits/stdc++.h>

using namespace std;

const int maxi = 1e5;
int n;
int m;
int x;
unordered_map <int, vector<int>> better;
unordered_map <int, vector<int>> worse;
bool visited[maxi+ 5];
int num = 0;

void input()
{
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        int studentA;
        int studentB;
        cin >> studentA >> studentB;

        // if A > B => better[B] = A  && worse[A] = B
        better[studentB].push_back(studentA);
        worse[studentA].push_back(studentB);
    }
}


int dfsBetter(int student)
{
    visited[student] = true;
    for (int betterStudent : better[student])
    {   
        if (!visited[betterStudent])
        {
            // cout << betterStudent << " is better than " << student << endl;
            visited[betterStudent] = true;
            num++;
            dfsBetter(betterStudent);
        }
    }
    return num;
}


int dfsWorse(int student)
{
    visited[student] = true;
    for (int worseStudent : worse[student])
    {   
        if (!visited[worseStudent])
        {
            // cout << worseStudent << " is worse than " << student << endl;
            visited[worseStudent] = true;
            num++;
            dfsWorse(worseStudent);
        }
    }
    return num;
}


int getBest(int student)
{
    num = 0;
    memset(visited, false, sizeof(visited));
    dfsBetter(student);

    return 1 + num;
}

int getWorst(int student)
{
    num = 0;
    memset(visited, false, sizeof(visited));
    dfsWorse(student);

    return n - num;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();

    // getBest(x);
    // getWorst(x);

    cout << getBest(x) << " " << getWorst(x);
}