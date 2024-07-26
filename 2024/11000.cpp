#include <bits/stdc++.h>

using namespace std;

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return hash1 ^ hash2;              
        }
         
        // If hash1 == hash2, their XOR is zero.
          return hash1;
    }
};

typedef pair<int, int > pii;
unordered_map<pii, bool, hash_pair> visited;
vector<pii> classes;
int N;

// 끝나는 순서대로 먼저 정렬, 그 후 시작한 순서가 우선
bool compare(pii & a, pii & b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

void input()
{
    cin>> N;
    for (int i = 0 ; i < N; i++)
    {
        int a, b; 
        cin >> a >> b;
        classes.push_back({a,b});
        visited[{a,b}] = false;
    }
}

int solve()
{
    sort(classes.begin(), classes.end(), compare);
    
    int room = 1;       // 방 한개부터시작
    int size = classes.size();

    int ind = -1;
    int prevFinish = -1;
    int cnt = 0;    // store how many rooms we found

    while(cnt < size)
    {
        ind++;

        // after iterating all classes
        if (ind >= size)
        {
            ind = 0;
            room++;
            prevFinish = -1;
        }

        // if visited, continue
        if (visited[classes[ind]])
            continue;

        // if starting of this class is after previous finish, update
        if (classes[ind].first >= prevFinish)
        {
            prevFinish = classes[ind].second;   // update prevFinish
            cnt++;                              // increase cnt
        }
    }

    return room;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    cout << solve();
}