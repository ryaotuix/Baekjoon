#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct fishMonger
{
    ll pricePerKilo;
    ll numFish;
    void printInfo() {
        cout << "{" << numFish << "," << pricePerKilo << "}\n";
    }
};

class myComparative
{
    public:
    bool operator() (fishMonger & a, fishMonger & b) 
    {
        return a.pricePerKilo < b.pricePerKilo; // make MAX pq
    }
};

int main()
{
    ll fish, fishmongers; cin >> fish >> fishmongers;
    // priority queue for fish by weight
    priority_queue<ll> fishes;
    // priority queue for fishmongers by price
    priority_queue<fishMonger, vector<fishMonger>, myComparative> pq;
    // fill fishes
    for (int i = 0; i < fish; i++)
    {
        ll a; cin >> a;
        fishes.push(a);
    }
    // fill pq (fishMongers sorted by price per fish)
    for (int i = 0; i < fishmongers; i++)
    {
        fishMonger a;
        cin >> a.numFish >> a.pricePerKilo;
        pq.push(a);
    }

    ll res = 0;
    // from the biggest fish
    while(!fishes.empty())
    {
        // if there is not fishmonger left
        if (pq.empty()) break;

        // get the best paying fishmonger
        fishMonger fm = pq.top(); pq.pop();
        ll num = fm.numFish;
        ll price = fm.pricePerKilo;

        // use fish for the numFish for best paying fishMonger
        // CASE i account : if fish runs out for this fishmonger, 
        for (int i = 0; i < num && !fishes.empty(); i++)
        {
            res += price * fishes.top();
            fishes.pop();
        }
    }
    cout << res;
    // while(!fishes.empty()) 
    // {
    //     cout << fishes.top() << " ";
    //     fishes.pop();
    // }
    // cout << endl;
    // while(!pq.empty())
    // {
    //     fishMonger a = pq.top();
    //     a.printInfo(); pq.pop();
    // }
    
}