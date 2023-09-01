#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;     // cnt, full per price

int n, k;   // 과일개수 n, 플레이어가 가진 돈 k

vector<pii> fruits; // store fruit information

bool comp(pii & a, pii & b)
{
    return a.second > b.second;
}

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int p, c; cin >> p >> c;
        fruits.push_back({p, c/p}); // number, full per number
    }

    sort(fruits.begin(), fruits.end(), comp);   // sort it in increasing order of full per number

    // for (pii p : fruits)
    //     cout << p.first << "," << p.second << " ";
}

long long getMax()
{
    int ind = 0;
    
    long long res = 0;

    for (int i = 0; i < fruits.size(); i++)
    {
        pii f = fruits[i];  // this fruit

        int cnt = min(k, f.first);      // cnt is minimum between reamining price and this price
        res += cnt * f.second;          // res += filling hunger

        k -= cnt;
        
        if (k == 0) break;
    }
    return res;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << getMax();
}