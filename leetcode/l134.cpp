#include <bits/stdc++.h>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int totalGas = 0;
    int totalCost = 0;
    int startInd;
    int tank = 0;

    for (int i = 0; i < gas.size(); i++)
    {
        totalGas += gas[i];
        totalCost += cost[i];
        tank += gas[i] - cost[i];
        if (tank < 0)
        {  
            startInd = (i + 1) % gas.size();
            tank = 0;
        }
    }

    if (totalGas < totalCost)
        return -1;

    
    return startInd;
}


int main()
{
    vector<int> gas = {3,1,1};
    vector<int> cost = {1,2,2};
    cout << canCompleteCircuit(gas, cost);
}