#include <bits/stdc++.h>

using namespace std;

int N, K;

typedef struct Jewlery
{
    int mass;
    int value;
}Jewlery;


// sort by value in descending order
struct Compare
{  
    bool operator()(const Jewlery & a, const Jewlery & b)
    {
        return a.value < b.value;
    }
};

// in vector, sort Jewleries by mass (ascending order). If mass is same, sort it by value (descending order)
bool compare(Jewlery & a, Jewlery & b)
{
    if (a.mass == b.mass)
    {
        return a.value > b.value;
    }
    return a.mass < b.mass;
}

vector<int> bags;
vector<Jewlery> jewleries;

void input()
{
    cin >> N >> K;

    // receive jewleries info
    for (int i = 0; i < N; i++)
    {
        int mass, value;
        cin >> mass >> value;

        Jewlery temp;
        temp.mass = mass;
        temp.value = value;

        jewleries.push_back(temp);
    }

    sort(jewleries.begin(), jewleries.end(), compare);

    // receive bags info
    for (int i = 0; i < K; i++)
    {
        int weight;
        cin >> weight;
        bags.push_back(weight);
    }

    sort(bags.begin(), bags.end());    // sort in ascending order

    // while(!jewleries.empty())
    // {
    //     int weight = jewleries.top().mass;
    //     int val = jewleries.top().value;
    //     cout << weight << " " << val << "\n";
    //     jewleries.pop();
    // }
}


/*
    Idea : put all jewleries that you can put 
*/
long long solve()
{
    long long sum = 0;
    priority_queue<Jewlery, vector<Jewlery>, Compare> pq;    // pq that sort jewlery by value in descending order
    int ind = 0;                                             // jewlery index

    for (int capacity : bags)
    {
        // push all Jewlery that you can put in in this bag
        while (ind < jewleries.size() && jewleries[ind].mass <= capacity)
        {
            pq.push(jewleries[ind]);
            ind++;
        }

        // now in pq, all elements are jewlery that you can put in this bag

        // put a jewlery with the highest value 
        if (!pq.empty())
        {
            sum += pq.top().value;
            pq.pop();
        }
    }

    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();    
    cout << solve();
}