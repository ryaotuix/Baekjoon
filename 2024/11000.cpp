#include <bits/stdc++.h>

using namespace std;

int N;
typedef pair<int, int> pii;
vector<pii> v;

// sort by starting then ending
bool compare(pii & a, pii & b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }

    return a.first < b.first;
}

void input()
{
    cin >> N;
    while(N--)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end(), compare);
}

int solve()
{
    priority_queue<int> pq;             // c++ pq is max heap (to make it min heap, use -)
    // store ending time
    pq.push(-v[0].second);

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].first >= -pq.top())
        {
            pq.pop();
        }
        pq.push(-v[i].second);
    }

    return pq.size();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    cout << solve();
}