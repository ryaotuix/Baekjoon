#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef struct fruit
{
    int fullPerCnt;
    int cnt;
}fruit;

int N, K;

struct Compare {
    bool operator()(fruit & a, fruit & b)
    {
        return a.fullPerCnt < b.fullPerCnt;
    }
};

priority_queue<fruit, vector<fruit>, Compare> pq;   // pq sorted y price/cnt is on top

void input()
{
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        int p, c; cin >> p >> c;
        int fullPerCnt = c/p;
        pq.push({fullPerCnt, p});
    }
}

ll getMax()
{
    ll res = 0;
    while (K)
    {
        fruit f = pq.top(); pq.pop();
        // cout << f.fullPerCnt << " " << f.cnt << "\n";
        res += f.fullPerCnt;
        K--;

        // if this cnt -1 is not 0, then we can push back
        if (f.cnt - 1 != 0)
            pq.push({f.fullPerCnt, f.cnt - 1});
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    // cout << "\n";
    cout << getMax();
}