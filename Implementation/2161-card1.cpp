#include <iostream>
#include <queue>

//push
//pop
//front
//back
//size
//empty
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    queue<int> q;
    
    int n; cin >> n;
    
    for (int i = 1; i <= n; i++)
    {
        q.push(i); 
    }


    while (q.size() != 1)
    {
        cout << q.front() << " "; q.pop();
        int temp = q.front(); q.pop();
        q.push(temp);
    }

    cout << q.front() << endl;
    return 0;
}