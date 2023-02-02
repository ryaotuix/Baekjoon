#include <bits/stdc++.h>

using namespace std;

// Make my own structure
struct person{
    int time;
    int money;
    void printInfo() { cout << "Money: " << money << " Time: " << time << endl;}
    bool operator<(person & other) {return money > other.money;};
};

// Make my own Comparative Class to use for Priority Q
class myCompare
{
    public:
    bool operator() (person &a, person&b)
    {
        return a.money < b.money; // a < b makes it as MAX HEAP
    }
};

int main()
{
    int numP, ultTime; cin >> numP >> ultTime;
    priority_queue<person, vector<person>, myCompare> pq;
    // Save Infos
    for (int i = 0; i < numP; i++)
    {
        person p;
        cin >> p.money >> p.time;
        pq.push(p);
    }

    // make array as value 0
    int arr[ultTime] = {0}; 

    int cnt = 0;
    while (!pq.empty())
    {
        person p = pq.top(); pq.pop();
        int ind = p.time;
        for (int i = ind; i >= 0; i--) // starting from the last index
        {
            if (arr[i] < p.money) // if index is less than p.money, then fill it
            {
                arr[i] = p.money;
                break;
            }
        }
    }

    int res = 0;
    for (int i = 0; i <ultTime; i++)
    {
        res += arr[i];
    }

    cout << res;
}