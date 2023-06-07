#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, m;   // n : number of trees  &&  m : how much we need
ll maxTree = 0;

// Get the sum of the acquired tree when height of the machine is given
// O(n)
ll woodCut(vector<ll> & trees, ll height)
{
    ll sum = 0;
    for (ll tree : trees)
    {
        ll remaining = tree - height;
        if (remaining > 0)
            sum += remaining;
    }
    return sum;
}

// get the highest machine level to get the amount of tree we want
ll binarySearch(vector<ll> & trees, ll target)
{
    ll lo = 0 - 1;
    ll hi = maxTree;
    ll mid;
    
    while (lo + 1 < hi)
    {
        mid = (lo + hi) / 2;
        ll sum = woodCut(trees, mid);        // get sum of wood when cutting with this height

        if (sum < target)                   // 가지고 가는 양이 적을때는, 더 많이 가져가야지! 높이를 낮춰줘야한다
            hi = mid;
        else // sum >= target               // 가지고 가는 양이 많을때는, 더 조금 가져가야지! 높이를 올려줘야 한다
            lo = mid;
    }
    return lo;                              // = 포함이 lo 에 되어있으니 lo 를 리턴
}

int main()
{
    cin >> n >> m;
    vector<ll> trees(n, 0);

    for (ll i = 0; i < n; i++)
    {
        ll tree;
        cin >> tree;
        trees[i] = tree;
        if (tree > maxTree)
            maxTree = tree;
    }   

    // input done Starting at index 0!

    // Binary Search the maximum height of the wood cutter with min and max O(nlogn)
    ll solution = binarySearch(trees, m);
    cout << solution;
    
}

