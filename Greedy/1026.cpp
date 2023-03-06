#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    int res = 0;

    // A 는 vector 에 저장
    vector<int> a;
    for (int i = 0; i < N; i++)
    {
        int k; cin >> k;
        a.push_back(k);
    }

    // B 는 bst 에 저장
    multiset<int> b;
    for (int i = 0; i < N; i++)
    {
        int k; cin >> k;
        b.insert(k);
    }

    // sort A as descending order
    sort(a.begin(), a.end(), greater<int>());

    multiset<int>::iterator itr;
    int i = 0;
    for (itr = b.begin(); itr != b.end(); itr++, i++)
    {
        int bVal = *itr;
        int aVal = a[i];
        res += aVal * bVal;
    }

    cout << res << endl;
}