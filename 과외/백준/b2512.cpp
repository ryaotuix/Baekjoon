#include <bits/stdc++.h>

using namespace std;

int n;      // number of state
int total;  // total money we have
int maxRequest = 0;             // save the maximum request from a single state
int sumRequest = 0;             // save the total request from all states


// Return the sum request for a given upper limit
int getSumRequest(vector<int> & states, int upperLimit)
{
    int sum = 0;
    for (int request : states)
    {
        if (request > upperLimit)       // if this state's request > upperLimit, only give them upperLimit
            sum += upperLimit;
        else                            // otherwise, (when we can give what they want), give them as they requested
            sum += request;
    }
    return sum;
}

int binarySearch(vector<int> & states)
{
    int lo = 0;
    int hi = maxRequest + 1;
    int mid;                        // current upper limit

    while (lo + 1 < hi)
    {
        mid = (hi + lo) / 2;
        int spending = getSumRequest(states, mid);      // total money to spend according to the current upper limit

        if (spending <= total)                          // if this spending <= total, increase the lo
        {
            lo = mid;
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
    // INPUT
    cin >> n;

    vector<int> states (n);         

    for (int i = 0; i < n; i++)
    {
        int request; cin >> request;
        sumRequest += request;      // add up each state's request

        states[i] = request;        // store each state's request        

        if (request > maxRequest)   // update the max request from a single state
            maxRequest = request;   
    }
        

    cin >> total;

    // When we can give all, print maxRequest and terminate
    if (sumRequest <= total)
    {
        cout << maxRequest;
        return 0;
    }

    // Binary Search
    cout << binarySearch(states);
}