#include <bits/stdc++.h>

using namespace std;

typedef struct load
{
    int from;
    int to;
    int amount;
} load;

/* Materials */
vector<load> loads;
int N;
int C;
int num;

// comparator to sort load
bool loadComp(const load &a, const load &b)
{
    if (a.from == b.from)
    {
        if (a.to == b.to)
        {
            return a.amount < b.amount; // '<' sorts in an ascending order
        }

        return a.to < b.to;
    }

    return a.from < b.from;
}

struct byTo
{
    bool operator()(const load &a, const load &b)
    {
        return a.to > b.to;
    }
};

void
input()
{
    cin >> N >> C;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        int from, to, amount;
        cin >> from >> to >> amount;
        load curr = {from, to, amount};
        loads.push_back(curr);
    }

    sort(loads.begin(), loads.end(), loadComp);

    cout << endl;
    for (auto i : loads)
    {
        cout << i.from << " " << i.to << " " << i.amount << endl;
    }
}

void printLoad(load l)
{
    cout << "From : " << l.from << " To : " << l.to << " Amount : " <<  l.amount << endl;
}

int getAmont()
{
    int res = 0;
    int truck = 0; // current load

    // sorted by the town to send
    priority_queue<load, vector<load>, byTo> pq; // contain current load on truck

    int i = 0; // ptr at load vectors

    for (int town = 0; town <= N; town++)
    {
       
        // (I) get out of the truck first
        // if not empty and there is a load to this town
        while (!pq.empty() && pq.top().to == town)
        {
            cout << "Unloading" << endl;
            printLoad(pq.top());

            res += pq.top().amount;   // carried this successfully
            truck -= pq.top().amount; // unload it from truck (remove weight and pop)
            pq.pop();
        }

        cout << endl;
        // (II) load the truck
        while (i < loads.size() && loads[i].from == town)
        {
            cout << "Loadng \n";
            // if truck does not have capacity, we can't load from this town
            if (truck == C)
            {
                i++;
                continue;
            }
            
            // if truck has capacity
            // i.e. we have the amount of 60 but truck has 20 spaces left
            loads[i].amount = (C - truck < loads[i].amount) ? C - truck : loads[i].amount;

            // add it to truck
            truck += loads[i].amount;
            pq.push(loads[i]);
            
            cout << "just loaded ";
            printLoad(loads[i]);
            i++;
            
        }

        cout << endl;
        cout << endl;
    }

    return res;
}

int main()
{
    input();
    cout << getAmont();
}