#include <bits/stdc++.h>

using namespace std;

vector<int> v;

void input()
{
    int n;
    cin >> n;
    while(n--)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
}

void solve()
{
    pair<int, int> res;

    int minDif = 2e9;
    
    int left = 0;
    int right = v.size()-1;

    int sum = sum = v[left] + v[right];

    while(left < right)
    {
        sum = v[left] + v[right];
        
        if (abs(sum) < abs(minDif))
        {
            res.first = v[left];
            res.second = v[right];
            minDif = sum;
        }

        if (sum > 0)
            right--;
        else
            left++;
    }

    cout << res.first << " " << res.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();
}