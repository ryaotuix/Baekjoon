#include <bits/stdc++.h>

using namespace std;

// materials
int n;
int matrix[20 + 5][20 + 5]; // store power info
int total = 0;              // total power possible

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> matrix[i][j];
            total += matrix[i][j];
        }
    }
}



// material
bool used[20 + 5];
vector<vector<int>> combinations;  // store all combination of Star Team

// get team Start Combination (combination not permutation) ; starting at depth 1
void dfsTeamComb(int depth, vector<int> & v, int prev)
{
    // base case:
    if (depth == n/2 + 1)
    {
        combinations.push_back(v);
        // for (int i = 1; i <= n/2; i++)
        //     cout << v[i] << " ";
        // cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        // if not visited
        if (!used[i] && i >= prev)
        {
            used[i] = true;
            v[depth] = i;               // mark the value

            dfsTeamComb(depth + 1, v, i);
            used[i] = false;
        }
    }
}

// materials
// Now we got all combinatiosn and stored in combinations <each starting at index 1>
int dif = 1e9;
int loc[2];

// get power of a star team, given the team member
void getPower(vector<int> v, int & power, int depth)    // depth starting at 1
{
    // base case:
    if (depth == 3)
    {
        power += matrix[ loc[0]] [loc[1] ];
        return;
    }

    for (int i = 1; i <= n/2; i++)
    {
        // if not visited
        if (!used[ v[i] ])
        {
            used[ v[i] ] = true;
            loc[depth -1] = v[i];   // curr team

            getPower(v, power, depth + 1);
            used[ v[i] ] = false;
        }
    }
}


void getMinDif()
{
    vector<int> v2;

    for (auto v: combinations)
    {
        int starTeam = 0;
        // refresh bool used arr
        memset(used, false, sizeof(used));
        getPower(v, starTeam, 1);
        v2.push_back(starTeam);
    }

    // for (int p : v2)
    //     cout << p << endl;
    
    int len = v2.size() - 1;
    for (int i = 0; i < len; i++)
    {
        int teamDif = abs(v2[i] - v2[len-i]);
        dif = min(dif, teamDif);
    }
}

int main()
{
    input();
    vector<int> v (n/2 + 1);    // make a container to list combinations starting at index 1

    // cout << endl;
    dfsTeamComb(1, v, 0);
    // cout << endl;

    getMinDif();

    // cout << endl;
    cout << dif << endl;

    
}