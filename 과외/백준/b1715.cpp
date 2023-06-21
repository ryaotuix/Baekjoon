#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    priority_queue<int> pq; // pq to store the card deck <it is max heap>

    // put all the given cards into pq
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        pq.push(-temp);
    }

    // Case when there is only one card group
    if (pq.size() == 1)
    {
        cout << 0;
        return 0;
    }

    int sum = 0;
    // Start here
    while(true)
    {
        if (pq.size() == 1)
            break;
        
        int a = -pq.top(); pq.pop();
        int b = -pq.top(); pq.pop();

        int c = a+b;
        sum += c;
        pq.push(-c);
    }

    cout << sum;
    return 0;
}