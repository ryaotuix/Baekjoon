#include <bits/stdc++.h>

using namespace std;

/*
    Idea : 
    1. make unions of ppl who know Truth
    2. make union of each party,
    3. mark each parent of the union,
    4. 
*/

int N, M;
const int MAX = 50 + 1;
bool know[MAX];
int parent[MAX];
vector<int> toCheck;    // store minimum of each party (guaranteed parent of each party)

int find(int x)
{
    if (parent[x] == x)
        return x;
    
    return parent[x] = find(parent[x]);
}

void _union(int a, int b)
{
    a = find(a);
    b = find(b);
    
    if (know[a] || know[b])
    {
        know[a] = true;
        know[b] = true;
    }

    if (a > b)
    {
        swap(a, b);
    }
    
    parent[b] = a;
}

void input()
{
    cin >> N >> M;

    // init parent
    for (int i = 1; i <= N; i++)
        parent[i] = i;

    // init ppl who knows turh
    int num; 
    cin >> num;

    if (num == 0)
        return;

    vector<int> pplKnow;
    while(num--)
    {   
        int temp;
        cin >> temp;
        pplKnow.push_back(temp);
        know[temp] = true;
    }

    for (int i = 0; i < pplKnow.size() - 1; i++)
    {
        _union(pplKnow[i], pplKnow[i+1]);
    }

    


    // union each party
    while(M--)
    {
        int size;   cin >> size;
        vector<int> party;
        int p = MAX;

        while(size--)
        {
            int temp; cin >> temp;
            party.push_back(temp);
            p = min(p, temp);
        }

        // union this party
        for (int i = 0; i < party.size() - 1; i++)
        {
            _union(party[i], party[i + 1]);
        }

        // push p into toCheck
        toCheck.push_back(p);
    }
}

int solve()
{
    if (M != -1)
        return M;

    int cnt = 0;
    for (int check : toCheck)
    {
        // if parent of check knows the truth, you can't lie
        if (know[find(check)])
            continue;
        
        // otherwise, there is noone who knwos the truth, you can lie
        cnt++;
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    cout << solve();
}