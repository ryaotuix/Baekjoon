#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii; // <original, cnt>
int n;
int k;
vector<pii> vec;


bool compare(pii & a, pii & b)
{
    // 2진수가 같을때
    if (a.second == b.second)
    {
        return a.first > b.first;
    }
    // 아니면 2진수로 정렬
    return a.second > b.second;
}

int getNumOne(int temp)
{
    int cnt = 0;
    while (temp)
    {
        if ((1 & temp) == 1)
            cnt++;
        temp = temp >> 1;
    }

    return cnt;
}


void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        int oneCnt = getNumOne(temp);
        vec.push_back({temp, oneCnt});
    }
    
    sort(vec.begin(), vec.end(), compare);

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << vec[k-1].first;
}