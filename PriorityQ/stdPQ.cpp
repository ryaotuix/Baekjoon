#include <bits/stdc++.h>

using namespace std;
int main()
{

    //priority_queue<int, vector<int>, greater<int>> minPQ;

    
    // Min Heap
    priority_queue <int, vector<int>, greater<int>> minPQ;

    // MaxHeap
    priority_queue <int> maxPQ;

    for (int i =1; i< 10; i++)
    {
        minPQ.push(i);
        maxPQ.push(i);
    }

    while (!minPQ.empty())
    {
        cout << minPQ.top() << " ";
        minPQ.pop();
    }
    cout << "\n";
    while (!maxPQ.empty())
    {
        cout << maxPQ.top() << " ";
        maxPQ.pop();
    }



}