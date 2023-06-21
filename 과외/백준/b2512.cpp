#include <bits/stdc++.h>

using namespace std;


vector<int> states;         // vector to store state's budget request
int numStates;              // number of states
int totalBudget;

// min and max of budget request from one state
int minState = 1e5;
int maxState = 0;

void Input()
{
    cin >> numStates;
    for (int i = 0; i < numStates; i++)
    {
        int temp; cin >> temp;

        // update min and max state
        if (temp < minState)
            minState = temp;
        if (temp > maxState)
            maxState = temp;

        states.push_back(temp);
    }
    cin >> totalBudget;
}


// function to get Sum with the given upper bound for each state's budget
int getSum(int mid)
{
    int sum = 0;
    for (int budget : states)
    {
        if (budget <= mid)          // add requested amount when it is lower than mid
            sum += budget;
        else                        // add the upper bound (mid) when requested amount is greater than mid
            sum += mid;
    }

    return sum;
}

// function to get Sum
int binarySearch()
{
    int lo = 0 - 1;
    int hi = maxState + 1;

    while(lo + 1 < hi)
    {
        int mid = (lo + hi) / 2;
        int sum = getSum(mid);

        if (sum <= totalBudget)     // if sum is less than total budget
        {
            lo = mid;               // we can bring 'mid' up 
        }
        else
        {
            hi = mid;
        }
    }
    
    return lo;
}


int main()
{
    Input();
    cout << binarySearch();
}