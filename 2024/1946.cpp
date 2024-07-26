#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
const int MAX = 100000 + 1;

// sort by 1st then second
bool compare(pii & a, pii & b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int solve()
{
    int N;
    vector<pii> v;
    cin >> N;

    while (N--)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end(), compare);

    // 1차 , 2차 최소 값 저장
    int firstMin = v[0].first;
    int secMin = v[0].second;

    int cnt = 1;
    for (int i = 1; i < v.size(); i++)
    {
        int currFirst = v[i].first;
        int currSec = v[i].second;

        // if both current fisrt and second is bigger than minimum. we can't hire this person
        if (currFirst > firstMin && currSec > secMin)
            continue;

        // otherwise, we hire this person
        cnt++;
        firstMin = min(firstMin, currFirst);
        secMin = min(secMin, currSec);
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        cout << solve() << "\n";
    }
}