#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
struct coworker
{
    ll curr;
    ll moreAnnoy;
};

class myComparative
{
    public:
        bool operator()(coworker &a, coworker&b)
        {
            ll moreA = a.curr + a.moreAnnoy;
            ll moreB = b.curr + b.moreAnnoy;
            if (moreA == moreB) return a.moreAnnoy > b.moreAnnoy; // ex) 1 1000 ; 1000 1
            return moreA >= moreB; // (>>>>> means MIN Heap)
        }
};

int main()
{
    // ios_base::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    int numHelp, numCoworker; // < 10^5 
    cin >> numHelp >> numCoworker;

    priority_queue<coworker, vector<coworker>, myComparative> pq; // sorted by 
    ll maxCurr = 0; // if we don't need help, we would have to return the or gmax

    // create coworker and put it in a priority queue
    for (int i = 0; i<numCoworker; ++i)
    {
        coworker a;
        ll start, increase; cin >> start >> increase;
        a.curr = start; a.moreAnnoy = increase;
        if (start > maxCurr) maxCurr = start; // update maxCurr
        pq.push(a);
    }

    // if we don't need help
    while (numHelp != 0) 
    {
        numHelp--;
        coworker a = pq.top(); pq.pop();
        a.curr = a.curr + a.moreAnnoy;
        if (maxCurr < a.curr) maxCurr = a.curr;
        pq.push(a);
    }

    cout << maxCurr;
   
}