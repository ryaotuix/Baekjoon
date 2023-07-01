#include <bits/stdc++.h> 

using namespace std;

/* Materials */
typedef pair<int, int> pii;                                                    // <# loads, Town To>

priority_queue< pii, vector<pii>, greater<pair<int,int>> > town[2000 + 5];     // arr of pq <town TO, # loads>         ind : town FROM
int C;                                                                         // Capacity of the truck
int truck;                                                                     // number of loads in truck
priority_queue< pii, vector<pii>, greater<pair<int,int>> > currLoads;          // stores the information of current load in truck (pq by town TO)
int N;                                                                         // # town

void input()
{
    cin >> N >> C;
    int m; cin >> m;
    for (int i = 0; i < m; i++)
    {
        int ind, townTo, load;
        cin >> ind >> townTo >> load;

        pii currPack = make_pair(load, townTo);

        town[ind].push(currPack);
    }
    // ordered by townTo number
}

void checkInput()
{
    for (int i = 0; i < N; i++)
    {
        cout << "Index " << i << " : \n";
        while (!town[i].empty())
        {
            pii currLoad = town[i].top();
            town[i].pop();
            cout << "<" << currLoad.second << " " << currLoad.first << ">" << endl;
        }
    }
}   

int getTotal()
{
    int total = 0;

    // iterate through Towns
    for (int i = 1; i <= N; i++)
    {  
        // town has packages to unload and we have packages to unload here
        while(!currLoads.empty() && currLoads.top().first == i)
        {
            int unload = currLoads.top().second;                 
            cout << "UNLOAD: In town " << i << ": " << "unload amount" << unload << endl;
            total += unload;                                    // unload and increase total
            truck -= unload;
            currLoads.pop();
        }

        // town has a package to deliver, Saved in TOWN
        while(!town[i].empty() && truck < C)
        {
            
            int townTo = town[i].top().second;
            int amount = town[i].top().first;
            // i.e. if we can load 7 more but found amount is 10, -> load amount 7 
            amount = (amount > C - truck) ? C - truck : amount;

            cout << "LOAD: In town " << i << ": " << "with current amount " << truck << " load " << amount << " to " << townTo << endl;
            town[i].pop();
           
            // update amount on truck, and curr load we are carrying
            truck += amount;
            currLoads.push({townTo, amount});
        }
        cout << endl;
    }

    // cout << total;
    return total;
}

int main()
{
    input();
    cout << getTotal();

    

}